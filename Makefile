# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/09 16:59:31 by hbutt             #+#    #+#              #
#    Updated: 2024/08/21 12:46:26 by hbutt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Werror -Wall -Wextra -g
RM = rm -rf

SRCS = main.c utils.c check_args.c process.c get_path.c
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJS = $(SRCS:.c=.o)

# Compilation de l'exécutable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Compilation des fichiers objets
%.o: %.c Makefile
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@

# Compilation de la bibliothèque libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Règles par défaut
all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re