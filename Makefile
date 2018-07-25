
test: cards.c cards.h my-test-main.c
	gcc -o test -ggdb3 cards.c cards.h my-test-main.c
clean:
	rm test poker cards.o my-test-main.o *~
