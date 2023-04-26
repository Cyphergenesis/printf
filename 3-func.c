#include "main.h"

/**
* non_print - Prints ascii codes in hexa of non printable character
* @list: List of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int non_print(va_list list, char buffer[], int flags, int width, int
		precision, int size)
{
	char *ptr = va_arg(list, char*);
	int j = 0, offset = 0;

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (ptr == NULL)
		return (write(1, "(null)", 6));
	while (ptr[j] != '\0')
	{
		if (_prints_all(ptr[j]))
			buffer[j + offset] = ptr[j];
		else
		offset += _append_hex(ptr[j], buffer, j + offset);
	}
	buffer[j + offset] = '\0';
	return (write(1, buffer, j + offset));
}

/**
 * display_pointer - Prints the value of a pointer variable
 * @list: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int display_pointer(va_list list, char buffer[], int flags, int width,
		int precision, int size)
{
	char set_to[] = "0123456789abcdef";
	char more = 0, snt = ' ';
	unsigned long val_add;
	int index = BUFFER_SIZE - 2, length, add = 1;
	void *store = va_arg(list, void*);

	UNUSED(width);
	UNUSED(size);

	if (store == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFFER_SIZE - 1] = '\0';
	UNUSED(precision);

	val_add = (unsigned long)store;

	for (length = 0; val_add > 0; length++)
	{
		buffer[index--] = set_to[val_add % 16];
		val_add /= 16;
	}
	if ((flags & _ZERO_) && !(flags & _MINUS_))
		snt = '0';
	if (flags & _PLUS_)
		more = '+', length++;
	else if (flags & _SPACE_)
		more = ' ', length++;
	index++;

	return (_pointer_write(buffer, index, length, width, flags,
				snt, more, add));
}

/**
* reverse_print- Prints reverse string.
* @list: List of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Numbers of character printed
*/
int reverse_print(va_list list, char buffer[], int flags, int width,
		int precision, int size)
{
	int n, count = 0;
	char *ptr;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	ptr = va_arg(list, char*);

	if (ptr == NULL)
	{
		UNUSED(precision);
		ptr = "(null)";
	}
	for (n = 0; ptr[n]; n++)

	n -= 1;
	while (n >= 0)
	{
		char y =  ptr[n];

		write(1, &y, 1);
		n--;
		count++;
	}
	return (count);
}

/**
* rot13_string - Print a string in rot13.
* @list: Lista of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Numbers of character printed
*/
int rot13_string(va_list list, char buffer[], int flags, int width,
		int precision, int size)
{
	unsigned int i, k;
	int count = 0;
	char u, *ptr;
	char upper_lower[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char mixed[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	ptr = va_arg(list, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (ptr == NULL)
		ptr = "(AHYY)";

	for (i = 0; ptr[i] != '\0'; i++)
	{
		for (k = 0; upper_lower[k]; k++)
		{
			if (upper_lower[k] == ptr[k])
			{
				u = mixed[k];
				write(1, &u, 1);
				count++;
				break;
			}
		}
		if (!upper_lower[k])
		{
			u = ptr[i];
			write(1, &u, 1);
			count++;
		}
	}
	return	(count);
}
