make re --directory ~/$1
gcc -Wall -Wextra -Werror -O0 -g -Werror -I ~/$1 main.c -L ~/$1 -lft
~/Applications/valgrind/bin/valgrind --leak-check=yes ./a.out
rm a.out
make --directory ~/$1 fclean