# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryada <ryada@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 08:40:34 by ryada             #+#    #+#              #
#    Updated: 2025/02/03 15:50:37 by ryada            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# Directories
SRCS_DIR = srcs
HELPERS_DIR = helpers
INCLUDES_DIR = includes
LIBFT_DIR = libft

# Sources
SRCS = $(addprefix $(SRCS_DIR)/,\
		ft_printf.c\
		ft_printf_char.c\
		ft_printf_int.c\
		ft_printf_str.c\
		ft_printf_ptr.c\
		ft_printf_unsigned.c\
		ft_printf_lowhex.c\
		ft_printf_uphex.c\
		ft_printf_percent.c)

HELPERS = $(addprefix $(HELPERS_DIR)/,\
		ft_tohex.c\
		ft_utoa.c)

LIBFT = $(addprefix $(LIBFT_DIR)/,\
		ft_itoa.c\
		ft_strlen.c\
		ft_toupper.c)

OBJS = $(SRCS:.c=.o) $(HELPERS:.c=.o) $(LIBFT:.c=.o)

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Rules
all: $(NAME)
	@echo "✅ ft_printf compiled successfully."

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "📦 Archive created: $(NAME)"

# Compile libft
$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Compile helpers
$(HELPERS_DIR)/%.o: $(HELPERS_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Compile sources
$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "🧹 Cleaned object files of $(NAME)!"

fclean: clean
	@rm -f $(NAME)
	@echo "🗑️ Removed executable and object files of $(NAME)!"

re: fclean all

.PHONY: all clean fclean re


