#include "main.h"

/**
* get_flags - Calculates active flags
* @format: Formatted string in which to print the arguments
* @i: take a parameter.
* Return: Flags:
*/
int get_flags(const char *format, int *i)
{
	/* j = k, curr_i = cur*/
	int k, cur;
	int flags = 0;
	const char flags_ch[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flags_str[] = {_MINUS_, _PLUS_, _ZERO_, _HASH_, _SPACE_, 0};
		for (cur = *i + 1; format[cur] != '\0'; cur++)
		{
			for (k = 0; flags_ch[k] != '\0'; k++)
			{
			if (format[cur] == flags_ch[k])
			{
				flags |= flags_str[k];
				break;
			}
			if (flags_ch[k] == 0)
				break;
			}
		}
	*i = cur - 1;
	return (flags);
}
