# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryada <ryada@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 15:38:32 by ryada             #+#    #+#              #
#    Updated: 2025/03/08 17:29:26 by ryada            ###   ########.fr        #
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
MLX_DIR = mlx/

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L $(MLX_DIR) -lmlx -L /usr/lib -Imlx -lXext -lX11 -lm -lbsd


SRC_FILES = checker.c \
			enemy.c \
			key.c \
			main.c \
			map_error.c \
			map_load.c \
			map_read.c \
			map_util.c \
            $(GNL_DIR)get_next_line_utils.c \
			$(GNL_DIR)get_next_line.c\

# Convert source files to object files inside OBJ_DIR
OBJ_FILES = $(addprefix $(OBJ_DIR), $(notdir $(SRC_FILES:.c=.o)))

# Include directories
INCLUDE = -I $(INC_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I $(GNL_DIR) -I $(MLX_DIR)

# Library linking
LIBS = -L $(LIBFT_DIR) -lft -L $(PRINTF_DIR) -lftprintf -L $(MLX_DIR) -lmlx

define BANNER
	@echo "███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗        "       
	@echo "██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝        "       
	@echo "███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗       "       
	@echo "╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║       "       
	@echo "███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝       "       
	@echo "╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝        "       
	@echo "																			    "
	@echo "	██╗    ██╗██╗████████╗██╗  ██╗    ██╗   ██╗███████╗██╗     ██╗  ██╗ █████╗  "
	@echo "	██║    ██║██║╚══██╔══╝██║  ██║    ██║   ██║██╔════╝██║     ██║ ██╔╝██╔══██╗ "
	@echo "	██║ █╗ ██║██║   ██║   ███████║    ██║   ██║█████╗  ██║     █████╔╝ ███████║ "
	@echo "	██║███╗██║██║   ██║   ██╔══██║    ╚██╗ ██╔╝██╔══╝  ██║     ██╔═██╗ ██╔══██║ "
	@echo "	╚███╔███╔╝██║   ██║   ██║  ██║     ╚████╔╝ ███████╗███████╗██║  ██╗██║  ██║ "
	@echo "	╚══╝╚══╝ ╚═╝   ╚═╝   ╚═╝  ╚═╝      ╚═══╝  ╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝  "
	@echo "------------------------------------------------------------------------------"
	@echo "This is the game of my dog, Velka who loves to hunt poops during her walk..."
	@echo "------------------------------------------------------------------------------"

endef

# Rules
all: $(NAME)
	
	@echo "🚀 Compilation started..."
	@echo "📦 Building executable: $(NAME)"
	$(BANNER)

$(NAME): $(OBJ_FILES)
	@make -C $(LIBFT_DIR) --silent > /dev/null
	@make -C $(PRINTF_DIR) --silent > /dev/null
	@make -C $(MLX_DIR) --silent > /dev/null
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME) $(LIBS) $(MLX_FLAGS)
	@echo "✅ Compilation successful!"
	@echo "🎯 Run with: ./$(NAME)"

# Rule for compiling C files from src/
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	@echo "🔨 Compiling: $<"
	@$(CC) $(CFLAGS) -c $< -o $@ 

# Rule for compiling C files from gnl/
$(OBJ_DIR)%.o: $(GNL_DIR)%.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	@echo "🔨 Compiling: $<"
	@$(CC) $(CFLAGS) -c $< -o $@ 2> /dev/null

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

