#include <stdio.h>
#include <string.h>
#include <ctype.h>

void CountC(char *filename);
void CountW(char *filename);

int main(int argc, char **args) {
    if (args[1][1] == 'c') {
        CountC(args[2]);
    }
    if (args[1][1] == 'w') {
        CountW(args[2]);
    }
    return 0;
}

void CountW(char *filename){
    FILE *fp;
    char buffer[1024] = {0};
    fp = fopen(filename, "r");
    int count = 0;
    while (!feof(fp)) {
        int flag = 0;
        fgets(buffer, 1024, fp);
        int len = strlen(buffer);
        for (int i = 0; i < len; ++i) {
            if (isalpha(buffer[i]) && flag == 0) {
                flag = 1;
                count++;
            } else if (buffer[i] == ' ' || buffer[i] == ',') {
                flag = 0;
            }
        }
    }
    printf("The number of words is %d", count);
}

void CountC(char *filename){
    FILE *fp;
    char buffer[1024] = "";
    fp = fopen(filename, "r");
    int count = 0;
    while (!feof(fp)) {
        fread(buffer, 1024, 1,fp);
        int len = strlen(buffer);
        for (int i = 0; i < len; ++i) {
            count++;
        }
    }
    printf("The number of characters is %d", count);
}