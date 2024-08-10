#ifndef PYTHONVECTORPARSER_H
#define PYTHONVECTORPARSER_H

#include <vector>
#include <Python.h>


class PythonVectorParser {
public:
    static std::vector<int> parseIntegers(PyObject* object);
    static std::vector<double> parseDoubles(PyObject* object);

private:
    static std::vector<PyObject*> parseItems(PyObject* object);
};

#endif
