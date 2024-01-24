#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isdigit(int c) {
    return (c >= '0' && c <= '9') ? 1 : 0;
}

int main(int argc, char *argv[]) {
    FILE * f = fopen("./input.txt", "r");
    char *str = malloc (60 * sizeof(char)), *new_str = malloc(60), *num = malloc(60);
    int sum = 0, first_digit, last_digit, n, flag;
    char nums[9][8] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    while (str = fgets(str, 60, f)) {
        first_digit = -1;
        last_digit = -1;
        n = 0;
        for (int i=0; i < strlen(str); i++) {
            if (isdigit(str[i])) {
                if (first_digit == -1) {
                    first_digit = str[i] - '0';
                    continue;
                }
                last_digit = str[i] - '0';
                continue;
            }
            strncpy(new_str, str+i, 5);
            if (strlen(new_str) < 3) break;
            for (int j = 0; j < 9; j++) {
                flag = 0;
                for (int k = 0; k < 3; k++) {
                    if (isdigit(new_str[k])) {
                        flag = 1;
                        break;
                    }
                }
                if (flag) break;
                if (strstr(new_str, nums[j])) {
                    
                    if (flag) break;
                    n = j+1;
                    if (first_digit == -1) {
                        first_digit = n;
                        break;
                    }
                    last_digit = n;
                    break;
                }
            }
        }   
        sum += first_digit * 10;
        printf("First digit: %d\n", first_digit);
        if (last_digit == -1) {
            sum += first_digit;
            printf("Second digit: %d\n", first_digit);
        }
        else {
            sum += last_digit;
            printf("Second digit: %d\n", last_digit);
        }
    }
    printf("Sum is equal to: %d\n", sum);
}