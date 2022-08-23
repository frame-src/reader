NAME 		= reader

SOURCES 	= $(shell find . -name "*.c")
HEADERS 	= $(shell find . -name "*.h")

OBJECTS 	= $(patsubst %.c, %.o, $(SOURCES))

CFLAGS 		= -g -Wall

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
#	@$(CC) -Iincludes $(CFLAGS) -MMD -MP -c $< -o $@

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) -g $(OBJECTS) -o $(NAME)

clean:
	-@$(RM) $(OBJECTS)

fclean: clean
	-@$(RM) $(NAME)

run: all
	$(NAME)

make exe: all
	./$(NAME)
re: clean all
