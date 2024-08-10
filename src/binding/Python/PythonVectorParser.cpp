#include "PythonVectorParser.h"


std::vector<int> PythonVectorParser::parseIntegers(PyObject* object)
{
    std::vector<int> result;
    auto vector = parseItems(object);
    for (size_t i=0; i<vector.size(); i++)
    {
        if (PyLong_Check(vector[i]))
            result.push_back(PyLong_AsLong(vector[i]));
    }
    return result;
}

std::vector<double> PythonVectorParser::parseDoubles(PyObject* object)
{
    std::vector<double> result;
    auto vector = parseItems(object);
    for (size_t i=0; i<vector.size(); i++)
    {
        if (PyFloat_Check(vector[i]))
            result.push_back(PyFloat_AsDouble(vector[i]));
        else if (PyLong_Check(vector[i]))
            result.push_back(double(PyLong_AsLong(vector[i])));
    }
    return result;
}

std::vector<PyObject*> PythonVectorParser::parseItems(PyObject* object)
{
    size_t i;
    std::vector<PyObject*> result;
    if (PyList_Check(object))
    {
        for (i=0; i<size_t(PyList_Size(object)); i++)
            result.push_back(PyList_GetItem(object, i));
    }
    else if (PyTuple_Check(object))
    {
        for (i=0; i<size_t(PyTuple_Size(object)); i++)
            result.push_back(PyTuple_GetItem(object, i));
    }
    return result;
}
