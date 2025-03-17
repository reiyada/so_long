/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:29:30 by ryada             #+#    #+#             */
/*   Updated: 2025/03/17 11:03:38 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_pos	ft_find_position(char **map, char find)
{
	t_pos	position;
	int		x;
	int		y;

	position.column = 0;
	position.row = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == find)
			{
				position.column = x;
				position.row = y;
				return (position);
			}
			x++;
		}
		y++;
	}
	return (position);
}

void	ft_find_player_position(t_game *game)
{
	game->player = ft_find_position(game->map, 'P');
}

void	ft_find_enemy_position(t_game *game)
{
	game->enemy = ft_find_position(game->map, 'H');
}

void	ft_find_exit_position(t_game *game)
{
	game->exit = ft_find_position(game->map, 'E');
}
