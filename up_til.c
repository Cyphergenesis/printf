#include "main.h"

/**
* _append_hex- Append ascci in hexadecimal code to buffer
* @buffer: Array of chars.
* @i: Index at which to start appending.
* @ascii_code: ASSCI CODE.
* Return: Always 3
*/
int _append_hex(char ascii_code, char buffer[], int i)
{
	char set_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = set_to[ascii_code / 16];
	buffer[i] = set_to[ascii_code % 16];

	return (3);
}

/**
* _prints_all - Evaluates if a char is printable
* @c: Character to be printed
*
* Return: 1 if c is printable, 0 otherwise
*/
int _prints_all(char c)
{
	if (c >= 32 && c < 127)
	return (1);
	else
	return (0);
}

/**
* change_size_number - Casts a number to the specified size
* @num: Number to be casted.
* @size: Number indicating the type to be casted.
*
* Return: Casted value of num
*/
long int change_size_number(long int num, int size)
{
	if (size == _LONG_)
	return (num);
	else if (size == _SHORT_)

	return ((short)num);

	return ((int)num);
}

/**
 *verify_is_digit - Verifies if a char is a digit
 * @c: Character to be printed
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int verify_is_digit(char c)
{
	if (c >= '0' && c <= '9')
	return (1);
	else
	return (0);
}

/**
* convert_unsignd - Casts a number to the specified size
* @num: Number to be casted
* @size: Number indicating the type to be casted
*
* Return: Casted value of num
*/
long int convert_unsignd(unsigned long int num, int size)
{
	if (size == _LONG_)
	return (num);
	else if (size == _SHORT_)
	return ((unsigned short)num);

	return ((unsigned int)num);
}
