#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(int argc, char *argv[]) {
    FILE * f = fopen("./input.txt", "r");
    int red = 12, green = 13, blue = 14, sum = 0, num_of_game, sum_red, sum_green, sum_blue;
    int counter, num, pos, flag, max_blue, max_red, max_green;
    char *str = malloc(170), *new_str = malloc(5), *res;
    while (str = fgets(str, 170, f)) {
        flag = 0;
        num_of_game = 0;
        sum_red = sum_blue = sum_green = -1;
        max_red = max_blue = max_green = -1;
        counter = 1;
        int i = 0;
        while (str[i] != ':') {
            i++;  
        }
        while (!isspace(str[i - counter])) {
            num_of_game += (str[i - counter] - '0') * pow(10, counter-1);
            counter++;
        }
        i++;
        for (i; i < strlen(str); i++) {
            if (isspace(str[i]) || str[i] == ',') {
                continue;
            }
            if (str[i] == ';') {
                sum_red = sum_blue = sum_green = -1;
            }
            strncpy(new_str, str+i, 5);
            num = 0;
            counter = 0;
            if ((res = strstr(new_str, "blue")) && sum_blue == -1) {
                pos = i - (2 - (res - new_str));
                while (!isspace(str[pos - counter])) {
                    num += (str[pos - counter] - '0') * pow(10, counter);
                    counter++;
                }
                sum_blue = num;
                if (num > max_blue) {
                    max_blue = num;
                }
            }
            else if ((res = strstr(new_str, "red")) && sum_red == -1) {
                pos = i - (2 - (res - new_str));
                while (!isspace(str[pos - counter])) {
                    num += (str[pos - counter] - '0') * pow(10, counter);
                    counter++;
                }
                sum_red = num;
                if (num > max_red) {
                    max_red = num;
                }
            }
            else if ((res = strstr(new_str, "green")) && sum_green == -1) {
                pos = i - (2 - (res - new_str));
                while (!isspace(str[pos - counter])) {
                    num += (str[pos - counter] - '0') * pow(10, counter);
                    counter++;
                }
                if (num > max_green) {
                    max_green = num;
                }
            }
        }
        printf("max green %d, max_blue %d, max_red %d\n", max_green, max_blue, max_red);
        sum += max_green * max_blue * max_red;
    }
    printf("%d", sum);
    fclose(f);
    return 0;

}