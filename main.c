/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:34:53 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/09 19:02:49 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libftprintf.h"

int main(void)
{
	int num_char;
	num_char = ft_printf("%c", 'A');
	printf("\nNumber of characters printed: %d\n", num_char);
	num_char = printf("%c", 'A');
	printf("\nNumber of characters printed: %d\n", num_char);

	num_char = ft_printf("%s", "This is a string");
	printf("\nNumber of characters printed: %d\n", num_char);
	num_char = printf("%s", "This is a string");
	printf("\nNumber of characters printed: %d\n", num_char);

	num_char = ft_printf("%d", 42);
	printf("\nNumber of characters printed: %d\n", num_char);
	num_char = printf("%d", 42);
	printf("\nNumber of characters printed: %d\n", num_char);

	num_char = ft_printf("%i", -42);
	printf("\nNumber of characters printed: %d\n", num_char);
	num_char = printf("%i", -42);
	printf("\nNumber of characters printed: %d\n", num_char);

	num_char = ft_printf("%d", INT_MAX);
	printf("\nNumber of characters printed: %d\n", num_char);
	num_char = printf("%d", INT_MAX);
	printf("\nNumber of characters printed: %d\n", num_char);

	num_char = ft_printf("%d", INT_MIN);
	printf("\nNumber of characters printed: %d\n", num_char);
	num_char = printf("%d", INT_MIN);
	printf("\nNumber of characters printed: %d\n", num_char);

	num_char = ft_printf("%i", -42);
	printf("\nNumber of characters printed: %d\n", num_char);
	num_char = printf("%i", -42);
	printf("\nNumber of characters printed: %d\n", num_char);

	num_char = ft_printf("%i", INT_MAX);
	printf("\nNumber of characters printed: %d\n", num_char);
	num_char = ft_printf("%i", INT_MAX);
	printf("\nNumber of characters printed: %d\n", num_char);

	num_char = ft_printf("%i", INT_MIN);
	printf("\nNumber of characters printed: %d\n", num_char);
	num_char = printf("%i", INT_MIN);
	printf("\nNumber of characters printed: %d\n", num_char);
}
