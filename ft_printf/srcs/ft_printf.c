/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:40:15 by ryada             #+#    #+#             */
/*   Updated: 2024/11/20 11:32:19 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_by_type(char c, va_list args)
{
	if (c == 'd' || c == 'i')
		return (ft_printf_int(args));
	else if (c == 'c')
		return (ft_printf_char(args));
	else if (c == 's')
		return (ft_printf_str(args));
	else if (c == 'p')
		return (ft_printf_ptr(args));
	else if (c == 'u')
		return (ft_printf_unsigned(args));
	else if (c == 'x')
		return (ft_printf_lowhex(args));
	else if (c == 'X')
		return (ft_printf_uphex(args));
	else if (c == '%')
		return (ft_printf_percent());
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_chars;
	int		i;

	printed_chars = 0;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			printed_chars += ft_print_by_type(format[i], args);
		}
		else
			printed_chars += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (printed_chars);
}
