#include "PythonNetworkWrapper.h"
#include "PythonVectorParser.h"
#include "../../module/Network.h"
#include "../../module/RegulatorFactory.h"


PyObject* PythonNetworkWrapper::create(PyObject* self, PyObject* args)
{
    int nodeCount;
    if (!PyArg_ParseTuple(args, "i", &nodeCount))
        return nullptr;
    
    Network* network = new Network(nodeCount);
    return Py_BuildValue("k", reinterpret_cast<unsigned long>(network));
}

PyObject* PythonNetworkWrapper::destroy(PyObject* self, PyObject* args)
{
    unsigned long networkID;
    if (!PyArg_ParseTuple(args, "k", &networkID))
        return nullptr;
    
    Network* network = reinterpret_cast<Network*>(networkID); 
    if (network)
        delete network;
    return Py_BuildValue("");
}

PyObject* 
PythonNetworkWrapper::countRegulationParameter(PyObject* self, PyObject* args)
{
    char* regulation; 
    if (!PyArg_ParseTuple(args, "s", &regulation))
        return nullptr;
    return PyLong_FromLong(RegulatorFactory::countParameter(regulation));
}

PyObject* 
PythonNetworkWrapper::setRegulationType(PyObject* self, PyObject* args)
{
    unsigned long networkID;
    PyObject* sourceIndexList;
    int targetIndex;
    char* regulation; 
    if (!PyArg_ParseTuple(args, "kOis", &networkID, 
                          &sourceIndexList, &targetIndex, &regulation))
        return nullptr;
    
    Network* network = reinterpret_cast<Network*>(networkID);
    int nodeCount = network->nodeCount;
    if (targetIndex > nodeCount)
        return Py_BuildValue("");
    
    size_t i;
    size_t regulationCount = network->regulations[targetIndex].size();
    std::vector<int> sourceIndexes = 
                        PythonVectorParser::parseIntegers(sourceIndexList);
    const Regulator* regulator = nullptr;
    for (i=0; i<regulationCount; i++)
    {
        if (network->regulations[targetIndex][i].first == sourceIndexes)
        {
            if (network->regulations[targetIndex][i].second->name() == 
                regulation)
                regulator = network->regulations[targetIndex][i].second;
            else
            {
                // Remove the existing regulator if it is of different type
                network->removeRegulation(sourceIndexes, targetIndex);
            }
            break;
        }
    }
    if (regulator == nullptr)
    {
        regulator = RegulatorFactory::createFromName(regulation);
        network->setRegulation(sourceIndexes, targetIndex, regulator);
    }
    
    return Py_BuildValue("k", reinterpret_cast<unsigned long>(regulator));
}

PyObject* 
PythonNetworkWrapper::setRegulationParameter(PyObject* self, PyObject* args)
{
    unsigned long regulatorID;
    int parameterIndex;
    double parameter;
    if (!PyArg_ParseTuple(args, "kid", 
                          &regulatorID, &parameterIndex, &parameter))
        return nullptr;
    
    Regulator* regulator = reinterpret_cast<Regulator*>(regulatorID);
    if (regulator)
        regulator->setParameter(parameterIndex, parameter);
    return Py_BuildValue("");
}

PyObject* 
PythonNetworkWrapper::setRegulationParameters(PyObject* self, PyObject* args)
{
    unsigned long regulatorID;
    PyObject* parameterList;
    if (!PyArg_ParseTuple(args, "kO", &regulatorID, &parameterList))
        return nullptr;
    
    Regulator* regulator = reinterpret_cast<Regulator*>(regulatorID);
    std::vector<double> parameters = 
                            PythonVectorParser::parseDoubles(parameterList);
    if (regulator && parameters.size() <= regulator->parameterCount())
    {
        for (size_t i=0; i<parameters.size(); i++)
            regulator->setParameter(i, parameters[i]);
    }
    return Py_BuildValue("");
}

