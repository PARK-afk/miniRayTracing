CC = cc
CFLAGS = -Wall -Wextra -Werror
HEAD = include/
NAME = miniRT
LIBFT = -L ./libft -lft
MLX = -L ./mlx -lmlx
SRCS = 	srcs/parse.c srcs/main.c srcs/get_color.c srcs/get_info.c srcs/get_vec.c \
		srcs/init_scene.c srcs/parse_obj.c srcs/parse_obj2.c  srcs/color_utils.c \
		srcs/utils.c srcs/cam2view.c srcs/vector.c srcs/vector2.c srcs/ob_hit.c \
		srcs/ob_cy_hit.c srcs/keyhook.c srcs/lightcalculate.c srcs/sp_utils.c \
		srcs/cy_utils.c srcs/pl_utils.c srcs/shadow.c srcs/shadow_ob.c srcs/mlxutils.c

SRCS_BO = boonus/cam2view_bonus.c boonus/color_utils_bonus.c boonus/get_color_bonus.c \
		boonus/get_info_bonus.c boonus/get_vec_bonus.c boonus/init_scene_bonus.c \
		boonus/main.c boonus/ob_cy_hit_bonus.c boonus/ob_hit_bonus.c \
		boonus/parse_bonus.c boonus/parse_obj_bonus.c boonus/parse_obj2_bonus.c \
		boonus/pl_utils_bonus.c boonus/shadow_bonus.c boonus/shadow_ob_bonus.c \
		boonus/sp_utils_bonus.c boonus/utils_bonus.c boonus/vector2_bonus.c \
		boonus/vector_bonus.c boonus/keyhook_bonus.c boonus/lightcalculate_bonus.c \
		boonus/cy_utils_bonus.c boonus/mlxutils_bonus.c

MAN_OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(SRCS_BO:.c=.o)

ifdef BONUS
	OBJS = $(BONUS_OBJS)
else
	OBJS = $(MAN_OBJS)
endif

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@ -g3

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) -I $(HEAD) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) -lm -framework OpenGL -framework AppKit

clean:
	rm -rf $(OBJS) all
	rm -rf $(MAN_OBJS)
	rm -rf $(BONUS_OBJS)
	rm -rf bonus
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME) 
	make fclean -C ./libft

re: $(MAKE) fclean
	$(MAKE) all

bonus:
	$(MAKE) BONUS=1 $(NAME)

.PHONY: all re clean fclean libft bonus
