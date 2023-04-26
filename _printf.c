#include "main.h"

void display_buffer(char buffer[], int *index_buffer);
/**
 *_printf - printf function
 *@format: format
 *
 *Return: printed chars
 */
int _printf(const char *format, ...)
{
	int i;
	int flags, width, precision, size = 0;
	int index_buffer = 0, print = 0, print_ch = 0;
	va_list list;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);

	i = 0;
	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[index_buffer++] = format[i];
			if (index_buffer == BUFFER_SIZE)
				display_buffer(buffer, &index_buffer);
					print_ch++;
		}
		else
		{
			display_buffer(buffer, &index_buffer);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			++i;
	print = create_print(format, &i, list, buffer, flags, width, precision, size);
		if (print == -1)
		return (-1);
	print_ch += print;
		}
		i++;
	}
	display_buffer(buffer, &index_buffer);
	va_end(list);
	return (print_ch);
}
/**
 *display_buffer - prints content of buffer
 *@buffer: Array of chars
 *@index_buffer: Index at which to add next char
 *
 */
void display_buffer(char buffer[], int *index_buffer)
{
	if (*index_buffer > 0)
		write(1, &buffer[0], *index_buffer);
	*index_buffer = 0;
}
