/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:47:30 by ryada             #+#    #+#             */
/*   Updated: 2024/11/20 11:32:39 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

// int main(int argc, char **argv)
// {
//     int i;
//     if (argc == 2)
//     {
//         i = 0;
//         char result[20];
//         while (argv[1][i] != '\0')
//         {
//             result[i] = ft_toupper(argv[1][i]);
//             i++;
//         }
//         result[i] = '\0';
//         printf("%s", result);
//     }
//     printf("\n");
//     return (0);
// }