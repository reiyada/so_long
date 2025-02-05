/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:39:34 by ryada             #+#    #+#             */
/*   Updated: 2024/11/20 11:31:45 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//the return value of printf is int; the number of charactors you print
// va_list: The magic box to hold extra arguments.
// va_start: Opens the box and gets ready to pick arguments.
// va_arg: Grabs the next argument (toy) from the box.
// va_end: Closes the box when done.

int	ft_printf_char(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (write(1, &c, 1));
}
