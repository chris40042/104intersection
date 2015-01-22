##
## Makefile for Makefile in /home/pliso_c/Igraph
## 
## Made by Christian  Pliso
## Login   <pliso_c@epitech.net>
## 
## Started on  Fri Oct 31 12:26:20 2014 Christian  Pliso
## Last update Fri Jan 16 18:44:30 2015 Christian  Pliso
##

SRC	= 104.c

NAME 	= 104intersection

OBJ 	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ) -lm

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME) $(OBJ)
coffee:
	cat caf

re: fclean all
