#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    int row, col;

    scanf("%d", &row);
    scanf("%d", &col);

    int grid[row][col];

    int i, j;

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d", &grid[i][j]);
        }
    }

    int max = 0;
    int number = 0;
    int temp = 0;

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(grid[i][j] == 1){
                if(grid[i+1][j] == 1 && i<row){
                    temp++;
                }
                if(grid[i+1][j+1] == 1 && i<row && j<col){
                    temp++;
                }
                if(grid[i][j+1] == 1 && j<col){
                    temp++;
                }
                if(grid[i-1][j+1] == 1 && i>=0 && j<col){
                    temp++;
                }
                if(grid[i-1][j] == 1 && i>=0){
                    temp++;
                }
                if(grid[i-1][j-1] == 1 && i>=0 && j>=0){
                    temp++;
                }
                if(grid[i][j-1] == 1 && j>=0){
                    temp++;
                }
                if(grid[i+1][j-1] == 1 && i<row && j>=0){
                    temp++;
                }
            }

            if(temp >= 2){
                number++;
            }
            if(temp == 1 && number > max){
                    max = number;
                    number = 0;
            }
            if(temp == 1 && number < max){
                    number = 0;
            }
            if(temp == 1 && number == 0){
                number = 1;
            }
            temp = 0;

        }
    }
    printf("%d", max);

return 0;
}
