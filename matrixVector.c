//Joseph Miklos Topics in computer science Excersize 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define FILE " Double Percision Data Types - ([A]x[B]=[C]). Excersize 3."  //name of file
#define SIZE 1000           //size of vector
#define CPU_CLOCK 4.2e9     //clock speed of CPU
#define ITERATIONS 1E10      //ammount of iterations and amount of accuracy improvement loops


int main() // main method for program
{
    int i;
    clock_t totalT;
    totalT = clock();
    time_t start_time;
    time_t end_time;


    //r stands for row and c stands for column
    //x,y , and z are for matrices a b c
    int a[i][i], b[i][i], result[i][i], r1, c1, r2, c2, x, y, z;
    
    long long MATRIX;
    
    //begins timing "clock" for executable process
    clock_t begin = clock();
    
    srand((int)time (NULL));     
    
   
    double totalTime = 0.0;                // setting total time as a double at 0.0
    double totalArrayTime = 0.0;           // setting total array time as a double at 0.0
    double totalArithmeticTime = 0.0;      // setting total arithmatic operations time as a double at 0.0
    double totalElementsTime = 0.0;             // setting total element time as a double at 0.0  
    double FLOPS; 
    double CpuOps;                          //Amount of CPU Operations conducted 
    double ElapsedTime;                    //Elapsed time of total process
    clock_t arrayT;                        //setting clock for arrayT
    clock_t aTime;                       //clock for arithmetic time
    clock_t eTime;
    arrayT = clock();                        //array to clock
    MATRIX = ITERATIONS/SIZE;               //Sets MATRIX to be equal to the Iterations over the SIZE of the array


    //print File name
    printf("File name: %s \n\n", FILE);
    //prompts user to enter number of rows for Matrix A and sets it for r1
    printf("Enter amount of rows for matrix A : ");
    scanf("%d", &r1);
    
    //prompts user to enter number of columns for Matrix A and sets it for c1
    printf("Enter amount of columns for matrix A : ");
    scanf("%d",&c1);
    
    //prompts user to enter number of rows for Matrix B and sets it for r2
    printf("Enter amount of rows for matrix B : ");
    scanf("%d", &r2);
    
    //prompts user to enter number of columns for Matrix B and sets it for c2
    printf("Enter amount of columns for matrix B : ");
    scanf("%d", &c2);

    // While loop to print error if the column for matrix A does not equal the rows for matrix B 
    while (c1 != r2)
    {
        printf("Error!\n");
        printf("The number of columns in Matrix A and the number or rows in Matrix B do not equal! \n");
        
        //prompts the user to re-enter their numbers for matrices a and b
        printf("Please re-enter acceptable numbers for both matrices a and b! \n\n");
        
        //repeat from before loop
        printf("Enter amount of rows for matrix A : ");
        scanf("%d", &r1);
        printf("Enter amount of columns for matrix A : ");
        scanf("%d",&c1);
        
        printf("Enter amount of rows for matrix B : ");
        scanf("%d", &r2);
        printf("Enter amount of columns for matrix B : ");
        scanf("%d", &c2);
    }
    CpuOps=(double)(2 * SIZE * (double)MATRIX);  // Sets the called double of Cpu Operations to be 2 time the Size of the array time the Matrix 
    
    start_time = (double)time(0);
    //for loops for random numbers to fill up matrices
    for (x = 0; x < r1; x++)
        for (y = 0; y < c1; y++)

    {
    //filling matrix a with random numbers
     a[x][y]=(rand()%100-1);
    //filling matrix b with random numbers
     b[x][y]=(rand()%1000-1);
    
    }

    // Initializing all elements of result matrix to 0
    for(x=0; x<r1; ++x)
        for(y=0; y<c2; ++y)
        {
            result[x][y] = 0;
        }

    // Multiplying matrices a and b using 3 for loops for matrices a b c 
    for(x=0; x<r1; ++x)
        for(y=0; y<c2; ++y)
            for(z=0; z<c1; ++z)
            {
                   // storing result in result matrix c
                result[x][y]+=a[x][z]*b[x][y];
            }

    // Output for reults of the multiplication between matrix a and matrix b
    //for loop for integer x or matrix a
    for(x=0; x<r1; ++x)
        //for loop for integer y or matrix b
        for(y=0; y<c2; ++y)
        {
            //print out working... based on the number or rows/colums for the array elements 
        
            if(y == c2-(c2-1))
                printf("Working...\n");
                
        }
        aTime = (clock() - aTime);                        //arithmetic time equals the clock minus the arithmetic time
         
        totalArithmeticTime += ((double)aTime)/CLOCKS_PER_SEC;       //setting total arithmetic time for the arithmetic time over the Clocks Per Second
        
        ElapsedTime = ((end_time - start_time));
        //computes the time spent on process from begin process at top
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        FLOPS = (2/(ElapsedTime/SIZE));
        
        printf("\n");
        end_time = (double)time(0);
        
        //print statment for name of processor
        printf("Processor Name : Intel i7-7700k\n");
        
        //print statement for clock frequency of processor 
        printf("Processor Clock Frequency : 4.200GHz\n\n");                            
        printf("Number of Vector Elements : %d \n", SIZE);
        printf("Square Matrix dimension: %d \n", SIZE*SIZE);
        //optimization setting for compiler
        printf("Compiler optimization setting: -O3 \n");
        printf("Number of accuracy loops: %e\n", (double)ITERATIONS);
        printf("Algorithmically evaluated number of arithmetic operations required to compute the NxN multiplication: %d \n", (CpuOps/SIZE));
        printf("Evaluated execution time for NxN matrix : %e \n", (double)totalTime);
        //Used from answers to excersize 2/assingment 2 for the calculation of the clock cycles per operation and operations per clock cycle
        printf("Estimated number of clock cycles per OP is : %0.2f  CPU Clock Cycles per OP\n", (CPU_CLOCK) / (FLOPS));
	      printf("Estimated number of Ops per clock cycle is : %0.2f  OPs per CPU Clock Cycles\n", (FLOPS) / (CPU_CLOCK));       
        printf("Evaluated time per matrix Element: %d \n", ElapsedTime/ITERATIONS);
        
        printf("Evaluated execution time per arithmetic operation: %e \n", (double)totalArrayTime/SIZE);
    
        //prints the length of the vector or just rows multiplied by columns
        printf("Length of Vector : %d", r1*c1);
       
        //prints time spent in miliseconds
        printf("\nTotal Execution time in miliseconds : %d \n", clock());
        
        //print statement with my name and  the class name in it
        printf("\nJoseph Miklos, Topics in Computer Science.\n");
      
  
    return 0;
}
//end of program