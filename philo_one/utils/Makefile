# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <mli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/18 12:06:51 by mli               #+#    #+#              #
#    Updated: 2020/09/22 23:55:18 by mli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EOC = \033[0m
BOLD = \033[1m
GREEN = \033[32m
YELLOW = \033[33m

# ############################################################################ #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ${INCL_PATH}

INCL_PATH = ./

LIBFT_PATH = ./
LIBFT_SRCS = ft_atoi_isdigit.c \
			 ft_isdigit.c \
			 ft_memalloc.c \
			 ft_free.c \
			 ft_nbrlen.c \
			 ft_putendl_fd.c \
			 ft_putstr_fd.c \
			 ft_strlen.c


SRCS_FILES = ${addprefix ${LIBFT_PATH}, ${LIBFT_SRCS}}

OBJS_PATH = ./obj/
OBJS = ${addprefix ${OBJS_PATH}, ${SRCS_FILES:.c=.o}}

all:
	@printf "\033[1mMake utils\033[0m : "
	@make ${NAME}

$(NAME): ${OBJS_PATH} ${OBJS}
	@echo ""
	@ar rcs ${NAME} ${OBJS}

${OBJS_PATH}:
	@mkdir -p $@

${OBJS_PATH}%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@
	@printf "$(YELLOW)▓$(EOC)"

clean:
	@echo "$(BOLD)$(YELLOW)Remove......... |$(GREEN)| done$(EOC)"
	@rm -rf ${OBJS_PATH}

fclean: clean
	@echo "$(BOLD)$(YELLOW)Remove all..... |$(GREEN)| done$(EOC)"
	@rm -rf $(NAME)


re: fclean all

.PHONY: all clean fclean re
