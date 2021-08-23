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
int gap = 0, inIndx=0,divIndx=0;
char keywords[10][20]={"VarInt","VarChar","VarNum","start","stop","print","get","give","loop","if"};

void fileReader(){
    int i,ch;

    FILE *inputFile = fopen("input_file.txt","r"); //reading all the character
    for (i = 0; (i < (sizeof(inputFileString)-1) && ((ch = fgetc(inputFile)) != EOF)); i++)
      inputFileString[i] = ch;
    inputFileString[i]='\n';
    inputFileString[i+1]='\n';
    inputFileString[i+2] = '\0';
    fclose(inputFile);
}

void stringParsing(){
    int currentIndx = 1;
    dividers[0].type=0;
    dividers[0].position=-1;
    dividingChars=0;

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
    outputFileString[0]='#';
    outputFileString[1]='i';
    outputFileString[2]='n';
    outputFileString[3]='c';
    outputFileString[4]='l';
    outputFileString[5]='u';
    outputFileString[6]='d';
    outputFileString[7]='e';
    outputFileString[8]=' ';
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

void stringDeleter(int str, int pos, int amount){

}

void variableTranslator(){
    //checking for variable tokens
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
        else if( dividers[divIndx].position+1 == inIndx &&
           dividers[divIndx+1].position-dividers[divIndx].position==6 &&
           stringMatching(inIndx,5) )
        {
            outputFileString[inIndx+gap]='p';
            outputFileString[inIndx+1+gap]='r';
            outputFileString[inIndx+2+gap]='i';
            outputFileString[inIndx+3+gap]='n';
            outputFileString[inIndx+4+gap]='t';
            outputFileString[inIndx+5+gap]='f';
            gap+=1;
            inIndx = dividers[divIndx+1].position;
            divIndx++;
        }
        else if( dividers[divIndx].position+1 == inIndx &&
           dividers[divIndx+1].position-dividers[divIndx].position==4 &&
           stringMatching(inIndx,6) )
        {
            outputFileString[inIndx+gap]='s';
            outputFileString[inIndx+1+gap]='c';
            outputFileString[inIndx+2+gap]='a';
            outputFileString[inIndx+3+gap]='n';
            outputFileString[inIndx+4+gap]='f';
            gap+=2;
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
}

void functionTranslator(){
    //tokenising function
    inIndx=0;
    divIndx=0;
    gap=0;
    int foundNL = 0;

    while(1){
        if( dividers[divIndx].position+1 == inIndx && dividers[divIndx+1].position-dividers[divIndx].position==6 && stringMatching(inIndx,3) ){

            //deleting the first start
            gap-=5;
            inIndx = dividers[divIndx+1].position;
            divIndx++;

            //searching for first new line
            while(1){
                if(inputFileString[inIndx]=='\n'){
                    outputFileString[inIndx+gap]='{';
                    outputFileString[inIndx+gap+1]='\n';
                    gap+=1;
                    inIndx++;
                    divIndx++;
                    break;
                }
                else {
                    outputFileString[inIndx+gap] = inputFileString[inIndx];
                    inIndx++;
                    if(inIndx-1 == dividers[divIndx+1].position) divIndx++;
                    if(inputFileString[inIndx-1]=='\0') break;
                }
            }

            //searching for first stop
            while(1){
                if( dividers[divIndx].position+1 == inIndx && dividers[divIndx+1].position-dividers[divIndx].position==5 && stringMatching(inIndx,4) ){
                    //deleting the first stop
                    gap-=4;
                    inIndx = dividers[divIndx+1].position;
                    divIndx++;
                    break;
                }
                else {
                    outputFileString[inIndx+gap] = inputFileString[inIndx];
                    inIndx++;
                    if(inIndx-1 == dividers[divIndx+1].position) divIndx++;
                    if(inputFileString[inIndx-1]=='\0') break;
                }
            }

            //searching for first give
            while(1){
                if( dividers[divIndx].position+1 == inIndx && dividers[divIndx+1].position-dividers[divIndx].position==5 && stringMatching(inIndx,7) ){
                    outputFileString[inIndx+gap]='r';
                    outputFileString[inIndx+gap+1]='e';
                    outputFileString[inIndx+gap+2]='t';
                    outputFileString[inIndx+gap+3]='u';
                    outputFileString[inIndx+gap+4]='r';
                    outputFileString[inIndx+gap+5]='n';
                    gap+=2;
                    inIndx = dividers[divIndx+1].position;
                    divIndx++;
                    break;
                }
                //if there is no return then nothing
                else if(inputFileString[inIndx]=='\n'){
                    outputFileString[inIndx+gap]='}';
                    outputFileString[inIndx+gap+1]='\n';
                    gap++;
                    foundNL=1;
                    break;
                }
                else {
                    //no need to copy the function name
                    gap--;
                    inIndx++;
                    if(inIndx-1 == dividers[divIndx+1].position) divIndx++;
                    if(inputFileString[inIndx-1]=='\0') break;
                }
            }
            //searching for first new line
            while(!foundNL){
                if(inputFileString[inIndx]=='\n'){
                    outputFileString[inIndx+gap]=';';
                    outputFileString[inIndx+gap+1]='\n';
                    outputFileString[inIndx+gap+2]='}';
                    outputFileString[inIndx+gap+3]='\n';
                    gap+=3;
                    inIndx++;
                    divIndx++;
                    break;
                }
                else {
                    outputFileString[inIndx+gap] = inputFileString[inIndx];
                    inIndx++;
                    if(inIndx-1 == dividers[divIndx+1].position) divIndx++;
                    if(inputFileString[inIndx-1]=='\0') break;
                }
            }

        }
        else {
            outputFileString[inIndx+gap] = inputFileString[inIndx];
            inIndx++;
            if(inIndx-1 == dividers[divIndx+1].position) divIndx++;
            if(inputFileString[inIndx-1]=='\0') break;
        }
    }
}

void semicolonTranslator(){
    inIndx=0;
    gap=0;
    //semicolon
    while(1){
        //checking for \n
        if( inputFileString[inIndx] == '\n' && inputFileString[inIndx-1] != '{' && inputFileString[inIndx-1] != '}' && inputFileString[inIndx-1] != ';' && inputFileString[inIndx-1] != '\n' && inputFileString[inIndx-1] !='>'){
            outputFileString[inIndx+gap]=';';
            outputFileString[inIndx+1+gap]='\n';
            gap+=1;
            inIndx++;
        }
        else {
            outputFileString[inIndx+gap] = inputFileString[inIndx];
            inIndx++;
            if(inputFileString[inIndx-1]=='\0') break;
        }
    }
}

int main(){
    int x,y,i;
    fileReader();
    stringParsing();
    //printf("%s\n\n\n\n",inputFileString);

    for(int i=0; i<dividingChars;i++){
        printf("%d, %d\n",dividers[i].type, dividers[i].position);
    }

    outputInitializer();
    //replacing all the variable names for their c counterparts
    variableTranslator();

    //copying the output to input for a new iteration
    for(i=0;outputFileString[i]!='\0';i++){
        inputFileString[i]=outputFileString[i];
    }
    inputFileString[i]='\0';
    stringParsing();
    //replacing all the functions by the formate of their c counterpart
    functionTranslator();

    //copying the output to input for a new iteration
    for(i=0;outputFileString[i]!='\0';i++){
        inputFileString[i]=outputFileString[i];
    }
    inputFileString[i]='\0';
    stringParsing();

    //to replace newlines with semicolon and new line
    semicolonTranslator();

    FILE* outputFile;
    outputFile = fopen("output_file.c","w");
    fprintf(outputFile,"%s",outputFileString);
    fclose(outputFile);

    printf("%s\n\n",outputFileString);

    return 0;
}
