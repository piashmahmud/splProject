#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define MAX_LEN 5000
#define MAX_DIV 2000

struct Node {
    int type;
    int position;
} dividers[MAX_DIV];
int dividingChars=0;
char inputFileString[MAX_LEN+1];
char outputFileString[MAX_LEN];
int gap = 0;
char keywords[10][20]={"VarInt","start","stop","main","print","get","give","loop","VarChar","if"};

void fileReader(){
    int i,ch;

    FILE *inputFile = fopen("input_file.txt","r"); //reading all the character
    for (i = 0; (i < (sizeof(inputFileString)-1) && ((ch = fgetc(inputFile)) != EOF)); i++)
      inputFileString[i] = ch;
    inputFileString[i] = '\0';
    fclose(inputFile);
}

void stringParsing(){
    int currentIndx = 1;
    dividers[0].type=0;
    dividers[0].position=-1;

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

bool stringMatching(int indxIn, int key){
    bool retVal=true;
    for(int i=0;keywords[key][i]!='\0';i++){
        if(keywords[key][i]!=inputFileString[indxIn+i] && keywords[key][i]!='\0' ){
            retVal = false;
            printf("false\n");
            break;
        }
    }
    if(retVal){
        printf("true\n");
        return retVal;
    }
    else return false;
}


int main(){
    int inIndx=0,divIndx=0,x,y;
    fileReader();
    stringParsing();
    //printf("%s\n\n\n\n",inputFileString);

    for(int i=0; i<dividingChars;i++){
        printf("%d, %d\n",dividers[i].type, dividers[i].position);
    }

   for(int i=0; i<10;i++){
        printf("%s\n",keywords[i]);
    }

    printf("\n\n\n\n");
    while(inIndx<=MAX_LEN){
        if( dividers[divIndx].position+1 == inIndx && dividers[divIndx+1].position-dividers[divIndx].position==7 && stringMatching(inIndx,0) ){
            printf("at divider %d pos %d\n",divIndx,dividers[divIndx].position);
            printf("string matching working\n");
            outputFileString[inIndx+gap]='i';
            outputFileString[inIndx+1+gap]='n';
            outputFileString[inIndx+2+gap]='t';
            gap-=3;
            inIndx = dividers[divIndx+1].position;
            divIndx++;
        }
        else {
            outputFileString[inIndx+gap] = inputFileString[inIndx];
            inIndx++;
            if(inIndx-1 == dividers[divIndx+1].position) divIndx++;
        }
    }

    printf("%s",outputFileString);

    return 0;
}
