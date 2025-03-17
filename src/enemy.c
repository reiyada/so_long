/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:56:29 by ryada             #+#    #+#             */
/*   Updated: 2025/03/17 14:01:54 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_set_dir_enemy(t_game *game, int img_size, char direction)
{
	mlx_destroy_image(game->mlx, game->img.enemy);
	if (direction == 'U')
		game->img.enemy = mlx_xpm_file_to_image(game->mlx,
				"./textures/h_up.xpm", &img_size, &img_size);
	else if (direction == 'D')
		game->img.enemy = mlx_xpm_file_to_image(game->mlx,
				"./textures/h_down.xpm", &img_size, &img_size);
	else if (direction == 'R')
		game->img.enemy = mlx_xpm_file_to_image(game->mlx,
				"./textures/h_right.xpm", &img_size, &img_size);
	else if (direction == 'L')
		game->img.enemy = mlx_xpm_file_to_image(game->mlx,
				"./textures/h_left.xpm", &img_size, &img_size);
}

t_dis	ft_set_distanc(t_game *game)
{
	t_dis	d;

	d.x = 1;
	d.y = 1;
	if (game->player.column > game->enemy.column)
		d.x = 1;
	else if (game->enemy.column > game->player.column)
		d.x = -1;
	if (game->player.row > game->enemy.row)
		d.y = 1;
	else if (game->enemy.row > game->player.row)
		d.y = -1;
	return (d);
}

void	ft_move_holiz(t_game *game, t_dis d, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'P')
		ft_exit('P', game);
	if (d.x == 1)
		ft_change_pose(game, 'H', 'R');
	else if (d.x == -1)
		ft_change_pose(game, 'H', 'L');
	game->map[game->enemy.row][game->enemy.column] = '0';
	if (!ft_check_element(game, 'E'))
		game->map[game->exit.row][game->exit.column] = 'E';
	game->map[new_y][new_x] = 'H';
	ft_find_enemy_position(game);
}

void	ft_move_virt(t_game *game, t_dis d, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'C')
	{
		if (d.y == 1)
			ft_change_pose(game, 'H', 'D');
		else if (d.y == -1)
			ft_change_pose(game, 'H', 'U');
		game->map[game->enemy.row][game->enemy.column] = '0';
		if (!ft_check_element(game, 'E'))
			game->map[game->exit.row][game->exit.column] = 'E';
		game->map[new_y][new_x] = 'H';
		ft_find_enemy_position(game);
		if (game->map[new_y][new_x] == 'P')
			ft_exit('P', game);
	}
}

void	ft_move_enemy(t_game *game)
{
	t_dis	d;
	int		new_x;
	int		new_y;

	d = ft_set_distanc(game);
	new_x = game->enemy.column + d.x;
	new_y = game->enemy.row;
	if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'C')
		ft_move_holiz(game, d, new_x, new_y);
	else
	{
		new_x = game->enemy.column;
		new_y = game->enemy.row + d.y;
		ft_move_virt(game, d, new_x, new_y);
	}
	ft_draw_map(game);
}
