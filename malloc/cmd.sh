#!/bin/zsh
make re ; gcc main.c -L libft/ -lft -I libft/includes -I includes srcs/* ; ./a.out
