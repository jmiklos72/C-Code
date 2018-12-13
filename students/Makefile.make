hw4: students.o
	gcc students.c -o hw4

students.o: students.c students.h
	gcc -c students.c
	
clean:
	rm students.o
	rm hw4
