NAME = ps_visualizer
FLAG = -Wall -Wextra -Werror
FLAG_MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
OPTION = -MMD -c -I.
LIBFT_PATH = lib/Libft
MINILIBX_PATH = mlx_linux

# Library files
LIBFT = $(LIBFT_PATH)/libft.a
MINILIBX = $(MINILIBX_PATH)/libmlx_Linux.a

INCLUDE = $(LIBFT_PATH)/libft.h \
	$(LIBFT_PATH)/libft.a \
	$(MINILIBX_PATH)/libmlx_Linux.a \
	src/ps_visualizer.h \
	src/ps_visualizer.c \
	Makefile \

LIB =  $(LIBFT) $(MINILIBX)

SRC = src/ps_visualizer.c \
	src/utils.c \
	src/hooks.c \
	src/image.c \
	src/ft_instructions.c \
	src/ft_execute.c \
	lib/list1.c \
	lib/list2.c \

OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

all: $(NAME)

exec: $(NAME)
	../push_swap $(ARG) | ./$(NAME) $(ARG)

-include $(DEP)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_PATH)

%.o: %.c $(INCLUDE)
	cc $(FLAG) $(OPTION) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ) $(INCLUDE) $(LIB)
	cc $(OBJ) $(FLAG) $(FLAG_MLX) $(LIB) -o $(NAME)

clean:
	/bin/rm -f $(OBJ) $(OBJBONUS) $(DEP)
	$(MAKE) -C $(LIBFT_PATH) clean

# Full clean
fclean: clean
	/bin/rm -f $(NAME) $(NAMEBONUS)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(MINILIBX_PATH) clean

re: fclean all
