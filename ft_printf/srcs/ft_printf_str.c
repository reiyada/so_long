/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:39:59 by ryada             #+#    #+#             */
/*   Updated: 2024/11/20 11:32:06 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//the return value of printf is int; the number of charactors you print
// va_list: The magic box to hold extra arguments.
// va_start: Opens the box and gets ready to pick arguments.
// va_arg: Grabs the next argument (toy) from the box.
// va_end: Closes the box when done.

int	ft_printf_str(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = 0;
	while (str[len])
		len++;
	return (write (1, str, len));
}

// int main()
// {
//     ft_printf("My ft_printf_str:%s\n", "Hello, World!");
//     printf("Original printf: %s\n", "Hello, World!");

//     ft_printf("My ft_printf_str: %s\n", "");
//     printf("Original printf: %s\n", "");

//     ft_printf("My ft_printf_str: %p\n", NULL);
//     printf("Original printf: %p\n", NULL);
//     return 0;
// }