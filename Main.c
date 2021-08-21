#include<stdio.h>

#define MAX_LEN 1000

int main(){
    int i,ch;
    char inputFileString[MAX_LEN+1];

    FILE *inputFile = fopen("input_file.txt","r"); //reading all the character
    for (i = 0; (i < (sizeof(inputFileString)-1) && ((ch = fgetc(inputFile)) != EOF)); i++)
      inputFileString[i] = ch;
    inputFileString[i] = '\0';
    fclose(inputFile);

    printf("%s",inputFileString);
    return 0;
}
