if [ -z "$1" ]; then
	echo "Usage: bash gcc.sh [your_path_without_~/]"
	exit 0;
fi
make re --directory ~/$1
gcc -Wall -Wextra -Werror -O0 -g -Werror -I ~/$1 main.c -L ~/$1 -lft
./a.out
rm a.out
make --directory ~/$1 fclean
