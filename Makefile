# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryada <ryada@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 15:38:32 by ryada             #+#    #+#              #
#    Updated: 2025/02/07 17:04:05 by ryada            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
RM = rm -f

INC_DIR = includes/
SRC_DIR = src/
OBJ_DIR = objects/
GNL_DIR = gnl/
LIBFT_DIR = Libft/
PRINTF_DIR = ft_printf/
MLX_DIR = minilibx-linux/

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L $(MLX_DIR) -lmlx -L /usr/lib -lXext -lX11 -lm -lbsd


SRC_FILES = main.c \
			map_error.c \
			map_read.c \
			map_util.c \
            $(GNL_DIR)get_next_line_utils.c \
			$(GNL_DIR)get_next_line.c\

# Convert source files to object files inside OBJ_DIR
OBJ_FILES = $(addprefix $(OBJ_DIR), $(notdir $(SRC_FILES:.c=.o)))

# Include directories
INCLUDE = -I $(INC_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I $(GNL_DIR) -I $(MLX_DIR)

# Library linking
LIBS = -L $(LIBFT_DIR) -lft -L $(PRINTF_DIR) -lftprintf -L $(MLX_DIR)

# Rules
all: $(NAME)
	@echo "🚀 Compilation started..."
	@echo "📦 Building executable: $(NAME)"
	@echo "-----------------------------------"

$(NAME): $(OBJ_FILES)
	@make -C $(LIBFT_DIR) --silent
	@make -C $(PRINTF_DIR) --silent
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(MLX_DIR) -o $(NAME) $(LIBS)
	@echo "✅ Compilation successful!"
	@echo "🎯 Run with: ./$(NAME)"

# Rule for compiling C files from src/
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "🔨 Compiling: $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# Rule for compiling C files from gnl/
$(OBJ_DIR)%.o: $(GNL_DIR)%.c | $(OBJ_DIR)
	@echo "🔨 Compiling: $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# Ensure OBJ_DIR exists before compiling
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_FILES) 
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR) --silent
	@make clean -C $(PRINTF_DIR) --silent
	@echo "🧹 Cleaned object files of $(NAME)!"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR) --silent
	@make fclean -C $(PRINTF_DIR) --silent
	@echo "🗑️  Removed executable and object files of $(NAME)!"

re: fclean all
	@echo "🔄 Recompiling the project..."

