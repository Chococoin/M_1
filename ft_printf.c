#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h> // malloc, free

#define F_SPEC "csdip" //uxX"

static int	ft_get_num_length(long n)
{
	int		length;
	long	m;

	length = 0;
	m = n;
	if (n < 0)
		m = -m;
	while (m >= 1)
	{
		m /= 10;
		length++;
	}
	return (length);
}

static void	ft_freemem(char *bffr, int j)
{
	while (j + 1 > 0)
		free((void *)&bffr[j--]);
}

static void	ft_fill_chars(char *character, long n, int length)
{
	int	i;

	i = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		character[0] = '0';
	while (i < length && n > 0)
	{
		character[length -1 - i] = (n % 10) + '0';
		i++;
		n /= 10;
	}
	character[length] = '\0';
}

char	*ft_itoa(int n)
{
	int		length;
	char	*character;
	int		is_negative;
	long	nbr;

	nbr = n;
	length = ft_get_num_length(nbr);
	is_negative = (nbr < 0);
	if (is_negative)
		length++;
	if (nbr == 0)
		length = 1;
	character = (char *)malloc(sizeof(char) * (length + 1));
	if (!character)
	{
		ft_freemem(character, length);
		return (NULL);
	}
	ft_fill_chars(character, nbr, length);
	if (is_negative)
		character[0] = '-';
	return (character);
}


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

int	ft_putnum(int num)
{
	int	len;
	int	n;

	n = num;
	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	write(1, ft_itoa(num), len);
	return (len);
}

int	f_selector(va_list *args, const char *format)
{
	char	*s;

 	if (format[1] == 'c')
	{
		s = malloc(sizeof(int));
		s[0] = (char)va_arg(*args, int);
		return (ft_putchar(&s[0]));
	} 
	else if (format[1] == 's')
	{
		s = va_arg(*args, char *);
		return (ft_putstr(s));
	}
	else if (format[1] == 'd' || format[1] == 'i')
	{
		return (ft_putnum(va_arg(*args, int)));
	}
	else
		s = NULL;
	free(s);
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
	// int	number_of_char;
	// int	number_of_char_2;

	// number_of_char = ft_printf("Hola%c %s %d %i", '!', "mundo", 42, 100000);
	// printf("\n%i\n", number_of_char);
	// number_of_char = ft_printf("El número máximo para un int es: %d", 2147483647);
	// printf("\n%i\n", number_of_char);
	// number_of_char = 
	ft_printf("Número mínimo para un int es: %d", -2147483647);
	// printf("El número mínimo para un int es: %d", -2147483647);
	// printf("\n%i\n", number_of_char);
	// number_of_char_2 = printf("Hola%c%", '!');
	// printf("\n%i\n", number_of_char_2);
}
