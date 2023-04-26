#include "main.h"

/**
 *display_char - prints a char
 *@buffer: Buffer array to handle print
 *@list: List of arguments
 *@flags: Calculate active flags
 *@precision: Precision specification
 *@size: Size specifier
 *@width: calculate width
 *
 *Return: Number of chars printed
 */
int display_char(va_list list, char buffer[], int flags, int width,
		int precision, int size)
{
	char c = va_arg(list, int);

	return (_write_char(c, buffer, flags, width, precision, size));
}
/**
 *display_binary - prints an unsigned number
 *@list: list of arguments
 *@buffer: Buffer array to control print
 *@flags: Calculates active flags
 *@width: width size
 *@precision: precision specification
 *@size: Size specifier
 *
 *Return: Numbers of char to print
 */
int display_binary(va_list list, char buffer[], int flags, int width,
int precision, int size)
{
	unsigned int j, k, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	j = va_arg(list,  unsigned int);
	k = 2147483648;
	a[0] = j / k;

	for (i = 1; i < 32; i++)
	{
		k /= 2;
		a[i] = (j / k) % 2;

	}

	i = 0, sum = 0, count = 0;

	while (i < 32)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char p = '0' + a[i];

			write(1, &p, 1);
			count++;
		}
		i++;
	}
	return (count);
}
/**
 *_percent - prints a percent sign
 *@list: list of arguments
 *@buffer: buffer array to handle print
 *@flags: calculates flags
 *@width: calculate width
 *@precision: Precision specification
 *@size: Size specifier
 *
 *Return: Numbers of chars to print
 */
int _percent(va_list list, char buffer[], int flags, int width,
	int precision, int size)
{
	UNUSED(list);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 *display_strings - prints a string
 *@size: Size specifier
 *@flags: calculate active flags
 *@width: Calculate width
 *@precision: Precision specification
 *@list: List of arguments
 *@buffer: Buffer array to display print
 *
 *Return: Number of chars printed
 */
int display_string(va_list list, char buffer[], int flags, int width,
int precision, int size)
{
	int i, len;
	char *ptr = va_arg(list, char*);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (ptr == NULL)
	{
		ptr = "(null)";
		if (precision >= 6)
			ptr = " ";
	}

	for (len = 0; ptr[len] != '\0'; len++)

		if (precision >= 0 && precision < len)
			len = precision;
	if (width > len)
	{
		if (flags & _MINUS_)
		{
			write(1, &ptr[0], len);
			for (i = width - len; i > 0; i--)
				write(1, "", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i++)
			{
				write(1, " ", 1);
				write(1, &ptr[0], len);
				return (width);
			}
		}
	}
	return (write(1, ptr, len));
}

/**
 *write_int - print int
 *@list: list of arguments
 *@buffer: buffer array to show print
 *@flags: Calculates flags
 *@width: width size
 *@precision: Precision specification
 *@size: Size specifier
 *Return: Number of chars printed
 */
int write_int(va_list list, char buffer[], int flags, int width,
int precision, int size)
{
	long int j = va_arg(list, long int);
	int i = BUFFER_SIZE - 2;
	int non_negative = 0;
	unsigned long int mun;

	j = change_size_number(j, size);

	if (j == 0)
		buffer[i--] = '\0';

	buffer[BUFFER_SIZE - 1] = '\0';
	mun = (unsigned long int)j;

	if (j < 0)
	{
		mun = (unsigned long int)((-1) * j);
		non_negative = 1;
	}
	while (mun > 0)
	{
		buffer[i--] = (mun % 10) + '0';
		mun /= 10;
	}
	i++;

	return (display_num(non_negative, i, buffer, flags, width, precision, size));
}
