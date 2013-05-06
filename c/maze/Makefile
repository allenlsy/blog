all: main

main: main.o stack.o maze.o
	gcc $^ -o $@

clean:
	-rm main *.o

.PHONY: clean

sources = main.c stack.c maze.c

# substitute .c -> .d in $(sources)
include $(sources:.c=.d) 
	
# 1. set -e: if anything returns non-zero value, then exit from the shell
# 2. delete maze.d
# 3. Generate maze.c dependencies. $$ is the literal '$'. $$$$ becomes '$$' in shell, which means the current pid
# 4. maze.d.$$
# 5. delete maze.d.$$

%.d: %.c
	set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
