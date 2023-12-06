#include <Python.h>

/**
 * print_python_bytes - Function prints information about a Python bytes object
 * @p: Python object
 */
void print_python_bytes(PyObject *p)
{
	long int byte_size;
	int next;
	char *str = NULL;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	PyBytes_AsStringAndSize(p, &str, &byte_size);
	printf("  size: %li\n", byte_size);
	printf("  trying string: %s\n", str);
	if (byte_size < 10)
		printf("  first %li bytes:", byte_size + 1);
	else
		printf("  first 10 bytes:");
	for (next = 0; next <= byte_size && next < 10; next++)
		printf(" %02hhx", str[next]);
	printf("\n");
}

/**
 * print_python_list - Function prints information about a Python list object
 * @p: PY object
 */
void print_python_list(PyObject *p)
{
	long int byte_size = PyList_Size(p);
	int next;
	PyListObject *list = (PyListObject *)p;
	const char *obj;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %li\n", byte_size);
	printf("[*] Allocated = %li\n", list->allocated);
	for (next = 0; next < byte_size; next++)
	{
		obj = (list->ob_item[next])->ob_type->tp_name;
		printf("Element %i: %s\n", next, obj);
		if (!strcmp(obj, "bytes"))
			print_python_bytes(list->ob_item[next]);
	}
}
