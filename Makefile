# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 14:21:53 by bsoubaig          #+#    #+#              #
#    Updated: 2023/10/28 13:39:02 by bsoubaig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors constants
PURPLE			= \033[38;5;141m
GREEN			= \033[38;5;46m
RED				= \033[0;31m
GREY			= \033[38;5;240m
RESET			= \033[0m
BOLD			= \033[1m
CLEAR			= \r\033[K

# Executable and compilation
NAME			= cub3d

SRC_DIR			= ./srcs/
SRCS			= cub3d.c \
				  game/ft_game_init.c \
				  game/ft_key_handler.c \
				  parsing/ft_args_checker.c \
				  parsing/ft_floodfill.c \
				  parsing/ft_parser.c \
				  parsing/ft_scan.c \
				  parsing/ft_tx_parser.c \
				  raycasting/ft_drawer.c \
				  raycasting/ft_raycaster.c \
				  utils/ft_floodfill_utils.c \
				  utils/ft_free_utils.c \
				  utils/ft_mlx_utils.c \
				  utils/ft_other_utils.c \
				  utils/ft_parser_utils.c \

LIBFT_LIB		= libft/libft.a
LIBFT_LIB_DIR	= libft

MLX_LIB			= mlx/libmlx.a
MLX_LIB_DIR		= mlx

OBJ_DIR			= ./objs/
OBJS			= ${addprefix ${OBJ_DIR}, ${SRCS:.c=.o}}

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -arch x86_64 -g -Imlx -I $(LIBFT_LIB_DIR)/includes/
RM				= rm -rf

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@printf "${CLEAR}${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Compiling ${GREEN}%s${RESET}...${GREY}" ${notdir $<}
	@${CC} ${CFLAGS} -I${SRC_DIR} -c $< -o $@

all: 			$(NAME)

$(NAME): 		${LIBFT_LIB} $(MLX_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT_LIB)
	@clear
	@printf "${CLEAR}${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: ${RED}${BOLD}${NAME} ${RESET}compiled ${GREEN}successfully${RESET}.${GREY}\n${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}"

$(LIBFT_LIB_DIR):
	@$(MAKE) -C $(LIBFT_LIB_DIR)

${OBJS}:		| ${OBJ_DIR}

${OBJ_DIR}:
	@mkdir ${OBJ_DIR}
	@mkdir ${OBJ_DIR}game
	@mkdir ${OBJ_DIR}parsing
	@mkdir ${OBJ_DIR}raycasting
	@mkdir ${OBJ_DIR}utils

${LIBFT_LIB}:
	@make -C ${LIBFT_LIB_DIR}

$(MLX_LIB):
	@$(MAKE) -C $(MLX_LIB_DIR)

clean:
	@$(MAKE) clean -C $(LIBFT_LIB_DIR)
	@$(MAKE) clean -C $(MLX_LIB_DIR)
	@${RM} ${OBJ_DIR}
	@printf "${CLEAR}${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Objects were cleaned ${GREEN}successfully${RESET}.\n${RESET}"

fclean: 		clean
	@$(MAKE) fclean -C $(LIBFT_LIB_DIR)
	@${RM} ${NAME}
	@printf "${CLEAR}${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Project cleaned ${GREEN}successfully${RESET}.${GREY}\n${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}"

re: fclean all

.SILENT: all clean fclean re
.PHONY: all clean fclean re
