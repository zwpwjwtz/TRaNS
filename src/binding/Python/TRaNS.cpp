#include <Python.h>
#include "PythonNetworkWrapper.h"


static PyMethodDef TRANS_python_methods[] = 
{
    {"newNetwork", 
     PythonNetworkWrapper::create, METH_VARARGS, 
     "Create a Network object and return its identity."}, 
    
    {"deleteNetwork", 
     PythonNetworkWrapper::destroy, METH_VARARGS, 
     "Delete an existing Network object."}, 
    
    {"setRegulationType", 
     PythonNetworkWrapper::setRegulationType, 
     METH_VARARGS, 
     "Set the regulation between source nodes and a target node in "
     "a network."}, 
    
    {"setRegulationParameter", 
     PythonNetworkWrapper::setRegulationParameter, 
     METH_VARARGS, 
     "Set the parameters of a regulation."}, 
    
    {"setRegulationNoise", 
     PythonNetworkWrapper::setRegulationNoise, 
     METH_VARARGS, 
     "Set the relative noise level and the minimum noise of a regulation."}, 
    
    {"removeRegulation", 
     PythonNetworkWrapper::removeRegulation, 
     METH_VARARGS, 
     "Remove a regulation from a network."}, 
    
    {"setSeed", 
     PythonNetworkWrapper::setSeed, 
     METH_VARARGS, 
     "Set the seed of random number generators for generating noise."},
    
    {"evolveNetwork", 
     PythonNetworkWrapper::evolve, 
     METH_VARARGS, 
     "Evolve the network within a given time span."}, 
    
    {"evolveMultipleNetwork", 
     PythonNetworkWrapper::evolveMultiple, 
     METH_VARARGS, 
     "Evolve the network in multiple trajectories within a given time span."}, 
    
    {NULL, NULL, 0, NULL}
};

static PyModuleDef TRaNS_python_module = 
{
    PyModuleDef_HEAD_INIT, 
    "TRaNS", 
    "Python binding of TRaNS",
    -1, 
    TRANS_python_methods
};

PyMODINIT_FUNC PyInit_TRaNS(void)
{
    return PyModule_Create(&TRaNS_python_module);
}

