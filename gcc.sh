make --directory ~/Libft
gcc -I ~/Libft main.c -L ~/Libft -lft
./a.out
rm a.out
make --directory ~/Libft fclean