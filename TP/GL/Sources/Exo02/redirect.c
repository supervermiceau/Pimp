#include <stdio.h>



int main()
{
  FILE * f = fopen("resultat","w");
  int valeurs[200];
  int indices[200];
  int i,j;
  /*Initialisation des valeurs à stocker*/
  for(i=0; i<=200; i++)
    valeurs[i] = i*i;
  
  for(j=0; j<=200; j++)
    indices[i] = 199-j;
    
  for(i=0; i<=200; i++)
    fprintf(f,"%d\t",valeurs[indices[i]]);

  return 0;
}
