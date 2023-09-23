# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 11:45:32 by bsoubaig          #+#    #+#              #
#    Updated: 2023/02/13 17:05:05 by bsoubaig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE			= \033[38;5;141m
GREEN			= \033[38;5;46m
RED				= \033[0;31m
GREY			= \033[38;5;240m
RESET			= \033[0m
BOLD			= \033[1m
CLEAR			= \r\033[K

NAME		  	= libft.a

SRC_DIR			= ./srcs/
SRCS			= libft/ft_atoi.c \
			    libft/ft_bzero.c \
			    libft/ft_calloc.c \
			    libft/ft_isalnum.c \
			    libft/ft_isalpha.c \
			    libft/ft_isascii.c \
			    libft/ft_isdigit.c \
			    libft/ft_isprint.c \
			    libft/ft_itoa.c \
			    libft/ft_memchr.c \
			    libft/ft_memcmp.c \
			    libft/ft_memcpy.c \
			    libft/ft_memmove.c \
			    libft/ft_memset.c \
			    libft/ft_putchar_fd.c \
			    libft/ft_putendl_fd.c \
			    libft/ft_putnbr_fd.c \
			    libft/ft_putstr_fd.c \
			    libft/ft_split.c \
			    libft/ft_strchr.c \
			    libft/ft_strdup.c \
			    libft/ft_striteri.c \
			    libft/ft_strjoin.c \
			    libft/ft_strlcat.c \
			    libft/ft_strlcpy.c \
			    libft/ft_strlen.c \
			    libft/ft_strmapi.c \
			    libft/ft_strncmp.c \
			    libft/ft_strnstr.c \
			    libft/ft_strrchr.c \
			    libft/ft_strtrim.c \
			    libft/ft_substr.c \
			    libft/ft_tolower.c \
			    libft/ft_toupper.c \
				libft/ft_lstnew.c \
				libft/ft_lstadd_front.c \
				libft/ft_lstadd_back.c \
				libft/ft_lstsize.c \
				libft/ft_lstlast.c \
				libft/ft_lstdelone.c \
				libft/ft_lstclear.c \
				libft/ft_lstiter.c \
				libft/ft_lstmap.c \
				ft_printf/ft_parser.c \
				ft_printf/ft_printf.c \
				ft_printf/ft_putchar.c \
				ft_printf/ft_puthexnbr.c \
				ft_printf/ft_putnbr.c \
				ft_printf/ft_putpointer.c \
				ft_printf/ft_putstr.c \
				ft_printf/ft_putunsigned.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c

OBJ_DIR			= ./objs/
OBJS			= ${addprefix ${OBJ_DIR}, ${SRCS:.c=.o}}

RM			  	= rm -rf
CC			  	= gcc
CFLAGS		 	= -Wall -Wextra -Werror

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@printf "${CLEAR}${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Compiling ${GREEN}%s${RESET}...${GREY}" ${notdir $<}
	@${CC} ${CFLAGS} -I${SRC_DIR} -arch x86_64 -c $< -o $@

all:			${NAME}

${NAME}: 		${OBJS}
	@ar rcs ${NAME} ${OBJS}
	@printf "${CLEAR}${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Library compiled ${GREEN}successfully${RESET}.${GREY}\n${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}"

${OBJS}:		| ${OBJ_DIR}

${OBJ_DIR}:
	@mkdir ${OBJ_DIR}
	@mkdir ${OBJ_DIR}/libft
	@mkdir ${OBJ_DIR}/ft_printf
	@mkdir ${OBJ_DIR}/get_next_line

clean:
	@${RM} ${OBJ_DIR}

fclean:			clean
	@${RM} ${NAME}

re: 			fclean all

.SILENT: all clean fclean re
.PHONY: all clean fclean re