#include <stdio.h>
#include <ctype.h>

void CountC(char *filename);
void CountW(char *filename);

int main(int argc, char **args) {
    if(argc != 3){
        //错误输入
        printf("input error");
        return -1;
    }
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
        fread(buffer, 1024, 1,fp);
        //手动添加结束符
        for (int i = 0; buffer[i] != '\0'; ++i) {
            if (isalpha(buffer[i]) && flag == 0) {
                flag = 1;
                count++;
            } else if (buffer[i] == ' ' || buffer[i] == ',') {
                flag = 0;
            }
        }
    }
    fclose(fp);
    printf("The number of words is %d", count);
}

void CountC(char *filename){
    FILE *fp;
    char buffer[1025] = "";
    fp = fopen(filename, "r");
    int count = 0;
    while (!feof(fp)) {
        fread(buffer, 1024, 1,fp);
        //手动添加结束符
        buffer[1024] = '\0';
        for (int i = 0; buffer[i] != '\0'; ++i) {
            count++;
        }
    }
    fclose(fp);
    printf("The number of characters is %d", count);
}