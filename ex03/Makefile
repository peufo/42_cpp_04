NAME			=	prog
DIR_SRC			=	./
DIR_BUILD		=	./build
SOURCES			=	AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp 
SOURCES_NAME	=	$(basename $(SOURCES))
OBJECTS			=	$(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(SOURCES_NAME)))
CFLAGS			=	-Wall -Wextra -Werror -std=c++98 -pedantic -g
LDINCLUDE		=	-I$(DIR_SRC)
LDFLAGS			=
LDLIBS			=

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CXX) $(OBJECTS) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $@

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CFLAGS) $(LDINCLUDE) -c $^ -o $@

clean:
	$(RM) -r $(DIR_BUILD)

fclean: clean
	$(RM) $(NAME)

re: fclean all
