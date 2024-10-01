#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 4

int devides(int num, int digit);
int path_exists(int mat[][N], int rows, int cols);

int main(){
    //int amount = devides(1345678, 2);  // calls recursive function
    //printf("%d", amount);
    //int mat[][N] = { {1,0,0,1},{0,1,1,0},{0,1,0,1},{0,0,0,1} };
    //int rows = 0, cols = 0;
    int mat[N][N];
    printf("please enter matrix\n");
    for (int rows = 0; rows < N; rows++) {
        for (int cols = 0; cols < N; cols++) {
            scanf_s("%d", &mat[rows][cols]);
        }
    }
    int success = path_exists(mat, 0, 0);
    printf("%d", success);
    //int compare = gimatria('abc', 'kbc');
    //printf("%d", compare);
}

int devides(int num, int digit) {  // returns amount of digits that are divisible by digit
    if (num == 0 || digit == 0) {  // exit condition, exit when num is 0
        return 0;
    }
    int fits = num % 10;  // fits equals digits of units
    if (fits % digit == 0) {  // if divides perfectly add one to next recursion
        return devides(num / 10, digit) + 1;
    }
    else {  // if does not devide perfectly call new recursion without adding 1
        return devides(num / 10, digit);
    }
}

int path_exists(int mat[][N], int rows, int cols) {
    static int check;  // parameter that checks success or failure
    if (rows == (N - 1) && cols == (N - 1)) { // exit condition, checks if got to last slot
        return 1;
    }
    if (rows != (N - 1)) {
        if (mat[rows + 1][cols] == 1) {  // checks num below
            check = path_exists(mat, rows + 1, cols);  // if 1, continue rout
            if (check == 1) {  // if rout successful keep returning, else check different rout 
                return 1;
            }
        }
    }
    if (cols != (N - 1)) {
        if (mat[rows][cols + 1] == 1) {  // checks next num on the right
            check = path_exists(mat, rows, cols + 1);  // continue rout
            if (check == 1) {
                return 1;
            }
        }
    }
    if (rows != (N - 1) && cols != (N - 1)) {
        if (mat[rows + 1][cols + 1] == 1) {  // checks num on the right of num below
            check = path_exists(mat, rows + 1, cols + 1); // continue rout
            if (check == 1) {
                return 1;
            }
        }
    }
    else {  // if no routs available, return failure
        return 0;
    }
}

int gimatria(char* str1, char* str2) {
    if (str1 == '\0' || str2 == '\0') {
        return 0;
    }
    if (str1 == str2)
        return gimatria(*(str1++), *(str2++));
    if (str1 > str2)
        return -1;
    if (str1 < str2)
        return 1;
}