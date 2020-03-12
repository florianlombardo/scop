NAME = scop

#--- SOURCES ---#

SRC_DIR = src/
SRC = $(wildcard $(SRC_DIR)*.c $(SRC_DIR)*/*.c)

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))
OBJ_DEBUG_DIR = obj/debug/
OBJ_DEBUG = $(addprefix $(OBJ_DEBUG_DIR), $(notdir $(SRC:.c=.o)))

INCLUDE = include/

LIBFT_DIR = libft/
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

MLX_DIR = minilibx/
MLX_FILE = libmlx.a
MLX = $(addprefix $(MLX_DIR), $(MLX_FILE))

#--- COMPILATION ---#

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE) -I$(LIBFT_DIR) -I$(MLX_DIR)
LIBFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lm

#--- REGLES ---#

vpath %c $(sort $(dir $(SRC)))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX) $(INCLUDE)
	$(CC) $(CFLAGS) $(LIBFLAGS) $(OBJ) -o $@

$(OBJ): $(OBJ_DIR)%.o: %.c $(INCLUDE)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DEBUG): $(OBJ_DEBUG_DIR)%.o: %.c $(INCLUDE)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DEBUG_DIR)
	$(CC) $(CFLAGS) -g -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

debug: $(OBJ_DEBUG) $(LIBFT) $(MLX) $(INCLUDE)
	$(CC) $(CFLAGS) -g $(LIBFLAGS) $(OBJ_DEBUG) -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJ) $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

dclean: fclean
	rm -rf $(NAME).dSYM

re: fclean all