
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 1000

double mul1_test[N][N];
double mul2_test[N][N];
double result[N][N];

int main(){
    clock_t start,end;
    double cpu_end_time;
    for (int a = 0; a < N; a += 1){
        for (int b = 0; b < N; b += 1){
            mul1_test[a][b] = a+b;
            mul2_test[a][b] = a-b;
        }
    }
    int i, j, k;
    start= clock(); 
    double tmp[N][N];
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            tmp[i][j] = mul2_test[j][i];
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
		result[i][j] = 0.0;
            for (k = 0; k < N; k++) {
                result[i][j] += mul1_test[i][k] * tmp[k][j];
            }
        }
    }

    // Stop measuring time
    end = clock();
    cpu_end_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("time for transposed taken: %f seconds \n", cpu_end_time);
}
