#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h> // Añadir esta línea

#define F_SPEC "cs" //idpuxX"

int	ft_putchar(char *s)
{
	if (s && *s != '\0')
	{
		write(1, s, 1);
		return (1);
	}
	return (0);
}
int ft_putstr(char *c)
{
	int	len;

	len = 0;
	while (*c != '\0')
	{
		ft_putchar(c);
		c++;
		len++;
	}
	return (len);
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

int	f_selector(va_list *args, const char *format)
{
	char	c;
	char	*s;

	if (format[1] == 'c')
	{
		c = (char)va_arg(*args, int);
		return (ft_putchar(&c));
	} 
	else if (format[1] == 's')
	{
		s = va_arg(*args, char *);
		printf("%c", *s);
		return (ft_putstr(s));
	}
/* 	else if (format[1] == d)
	{
		*c = (char)va_arg(args, int);
		return ()
	} */
	return (0);
}

int	ft_printf(char *f, ...)
{
	va_list	args;
	int		count_char;

	va_start (args, f);
	count_char = 0;
	while (*f)
	{
		if (*f == '%' && f[1] == ft_strchr(F_SPEC, f[1]) && f[1])
		{
			count_char += f_selector(&args, f);
			f += 2;
		}
		else if (*f == '%' && f[1] == '%')
		{
			count_char += ft_putchar(f);
			f += 2;
		}
		else
		{
			count_char += ft_putchar(f);
			f++;
		}
	}
	va_end(args);
	return (count_char);
}

int	main(void)
{
	int	number_of_char;
	// int	number_of_char_2;

	number_of_char = ft_printf("Hola%c%c%c", '!', '?', '!');
	printf("\n%i\n", number_of_char);

	// number_of_char_2 = printf("Hola%c%", '!');
	// printf("\n%i\n", number_of_char_2);
}
