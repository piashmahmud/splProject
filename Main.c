#include<stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000
#define MAX_DIV 500

struct Node {
    int type;
    int position;
} dividers[MAX_DIV];
int dividingChars=0;
char inputFileString[MAX_LEN+1];

void fileReader(){
    int i,ch;

    FILE *inputFile = fopen("input_file.txt","r"); //reading all the character
    for (i = 0; (i < (sizeof(inputFileString)-1) && ((ch = fgetc(inputFile)) != EOF)); i++)
      inputFileString[i] = ch;
    inputFileString[i] = '\0';
    fclose(inputFile);
}

void stringParsing(){
    int currentIndx = 0;
    for(int i=0; i<MAX_LEN && inputFileString[i] != '\0'; i++){
        if(inputFileString[i]==','){
            dividers[currentIndx].type=1;
            dividers[currentIndx].position=i;
            currentIndx++;
            dividingChars++;
        }
        else if(inputFileString[i]==';'){
            dividers[currentIndx].type=2;
            dividers[currentIndx].position=i;
            currentIndx++;
            dividingChars++;
        }
        else if(inputFileString[i]==' '){
            dividers[currentIndx].type=3;
            dividers[currentIndx].position=i;
            currentIndx++;
            dividingChars++;
        }
        else if(inputFileString[i]=='\n'){
            dividers[currentIndx].type=4;
            dividers[currentIndx].position=i;
            currentIndx++;
            dividingChars++;
        }
        else if(inputFileString[i]=='('){
            dividers[currentIndx].type=5;
            dividers[currentIndx].position=i;
            currentIndx++;
            dividingChars++;
        }
        else if(inputFileString[i]==')'){
            dividers[currentIndx].type=6;
            dividers[currentIndx].position=i;
            currentIndx++;
            dividingChars++;
        }
        else if(inputFileString[i]=='{'){
            dividers[currentIndx].type=7;
            dividers[currentIndx].position=i;
            currentIndx++;
            dividingChars++;
        }
        else if(inputFileString[i]=='}'){
            dividers[currentIndx].type=8;
            dividers[currentIndx].position=i;
            currentIndx++;
            dividingChars++;
        }
        else if(inputFileString[i]=='['){
            dividers[currentIndx].type=9;
            dividers[currentIndx].position=i;
            currentIndx++;
            dividingChars++;
        }
        else if(inputFileString[i]==']'){
            dividers[currentIndx].type=10;
            dividers[currentIndx].position=i;
            currentIndx++;
            dividingChars++;
        }

    }

}

int main(){
    fileReader();
    stringParsing();
    printf("%s\n\n\n\n",inputFileString);

    for(int i=0; i<dividingChars;i++){
        printf("%d, %d\n",dividers[i].type, dividers[i].position);
    }

    return 0;
}
