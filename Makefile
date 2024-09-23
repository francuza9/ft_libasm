CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fPIC

LIBASM_DIR = libasm
LIBASM = $(LIBASM_DIR)/libasm.a

NAME = a.out

SRCS =	main.c \
		tests.c

OBJ_DIR = .o
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

HEADER = -I includes
LIBS = -L$(LIBASM_DIR) -lasm
RM = rm -f

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(NAME): $(OBJ) $(LIBASM)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(HEADER) $(LIBS)

$(LIBASM):
	$(MAKE) -C $(LIBASM_DIR) -s

all: $(NAME)

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBASM_DIR) clean -s

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBASM_DIR) fclean -s

re: fclean all

.PHONY: all clean fclean re
