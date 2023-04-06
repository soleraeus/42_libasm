# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdetune <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 16:31:58 by bdetune           #+#    #+#              #
#    Updated: 2023/04/06 16:48:44 by bdetune          ###   ########.fr        #
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
			 ft_list_remove_if.s \
			 ft_atoi_base.s

SRCS_TEST = main.c \
			utils.c \
			test_strlen.c \
			test_strcpy.c \
			test_strcmp.c \
			test_write.c \
			test_read.c \
			test_strdup.c \
			test_atoi_base.c \
			test_list_push_front.c \
			test_list_size.c \
			test_list_sort.c \
			test_list_remove_if.c

ASM = nasm
ASM_FLAGS = -f elf64 -wall -werror

CC = cc
CFLAGS = -Wall -Werror -Wextra -Wpedantic -Wshadow -g

SRC_DIR = srcs
TEST_DIR = tests
OBJ_DIR = objs
OBJ_DIR_TEST = objs

OBJS := $(SRCS:%.s=$(OBJ_DIR)/%.o)
OBJS_BONUS := $(SRCS_BONUS:%.s=$(OBJ_DIR)/%.o)
OBJS_TEST := $(SRCS_TEST:%.c=$(OBJ_DIR_TEST)/%.o)

TEST_DEP = includes/libasm.h tests/tests.h

${NAME}:	${OBJS}
			ar rcs  ${NAME}	${OBJS}
			ranlib	${NAME}


all:	${NAME}

bonus:		${OBJS} ${OBJS_BONUS}
			ar rcs ${NAME} ${OBJS} ${OBJS_BONUS}
			ranlib ${NAME}

tester:		bonus ${OBJS_TEST}
			${CC} ${CFLAGS} -Iincludes ${OBJS_TEST} -L. -lasm -o tester

clean:
			rm -rf ${OBJ_DIR} ${OBJ_DIR_BONUS} ${OBJ_DIR_TEST}

fclean:		clean
			rm -rf ${NAME}
			rm -rf tester

re:			fclean all

${OBJS_TEST}:	${TEST_DEP}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
				test -d ${OBJ_DIR} || mkdir -p ${OBJ_DIR}
				${ASM} ${ASM_FLAGS} $< -o $@

$(OBJ_DIR_TEST)/%.o: $(TEST_DIR)/%.c
				test -d ${OBJ_DIR_TEST} || mkdir -p ${OBJ_DIR_TEST}
				${CC} ${CFLAGS} -Iincludes -c $< -o $@

.PHONY: all bonus clean fclean re
