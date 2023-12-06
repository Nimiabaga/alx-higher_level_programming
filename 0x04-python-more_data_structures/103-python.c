#include <Python.h>

/**
 * print_python_bytes_info - Function prints information
 * about a Python bytes object
 * @p: Python object
 */
void print_python_bytes_info(PyObject *p)
{
	long int size;
	int i;
	char *bytes_str = NULL;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	PyBytes_AsStringAndSize(p, &bytes_str, &size);
	printf("  size: %li\n", size);
	printf("  trying string: %s\n", bytes_str);
	if (size < 10)
		printf("  first %li bytes:", size + 1);
	else
		printf("  first 10 bytes:");

	for (i = 0; i <= size && i < 10; i++)
		printf(" %02hhx", bytes_str[i]);

	printf("\n");
}

/**
 * print_python_list_info - Function prints information
 * about a Python list object
 * @p: Python object
 */
void print_python_list_info(PyObject *p)
{
	long int size
