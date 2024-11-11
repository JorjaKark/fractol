CC      	= cc
CFLAGS		= -Wall -Werror -Wextra

RM = rm -rf

NAME = fractol
SRCS = arg_checkers.c main.c mandelbrot.c put_img.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
INCLUDES = -I$(LIBFT_DIR) -I$(MLX_DIR)

.PHONY: all clean fclean re

all: $(NAME) $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a .
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) libft.a -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)
	$(RM) $(NAME)

fclean: clean
	$(RM) libft.a
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

