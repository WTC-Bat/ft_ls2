
NAME = ft_ls
SRC = "./src/"
HEAD = "./includes/"
HEADLFT = "./libft/"
FLAGS = -Wall -Werror -Wextra
SRCS = $(SRC)ft_ls.c $(SRC)arg_funcs.c $(SRC)lsargs_funcs.c \
		$(SRC)s_file_funcs.c $(SRC)format_funcs.c $(SRC)length_funcs.c \
		$(SRC)do_pad.c $(SRC)print_funcs.c $(SRC)s_file_print_members.c \
		$(SRC)do_sort.c $(SRC)s_file_sort.c

all: $(NAME)

$(NAME):
	cd libft && $(MAKE) && $(MAKE) clean
	mv libft/libft.a ./
	gcc $(FLAGS) -I$(HEAD) -I$(HEADLFT) $(SRCS) libft.a -o ft_ls

dbg:
	cd libft && $(MAKE) && $(MAKE) clean
	mv libft/libft.a ./
	gcc -g -o0 $(FLAGS) -I$(HEAD) -I$(HEADLFT) $(SRCS) libft.a -o ft_ls

clean:
	rm -f libft.a

fclean: clean
	rm -f $(NAME)

re: fclean all
