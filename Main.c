#include<stdio.h>
#include <stdlib.h>
#define MAX_LEN 1000

struct Node {
    int index;
    int type;
    struct Node* next;
    struct Node* previous;
};
struct Node head;
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


void printList(struct Node* n){
    while (n != NULL) {

        printf(" %d. %d\n", n->index,n->type);
        n = n->next;
    }
}

void stringParsing(){
    struct Node current, next, prev;
    int currentIndx = 0;

    for(int i=0; i<MAX_LEN && inputFileString[i] != '\0'; i++){
        if(inputFileString[i]==','){
            current.index = currentIndx;
            current.type=1;
            current.next = (struct Node) NULL;
            current.previous = prev;

            if(currentIndx==0) head = current;
            currentIndx++;
            prev = current;
            dividingChars++;
        }
        else if(inputFileString[i]==';'){
            current.index = currentIndx;
            current.type=2;
            current.next = NULL;
            current.previous = prev;

            if(currentIndx==0) head = current;
            currentIndx++;
            prev = current;
            dividingChars++;
        }
        else if(inputFileString[i]==' '){
            current.index = currentIndx;
            current.type=3;
            current.next = NULL;
            current.previous = prev;

            if(currentIndx==0) head = current;
            currentIndx++;
            prev = current;
            dividingChars++;
        }
        else if(inputFileString[i]=='\n'){
            current.index = currentIndx;
            current.type=4;
            current.next = NULL;
            current.previous = prev;

            if(currentIndx==0) head = current;
            currentIndx++;
            prev = current;
            dividingChars++;
        }
        else if(inputFileString[i]=='('){
            current.index = currentIndx;
            current.type=5;
            current.next = NULL;
            current.previous = prev;

            if(currentIndx==0) head = current;
            currentIndx++;
            prev = current;
            dividingChars++;
        }
        else if(inputFileString[i]==')'){
            current.index = currentIndx;
            current.type=6;
            current.next = NULL;
            current.previous = prev;

            if(currentIndx==0) head = current;
            currentIndx++;
            prev = current;
            dividingChars++;
        }
        else if(inputFileString[i]=='{'){
            current.index = currentIndx;
            current.type=7;
            current.next = NULL;
            current.previous = prev;

            if(currentIndx==0) head = current;
            currentIndx++;
            prev = current;
            dividingChars++;
        }
        else if(inputFileString[i]=='}'){
            current.index = currentIndx;
            current.type=8;
            current.next = NULL;
            current.previous = prev;

            if(currentIndx==0) head = current;
            currentIndx++;
            prev = current;
            dividingChars++;
        }
        else if(inputFileString[i]=='['){
            current.index = currentIndx;
            current.type=9;
            current.next = NULL;
            current.previous = prev;

            if(currentIndx==0) head = current;
            currentIndx++;
            prev = current;
            dividingChars++;
        }
        else if(inputFileString[i]==']'){
            current.index = currentIndx;
            current.type=10;
            current.next = NULL;
            current.previous = prev;

            if(currentIndx==0) head = current;
            currentIndx++;
            prev = current;
            dividingChars++;
        }
    }

}

int main(){
    fileReader();
    stringParsing();
    printList(head);
    printf("%s",inputFileString);

 return 0;
}
