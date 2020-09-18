# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <mli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/16 14:22:00 by mli               #+#    #+#              #
#    Updated: 2020/09/18 15:53:22 by mli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EOC = \033[0m
BOLD = \033[1m
GREEN = \033[32m
YELLOW = \033[33m

# ############################################################################ #

NAME = philo_one

CC = clang
CFLAGS = -Wall -Wextra -Werror

SRCS_FILES = main.c utils.c parser.c destroy.c

OBJS_PATH = ./obj/
OBJS = ${addprefix ${OBJS_PATH}, ${SRCS_FILES:.c=.o}}

LIBFT_PATH = ./utils
LIBFT_A = ${LIBFT_PATH}/libft.a

all: ${LIBFT_A}
	@printf "$(BOLD)Make $(NAME)$(EOC) : "
	@make ${NAME}

$(NAME): ${OBJS_PATH} ${OBJS}
	@echo ""
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT_A}

${OBJS_PATH}:
	@mkdir -p $@

${OBJS_PATH}%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@
	@printf "$(YELLOW)▓$(EOC)"

${LIBFT_A}:
	@make -C ${LIBFT_PATH}

clean:
	@echo "$(BOLD)$(YELLOW)Remove......... |$(GREEN)| done$(EOC)"
	@make clean -C ${LIBFT_PATH}
	@rm -rf ${OBJS_PATH}

fclean: clean
	@echo "$(BOLD)$(YELLOW)Remove all..... |$(GREEN)| done$(EOC)"
	@rm -rf ${LIBFT_A}
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
