/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:40:23 by ryada             #+#    #+#             */
/*   Updated: 2024/11/20 10:09:17 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_printf_char(va_list args);
int		ft_printf_str(va_list args);
int		ft_printf_int(va_list args);
int		ft_printf_ptr(va_list args);
int		ft_printf_unsigned(va_list args);
int		ft_printf_lowhex(va_list args);
int		ft_printf_uphex(va_list args);
int		ft_printf_percent(void);
int		ft_toupper(int c);

char	*ft_tohex(unsigned long num);
char	*ft_utoa(unsigned int num);
char	*ft_itoa(int n);

size_t	ft_strlen(const char *str);

#endif
