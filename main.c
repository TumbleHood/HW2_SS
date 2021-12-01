#include "my_mat.h"
#include <stdio.h>


int main()
{
    int matrix[10][10];
    char input = getchar(); //read a character from the user

    while (input != 'D'){ //while the character is not 'D', call the corresponding function
        if (input == 'A'){
            funcA(matrix);
        }
        else if (input == 'B'){
            funcB(matrix);
        }
        else if (input == 'C'){
            funcC(matrix);
        }
        input = getchar();
    }

    return 0;
}