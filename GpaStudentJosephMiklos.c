//Joseph Miklos Project 4

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student_struct
{
    char name[16];
    int age;
    float gpa;
    struct student_struct* next;
} Student;

//From : https://linux.die.net/man/3/strcpy
char *
my_strncpy(char *dest, const char *src, size_t n)
{
    size_t i;

   for (i = 0; i < n ; i++)
        dest[i] = src[i];
        
   return dest;
}

Student *HEAD = NULL; //The head of the linked list

/* Given the student values, initialize a structure,
   and return a pointer to the struct */
Student* makeStudent(char *name, int age, double gpa)
{
     Student *newStudent = malloc(sizeof(Student));
     //char = char[16]
     my_strncpy( newStudent -> name, name, 16);
     //new student age is age and gpa
     newStudent -> age = age;
     newStudent -> gpa = gpa;
    //makeStudent -> next = next;
    return newStudent;  

}
/* Inserts an element to the front of the linkedList */
void push(Student *student)
{
    //simple 2 line push, changed in main method
    student-> next = HEAD;
    HEAD = student;
}


/* Traverses the linked list and returns the student with the best GPA */
Student *findTopStudent()
{
    
    Student* temp = HEAD;
    //starting topGPA at 0.0 as a double type
    double topGPA = 0.0;
    Student* topStudent = NULL;
    //while loop for temp var not being NULL
    while(temp != NULL){
        //if statement for temp gpa to be greater than top GPA then the new gpa temp will overtake the topGPA
        if(temp -> gpa > topGPA){
            
            topGPA = temp ->gpa;
            topStudent = temp;
        }
        
        temp = temp->next;
    }
    return topStudent;  //returns topStudent of the list
}
/* Traverses the linked list and returns the average GPA across all students */
float getAverageGPA() //
{
   
    Student* temp = HEAD;
    double sum = 0 , count = 0;
    //while loop for AverageGPA
    while(temp!=NULL){
        sum += temp -> gpa;
        count += 1;
        temp = temp -> next;
    }
    //returns the sum over the count aka Averaging out the GPAs
    return (1.0 * sum)/count;
       
    }
   
   
int main(int argc, char **argv)
{
    if(argc != 2){
        //error if there are not 3 arguments 0, 1 ,2 
        perror("ERROR: Wrong number of command line args!\n");
        return -1;
    }
    //change in main method below:
    HEAD = NULL; //initialize that the linked list to be empty
    FILE * file;
    file = fopen(argv[1] , "r");
    if (!file){
        perror("ERROR opening file!\n");
        return -1;
    }

    char s1[16];
    char s2[16];
    char s3[16];
    
    Student *temp = NULL;
    int age = 0;
    float gpa = 0.0;
    char *name  = s1;
    //Format is Name, Age, GPA
    while (fscanf(file, "%s %s %s", s1,s2,s3)!=EOF)
    {
      // printf("READING FILE LINE: %s %s %s\n",s1, s2, s3);
        
        
        //Add students to the linked list 
        //chaging to integer
        age = atoi(s2);
        //changing to double
        gpa = atof(s3);
        temp = makeStudent(name, age, gpa);
        push(temp);
        
        //printing that program is adding students to the linked list
        printf("Added Students %s to the linked list\n", temp ->name);
        
    }
    fclose(file); // closes the file

    
    Student *topStudent = findTopStudent();
    printf("\nThe Student with the best GPA is: %s\n", topStudent->name); //prints the name of the top student
    
    printf("The average GPA is: %.2f\n", getAverageGPA()); //Student* list Average GPA

    return 0;
}