# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboualla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/31 20:59:16 by oboualla          #+#    #+#              #
#    Updated: 2019/04/02 19:44:27 by oboualla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a 

CC = gcc -Wall -Wextra -Werror

rm = rm -rf

all : $(NAME)

$(NAME) : 
	$(CC) -c *.c -Iincludes
	ar rc $(NAME) *.o

clean :
	$(rm) *.o

fclean : clean
	$(rm) $(NAME)

re : fclean all

