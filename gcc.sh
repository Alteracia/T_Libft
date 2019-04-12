make --directory ~/Libft
gcc -Wall -Wextra -Werror -Werror -I ~/Libft main.c -L ~/Libft -lft
./a.out
rm a.out
make --directory ~/Libft fclean