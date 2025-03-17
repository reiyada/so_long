/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:30:31 by ryada             #+#    #+#             */
/*   Updated: 2025/03/17 13:58:36 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_element(t_game *game, char c)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == c)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	ft_check_char_count(t_game *game)
{
	int	c;
	int	e;
	int	p;
	int	h;

	c = ft_count_element(game, 'C');
	e = ft_count_element(game, 'E');
	p = ft_count_element(game, 'P');
	h = ft_count_element(game, 'H');
	if (!c || e != 1 || p != 1 || h > 1)
		return (0);
	return (1);
}

int	ft_check_file_name(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len >= 4 && ft_strncmp(filename + len - 4, ".ber", 4) == 0)
		return (1);
	return (0);
}

int	ft_check_size(t_game *game)
{
	if (game->height > 31 || game->width > 60)
		return (0);
	return (1);
}
