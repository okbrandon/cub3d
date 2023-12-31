# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 14:21:53 by bsoubaig          #+#    #+#              #
#    Updated: 2023/11/01 22:54:30 by bsoubaig         ###   ########.fr        #
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

# Checking OS type
UNAME_S 		= $(shell uname -s)

ifneq ($(UNAME_S),Linux)
ifneq ($(UNAME_S),Darwin)
	$(error Unsupported OS $(UNAME_S))
endif
endif

# Executable and compilation
NAME			= cub3d

SRC_DIR			= ./srcs/
SRCS			= $(addprefix mandatory/, \
						cub3d.c \
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
)
SRCS_B			= $(addprefix bonus/, \
						cub3d_bonus.c \
						game/ft_game_cycle_$(shell echo $(UNAME_S) | tr A-Z a-z)_bonus.c \
						game/ft_game_init_bonus.c \
						game/ft_key_handler_bonus.c \
						game/ft_minimap_bonus.c \
						game/ft_sprite_init_bonus.c \
						parsing/ft_args_checker_bonus.c \
						parsing/ft_floodfill_bonus.c \
						parsing/ft_parser_bonus.c \
						parsing/ft_scan_bonus.c \
						parsing/ft_tx_parser_bonus.c \
						raycasting/ft_drawer_bonus.c \
						raycasting/ft_raycaster_bonus.c \
						raycasting/ft_spritecaster_bonus.c \
						utils/ft_door_utils_bonus.c \
						utils/ft_floodfill_utils_bonus.c \
						utils/ft_free_utils_bonus.c \
						utils/ft_mlx_utils_bonus.c \
						utils/ft_other_utils_bonus.c \
						utils/ft_parser_utils_bonus.c \
						utils/ft_sprite_utils_bonus.c \
)

LIBFT_LIB		= libft/libft.a
LIBFT_LIB_DIR	= libft

MLX_LIB			= mlx/macos/libmlx.a
MLX_LIB_DIR		= mlx/macos

OBJ_DIR			= ./objs/
OBJS			= ${addprefix ${OBJ_DIR}, ${SRCS:.c=.o}}
OBJS_B			= ${addprefix ${OBJ_DIR}, ${SRCS_B:.c=.o}}

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g -I $(LIBFT_LIB_DIR)/includes/
RM				= rm -rf

# Adding flag for MacOS not Intel based and associated mlx library
ifeq ($(UNAME_S),Darwin)
	CFLAGS += -arch x86_64 -Imlx/macos
endif

# Switching mlx library and associated flags for Linux
ifeq ($(UNAME_S),Linux)
	CFLAGS += -Imlx/linux
	MLX_LIB	= mlx/linux/libmlx.a
	MLX_LIB_DIR	= mlx/linux
endif

# Adding bonus objects if needed
ifdef MAKEBONUS
	OBJS = ${OBJS_B}
endif

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@printf "${CLEAR}${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Compiling ${GREEN}%s${RESET}...${GREY}" ${notdir $<}
	@${CC} ${CFLAGS} -I${SRC_DIR} -c $< -o $@

all: 			$(NAME)

# Compiling MacOS executable
ifeq ($(UNAME_S),Darwin)
$(NAME): 		${LIBFT_LIB} $(MLX_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -Lmlx/macos -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT_LIB)
	@clear
	@printf "${CLEAR}${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: ${RED}${BOLD}${NAME} ${RESET}compiled ${GREEN}successfully${RESET}.${GREY}\n${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}"
endif

# Compiling Linux executable
ifeq ($(UNAME_S),Linux)
$(NAME): 		${LIBFT_LIB} $(MLX_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -Lmlx/linux -lmlx -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT_LIB)
	@clear
	@printf "${CLEAR}${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: ${RED}${BOLD}${NAME} ${RESET}compiled ${GREEN}successfully${RESET}.${GREY}\n${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}"
endif

$(LIBFT_LIB_DIR):
	@$(MAKE) -C $(LIBFT_LIB_DIR)

${OBJS}:		| ${OBJ_DIR}

${OBJS_B}:		| ${OBJ_DIR}

${OBJ_DIR}:
	@mkdir -p ${OBJ_DIR}/mandatory/game
	@mkdir -p ${OBJ_DIR}/mandatory/parsing
	@mkdir -p ${OBJ_DIR}/mandatory/raycasting
	@mkdir -p ${OBJ_DIR}/mandatory/utils
	@mkdir -p ${OBJ_DIR}/bonus/game
	@mkdir -p ${OBJ_DIR}/bonus/parsing
	@mkdir -p ${OBJ_DIR}/bonus/raycasting
	@mkdir -p ${OBJ_DIR}/bonus/utils

${LIBFT_LIB}:
	@$(MAKE) -C ${LIBFT_LIB_DIR}

$(MLX_LIB):
	@$(MAKE) -C $(MLX_LIB_DIR)

bonus:
	@$(MAKE) MAKEBONUS=1 re

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
