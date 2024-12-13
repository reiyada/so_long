# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Project Name
NAME = so_long

# Directories
INCDIR = includes
SRCDIR = sources
OBJDIR = objects
GNLDIR = $(SRCDIR)/gnl
LIBFTDIR = $(SRCDIR)/Libft
MINILIBXDIR = minilibx-linux

# Source Files
SRCS = $(wildcard $(SRCDIR)/*.c) \
		$(wildcard $(GNLDIR)/*.c) \
		test.c
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS)) 

# Includes and Libraries
INCLUDES = -I$(INCDIR) -I$(MINILIBXDIR)
LIBS = -L$(MINILIBXDIR) -lmlx -lXext -lX11

# Rules
all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	$(MAKE) -C $(MINILIBXDIR)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR) $(OBJDIR)/gnl

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/gnl/%.o: $(GNLDIR)/%.c | $(OBJDIR)
	mkdir -p $(OBJDIR)/gnl
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(MINILIBXDIR) clean
	$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
