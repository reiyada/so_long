/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:40:05 by ryada             #+#    #+#             */
/*   Updated: 2024/11/20 11:32:10 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_unsigned(va_list args)
{
	unsigned int	num;
	char			*result;
	int				len;

	num = va_arg(args, unsigned int);
	result = ft_utoa(num);
	len = 0;
	if (result)
	{
		while (result[len])
			len++;
		write (1, result, len);
		free (result);
	}
	return (len);
}

// int main(void)
// {
//     unsigned int num1 = 4294967295;
//     unsigned int num2 = 0;
//     unsigned int num3 = 12345;

//     pritnf("num1\n");
//     ft_printf("My ft_printf: %u\n", num1);
//     printf("Standard printf: %u\n", num1);

//     pritnf("num2\n");
//     ft_printf("My ft_printf: %u\n", num2);
//     printf("Standard printf: %u\n", num2);

//     pritnf("num3\n");
//     ft_printf("My ft_printf: %u\n", num3);
//     printf("Standard printf: %u\n", num3);

//     return 0;
// }