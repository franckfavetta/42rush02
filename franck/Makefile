execname = ./rush-02
headers = includes/rush.h
src = srcs/default_base.c srcs/default_except.c srcs/loadfile.c srcs/sn_parsing.c srcs/rush-02.c
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
