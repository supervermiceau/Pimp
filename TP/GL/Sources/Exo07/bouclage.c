#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
  int i;
  int j = 32;

  for(i=0; i<10;i++)
    {
      j = (j-i)*(j+i) + i + 1; 
      if (((j>27)&&(i<3))||((i>4)&&(i==j)&&(j<32)))
		fprintf(stderr,"%d\t",j);
    }

  return 0;
}
