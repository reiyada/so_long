/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:29:48 by ryada             #+#    #+#             */
/*   Updated: 2025/02/07 17:19:50 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
    char **map;
    int height;
    int width;

    if (argc != 2)
        return (ft_putstr_fd("Error\n", 2), 1);
    map = ft_store_map(argv[1]);
    if (!map)
        return (ft_putstr_fd("Error\n", 2), 1);
    height = ft_count_height(map);
    width = ft_count_width(map);
    if (ft_is_valid_map(map, height, width))
        return (ft_printf("Map is valid!\n"), 0);
    else
        return (ft_putstr_fd("Error\n", 2), 1);
}