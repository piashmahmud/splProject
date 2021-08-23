#include <stdio.h>

 int add (int a, int b){
int c;
c = a + b;
return c;
}

 int main(){
int a,b,c;
scanf("%d", &a );
scanf("%d", &b );
c = add(a, b);
for(int i=0; i< 5; i++){
printf("loop works\n");
}
printf ("\n");
printf ("%d",c);
return 0;
}

