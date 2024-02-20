
NAME = fdf

#COMPIL
CC = cc
CFLAGS = -Wall -Wextra -Werror 
CLIBX = -lXext -lX11

#DIRECTORY
SRC_PATH = src/
OBJ_PATH = obj/
HEADER_FOLDER = includes

#MINILIBX
LIBX_PATH = minilibx-linux
LIBX_MAKE = Makefile
LIBX = $(LIBX_PATH)/libmlx.a

#SOURCES
SRC =  	test3.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

#MANDATORY
all: $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ libmlx.a $(CLIBX)
	@echo "$(GREEN) compilation ok $(RESET)"

#OBJECTS
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@if [ ! -e $(OBJ_PATH) ]; then\
		mkdir -p $(OBJ_PATH);\
	fi
	make -sC ./minilibx-linux
	cp ./minilibx-linux/libmlx.a .
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS) 


#CLEANS
clean:
	rm -rf $(OBJ_PATH)
	make clean -C ./minilibx-linux
	rm -f libmlx.a
	@echo "$(CLEAR) $(BLUE) cleaned $(RESET)"

	
fclean: clean
	rm -rf $(NAME)
	@echo "$(CLEAR) $(BLUE) fcleaned $(RESET)"

re: fclean all	

.PHONY: all clean fclean re

.SILENT: clean fclean

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[38;5;97m
CLEAR = \033[2J\033[H
RESET = \033[0m
