#!/bin/zsh

gcc main.c -I includes/ -I libft/includes/ -L libft/ -lft srcs/* ; ./a.out