/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:28:46 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/13 21:01:09 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	printf_error(void)
{
	const char	*error_message;

	error_message = "\033[31m*.c: error: spurious trailing ‘%’ in format "
		"[-Werror=format=]\033[0m\n"
		"   ** |  printf(\"%\");\n"
		"      |          ^\n"
		"\033[31mcc1: all warnings being treated as errors\033[0m\n";
	write(2, error_message, 167);
	return (167);
}
