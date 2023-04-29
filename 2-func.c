#include "main.h"

/**
 *write_upper_lower - prints unsigned number
 *@list: list of argument
 *@buffer: Buffer array to control print
 *@flags: Calculate active flags
 *@width: width
 *@precision: Precision specification
 *@size: Size specifier
 *@map_to: map to array of chars
 *@ch: extra chars
 *
 *Return: Number of characters are printed
 */
int write_upper_lower(va_list list, char map_to[], char buffer[], int
		flags, char ch, int width, int precision, int size)
{
	unsigned long int val = va_arg(list, unsigned long int);
	unsigned long int first_num = val;
	int i = BUFFER_SIZE - 2;

	UNUSED(width);

	val = convert_unsignd(val, size);

	if (val == 0)
		buffer[i--] = '\0';
	buffer[BUFFER_SIZE - 1] = '\0';

	while (val > 0)
	{
		buffer[i--] = map_to[val % 16];
		val /= 16;
	}
	if (flags & _HASH_ && first_num != 0)
	{
		buffer[i--] = ch;
		buffer[i--] = '0';
	}
	i++;
	return (print_unsign(0, i, buffer, flags, width, precision, size));
}

 /**
 *display_hex - prints an unsigned number in hexadecimal notation
 *@list: list of arguments
 *@buffer: Buffer  array to control print
 *@flags: Calculate flags
 *@width: get width
 *@precision: Precision specification
 *@size: Size specifier
 *
 *Return: Number of character printed
 */
int display_hex(va_list list, char buffer[], int flags, int width,
		int precision, int size)
{
	return (write_upper_lower(list, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}
/**
 *write_octal-print an unsigned number in octal
 *@list: list of argument
 *@buffer: Buffer array to control print
 *@flags: Calculate flags
 *@width: calculate width
 *@precision: Precision specification
 *@size: Size specifier
 *
 *
 *Return: Number of characters to print
 */
int write_octal(va_list list, char buffer[], int flags, int width,
int precision, int size)
{
	unsigned long int val = va_arg(list, unsigned long int);
	unsigned long int first_num = val;
	int i = BUFFER_SIZE - 2;

	UNUSED(width);
	val = convert_unsignd(val, size);

	if (val == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';

	while (val > 0)
	{
		buffer[i--] = (val % 8) + '0';
		val /= 8;
	}
	if (flags & _HASH_ && first_num != 0)
		buffer[i--] = '0';
	i++;
	return (print_unsign(0, i, buffer, flags, width, precision,
				size));

}
/**
 *display_unsigned - prints unsigned number
 *@list: list of argument
 *@buffer: Buffer array to control print
 *@flags: Calculate active flags
 *@width: width
 *@precision: Precision specification
 *@size: Size specifier
 *
 *Return: Number of chars printed
 */
int display_unsigned(va_list list, char buffer[], int flags, int width
		, int precision, int size)
{
	unsigned long int number = va_arg(list, unsigned long int);
	int i = BUFFER_SIZE - 2;

	number = convert_unsignd(number, size);

	if (number == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}
	i++;

	return (print_unsign(0, i, buffer, flags, width, precision,
				size));
}

/**
 *display_upper_hex - prints unsigned number
 *@list: list of argument
 *@buffer: Buffer array to control print
 *@flags: Calculate active flags
 *@width: width
 *@precision: Precision specification
 *@size: Size specifier
 *
 *Return: Number of characters are printed
 */
int display_upper_hex(va_list list, char buffer[], int flags, int
		width, int precision, int size)
{
	return (write_upper_lower(list, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}
