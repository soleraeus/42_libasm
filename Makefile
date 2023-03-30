# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdetune <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 16:31:58 by bdetune           #+#    #+#              #
#    Updated: 2023/03/30 19:36:45 by bdetune          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS = ft_read.s \
	   ft_strcmp.s \
	   ft_strcpy.s \
	   ft_strdup.s \
	   ft_strlen.s \
	   ft_write.s

SRCS_BONUS = ft_list_push_front.s \
			 ft_list_size.s \
			 ft_list_sort.s \
			 ft_list_remove_if.s

ASM = nasm
ASM_FLAGS = -f elf64 -wall -werror

SRC_DIR = srcs
SRC_BONUS_DIR = srcs_bonus
OBJ_DIR = objs
OBJ_BONUS_DIR = objs

OBJS := $(SRCS:%.s=$(OBJ_DIR)/%.o)
OBJS_BONUS := $(SRCS_BONUS:%.s=$(OBJ_DIR)/%.o)


${NAME}:	${OBJS}
			ar rcs  ${NAME}	${OBJS}
			ranlib	${NAME}


all:	${NAME}

bonus:		${OBJS} ${OBJS_BONUS}
			ar rcs ${NAME} ${OBJS} ${OBJS_BONUS}
			ranlib ${NAME}

test:		bonus
			cc -Wall -Werror -Wextra -Wshadow -Wpedantic tests/main.c -L. -lasm -o tester

clean:
			rm -rf ${OBJS} ${OBJS_BONUS}

fclean:		clean
			rm -rf ${NAME}
			rm -rf tester

re:			fclean all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
				${ASM} ${ASM_FLAGS} $< -o $@


$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.s
				${ASM} ${ASM_FLAGS} $< -o $@

.PHONY: all bonus clean fclean re
