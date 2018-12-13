#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "students.h"

// Creates the entire linked list from the file.
// Should call readNext and push
// Returns head of the linked list
Student *buildStudentList()
{
  
  Student *studentsPushed;                       //studentsPushed of type Student           
  studentsPushed = readNext();                  //calls readNext function to read next line in file
                                              //calls the push function along with what the readNext function returned
  
	return studentsPushed;                                  //returns head which is a pointer to the head of the list
 }
 
//Read a single line from standard input and return a student structure located on the heap
Student *readNext()
{
  Student *head = NULL;
  Student *nextStudent = (Student *)malloc(sizeof(Student));              //nextStudent of Student type
  
  char s1[16], s3[16];                                                   //character arrays to capture file inputs
  float s2;                                                              //float for middle input(GPA)
  
  FILE *file;                                                           //initializes file of type FILE
  file = fopen("test.data", "r");                                    //opens testData.data
  printf("\nFile opened Successfully\n\n");                              //prints if the file opens successfully
  
  while(fscanf(file, "%s %f %s", s1,&s2,s3) != EOF)                     //while loop that reads each line of the file and checks for the end of the file
  {
  nextStudent->name = s1;                                              //sets name to contents of s1
  nextStudent->gpa = s2;                                               //sets gpa to contents of s2
  nextStudent->year = s3;                                             //sets year to contents of year
  push(&head, nextStudent);                                        //printf("Name: %s  | GPA: %.2f  | Year: %s\n", s1, s2, s3);         
                                                                   //prints   contents of file, but not from list
  }
  
   fclose(file);                                                      //closes file, does not need anymore
   return head;                                               //returns nextStudent for push
}


//Return a student structure stored on the heap 
Student *makeStudent(char *name, float gpa, char *year)               //creates a student object for the input with name, gpa, and year
{

	Student *newStudent = (Student *) malloc(sizeof(Student));   //creates temp variable named newStudent, allocates size of student 
	newStudent->name = name; 
	newStudent->gpa = gpa;
	newStudent->year = year;
	
	return newStudent;                                            //returns newStudent temp variable 
}

//insert a new student node at the head of the linked list
void push(Student **list, Student *student)
{

  Student *newNode = (Student *) malloc(sizeof(Student));                   //creates and allocates memory for a new node on the list

	newNode->name = student->name;                               //sets the name of the student to newNode name
	newNode->gpa = student->gpa;                                  //sets the gpa of the student to the newNode gpa
	newNode->year = student->year;                                  //sets the year of the student to the newNode year
 
  newNode->next = *list;                                      //sets the next node to the student
	*list = newNode;
 
}

//Insert a student node in the desired position on the linked list
void insert(Student *list, Student *s, int position)         
{
	Student *listSize = malloc(sizeof(Student));                 //allocates space for listSize which is the size of the list
	
	if(position >= 0 && listSize != NULL){                        //if the position is greater than or equal to 0 and listSize is not NULL, will insert
		list->name = s->name;
		list->gpa = s->gpa;
		list->year = s->year;
		list->next;
		s->next;
	}
		
}


//Displays contents of a single student structure
void display(Student *s){
	
	
		printf("Name: %s", s->name);		                          //prints Name: [name]
		printf(" | GPA: %.2f", s->gpa);		                      	//prints GPA: [gpa]
		printf(" | Year: %s\n", s->year);		                       //prints Year: [year]
	
	
}

//Displays contents of the entire linked list
void displayAll(Student *list)
{
	Student * currentNode = list;
 
	printf("Displaying All Students: \n\n");
	while (currentNode != NULL){  			                           //while loop for head not being NULL
		printf("Name: %s  ", currentNode->name);		                //prints Name: [name]
		printf("   | GPA: %.2f", currentNode->gpa);			            //prints GPA: [gpa]
	  printf("   | Year: %s \n", currentNode->year);		        //prints Year: [year]
		currentNode = currentNode->next;						                //sets next head to the next head in list
   
	}
 
}

//Delete all data allocated on the heap before terminating program
void cleanUp(Student *list)
{
	free(list->name);                                               //frees up space from name
	free(list->year);                                             //frees up space from year in name         
   printf("\nMem is now free.\n");                           //once complete, will print this out 
}

//Main function tests your functions. 
int main()
{
	printf("\nProgram Started\n");

	//Construct Linked List from Standard Input
	Student *list = buildStudentList();
	
	//Insert a new student in desired position
	Student *s = makeStudent("Max",3.0, "senior");              //s is for singular student, list is for entire linked list of students
	insert(list, s, 3);
	
	//Display entire linked list
	displayAll(list);

	//Free all heap memory
	cleanUp(list);

    printf("Program Successful Exit\n\n");
    exit(EXIT_SUCCESS);
}