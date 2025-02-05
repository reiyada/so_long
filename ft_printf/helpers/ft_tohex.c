/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:40:26 by ryada             #+#    #+#             */
/*   Updated: 2024/11/20 11:32:56 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_tohex(unsigned long num)
{
	char			*hex;
	char			*digits;
	unsigned long	temp;
	int				len;

	digits = "0123456789abcdef";
	temp = num;
	len = 1;
	while (temp > 15)
	{
		temp /= 16;
		len++;
	}
	hex = (char *)malloc(len + 1);
	if (!hex)
		return (NULL);
	hex[len] = '\0';
	while (len-- > 0)
	{
		hex[len] = digits[num % 16];
		num /= 16;
	}
	return (hex);
}
