#include <stdio.h>
#include <string.h>

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

void CountC(char *filename){
    FILE *fp;
    char buffer[1024] = "";
    fp = fopen(filename, "r");
    int count = 0;
    while (!feof(fp)) {
        int flag = 0;
        fgets(buffer, 1024, fp);
        int len = strlen(buffer);
        for (int i = 0; i < len; ++i) {
            if (buffer[i] == ',') {
                count++;
            }
            if (buffer[i] == ' ') {
                flag = 0;
            }
            else if (flag == 0) {
                flag = 1;
                count++;
            }
        }
    }
    printf("The number of characters is %d", count);
}

void CountW(char *filename){
    FILE *fp;
    char buffer[1024] = "";
    fp = fopen(filename, "r");
    int count = 0;
    while (!feof(fp)) {
        fgets(buffer, 1024, fp);
        int len = strlen(buffer);
        for (int i = 0; i < len; ++i) {
            if (97 <= buffer[i] && buffer[i] <= 122 || 65 <= buffer[i] && buffer[i] <= 90) {
            } else {
                if (buffer[i] != '\n') {
                    count++;
                }
            }
        }
    }
    printf("The number of sign is %d", count);
}