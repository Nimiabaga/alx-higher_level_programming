#include <Python.h>

/**
 * print_python_bytes - a Functions that prints PY bytes
 * @p: python object
 */
void print_python_bytes(PyObject *p)
{
	long int element_size
	int u;
	char *str = NULL;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	PyBytes_AsStringAndSize(p, &str, &element_size);
	printf("  size: %li\n", element_size);
	printf("  trying string: %s\n", str);
	if (size < 10)
		printf("  first %li bytes:", element_size + 1);
	else
		printf("  first 10 bytes:");
	for (u = 0; u <= element_size && u < 10; u++)
		printf(" %02hhx", str[u]);
	printf("\n");
}

/**
 * print_python_list - a Function that prints PY list
 * @p: PY object
 */
void print_python_list(PyObject *p)
{
	long int  element_size = PyList_Size(p);
	int u;
	PyListObject *list = (PyListObject *)p;
	const char *obj;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %li\n", element_size);
	printf("[*] Allocated = %li\n", list->allocated);
	for (u = 0; u < element_size; u++)
	{
		obj = (list->ob_item[u])->ob_type->tp_name;
		printf("Element %i: %s\n", u, obj);
		if (!strcmp(obj, "bytes"))
			print_python_bytes(list->ob_item[u]);
	}
}