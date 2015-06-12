NAME		=		bomberman

CC		=		clang++ 

RM		=		rm -f

INCLUDES	=		-Icore/includes -Iscreen  -Ilibgdl/includes/ -Iitem/includes/ -IIA

CXXFLAGS	=		 $(INCLUDES) -Wall -Wextra -Werror

GDL_LDFLAGS	=		-Llibgdl/libs/ -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread -lSDL_mixer

SRCS		=		core/src/Param.cpp \
				core/src/main.cpp \
				core/src/GameEngine.cpp \
				core/src/Exception.cpp \
				core/src/AssetsController.cpp \
				screen/Screen.cpp \
				item/src/Player.cpp \
				item/src/Bomb.cpp \
				item/src/Wall.cpp \
				item/src/AObject.cpp \
				item/src/Map.cpp \
				item/src/Void.cpp \
				item/src/Bonus.cpp \
				item/src/Fire.cpp \
				item/src/GameOver.cpp \
				item/src/PlayerIndicator.cpp \
				IA/IA.cpp \
				IA/Move.cpp \
				IA/PosVectorTab.cpp

OBJS		=		$(SRCS:.cpp=.o)

RED_COLOR	=		"\033[31;01m"

NO_COLOR	=		"\033[0m"

EXPORT		=		$(RED_COLOR)"\n\nDon't forget to export library with:\n\
				export LD_LIBRARY_PATH=$$PWD/libgdl/libs/\n\n"$(NO_COLOR)

all:				$(NAME)

$(NAME):			$(OBJS)
				$(CC) -o $(NAME) $(OBJS) $(GDL_LDFLAGS)
				@if test "$$LD_LIBRARY_PATH" != "$$PWD/libgdl/libs/"; then echo -e $(EXPORT); fi

clean:
				$(RM) $(OBJS)

fclean:				clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:				all clean fclean re

