#include <Python.h>

#include "crypto.h"

static PyObject *crypto_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    crypto_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    crypto_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef CryptoMethods[] = {
    { "getPoWHash", crypto_getpowhash, METH_VARARGS, "Returns the proof of work hash using crypto hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef CryptoModule = {
    PyModuleDef_HEAD_INIT,
    "crypto_hash",
    "...",
    -1,
    CryptoMethods
};

PyMODINIT_FUNC PyInit_crypto_hash(void) {
    return PyModule_Create(&CryptoModule);
}

#else

PyMODINIT_FUNC initcrypto_hash(void) {
    (void) Py_InitModule("crypto_hash", CryptoMethods);
}
#endif
