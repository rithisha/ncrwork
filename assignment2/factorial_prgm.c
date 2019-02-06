#include<stdio.h>

  long int factorial(int n)
 {
    if(n==0)
    return 1;
    else {
    return n*factorial(n-1); }
 }
int main(){
    int n;
     long int fact;
    scanf("%d",&n);
    fact = factorial(n);
    printf("%ld",fact);
    return 0;
}
