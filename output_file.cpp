#include<iostream>

using namespace std;

 int sum(int a, int b){
int c;
c=a+b;
return c;
}

 int prime(int a){
int c=0,i=2;
while(i<=a/2){
if(a%i==0){
c=1;
break;
}
i++;
}
return c;
}

 int main(){
int a,b,c,i,d;
cin>> a;
cin>> b;
int p[5];
char s[5];

d=prime(a);
if(d==0){
cout<< a <<" is prime\n";
}

else{
cout<< a<<" isn't prime\n";
}

i=0;
while(i<5){
int j=3;
while(j<4){
cout<< 1;
cout<< "\n";
j++;
}
cin>> p[i];
i++;
}

c=sum(a,b);
cout<< "\nsum= ";
cout<< c;
return 0;
}

