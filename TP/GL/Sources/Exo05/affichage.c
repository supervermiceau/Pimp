#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXNUM 12

int * calculeresultat(int * donnees, int taille)
{
  int *tableau;
  int * machin;
  int i;
tableau = malloc(3*sizeof(int));
  tableau[1] = 27;
  for(i=0; i<taille; i++)
    tableau[1] = (1-tableau[1])*donnees[i];

  machin = &(tableau[0]);
  
  tableau[2] = 1789;
  for(i=taille-1; i>=0; i--)
    tableau[2] = tableau[2]*(8-donnees[i]);
  
  tableau[0] = tableau[1] * tableau[2];

  return machin;
}


void lecalculquifaittoutfoirer(int * donnees, int taille)
{
  int tab[257];
  int i;

  for(i=0;i<257;i++)
    tab[i] = donnees[i%taille]*donnees[tab[i]%taille];
  
  for(i=0;i<257;i++)
    tab[0] += tab[i];
}

int main()
{
  int * result = NULL;
  int sources[7] = {2,7,5,9,3,1,6};
  
  
  result = calculeresultat(sources,7);
  fprintf(stderr,"Le resultat est : %d\n", *result);

  lecalculquifaittoutfoirer(sources,7);

  fprintf(stderr,"Le resultat est : %d\n", *result);

  return 0;
}
