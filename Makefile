NAME = data_base.a
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
RM		= rm -f

SRC = \
	src/data_base.c \
	src/opperators.c \
	src/utils.c \

OBJS = $(SRC:%.c=%.o)

all:	$(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		$(RM) */*.o

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY : all clean fclean re git