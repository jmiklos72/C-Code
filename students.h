#ifndef STUDENTS_H
#define STUDENTS_H

typedef struct Student Student;

struct Student
{
   	char *name;
	float gpa;
	char *year;

	Student *next;
};

Student *makeStudent(char *name, float gpa, char *year);
void insert(Student *list, Student *s, int position);
Student *readNext();
Student *buildStudentList();
void display(Student *s);
void displayAll(Student *list);
void push(Student **list, Student *student);
void cleanUp(Student *list);

#endif