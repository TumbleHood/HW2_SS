#include "my_mat.h"
#include <stdio.h>


void funcA(int matrix[10][10])
{
    for (int i = 0; i < 10; i++){ //read numbers from the user and create the matrix
        for (int j = 0; j < 10; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int k = 0; k < 10; k++){ //applying the Floyd-Warshall algorithm to the matrix
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (i != j){ //the diagonal stays "0"
                    if (matrix[i][k] != 0 && matrix[k][j] != 0){ 
                        if (matrix[i][j] != 0){
                        /*since when 2 point don't have a connecting route the value is "0", and we want to find the shortest
                        path between those points, we check to see if there is a path which is not "0" */
                            if (matrix[i][j] > matrix[i][k] + matrix[k][j]){ //apply the shortest route, if it isn't shorter the value stays the same
                                matrix[i][j] = matrix[i][k] + matrix[k][j];
                            }
                        }
                        else {
                            matrix[i][j] = matrix[i][k] + matrix[k][j]; //if the current value is 0, any route (which is not 0) will suit
                        }
                    }
                }
            }
        }
    }
}

void funcB(int matrix[10][10]){
    int i, j;
    scanf("%d %d", &i, &j); //read 2 numbers from the user

    if (matrix[i][j]){ //if the value isn't "0" it means there is a route between i and j
        printf("True\n");
    }
    else {
        printf("False\n");
    }
}

void funcC(int matrix[10][10]){
    int i, j;
    scanf("%d %d", &i, &j); //read 2 numbers from the user

    if (matrix[i][j]){ //if the value isn't "0", there is a route between i and j and we will print it
        printf("%d\n", matrix[i][j]);
    }
    else { //if there isn't, we print -1
        printf("-1\n");
    }
}