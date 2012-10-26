#include <stdio.h>
#include <stdlib.h> 

void swap(int *x,int *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

int choose_pivot(int i,int j )
{
   return((i+j) /2);
}

void quicksort(int list[],int lower,int higher)
{
   int key,i,j,k;
   if( lower < higher)
   {
      k = choose_pivot(lower,higher);
      swap(&list[lower],&list[k]);
      key = list[lower];
      i = lower+1;
      j = higher;
      while(i <= j)
      {
         while((list[i] <= key)
                i++;
         while((list[j] > key)
                j--;
         if( i < j)
                swap(&list[i],&list[j]);
      }
	  // swap two elements
      swap(&list[lower],&list[j]);
	  // recursively sort the lesser list
      quicksort(list,lower,j-1);
      quicksort(list,j+1,higher);
   }
}
void printlist(int list[],int higher)
{
   int i;
   for(i=0;i<higher;i++)
      printf("%d\t",list[i]);
}

void main()
{
   const int MAX_ELEMENTS = 10;
   int list[MAX_ELEMENTS];

   int i = 0;
   
   // generate random numbers and fill them to the list
   for(i = 0; i < MAX_ELEMENTS; i++ ){
	   list[i] = rand();
   }
   printf("The list before sorting is:\higher");
   printlist(list,MAX_ELEMENTS);
   
   // sort the list using quicksort
   quicksort(list,0,MAX_ELEMENTS-1);

   // print the result
   printf("The list after sorting using quicksort algorithm:\higher");
   printlist(list,MAX_ELEMENTS);
}

