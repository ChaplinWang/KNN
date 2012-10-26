#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){

char* a = "abc";
char* b = "efg";

char* c = a;
a = b;
b = c;

printf("a = %s", a);
printf("b = %s", b);
return 0;

}
