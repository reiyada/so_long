/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:39:47 by ryada             #+#    #+#             */
/*   Updated: 2024/11/20 11:31:59 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_percent(void)
{
	write (1, "%", 1);
	return (1);
}

// int main()
// {
//     ft_printf("My ft_printf: %% %% %%\n");
//     printf("Original printf: %% %% %%\n");

//     return 0;
// }