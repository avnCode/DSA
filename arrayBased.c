#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"arrayBased.h"


#define MAXCHAR 100

int *arr, size;

int read_CSV()
{

    FILE *fp;
    char row[MAXCHAR];
    char *token;
    
    size=0;
    int i=0;
    fp = fopen("demo.csv","r");

    if (!fp)
	printf("Can't open file\n");

    else
    {
    
    	//arr
    	arr=(int*)malloc(0);
	
	while (!feof(fp))
	{
	    fgets(row, MAXCHAR, fp);

    	    token = strtok(row, ",");
    	  
    	    while(token != NULL)
            {

            //
            	arr=(int*)realloc(arr, (sizeof(int) * (i+1)) );
            	// printf("int token=%d\t i=%d", atoi(token), i);
            	arr[i++]=atoi(token);
            //
            
            //printf("Token: %s\n", token);
            token = strtok(NULL, ",");  
            }  
        }
    }
    
    size=i-1;
    fclose(fp);
    return 0 ;
}


int main()
{
   int i,j=0;
   read_CSV();

   while(i<size)
   {
   printf("%d ", arr[i++]);
   }

   unique1(arr);
   printf("\n");

   while(j<size)
   {
   printf("%d ", arr[j++]);
   }

}
