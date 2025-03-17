/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 09:45:01 by ryada             #+#    #+#             */
/*   Updated: 2025/03/17 11:12:09 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_load_images(t_game *game)
{
	int	img_size;

	img_size = TILE_SIZE;
	ft_file_to_img(game, img_size);
	if (!game->img.wall || !game->img.player || (!game->img.collect_pink
			&& !game->img.collect_green && !game->img.collect_yellow
			&& !game->img.collect_brown) || !game->img.empty
		|| !game->img.enemy || !game->img.exit)
	{
		ft_putstr_fd("[Error] Failed to load images\n", 2);
		ft_free_elements(game);
		exit(1);
	}
}

void	*ft_choose_collect(t_game *game, int x)
{
	void	*img;

	if (x % 4 == 0)
		img = game->img.collect_pink;
	else if (x % 4 == 1)
		img = game->img.collect_green;
	else if (x % 4 == 2)
		img = game->img.collect_yellow;
	else
		img = game->img.collect_brown;
	return (img);
}

void	ft_display_count(t_game *game)
{
	char	*move_text;

	move_text = ft_itoa(game->move_count);
	if (move_text)
	{
		mlx_string_put(game->mlx, game->win, 10, 10, 0xFF0000, "Moves: ");
		mlx_string_put(game->mlx, game->win, 80, 10, 0xFF0000, move_text);
		free(move_text);
	}
}

void	*ft_choose_img(t_game *game, int x, int y)
{
	void	*img;

	img = game->img.empty;
	if (game->map[y][x] == '1')
		img = game->img.wall;
	else if (game->map[y][x] == 'P')
		img = game->img.player;
	else if (game->map[y][x] == 'C')
		img = ft_choose_collect(game, x);
	else if (game->map[y][x] == 'E')
		img = game->img.exit;
	else if (game->map[y][x] == 'H')
		img = game->img.enemy;
	return (img);
}

void	ft_draw_map(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			img = ft_choose_img(game, x, y);
			mlx_put_image_to_window(game->mlx,
				game->win, img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	ft_display_count(game);
}
