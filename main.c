/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:34:53 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/13 19:23:52 by glugo-mu         ###   ########.fr       */
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
    num_char = printf("%i", INT_MAX);
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

    num_char = ft_printf("%%");
    printf("\nNumber of characters printed: %d\n", num_char);
    num_char = printf("%%");
    printf("\nNumber of characters printed: %d\n", num_char);

	num_char = ft_printf("%");
    printf("\nNumber of characters printed: %d\n", num_char);
    num_char = printf("%");
    printf("\nNumber of characters printed: %d\n", num_char); 

    // Case 1: Pasar un puntero nulo a %s
    char *str1 = NULL;
    printf("Case 1: %s\n", str1); // Imprime "(null)"
    ft_printf("Case 1: %s\n", str1);

    // Case 2: Usar %p con un puntero nulo
    void *ptr1 = NULL;
    char *str1 = NULL;
    printf("Case 2: %p\n", ptr1); // Imprime "(nil)" en algunas implementaciones
    ft_printf("Case 2: %p\n", ptr1);

    // Case 3: Array de cadenas mal inicializado
    char *strings[3] = { "Hello", NULL, "World" };
    printf("Case 3: %s\n", strings[1]); // Imprime "(null)"
    ft_printf("Case 3: %s\n", strings[1]);

    // Case 4: Formato incorrecto con punteros genéricos
    void *ptr2 = NULL;
    printf("Case 4: %s\n", (char *)ptr2); // Imprime "(null)"
    ft_printf("Case 4: %s\n", (char *)ptr2);

    // Case 5: String literal vacío combinado con puntero nulo
    printf("Case 5 cadena vacía: %s\n", str1); // Imprime cadena vacía ""
    ft_printf("Case 5 cadena vacía: %s\n", str1);

    // Case 6: Cadenas nulas dentro de estructuras
    struct example {
        char *name;
    };
    struct example ex = { NULL };
    printf("Case 6: %s\n", ex.name); // Imprime "(null)"
    ft_printf("Case 6: %s\n", ex.name); // Imprime "(null)"

    // Case 7: Address of un puntero válido
    int a = 42;
    int *ptr3 = &a;
    printf("Case 7: Address of ptr3 -> %p\n", (void *)ptr3); // Address of 'a'
    ft_printf("Case 7: Address of ptr3 -> %p\n", (void *)ptr3);

    // Case 8: Address of un puntero NULL
    int *ptr4 = NULL;
    printf("Case 8: Address of ptr4 (NULL) -> %p\n", (void *)ptr4); // Imprime "(nil)" en algunas implementaciones
    ft_printf("Case 8: Address of ptr4 (NULL) -> %p\n", (void *)ptr4); // Imprime "(nil)" en algunas implementaciones

    // Case 9: Address of a pointer to a puntero
    void **ptr5 = &ptr1;
    printf("Case 9: Address of ptr5 -> %p\n", (void *)ptr5); // Address of 'ptr1'
    ft_printf("Case 9: Address of ptr5 -> %p\n", (void *)ptr5);

    // Case 10: Address of una variable of tipo void *
    void *ptr6 = &a;
    printf("Case 10: Address of ptr6 -> %p\n", ptr6); // Address of 'a'
    ft_printf("Case 10: Address of ptr6 -> %p\n", ptr6);

    // Case 11: Address of an array
    int array[5] = {1, 2, 3, 4, 5};
    printf("Case 11: Address of array -> %p\n", (void *)array); // Address of primer elemento of array
    ft_printf("Case 11: Address of array -> %p\n", (void *)array);

    // Case 12: Address of an element into an array
    printf("Case 12: Address of array[2] -> %p\n", (void *)&array[2]); // Address of tercer elemento of array
    ft_printf("Case 12: Address of array[2] -> %p\n", (void *)&array[2]);

    // Case 13: Address of una estructura
    struct example2 {
        int id;
        char name[20];
    };
    struct example2 ex2 = {1, "Example"};
    printf("Case 13: Address of structure ex2 -> %p\n", (void *)&ex2);
    ft_printf("Case 13: Address of structure ex2 -> %p\n", (void *)&ex2);

    // Case 14: Address of un miembro of una estructura
    printf("Case 14: Address of ex2.id -> %p\n", (void *)&ex2.id);
    ft_printf("Case 14: Address of ex2.id -> %p\n", (void *)&ex2.id);
    printf("Case 15: Address of ex2.name -> %p\n", (void *)ex2.name);
    ft_printf("Case 15: Address of ex2.name -> %p\n", (void *)ex2.name);

    // Case 16: Address of un puntero global
    static int static_var = 100;
    printf("Case 16: Address of static_var -> %p\n", (void *)&static_var);
    ft_printf("Case 16: Address of static_var -> %p\n", (void *)&static_var);

    // Case 17: Address of una variable local
    int local_var = 99;
    printf("Case 17: Address of local_var -> %p\n", (void *)&local_var);
    ft_printf("Case 17: Address of local_var -> %p\n", (void *)&local_var);

    return (0);
}
