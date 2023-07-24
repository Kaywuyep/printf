int _printf (const char *format, ...)
{
	int i, char_count
	va_list arg
	unsign
		va_start (arg, format);
	if (format == NULL)
		return;
	char_count = vprintf(format, args);
	va_end;

	return(char_count);
}
