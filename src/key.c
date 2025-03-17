/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:33:23 by ryada             #+#    #+#             */
/*   Updated: 2025/03/17 10:44:14 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_handler(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == 65307)
		ft_close_game(game);
	else
	{
		if (key == 119)
			ft_move_player(game, 0, -1);
		else if (key == 115)
			ft_move_player(game, 0, 1);
		else if (key == 97)
			ft_move_player(game, -1, 0);
		else if (key == 100)
			ft_move_player(game, 1, 0);
	}
	return (0);
}
