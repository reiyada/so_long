/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:29:30 by ryada             #+#    #+#             */
/*   Updated: 2025/03/17 11:28:48 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_set_map_dimentions(t_game *game)
{
	game->height = ft_count_height(game->map);
	game->width = ft_count_width(game->map);
}

void	ft_init_img(t_game *game)
{
	game->img.wall = NULL;
	game->img.player = NULL;
	game->img.collect_pink = NULL;
	game->img.collect_green = NULL;
	game->img.collect_yellow = NULL;
	game->img.collect_brown = NULL;
	game->img.exit = NULL;
	game->img.empty = NULL;
	game->img.enemy = NULL;
}

void	ft_exit(char c, t_game *game)
{
	if (c == 'P')
	{
		ft_printf("You lost! The enemy caught you!\n");
		ft_free_elements(game);
		exit(1);
	}
	else if (c == 'E')
	{
		if (!ft_check_element(game, 'C'))
		{
			ft_printf("You won!\n");
			ft_free_elements(game);
			exit(0);
		}
	}
}

void	ft_file_to_img(t_game *game, int img_size)
{
	game->img.wall = mlx_xpm_file_to_image(game->mlx,
			"./textures/1.xpm", &img_size, &img_size);
	game->img.player = mlx_xpm_file_to_image(game->mlx,
			"./textures/p_down.xpm", &img_size, &img_size);
	game->img.collect_pink = mlx_xpm_file_to_image(game->mlx,
			"./textures/c_0.xpm", &img_size, &img_size);
	game->img.collect_green = mlx_xpm_file_to_image(game->mlx,
			"./textures/c_1.xpm", &img_size, &img_size);
	game->img.collect_yellow = mlx_xpm_file_to_image(game->mlx,
			"./textures/c_2.xpm", &img_size, &img_size);
	game->img.collect_brown = mlx_xpm_file_to_image(game->mlx,
			"./textures/c_3.xpm", &img_size, &img_size);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"./textures/exit.xpm", &img_size, &img_size);
	game->img.empty = mlx_xpm_file_to_image(game->mlx,
			"./textures/0.xpm", &img_size, &img_size);
	game->img.enemy = mlx_xpm_file_to_image(game->mlx,
			"./textures/h_down.xpm", &img_size, &img_size);
}
