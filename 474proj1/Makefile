all: proj1
	# cppcheck --enable=warning,performance,portability --error-exitcode=1 -v .

proj1: proj1.o
	# gcc -Werror -Wall -O0 proj1.o -o proj1
	# gcc -Werror -Wall -O3 proj1.o -o proj1
	# gcc -Werror -Wall proj1.o -o proj1
	# gcc -Wall proj1.o -o proj1
	gcc -O0 -Wall -Wextra -Werror -pedantic proj1.o -o proj1
	

proj1.o: proj1.c
	# gcc -Werror -Wall -O0 -c proj1.c
	# gcc -Werror -Wall -O3 -c proj1.c
	# gcc -Werror -Wall -c proj1.c
	# gcc -Wall -c proj1.c
	gcc -Wall -Wextra -Werror -pedantic -c proj1.c


clean:
	rm -rf *.o

memcheck:
	valgrind ./proj1 --trace-children=yes -s