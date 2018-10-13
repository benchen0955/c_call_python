// pyapi.c
#include "/home/ben/anaconda3/include/python3.7m/Python.h"
//#include <python3.5m/Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *src;
    Py_Initialize();
    PyObject *for_c_p;

    // 将当前目录加入sys.path
    printf("将当前目录加入sys.path\n");
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");

    // 导入hello.py模块
    printf("导入hello_e.py模块\n");
    PyObject *pmodule = PyImport_ImportModule("hello_e");

    // 获得函数xprint对象，并调用，输出“hello world\n”
    printf("获得函数xprint对象，并调用，输出==>hello world\n");
    PyObject *pfunc = PyObject_GetAttrString(pmodule, "xprint");
    PyObject_CallFunction(pfunc, NULL);

    // 获得类Hello并生成实例pinstance，并调用print成员函数，输出“5 6\n”
    PyObject *pclass    = PyObject_GetAttrString(pmodule, "HHello_c");
    PyObject *arg       = Py_BuildValue("(i)", 3);
    printf("print===>5\n");
    PyObject *pinstance = PyObject_Call(pclass, arg, NULL);
    printf("print===>6\n");
    PyObject_CallMethod(pinstance, "printt", "i", NULL);
    PyObject_CallMethod(pinstance, "printt", "i", 5);
    PyObject_CallMethod(pinstance, "printt", "i", 7);
   


    Py_Finalize();
    return 0;
}
