#include "Python.h"

/**
 * print_python_string - Function that prints
 *  information about Python strings
 * @p: PyObject representing a Python string
 *
 * Description: This function prints information about
 *  Python string objects,
 * including type, length, and value.
 */

void print_python_string(PyObject *p)
{
	long int str_length;

	fflush(stdout);

	/* Print header for string object information */
	printf("[.] string object info\n");

	/* Check if the given PyObject is a string */
	if (strcmp(p->ob_type->tp_name, "str") != 0)
	{
		printf("  [ERROR] Invalid String Object\n");
		return;
	}

	/* Extract the length of the string */
	str_length = ((PyASCIIObject *)(p))->length;

	/* Check if the string is a compact ASCII or compact Unicode object */
	if (PyUnicode_IS_COMPACT_ASCII(p))
		printf("  type: compact ascii\n");
	else
		printf("  type: compact unicode object\n");

	/* Print the length of the string */
	printf("  length: %ld\n", str_length);

	/* Print the value of the string */
	printf("  value: %ls\n", PyUnicode_AsWideCharString(p, &str_length));
}
