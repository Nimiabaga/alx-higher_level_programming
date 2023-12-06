#include <Python.h>

/**
 * print_python_bytes_info - Function prints information about a
 * Python bytes object
 * @p: Python object
 */
void print_python_bytes_info(PyObject *p)
{
	long int byte_size;
	int index;
	char *byte_str = NULL;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	PyBytes_AsStringAndSize(p, &byte_str, &byte_size);
	printf("  size: %li\n", byte_size);
	printf("  trying string: %s\n", byte_str);
	if (byte_size < 10)
		printf("  first %li bytes:", byte_size + 1);
	else
		printf("  first 10 bytes:");

	for (index = 0; index <= byte_size && index < 10; index++)
		printf(" %02hhx", byte_str[index]);

	printf("\n");
}

/**
 * print_python_list_info - Function prints information about a
 * Python list object
 * @p: Python object
 */
void print_python_list_info(PyObject *p)
{
	long int list_size = PyList_Size(p);
	int index;
	PyListObject *list = (PyListObject *)p;
	const char *element_type;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %li\n", list_size);
	printf("[*] Allocated = %li\n", list->allocated);

	for (index = 0; index < list_size; index++)
	{
		element_type = (list->ob_item[index])->ob_type->tp_name;
		printf("Element %i: %s\n", index, element_type);

		if (!strcmp(element_type, "bytes"))
			print_python_bytes_info(list->ob_item[index]);
	}
}
