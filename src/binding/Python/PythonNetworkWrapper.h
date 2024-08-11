#ifndef PYTHON_NETWORK_H
#define PYTHON_NETWORK_H
#include <Python.h>


class PythonNetworkWrapper
{
public:
    static PyObject* create(PyObject* self, PyObject* args);
    static PyObject* destroy(PyObject* self, PyObject* args);

    static PyObject* countRegulationParameter(PyObject* self, PyObject* args);
    static PyObject* setRegulationType(PyObject* self, PyObject* args);
    static PyObject* setRegulationParameter(PyObject* self, PyObject* args);
    static PyObject* setRegulationNoise(PyObject* self, PyObject* args);
    static PyObject* removeRegulation(PyObject* self, PyObject* args);

    static PyObject* setSeed(PyObject* self, PyObject* args);
    
    static PyObject* evolve(PyObject* self, PyObject* args);
    static PyObject* evolveMultiple(PyObject* self, PyObject* args);
};

#endif
