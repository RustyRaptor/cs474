all: main
	../../cppcheck-2.2/cppcheck --enable=warning,performance,portability --error-exitcode=1 -v .

main: main.o
	# gcc -Werror -Wall -O0 main.o -o main
	# gcc -Werror -Wall -O3 main.o -o main
	# gcc -Werror -Wall main.o -o main
	# gcc -Wall main.o -o main
	gcc -O0 -Wall -Wextra -Werror -pedantic main.o -o main
	

main.o: main.c
	# gcc -Werror -Wall -O0 -c main.c
	# gcc -Werror -Wall -O3 -c main.c
	# gcc -Werror -Wall -c main.c
	# gcc -Wall -c main.c
	gcc -Wall -Wextra -Werror -pedantic -c main.c


clean:
	rm -rf *.o

memcheck:
	valgrind ./main -s