
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 1200

double mul1[N][N];
double mul2[N][N];
double result[N][N];

int main(){
    clock_t start,end;
    double cpu_end_time;
    for (int a = 0; a < N; a += 1){
        for (int b = 0; b < N; b += 1){
            mul1[a][b] = a+b;
            mul2[a][b] = a-b;
        }
    }
    start= clock(); 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] += mul1[i][k] * mul2[k][j];
            }
        }
    }

    // Stop measuring time
    end = clock();
    cpu_end_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("time taken: %f seconds \n", cpu_end_time);
}