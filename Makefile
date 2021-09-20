solsquare: solve_square main
	gcc solve_square.o main.o -lm -o solsquare 

solsquare-test: solve_square test
	gcc test.o solve_square.o -lm -o solsquare-test

solve_square:
	gcc -c solve_square.c -Wall -Wextra

main:
	gcc -c main.c -Wall -Wextra 

test:
	gcc -c test.c -Wall -Wextra 

clean:
	rm -f *.o
