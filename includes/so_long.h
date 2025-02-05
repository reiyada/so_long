/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:10:09 by ryada             #+#    #+#             */
/*   Updated: 2025/02/05 15:57:08 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../Libft/libft.h"
#include "../gnl/get_next_line.h"
#include "../ft_printf/includes/ft_printf.h"

void ft_validate_map_line(char *line, int line_number, int expected_width);
void ft_parse_map(const char *filename);



#endif