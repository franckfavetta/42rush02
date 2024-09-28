functname = rush-02
headers = includes/rush.h
execname = ./$(functname)
src = $(wildcard srcs/*.c)
obj = $(src:srcs/%.c=obj/%.o)


all: exec

exec: $(obj)
	gcc -Wall -Wextra -Wall $(obj) -o $(execname)

dev: $(obj)
	gcc $(obj) -o $(execname)

$(obj): obj/%.o: srcs/%.c $(headers)
	mkdir -p obj
	gcc -Iincludes -c $< -o $@

clean:
	rm -f obj/*.o
	mkdir -p obj
	rmdir obj

fclean: clean
	rm -f $(execname)

re: fclean all
