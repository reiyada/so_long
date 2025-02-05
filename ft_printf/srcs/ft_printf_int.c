/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:39:41 by ryada             #+#    #+#             */
/*   Updated: 2024/11/20 11:31:50 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//the return value of printf is int; the number of charactors you print
// va_list: The magic box to hold extra arguments.
// va_start: Opens the box and gets ready to pick arguments.
// va_arg: Grabs the next argument (toy) from the box.
// va_end: Closes the box when done.

int	ft_printf_int(va_list args)
{
	int		num;
	char	*result;
	int		len;

	num = va_arg(args, int);
	result = ft_itoa(num);
	if (!result)
		return (0);
	len = 0;
	while (result[len])
		len++;
	write(1, result, len);
	free(result);
	return (len);
}

// int main()
// {
//     ft_printf("My ft_printf: %d\n", 12345);
//     printf("Original printf: %d\n", 12345);

//     ft_printf("My ft_printf: %d\n", -6789);
//     printf("Original printf: %d\n", -6789);

//     ft_printf("My ft_printf: %d\n", 0);
//     printf("Original printf: %d\n", 0);

//     return (0);
// }
