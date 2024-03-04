NAME = libft.a

#COMPIL
CC = cc
CFLAGS = -Wall -Wextra -Werror

#DIRECTORY
SRC_PATH = src/
OBJ_PATH = obj/

#ARCHIVE
AR = ar rc

SRC = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_strlen.c ft_memset.c  ft_bzero.c \
	ft_memcpy.c  ft_memmove.c ft_toupper.c ft_tolower.c \
	ft_strchr.c  ft_strrchr.c ft_strncmp.c ft_strlcpy.c\
	ft_strdup.c  ft_atoi.c  ft_putchar_fd.c ft_putstr_fd.c\
	ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_striteri.c\
	ft_strlcat.c ft_split.c ft_memchr.c  ft_memcmp.c\
	ft_calloc.c  ft_strnstr.c ft_substr.c  ft_strjoin.c\
	ft_strtrim.c ft_strmapi.c\
	ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c\
	ft_lstsize.c ft_lstlast.c ft_lstdelone.c\
	ft_lstclear.c ft_lstiter.c ft_lstmap.c\
	ft_findformat.c ft_printf.c ft_printpointer.c\
	ft_putchar.c ft_putnbr.c ft_putnbr_hexa.c\
	ft_putnbr_unsigned.c ft_putstr.c\
	get_next_line.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re
