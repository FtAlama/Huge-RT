# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alama <alama@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/09 16:39:48 by alama             #+#    #+#              #
#    Updated: 2025/04/20 16:30:31 by alama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCDIR = src
OBJDIR = .build


MLXDIR = minilibx-linux
MLX_NAME = libmlx_linux.a
MFLAGS = -L$(MLXDIR) -lmlx -lXext -lX11 -lm 

SRC_MAIN = $(SRCDIR)/main.c
SRC_MATH = $(SRCDIR)/math/operation_tuple.c \
	   $(SRCDIR)/math/tuple.c \
	   $(SRCDIR)/math/ft_math.c

SRC = $(SRC_MAIN) $(SRC_MATH)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) | $(OBJDIR)
	@make -C ./minilibx-linux 2> /dev/null 1>/dev/null
	@$(CC) $(CFLAGS) $(OBJ) $(MFLAGS) -o $(NAME) -I./includes -I/$(MLXDIR)
	@echo "$(NAME) compiled successfully!"

$(OBJDIR):
	@mkdir -p $(OBJDIR)/math

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I./includes 
	@echo "Compiled $(notdir $<)"

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)
	@rm -rf *dSYM*

re: fclean all

.PHONY: all fclean clean re
