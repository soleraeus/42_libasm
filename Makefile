# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdetune <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 16:31:58 by bdetune           #+#    #+#              #
#    Updated: 2023/03/28 18:46:41 by bdetune          ###   ########.fr        #
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
			 ft_list_size.s

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

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
				${ASM} ${ASM_FLAGS} $< -o $@


$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.s
				${ASM} ${ASM_FLAGS} $< -o $@
