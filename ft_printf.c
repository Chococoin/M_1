#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h> // Añadir esta línea

#define F_SPEC "csidpuxX"

int	ft_putchar(char *s)
{
	if (*s != '\0')
	{
		write(1, s, 1);
		return (1);
	}
	return (0);
}

char	ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (*s);
		s++;
	}
	if ((char)c == '\0')
		return (*s);
	return (0);
}

int	f_selector(va_list args, char *format)
{
	if (format[1] == 'c')
	{
		char c = (char)va_arg(args, int);
		write(1, &c, 1);
		return 1;
	}
	return 0;
}

int	ft_printf(char *f, ...)
{
	va_list	args;
	int		count_char;

	va_start (args, f);
	count_char = 0;
	while (*f)
	{
/* 		if (*f == '%' &&  !f[1])
			exit(1); */
		if (*f == '%' && f[1] == ft_strchr(F_SPEC, f[1]) && f[1])
		{
			count_char += f_selector(args, f);
			f += 2;
		}
		else if (*f == '%' && f[1] == '%')
		{
			count_char += ft_putchar(f);
			f += 2;
		}
		count_char += ft_putchar(f);
		f++;
	}
	va_end(args);
	return (count_char);
}

int	main(void)
{
	int	number_of_char;
	// int	number_of_char_2;

	number_of_char = ft_printf("Hola%c", '!');
	printf("\n%i\n", number_of_char);

	// number_of_char_2 = printf("Hola%c%", '!');
	// printf("\n%i\n", number_of_char_2);
}
