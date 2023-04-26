#include "main.h"
/**
* print_unsign - Writes an unsigned number
* @non_negative: Number indicating if the num is negative
* @index: Index at which the number starts in the buffer
* @buffer: Array of chars
* @flags: Flags specifiers
* @width: Width specifier
* @precision: Precision specifier
* @size: Size specifier
*
* Return: Number of written chars.
*/
int print_unsign(int non_negative, int index, char buffer[],
int flags, int width, int precision, int size)
{
	int length = BUFFER_SIZE - index - 1, i = 0;
	char pad = ' ';

	UNUSED(non_negative);
	UNUSED(size);

	if (precision == 0 && index == BUFFER_SIZE - 2 && buffer[index] == '0')
		return (0);

	if (precision > 0 && precision < length)
		pad = ' ';
	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}
	if ((flags & _ZERO_) && !(flags & _MINUS_))
		pad = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
		{
			buffer[i] = pad;
		buffer[i] = '\0';
		}
		if (flags & _MINUS_)
		{
return (write(1, &buffer[index], length) + write(1, &buffer[0],
i));
		}
		else
		{
	return (write(1, &buffer[0], i) + write(1, &buffer[index], length));
		}
	}
	return (write(1, &buffer[index], length));
}

/**
* _write_char - Prints a string
* @c: char types.
* @buffer: Buffer array to handle print
* @flags: Calculates active flags.
* @width: get width.
* @precision: precision specifier
* @size: Size specifier
*
* Return: Number of chars printed.
*/
int _write_char(char c, char buffer[], int flags, int width, int
		precision, int size)
{
	int i = 0;
	char pad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & _ZERO_)
		pad = '\0';
	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFFER_SIZE - i - 2] = pad;
		if (flags & _MINUS_)
	return (write(1, &buffer[0], 1) + write(1, &buffer[BUFFER_SIZE
				- i - 1], width - 1));
		else

	return (write(1, &buffer[BUFFER_SIZE - i - 1], width - 1) + 
			write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/**
* display_num - Prints a string
* @non_negative: List of arguments
* @index: char types.
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @precision: precision specifier
* @size: Size specifier
*
* Return: Number of chars printed.
*/
int display_num(int non_negative, int index, char buffer[], int flags,
		int width, int precision, int size)
{
	int length = BUFFER_SIZE - index - 1;
	char pad = ' ', ch = 0;

	UNUSED(size);

	if ((flags & _ZERO_) && !(flags & _MINUS_))
		pad = '\0';
	if (non_negative)
		ch = '-';
	else if (flags & _PLUS_)
		ch = '+';
	else if (flags & _SPACE_)
		ch = ' ';
	return (write_buffer(index, buffer, flags, width, precision, 
			length, pad, ch));
}

/**
*write_buffer - Write a number using a bufffer
*@index: Index at which the number starts on the buffer*
*@buffer: Buffer
*@flags: Flags
*@width: width
*@precision: Precision specifier
*@length: Number length
*@pad: Pading char
*@ch: Extra char
*
*Return: Number of printed characters
*/
int write_buffer(int index, char buffer[], int flags, int width, int
		precision, int length, char pad, char ch)
{
	int i, pad_start = 1;

	if (precision == 0 && index == BUFFER_SIZE - 2 &&
			buffer[index] == '0' && width == 0)
		return (0);
	if (precision == 0 && index == BUFFER_SIZE - 2 &&
			buffer[index] == '0')
		buffer[index] = pad = ' ';
	if (precision > 0 && precision < length)
		pad = ' ';
	while (precision > length)
		buffer[--index] = '0', length++;
	if (ch != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flags & _MINUS_ && pad == ' ')
		{
			if (ch)
			buffer[--index] = ch;
	return (write(1, &buffer[index], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & _MINUS_) && pad == ' ')
		{
			if (ch)
			buffer[--index] = ch;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], length));
		}
		else if (!(flags & _MINUS_) && pad == '0')
		{
			if (ch)
				buffer[--pad_start] = ch;
	return (write(1, &buffer[pad_start], i - pad_start) + write(1,
			&buffer[index], length - (1 - pad_start)));
		}
	}
	if (ch)
		buffer[--index] = ch;
	return (write(1, &buffer[index], length));
}

/**
* _pointer_write - Write a memory address
* @buffer: Arrays of chars
* @index: Index at which the number starts in the buffer
* @length: Length of number
* @width: Width specifier
* @flags: Flags specifier
* @pad: Char representing the padding
* @ch: Char representing extra char
* @pad_srt: Index at which padding should start
*
* Return: Number of written chars.
*/
int _pointer_write(char buffer[], int index, int length, int width,
	int flags, char pad, char ch, int pad_srt)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
		{
			buffer[i] = pad;
			buffer[i] = '\0';
		}
		if (flags & _MINUS_ && pad == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (ch != '\0')
				buffer[--index] = ch;
			return (write(1, &buffer[index], length) +
		write(1, &buffer[3], i - 3));
	}
	else if (!(flags & _MINUS_) && pad == ' ')
	{
		buffer[--index] = 'x';
		buffer[--index] = '0';
		if (ch)
			buffer[--index] = ch;
	return (write(1, &buffer[3], i - 3) + write(1, &buffer[index], length));
	}
	else if (!(flags & _MINUS_) && pad == '0')
	{
		if (ch)
		buffer[--pad_srt] = ch;
		buffer[1] = '0';
		buffer[2] = 'x';
	return (write(1, &buffer[pad_srt], i - pad_srt) + write(1,
		&buffer[index], length - (1 - pad_srt) - 2));
	}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (ch != '\0')
	buffer[--index] = ch;
	return (write(1, &buffer[index], BUFFER_SIZE - index - 1));
}
