NAME = test

CPP =	main \
		Graphics \
		gManager
		
HPP =	Graphics.hpp \
		gManager.hpp

SRC = $(addprefix src/, $(addsuffix .cpp, $(CPP)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(CPP)))
HDR = $(addprefix includes/, $(HPP))
INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-F./frameworks/
FRAMEWORKS	=	-F./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework SDL2 

FLAGS = -Wall -Wextra -Werror -std=c++11

HEADERS = -I./includes

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	clang++ $(FLAGS) $(OBJ) -lm $(FRAMEWORKS) $(HEADERS) -o $(NAME)


$(OBJ): obj/%.o : src/%.cpp $(HDR) 
	clang++ -o $@ $ -c $(FLAGS) $(INCLUDES) $(HEADERS) $<

clean:
	rm -f $(OBJ)

fclean :
	rm -f $(NAME)
	rm -rf $(OBJ)
	
re: fclean all