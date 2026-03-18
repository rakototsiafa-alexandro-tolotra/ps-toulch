# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: herasoan <herasoan@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/18 10:07:48 by herasoan          #+#    #+#              #
#    Updated: 2026/03/18 10:07:49 by herasoan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
NAME        = push_swap

# Compilateur et flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Chemins des librairies
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

PRINTF_DIR  = ft_printf
PRINTF      = $(PRINTF_DIR)/libftprintf.a

# Dossiers
INC_DIR     = inc
SRC_DIR     = src

# Fichiers sources (à adapter au fur et à mesure que tu crées tes fichiers)
SRCS        = $(SRC_DIR)/main.c \
              $(SRC_DIR)/operations_push.c \
              $(SRC_DIR)/operations_swap.c \
              $(SRC_DIR)/operations_rotate.c \
              $(SRC_DIR)/operations_rev_rotate.c

OBJS        = $(SRCS:.c=.o)

# Includes et flags de linkage
INCLUDES    = -I $(INC_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR)
LFLAGS      = -L $(LIBFT_DIR) -lft -L $(PRINTF_DIR) -lftprintf

# Règles
all: $(LIBFT) $(PRINTF) $(NAME)

# Compilation de la libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Compilation de ft_printf
$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

# Compilation de l'exécutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

# Compilation des objets (.c en .o)
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Nettoyage des objets
clean:
	rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(PRINTF_DIR)

# Nettoyage complet
fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(PRINTF_DIR)

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re
