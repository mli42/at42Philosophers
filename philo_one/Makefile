# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <mli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/16 14:22:00 by mli               #+#    #+#              #
#    Updated: 2020/09/22 11:16:49 by mli              ###   ########.fr        #
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

ifeq ($(argv), debug)
	CFLAGS += -fsanitize=address -g3
endif

SRCS_FILES = main.c utils.c init.c destroy.c logs.c time.c philosopher.c stop.c

HEADER_FILES = philo_one.h

OBJS_PATH = ./obj/
OBJS = ${addprefix ${OBJS_PATH}, ${SRCS_FILES:.c=.o}}

LIBFT_PATH = ./utils
LIBFT_A = ${LIBFT_PATH}/libft.a

all: ${LIBFT_A} ${HEADER_FILES}
	@printf "$(BOLD)Make $(NAME)$(EOC) : "
	@make ${NAME}

$(NAME): ${OBJS_PATH} ${OBJS} ${HEADER_FILES}
	@echo ""
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT_A}

${OBJS_PATH}:
	@mkdir -p $@

${OBJS_PATH}%.o: %.c ${HEADER_FILES}
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
