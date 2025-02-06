/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:29:48 by ryada             #+#    #+#             */
/*   Updated: 2025/02/06 15:29:08 by rei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_printf("Usage: %s <map.ber>\n", argv[0]);
        return 1;
    }
    ft_parse_map(argv[1]);
    ft_printf("Map is valid!\n");
    return 0;
}