#include <Python.h>

void print_python_float(PyObject *p);
void print_python_bytes(PyObject *p);
void print_python_list(PyObject *p);

/**
 * print_python_float - Func prints py float info
 * @p: Py Object
 */
void print_python_float(PyObject *p)
{
	double num = 0;
	char *str = NULL;

	fflush(stdout);
	printf("[.] float object info\n");

	if (!PyFloat_CheckExact(p))
	{
		printf("  [ERROR] Invalid Float Object\n");
		return;
	}
	elem = ((PyFloatObject *)p)->ob_fval;
	str = PyOS_double_to_string(num, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
	printf("  value: %s\n", str);
}
/**
 * print_python_bytes - Function that print py bytes data
 * @p: Py Object
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t len = 0;
	Py_ssize_t u = 0;
	char *str = NULL;

	fflush(stdout);
	printf("[.] bytes object info\n");
	if (!PyBytes_CheckExact(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	len = PyBytes_Size(p);
	printf("  size: %zd\n", len);
	str = (assert(PyBytes_Check(p)), (((PyBytesObject *)(p))->ob_sval));
	printf("  trying string: %s\n", str);
	printf("  first %zd bytes:", len < 10 ? len + 1 : 10);
	while (u < len + 1 && u < 10)
	{
		printf(" %02hhx", str[u]);
		u++;
	}
	printf("\n");
}
/**
 * print_python_list - Function that prints py list info
 * @p: Py Object
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t len = 0;
	PyObject *item;
	int k = 0;

	fflush(stdout);
	printf("[*] Python list info\n");
	if (PyList_CheckExact(p))
	{
		len = PyList_GET_SIZE(p);
		printf("[*] Size of the Python List = %zd\n", len);
		printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);
		while (k < len)
		{
			item = PyList_GET_ITEM(p, k);
			printf("Element %d: %s\n", k, item->ob_type->tp_name);
			if (PyBytes_Check(item))
				print_python_bytes(item);
			else if (PyFloat_Check(item))
				print_python_float(item);
			k++;
		}
	}
	else
		printf("  [ERROR] Invalid List Object\n");
}