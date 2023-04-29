#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024


#define _MINUS_ 1
#define _PLUS_ 2
#define _ZERO_ 4
#define _HASH_ 8
#define _SPACE_ 16

#define _LONG_ 2
#define _SHORT_ 1

struct ft
{
char ft;
int (*fn)(va_list, char[], int, int, int, int);
};

typedef struct ft gnt_t;
int _printf(const char *format, ...);
int handle_print(const char *ft, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);

/*Functions to print chars and strings*/
int display_char(va_list list, char buffer[], int flags, int width, 
		int precision, int size);
int display_string(va_list list, char buffer[], int flags, int width, 
 			int precision, int size);
int _percent(va_list list, char buffer[], int flags, int width, 
		int precision, int size);

/*Functions to print numbers */
int write_int(va_list list, char buffer[], int flags, int width, int 
		precision, int size);
int display_binary(va_list list, char buffer[], int flags, int width, 
 		int precision, int size);
int display_unsigned(va_list list, char buffer[], int flags, 
		int width, int precision, int size);
int write_octal(va_list list, char buffer[], int flags, int width, 
		int precision, int size);
int display_hex(va_list list, char buffer[], int flags, int width, 
		int precision, int size);
int write_upper_lower(va_list list, char map_to[], char buffer[], int 
 		flags, char ch, int width, int precision, int size);
int display_upper_hex(va_list list, char buffer[], int flags, 
		int width, int precision, int size);

/* Function to print non printable characters*/
int non_print(va_list list, char buffer[], int flags, int width, int 
		precision, int size);

/*function to print memory address*/
int display_pointer(va_list list, char buffer[], int flags, int width,
		int precision, int size);

/*Function to handle other specifiers*/
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int reverse_print(va_list list, char buffer[], int flags, int width, 
		int precision, int size);
		
/*function to print a string in rot 13*/
int rot13_string(va_list list, char buffer[], int flags, int width, 
		int precision, int size);


/*Write handlers*/
int print_unsign(int non_negative, int index, char buffer[], 
		int flags, int width, int precision, int size);
int _write_char(char c, char buffer[], int flags, int width, 
		int precision, int size);
int display_num(int non_negative, int index, char buffer[], 
		int flags, int width, int precision, int size);
int write_buffer(int index, char buffer[], int flags, int width, 
		int prec, int length, char pad, char ch);
int _pointer_write(char buffer[], int ind, int length, int width, 
		int flags, char pad, char ch, int pad_srt);
int create_print(const char *ft, int *index, va_list list, 
	char buffer[], int flags, int width, int precision, int size);

/*sutils*/
int _append_hex(char ascii_code, char buffer[], int i);
int verify_is_digit(char c);
long int change_size_number(long int num, int size);
long int convert_unsignd(unsigned long int num, int size);
int _prints_all(char c);

#endif
