#include "main.h"
/**
* create_print- Prints an argument based on its type
* @list: List of arguments to be printed.
* @index: index
* @buffer: Buffer array to handle print.
* @flags: Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
*@ft: pointer to constant chars
* Return: 1 or 2;
*/
int create_print(const char *ft, int *index, va_list list, char buffer
[], int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, print_chars = -1;

	gnt_t f_types[] = {
		{'c', display_char}, {'s', display_string},
		{'%', _percent}, {'i', write_int}, {'d', write_int},
		{'b', display_binary}, {'u', display_unsigned},
		{'o', write_octal}, {'x', display_hex},
		{'X', display_upper_hex}, {'p', display_pointer},
		{'S', non_print}, {'r', reverse_print},
		{'R', rot13_string}, {'\0', NULL}};
	for (i = 0; f_types[i].ft != '\0'; i++)

	if (ft[*index] == f_types[i].ft)

	return (f_types[i].fn(list, buffer, flags, width, precision,
				size));
	if (f_types[i].ft == '\0')
	{
		if (ft[*index] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (ft[*index - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (ft[*index] != ' ' && ft[*index] != '%')
				--(*index);
			if (ft[*index] == ' ')
				--(*index);
			return (1);
		}
		unknown_len += write(1, &ft[*index], 1);
		return (unknown_len);
	}
	return (print_chars);
}
