##
## Makefile for bomber in /home/roman/Documents/dev/cpp_bomberman
## 
## Made by grout_r
## Login   <roman@epitech.net>
## 
## Started on  Wed May  6 15:21:44 2015 grout_r
## Last update Mon May 11 14:40:53 2015 grout_r
##

NAME		=		bomberman

CC		=		clang++

RM		=		rm -f

INCLUDES	=		includes

CXXFLAGS	=		-Wall -Wextra -Werror -I./$(INCLUDES) -I./libgdl/includes/

GDL_LDFLAGS	=		-L./libgdl/libs/ -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread

SRCS		=		tp/main.cpp \

OBJS		=		$(SRCS:.cpp=.o)

all:				$(NAME)

$(NAME):			$(OBJS)
				$(CC) -o $(NAME) $(OBJS) $(GDL_LDFLAGS)

clean:
				$(RM) $(OBJS)

fclean:				clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:				all clean fclean re
