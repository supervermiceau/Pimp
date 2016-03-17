#include <stdio.h>
#include <stdlib.h>


int main()
{
  int i,j,k;
  int * tab;
  int t[3], u, *v = t, w, *x = t, y;

  tab = malloc(2000*sizeof(int));
  x[0] = 1;
  x[1] = 3;
  x[2] = 5;
  for(i=0;i<10; i++)
    for(j=0;j<10; j++)
      for(k=0;k<10; k++)
	{
	  tab[i*100+j*10+k] = (i+j+k+t[i%3]+v[j%3]+x[k%3])%7;
	  y = (i+k)/2;
	  t[2] = (t[0] + t[1] + t[2])/3 + y;
	  u+=3;
	  v+=4;
	  w+=5;
	}

  return 0;
}
