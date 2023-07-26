#include "main.h"

/**
 * Size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int Size(const char *format, int *i)
{
	int cur = *i + 1;
	int size = 0;
	/* get the MACRO for size specifier constant */
	if (format[cur] == 'l')
		size = S_LONG;
	/* get the MACRO for size specifier constant */
	else if (format[cur] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = cur - 1;
	else
		*i = cur;

	return (size);
}
/**
 * Width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int Width(const char *format, int *i, va_list list)
{
	int cur;
	int width = 0;

	/* loop through the format string after % */
	/* accumulates the digits to calculate the width specifier */
	for (cur = *i + 1; format[cur] != '\0'; cur++)
	{
		/* check if current char in the format string is decimal */
		if (is_digit(format[cur]))
		{
			width *= 10;
			width += format[cur] - '0';
		}
		/* retrieving the width from the variadic arguments */
		else if (format[cur] == '*')
		{
			cur++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur - 1;

	return (width);
}
