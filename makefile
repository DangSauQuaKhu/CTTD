all:	main
main:	main.o 
		gcc -g -o main main.o -lm
main.o:	main.c 
	gcc -g -I/ -c main.c -lm
clean:	
	rm -f *.o *~
	
