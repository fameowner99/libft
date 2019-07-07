NAME = libft.a

SRC = ft_atoi.c ft_lstiter.c ft_putchar_fd.c ft_strdel.c ft_strncpy.c \
	ft_bzero.c ft_lstmap.c ft_putendl.c ft_strdup.c ft_strnequ.c \
	ft_isalnum.c ft_lstnew.c ft_putendl_fd.c ft_strequ.c ft_strnew.c \
	ft_isalpha.c ft_memalloc.c ft_putnbr.c ft_striter.c ft_strnstr.c \
	ft_isascii.c ft_memccpy.c ft_putnbr_fd.c ft_striteri.c ft_strrchr.c \
	ft_isdigit.c ft_memchr.c ft_putstr.c ft_strjoin.c ft_strsplit.c \
	ft_isprint.c ft_memcmp.c ft_putstr_fd.c ft_strlcat.c ft_strstr.c \
	ft_itoa.c ft_memcpy.c ft_strcat.c ft_strlen.c ft_strsub.c \
	ft_memdel.c ft_strchr.c ft_strmap.c ft_strtrim.c \
	ft_lstadd.c ft_memmove.c ft_strclr.c ft_strmapi.c ft_tolower.c \
	ft_lstdel.c ft_memset.c ft_strcmp.c ft_strncat.c ft_toupper.c \
	ft_lstdelone.c ft_putchar.c ft_strcpy.c ft_strncmp.c \
	ft_count_words.c ft_count_letters.c ft_count_digits.c \
	ft_max.c get_next_line.c ft_realloc.c ft_atoi_ui.c \
	ft_decode.c ft_putstr_fixed_size.c \
	ft_realloc_fixed_size.c ft_swap.c ft_abs.c \
	ft_printf/convert_to_another_base.c \
	ft_printf/get_specifier.c \
	ft_printf/parsing1.c ft_printf/result_output.c \
	ft_printf/ft_itoa_for_ui.c ft_printf/get_specifier1.c \
	ft_printf/parsing2.c ft_printf/hash.c ft_printf/parsing_tools.c \
	ft_printf/parsing.c ft_printf/parsing_tools1.c \
	ft_printf.c ft_alloc_2d.c ft_free_2d.c ft_alloc_2d_int.c \
	ft_free_2d_int.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@ar rc $@ $^
	@echo "LIBFT is ready to use"

%.o:%.c
	@gcc -Wall -Werror -Wextra -o $@ -c $<
	@echo "building... $@"

clean:
	@rm -f $(OBJ)
	@echo "cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "fcleaned"

re: fclean all

.PHONY = all clean fclean re