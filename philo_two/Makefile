# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <mli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/16 14:22:00 by mli               #+#    #+#              #
#    Updated: 2020/09/23 10:53:05 by mli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EOC = \033[0m
BOLD = \033[1m
GREEN = \033[32m
YELLOW = \033[33m

# ############################################################################ #

NAME = philo_two

CC = clang
CFLAGS = -Wall -Wextra -Werror -pthread

ifeq ($(argv), debug)
	CFLAGS += -fsanitize=address -g3
endif

SRCS_FILES = main.c init.c destroy.c logs.c time.c philosopher.c stop.c \
			 utils.c utils1.c

HEADER_FILES = philo_two.h

OBJS_PATH = ./obj/
OBJS = ${addprefix ${OBJS_PATH}, ${SRCS_FILES:.c=.o}}

all: ${HEADER_FILES}
	@printf "$(BOLD)Make $(NAME)$(EOC) : "
	@make ${NAME}

$(NAME): ${OBJS_PATH} ${OBJS} ${HEADER_FILES}
	@echo ""
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS}

${OBJS_PATH}:
	@mkdir -p $@

${OBJS_PATH}%.o: %.c ${HEADER_FILES}
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
