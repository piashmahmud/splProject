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
char keywords[10][20]={"VarInt","VarChar","VarNum","start","stop","print","get","give","loop","if"};

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
        else if(inputFileString[i]=='+'){
            dividers[currentIndx].type=11;
            dividers[currentIndx].position=i;
            currentIndx++;
            dividingChars++;
        }
        else if(inputFileString[i]=='-'){
            dividers[currentIndx].type=12;
            dividers[currentIndx].position=i;
            currentIndx++;
            dividingChars++;
        }
        else if(inputFileString[i]=='*'){
            dividers[currentIndx].type=13;
            dividers[currentIndx].position=i;
            currentIndx++;
            dividingChars++;
        }
        else if(inputFileString[i]=='/'){
            dividers[currentIndx].type=14;
            dividers[currentIndx].position=i;
            currentIndx++;
            dividingChars++;
        }
        else if(inputFileString[i]=='='){
            dividers[currentIndx].type=15;
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
            break;
        }
    }
    if(retVal){
        return retVal;
    }
    else return false;
}

void outputInitializer(){
    outputFileString[0]='\n';
    outputFileString[1]='#';
    outputFileString[2]='i';
    outputFileString[3]='n';
    outputFileString[4]='c';
    outputFileString[5]='l';
    outputFileString[6]='u';
    outputFileString[7]='d';
    outputFileString[8]='e';
    outputFileString[9]='<';
    outputFileString[10]='s';
    outputFileString[11]='t';
    outputFileString[12]='d';
    outputFileString[13]='i';
    outputFileString[14]='o';
    outputFileString[15]='.';
    outputFileString[16]='h';
    outputFileString[17]='>';
    outputFileString[18]='\n';
    outputFileString[19]='\n';
    gap = 20;
}

int main(){
    int inIndx=0,divIndx=0,x,y;
    fileReader();
    stringParsing();
    //printf("%s\n\n\n\n",inputFileString);

    for(int i=0; i<dividingChars;i++){
        printf("%d, %d\n",dividers[i].type, dividers[i].position);
    }

    /*for(int i=0; i<10;i++){
        printf("%s\n",keywords[i]);
    }*/


    outputInitializer();
    //checking for variable tockens
    while(1){
        //checking for VarInt
        if( dividers[divIndx].position+1 == inIndx &&
           dividers[divIndx+1].position-dividers[divIndx].position==7 &&
           stringMatching(inIndx,0) )
        {
            outputFileString[inIndx+gap]='i';
            outputFileString[inIndx+1+gap]='n';
            outputFileString[inIndx+2+gap]='t';
            gap-=3;
            inIndx = dividers[divIndx+1].position;
            divIndx++;
        }
        //checking for VarChar
        else if( dividers[divIndx].position+1 == inIndx &&
           dividers[divIndx+1].position-dividers[divIndx].position==8 &&
           stringMatching(inIndx,1) )
        {
            outputFileString[inIndx+gap]='c';
            outputFileString[inIndx+1+gap]='h';
            outputFileString[inIndx+2+gap]='a';
            outputFileString[inIndx+3+gap]='r';
            gap-=3;
            inIndx = dividers[divIndx+1].position;
            divIndx++;
        }
        //checking for varnum
        else if( dividers[divIndx].position+1 == inIndx &&
           dividers[divIndx+1].position-dividers[divIndx].position==7 &&
           stringMatching(inIndx,2) )
        {
            outputFileString[inIndx+gap]='f';
            outputFileString[inIndx+1+gap]='l';
            outputFileString[inIndx+2+gap]='o';
            outputFileString[inIndx+3+gap]='a';
            outputFileString[inIndx+4+gap]='t';
            gap-=1;
            inIndx = dividers[divIndx+1].position;
            divIndx++;
        }
        else {
            outputFileString[inIndx+gap] = inputFileString[inIndx];
            inIndx++;
            if(inIndx-1 == dividers[divIndx+1].position) divIndx++;
            if(inputFileString[inIndx-1]=='\0') break;
        }
    }

    printf("%s\n\n",outputFileString);

    return 0;
}
