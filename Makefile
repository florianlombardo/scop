NAME = scop

#--- SOURCES ---#

SRC_DIR = src/
SRC = $(wildcard $(SRC_DIR)*.c $(SRC_DIR)*/*.c)

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))
OBJ_DEBUG_DIR = obj/debug/
OBJ_DEBUG = $(addprefix $(OBJ_DEBUG_DIR), $(notdir $(SRC:.c=.o)))

INCLUDE = include/
LIB = lib/

LIBFT_DIR = libft/
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

#--- COMPILATION ---#

CC = clang
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE) -I$(LIBFT_DIR) -Wl,-rpath,$(LIB) -D_REENTRANT
LIBFLAGS = -lm -L$(LIBFT_DIR) -lft -L$(LIB) -lSDL2 -lGLEW -lGL

#--- REGLES ---#

vpath %c $(sort $(dir $(SRC)))

.PHONY: all debug clean fclean dclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(INCLUDE)
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

debug: $(OBJ_DEBUG) $(LIBFT) $(INCLUDE)
	$(CC) $(CFLAGS) -g $(LIBFLAGS) $(OBJ_DEBUG) -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ) $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

dclean: fclean
	rm -rf $(NAME).dSYM

re: fclean all