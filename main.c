/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:34:53 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/09 15:47:43 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libftprintf.h"

int main(void)
{
	int num = 1;
	int num2;
	// num = ft_printf("Hola %s", "mundo");
	// ft_printf("\n%d\n", num);
	// num = printf("Hola %s", "mundo");
	
	num2 = ft_printf("%u", -255555);
	ft_printf("%d\n", num2);
	num2 = printf("%u\n", -255555);
	printf("%d\n", num2);
	printf("%d\n", num);
	printf("%d\n", num);
	printf("%d\n", num);
}
