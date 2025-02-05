/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:40:30 by ryada             #+#    #+#             */
/*   Updated: 2024/11/20 11:32:50 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_utoa(unsigned int num)
{
	char			*result;
	unsigned int	temp;
	int				len;

	temp = num;
	len = 1;
	while (temp > 9)
	{
		temp /= 10;
		len++;
	}
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}