PyObject* 
PythonNetworkWrapper::setRegulationNoise(PyObject* self, PyObject* args)
{
    unsigned long regulatorID;
    double relativeNoise, minNoise;
    if (!PyArg_ParseTuple(args, "kdd", 
                          &regulatorID, &relativeNoise, &minNoise))
        return nullptr;
    
    Regulator* regulator = reinterpret_cast<Regulator*>(regulatorID);
    if (regulator && relativeNoise >= 0 && minNoise >= 0)
    {
        GaussianNoiseGenerator* noise = 
                        new GaussianNoiseGenerator(minNoise, relativeNoise);
        regulator->setNoise(noise);
    }
    return Py_BuildValue("");
}

PyObject* 
PythonNetworkWrapper::removeRegulation(PyObject* self, PyObject* args)
{
    unsigned long networkID, regulatorID;
    if (!PyArg_ParseTuple(args, "kk", &networkID, &regulatorID))
        return nullptr;
    
    Network* network = reinterpret_cast<Network*>(networkID);
    Regulator* regulator = reinterpret_cast<Regulator*>(regulatorID);
    if (!(network && regulator))
        return Py_BuildValue("");
    
    for (size_t i=0; i<network->regulations.size(); i++)
    {
        for (auto j=network->regulations[i].cbegin(); 
             j!=network->regulations[i].cend(); j++)
        {
            if (j->second == regulator)
            {
                network->removeRegulation(j->first, i);
                break;
            }
        }
    }
    return Py_BuildValue("");
}

PyObject* PythonNetworkWrapper::setSeed(PyObject* self, PyObject* args)
{
    unsigned long networkID;
    unsigned long seed;
    if (!PyArg_ParseTuple(args, "kk", &networkID, &seed))
        return nullptr;
    
    Network* network = reinterpret_cast<Network*>(networkID);
    if (network)
    {
        int count = 0;
        for (size_t i=0; i<network->regulations.size(); i++)
        {
            for (auto j=network->regulations[i].cbegin(); 
                j!=network->regulations[i].cend(); j++)
            {
                const_cast<Regulator*>(j->second)->setSeed(seed + count);
                count += 1;
            }
        }
    }
    return Py_BuildValue("");
}

PyObject* PythonNetworkWrapper::evolve(PyObject* self, PyObject* args)
{
    unsigned long networkID;
    PyObject* valueList;
    double time;
    if (!PyArg_ParseTuple(args, "kOd", &networkID, &valueList, &time))
        return nullptr;
    
    Network* network = reinterpret_cast<Network*>(networkID);
    int nodeCount = network->nodeCount;
    std::vector<double> values = PythonVectorParser::parseDoubles(valueList);
    if (nodeCount > int(values.size()))
        return Py_BuildValue("");
    
    int i;
    std::vector<double> initialValues(nodeCount);
    for (i=0; i<nodeCount; i++)
        initialValues[i] = values[i];
    std::vector<double> targets = network->evolve(initialValues, time);
    
    PyObject* result = PyList_New(nodeCount);
    for (i=0; i<nodeCount; i++)
        PyList_SET_ITEM(result, i, PyFloat_FromDouble(targets[i]));
    return result;
}

PyObject* PythonNetworkWrapper::evolveMultiple(PyObject* self, PyObject* args)
{
    unsigned long networkID;
    PyObject* valueList;
    double time;
    int trajectoryCount;
    if (!PyArg_ParseTuple(args, "kOdi", &networkID, 
                          &valueList, &time, &trajectoryCount))
        return nullptr;
    
    Network* network = reinterpret_cast<Network*>(networkID);
    int nodeCount = network->nodeCount;
    std::vector<double> values = PythonVectorParser::parseDoubles(valueList);
    if (nodeCount > int(values.size()))
        return Py_BuildValue("");
    
    int i, j;
    std::vector<double> initialValues(nodeCount);
    for (i=0; i<nodeCount; i++)
        initialValues[i] = values[i];
    std::vector<std::vector<double>> targets = 
                network->evolveMultiple(initialValues, time, trajectoryCount);
    
    PyObject* result = PyList_New(trajectoryCount);
    for (i=0; i<trajectoryCount; i++)
    {
        PyObject* tempList = PyList_New(nodeCount);
        for (j=0; j<nodeCount; j++)
            PyList_SET_ITEM(tempList, j, PyFloat_FromDouble(targets[i][j]));
        PyList_SET_ITEM(result, i, tempList);
    }
    return result;
}

