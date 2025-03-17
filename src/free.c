/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:29:30 by ryada             #+#    #+#             */
/*   Updated: 2025/03/17 11:05:21 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_img(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.collect_pink)
		mlx_destroy_image(game->mlx, game->img.collect_pink);
	if (game->img.collect_green)
		mlx_destroy_image(game->mlx, game->img.collect_green);
	if (game->img.collect_yellow)
		mlx_destroy_image(game->mlx, game->img.collect_yellow);
	if (game->img.collect_brown)
		mlx_destroy_image(game->mlx, game->img.collect_brown);
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->img.empty)
		mlx_destroy_image(game->mlx, game->img.empty);
	if (game->img.enemy)
		mlx_destroy_image(game->mlx, game->img.enemy);
}

void	ft_free_map(char **map)
{
	int	y;

	if (!map)
		return ;
	y = 0;
	while (map[y])
	{
		if (map[y])
			free(map[y]);
		y++;
	}
	free(map);
}

void	ft_free_game(t_game *game)
{
	if (!game)
		return ;
	if (!game->win || !game->mlx)
		return ;
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	ft_free_elements(t_game *game)
{
	if (!game)
		return ;
	ft_free_img(game);
	ft_free_game(game);
	ft_free_map(game->map);
}
