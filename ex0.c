#include <stdio.h>
int main(){
  printf("%d", factorial(4));
}
 int factorial(int value){
   if(value <= 1){
     return 1;
   }else{
     return value * factorial(value-1);
   }
 };
 