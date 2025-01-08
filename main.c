/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:34:53 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/08 22:45:36 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libftprintf.h"

int main(void)
{
	int num;
	num = ft_printf("Hola %s", "mundo");
	ft_printf("\n%d\n", num);
	num = printf("Hola %s", "mundo");
	printf("\n%d\n", num);
}