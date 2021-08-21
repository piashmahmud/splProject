
#include<stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000


struct Node {
    int index;
    char type[20];
    struct Node* next;
    struct Node* previous;
};
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

void printList(struct Node* n)
{
    while (n != NULL) {
        printf(" %d. %s", n->index,n->type);
        n = n->next;
    }
}

int main(){
    fileReader();

    printf("%s",inputFileString);
    return 0;
}
