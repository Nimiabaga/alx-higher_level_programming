#include <Python.h>

void print_python_float(PyObject *obj);
void print_python_bytes(PyObject *obj);
void print_python_list(PyObject *obj);

/**
 * print_python_float - Print Python float object info
 * @obj: PyObject pointer
 */
void print_python_float(PyObject *obj)
{
	double value = 0;
	char *str_repr = NULL;

	fflush(stdout);
	printf("[.] float object info\n");

	if (!PyFloat_CheckExact(obj))
	{
		printf("  [ERROR] Invalid Float Object\n");
		return;
	}

	value = ((PyFloatObject *)obj)->ob_fval;
	str_repr = PyOS_double_to_string(value, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
	printf("  value: %s\n", str_repr);
	PyMem_Free(str_repr);
}

/**
 * print_python_bytes - Print Python bytes object info
 * @obj: PyObject pointer
 */
void print_python_bytes(PyObject *obj)
{
	Py_ssize_t size = 0;
	Py_ssize_t index = 0;
	char *byte_data = NULL;

	fflush(stdout);
	printf("[.] bytes object info\n");

	if (!PyBytes_CheckExact(obj))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	size = PyBytes_Size(obj);
	printf("  size: %zd\n", size);

	if (size > 0)
	{
		byte_data = ((PyBytesObject *)obj)->ob_sval;
		printf("  trying string: %s\n", byte_data);
		printf("  first %zd bytes:", size < 10 ? size : 10);

		while (index < size && index < 10)
		{
			printf(" %02hhx", byte_data[index]);
			index++;
		}

		printf("\n");
	}
}

/**
 * print_python_list - Print Python list object info
 * @obj: PyObject pointer
 */
void print_python_list(PyObject *obj)
{
	Py_ssize_t length = 0;
	PyObject *element;
	int index = 0;

	fflush(stdout);
	printf("[*] Python list info\n");

	if (PyList_CheckExact(obj))
	{
		length = PyList_GET_SIZE(obj);
		printf("[*] Size of the Python List = %zd\n", length);
		printf("[*] Allocated = %lu\n", ((PyListObject *)obj)->allocated);

		while (index < length)
		{
			element = PyList_GET_ITEM(obj, index);
			printf("Element %d: %s\n", index, element->ob_type->tp_name);

			if (PyBytes_Check(element))
				print_python_bytes(element);
			else if (PyFloat_Check(element))
				print_python_float(element);

			index++;
		}
	}
	else
	{
		printf("  [ERROR] Invalid List Object\n");
	}
}
