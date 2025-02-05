/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uphex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:40:08 by ryada             #+#    #+#             */
/*   Updated: 2024/11/20 11:32:14 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_uphex(va_list args)
{
	unsigned int	num;
	char			*str;
	int				len;
	int				i;

	num = va_arg(args, unsigned int);
	str = ft_tohex((unsigned long)num);
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	len = 0;
	while (str[len])
		len++;
	write (1, str, len);
	free (str);
	return (len);
}
// int main()
// {
//     unsigned int num1 = 255;
//     unsigned int num2 = 4095; 
//     unsigned int num3 = 0;

//     printf("num1\n");
//     ft_printf("My ft_printf: %X\n", num1);
//     printf("Original printf: %X\n", num1);

//     printf("num2\n");
//     ft_printf("My ft_printf: %X\n", num2);
//     printf("Original printf: %X\n", num2);

//     printf("num3\n");
//     ft_printf("My ft_printf: %X\n", num3);
//     printf("Original printf: %X\n", num3);

//     return 0;
// }
