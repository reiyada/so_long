/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:39:51 by ryada             #+#    #+#             */
/*   Updated: 2024/11/20 11:32:02 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_ptr(va_list args)
{
	void			*ptr;
	unsigned long	address;
	char			*hex;
	int				len;

	ptr = va_arg(args, void *);
	address = (unsigned long)ptr;
	len = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	hex = ft_tohex(address);
	if (!hex)
		return (0);
	len += write (1, "0x", 2);
	len += write(1, hex, ft_strlen(hex));
	free(hex);
	return (len);
}

// int main()
// {
//     char *c;
//     ft_printf("My ft_printf: %p\n", c);
//     printf("Original printf: %p\n", c);

//     c = NULL;
//     ft_printf("My ft_printf: %p\n", c);
//     printf("Original printf: %p\n", c);

//     return (0);
// }
