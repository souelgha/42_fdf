
NAME = fdf

#COMPIL
CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIBX = -lXext -lX11

#DIRECTORY
SRC_PATH = src/
OBJ_PATH = obj/
HEADER_FOLDER = includes

ARGS = test_maps/42.fdf

#SOURCES
SRC =  	fdf.c\
		utils_hooks.c\
		check_functions.c\
		parsing_file.c\
		lst_utils.c\
		line_utils.c\
		algo_line.c\
		utils_mlx.c\
		calcul_angles.c\
		init_map.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

#MANDATORY
all: $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ libmlx.a libft.a $(CLIBX) -lm
	@echo "$(GREEN) compilation ok $(RESET)"

#OBJECTS
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@if [ ! -e $(OBJ_PATH) ]; then\
		mkdir -p $(OBJ_PATH);\
	fi
	make -sC ./minilibx-linux
	cp ./minilibx-linux/libmlx.a .
	make -sC ./libft
	cp ./libft/libft.a .
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS) 


#CLEANS
clean:
	rm -rf $(OBJ_PATH)
	make clean -C ./minilibx-linux
	make fclean -C ./libft
	rm -f libmlx.a
	rm -f libft.a
	@echo "$(CLEAR) $(BLUE) cleaned $(RESET)"

	
fclean: clean
	rm -rf $(NAME)
	@echo "$(CLEAR) $(BLUE) fcleaned $(RESET)"

re: fclean all	

.PHONY: all clean fclean re

.SILENT: clean fclean

valgrind: clean all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s \
	--track-origins=yes --trace-children=yes --track-fds=yes --track-origins=yes \
	 ./$(NAME) $(ARGS)

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[38;5;97m
CLEAR = \033[2J\033[H
RESET = \033[0m
