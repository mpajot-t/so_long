# Variables
NAME = libftprintf.a            
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = printf.c \
	  printf_utils.c \
	  printf_utils2.c \
	  len_utils.c

OBJ = $(SRC:.c=.o)

# Cree la librairie
all: $(NAME)

# Compile fichiers sources en fichiers objets
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Compile les fichiers c en o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Supp fichiers objets
clean:
	rm -f $(OBJ)

# Supp fichiers objets + librairie
fclean: clean
	rm -f $(NAME)

# Supp tout et recompile
re: fclean all