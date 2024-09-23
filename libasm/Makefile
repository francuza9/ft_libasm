NAME = libasm.a

SRCS =	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s \
		ft_strdup.s

OBJ_DIR = .o
OBJTS = $(addprefix $(OBJ_DIR)/, $(SRCS:.s=.o))

NASM = nasm
RM = rm -f
NASMFLAGS = -f elf64 -DPIC

$(OBJ_DIR)/%.o: %.s
	mkdir -p $(@D)
	$(NASM) $(NASMFLAGS) $< -o $@

$(NAME): $(OBJTS)
	ar rcs $(NAME) $(OBJTS)

all: $(NAME)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
