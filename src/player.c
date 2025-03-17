/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:43:02 by ryada             #+#    #+#             */
/*   Updated: 2025/03/17 14:02:51 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_dir(t_game *game, int x_move, int y_move)
{
	if (y_move == -1)
		ft_change_pose(game, 'P', 'U');
	else if (y_move == 1)
		ft_change_pose(game, 'P', 'D');
	else if (x_move == 1)
		ft_change_pose(game, 'P', 'R');
	else if (x_move == -1)
		ft_change_pose(game, 'P', 'L');
}

void	ft_move_player(t_game *game, int x_move, int y_move)
{
	int	new_x;
	int	new_y;

	new_x = game->player.column + x_move;
	new_y = game->player.row + y_move;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'E')
		ft_exit('E', game);
	if (game->map[new_y][new_x] == 'H')
		ft_exit('P', game);
	ft_move_dir(game, x_move, y_move);
	game->map[game->player.row][game->player.column] = '0';
	game->move_count++;
	if (ft_check_element(game, 'C') && !ft_check_element(game, 'E')
		&& game->map[game->exit.row][game->exit.column]
		!= game->map[game->enemy.row][game->enemy.column])
		game->map[game->exit.row][game->exit.column] = 'E';
	game->map[new_y][new_x] = 'P';
	ft_find_player_position(game);
	ft_draw_map(game);
	if (game->move_count % 2 == 0)
		ft_move_enemy(game);
}

void	ft_set_dir_player(t_game *game, int img_size, char direction)
{
	mlx_destroy_image(game->mlx, game->img.player);
	if (direction == 'U')
		game->img.player = mlx_xpm_file_to_image(game->mlx,
				"./textures/p_up.xpm", &img_size, &img_size);
	else if (direction == 'D')
		game->img.player = mlx_xpm_file_to_image(game->mlx,
				"./textures/p_down.xpm", &img_size, &img_size);
	else if (direction == 'R')
		game->img.player = mlx_xpm_file_to_image(game->mlx,
				"./textures/p_right.xpm", &img_size, &img_size);
	else if (direction == 'L')
		game->img.player = mlx_xpm_file_to_image(game->mlx,
				"./textures/p_left.xpm", &img_size, &img_size);
}

void	ft_set_dir_img(t_game *game, char who, int img_size, char direction)
{
	if (who == 'P')
		ft_set_dir_player(game, img_size, direction);
	else if (who == 'H')
		ft_set_dir_enemy(game, img_size, direction);
}

void	ft_change_pose(t_game *game, char who, char direction)
{
	int	img_size;

	img_size = TILE_SIZE;
	ft_set_dir_img(game, who, img_size, direction);
	if (!game->img.player || !game->img.enemy)
	{
		ft_putstr_fd("Error\nFailed to load images\n", 2);
		ft_free_elements(game);
		exit(1);
	}
}
