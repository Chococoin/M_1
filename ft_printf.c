#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define F_SPEC "csdixX" //pu

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

int	hex_length(int decimal)
{
	int	length;

	length = 0;
	while (decimal > 0)
	{
		decimal /= 16;
		length++;
	}
	return (length);
}

int	cal_current_power(int i)
{
	int current_power = 1;
	int j = 0;
	while (j < i)
	{
		current_power *= 16;
		j++;
	}
	return current_power;
}

char	get_hex_digit(int digit, char f)
{
	if (digit < 10)
		return '0' + digit;
	else if (f == 'X')
		return 'A' + (digit - 10);
	else
		return 'a' + (digit - 10);
}

int	dec_to_hex(int decimal, char f)
{
	int		len;
	char	 *hexadecimal;
	int		i;
	int		current_power;
	int		digit;

	len = hex_length(decimal);
	hexadecimal = malloc(sizeof(char) * (len + 1));
	hexadecimal[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		current_power = cal_current_power(i);
		digit = decimal / current_power;
		decimal -= digit * current_power;
		hexadecimal[len - 1 - i] = get_hex_digit(digit, f);
		i--;
	}
	ft_putstr(hexadecimal);
	free(hexadecimal);
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
		return (ft_putstr(va_arg(*args, char *)));
	else if (format[1] == 'd' || format[1] == 'i')
		return (ft_putnum(va_arg(*args, int)));
	else if (format[1] == 'x' || format[1] == 'X')
		return (dec_to_hex(va_arg(*args, int), format[1]));
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
	ft_printf("Hexadecimal edge cases:\n");
	ft_printf("0x%x\n", 0);
	printf("0x%x\n", 0);
	ft_printf("0x%x\n", 1);
	printf("0x%x\n", 1);
	ft_printf("0x%x\n", 15);
	printf("0x%x\n", 15);
	ft_printf("0x%x\n", 16);
	printf("0x%x\n", 16);
	ft_printf("0x%x\n", 255);
	printf("0x%x\n", 255);
	ft_printf("0x%x\n", 256);
	printf("0x%x\n", 256);
	ft_printf("0x%x\n", 4095);
	printf("0x%x\n", 4095);
	ft_printf("0x%x\n", 4096);
	printf("0x%x\n", 4096);
	ft_printf("0x%x\n", 65535);
	printf("0x%x\n", 65535);
	ft_printf("0x%x\n", 65536);
	printf("0x%x\n", 65536);
	ft_printf("0x%x\n", -1);
	printf("0x%x\n", -1);
	ft_printf("0x%X\n", 0);
	printf("0x%X\n", 0);
	ft_printf("0x%X\n", 1);
	printf("0x%X\n", 1);
	ft_printf("0x%X\n", 15);
	printf("0x%X\n", 15);
	ft_printf("0x%X\n", 16);
	printf("0x%X\n", 16);
	ft_printf("0x%X\n", 255);
	printf("0x%X\n", 255);
	ft_printf("0x%X\n", 256);
	printf("0x%X\n", 256);
	ft_printf("0x%X\n", 4095);
	printf("0x%X\n", 4095);
	ft_printf("0x%X\n", 4096);
	printf("0x%X\n", 4096);
	ft_printf("0x%X\n", 65535);
	printf("0x%X\n", 65535);
	ft_printf("0x%X\n", 65536);
	printf("0x%X\n", 65536);
	ft_printf("0x%X\n", -1);
	printf("0x%X\n", -1);
}
