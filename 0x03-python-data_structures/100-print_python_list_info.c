#include <Python.h>

/**
 * print_python_list_info - Prints information about a Python list object.
 * @p: Pointer to the Python List object.
 */
void print_python_list_info(PyObject *p)
{
	int index;

	printf("[*] Size of the Python List = %li\n", Py_SIZE(p));
	printf("[*] Allocated = %li\n", ((PyListObject *)p)->allocated);
	for (index = 0; index < Py_SIZE(p); index++)
	{
		PyObject *item = PyList_GetItem(p, index);

		printf("Element %i: %s\n", index, Py_TYPE(item)->tp_name);
	}
}
