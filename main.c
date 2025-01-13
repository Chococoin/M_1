/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:34:53 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/13 14:36:18 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libftprintf.h"

int main(void)
{
	int num_char;
	/* num_char = ft_printf("%c", 'A');
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

	num_char = ft_printf("%d", INT_MAX);
	printf("\nNumber of characters printed: %d\n", num_char);
	num_char = printf("%d", INT_MAX);
	printf("\nNumber of characters printed: %d\n", num_char);
	
	printf("\nPrint INT_MIN\n");
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

	num_char = ft_printf("%u", 255);
	printf("\nNumber of characters printed: %d\n", num_char);
	num_char = printf("%u", 255);
	printf("\nNumber of characters printed: %d\n", num_char);

	num_char = ft_printf("%u", -255);
	printf("\nNumber of characters printed: %d\n", num_char);
	num_char = printf("%u", -255);
	printf("\nNumber of characters printed: %d\n", num_char);

	num_char = ft_printf("%x", 255);
	printf("\nNumber of characters printed: %d\n", num_char);
	num_char = printf("%x", 255);
	printf("\nNumber of characters printed: %d\n", num_char); 

	num_char = ft_printf("%x", -255);
	printf("\nNumber of characters printed: %d\n", num_char);
	num_char = printf("%x", -255);
	printf("\nNumber of characters printed: %d\n", num_char);

	num_char = ft_printf("%X", 43981);
	printf("\nNumber of characters printed: %d\n", num_char);
	num_char = printf("%X", 43981);
	printf("\nNumber of characters printed: %d\n", num_char);

	num_char = ft_printf("%X", -255);
	printf("\nNumber of characters printed: %d\n", num_char);
	num_char = printf("%X", -255);
	printf("\nNumber of characters printed: %d\n", num_char);

	num_char = ft_printf("%");
	printf("\nNumber of characters printed: %d\n", num_char);
	num_char = printf("%%");
	printf("\nNumber of characters printed: %d\n", num_char); */

    // Caso 1: Pasar un puntero nulo a %s
    /*char *str1 = NULL;
    printf("Caso 1: %s\n", str1); // Imprime "(null)"
    ft_printf("Caso 1: %s\n", str1);

    // Caso 2: Usar %p con un puntero nulo
    void *ptr1 = NULL;
    printf("Caso 2: %p\n", ptr1); // Imprime "(nil)" en algunas implementaciones
    ft_printf("Caso 2: %p\n", ptr1);

    // Caso 4: Array de cadenas mal inicializado
    char *strings[3] = { "Hello", NULL, "World" };
    printf("Caso 4: %s\n", strings[1]); // Imprime "(null)"
    ft_printf("Caso 4: %s\n", strings[1]);

    // Caso 5: Formato incorrecto con punteros genéricos
    void *ptr2 = NULL;
    printf("Caso 5: %s\n", (char *)ptr2); // Imprime "(null)"
    ft_printf("Caso 5: %s\n", (char *)ptr2);

    // Caso 6: String literal vacío combinado con puntero nulo
    printf("Caso 6 (cadena vacía): %s\n", str1 ?: ""); // Imprime cadena vacía ""
    ft_printf("Caso 6 (literal '(nil)'): %s\n", str1 ?: "(nil)");

    // Caso 7: Cadenas nulas dentro de estructuras
    struct example {
        char *name;
    };
    struct example ex = { NULL };
    printf("Caso 7: %s\n", ex.name); // Imprime "(null)"

    return (0);*/
}
