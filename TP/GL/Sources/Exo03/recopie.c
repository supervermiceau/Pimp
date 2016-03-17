#include <stdio.h>
#include <stdlib.h>


int main()
{
  FILE * f = fopen("fichier1","r");
  FILE * g = fopen("fichier2","r");
  FILE * h = fopen("fichier3","w");
  char * lecture;
  int taille;

  /* On commence par vérifier que les trois fichiers ont bien été
     ouverts */
  if(f==NULL)
    {
      perror("fichier1");
      exit(1);
    }
  else
    fprintf(stdout,"Le fichier1 a bien été ouvert\n\n");

  if(g==NULL)
    {
      perror("fichier2");
      exit(1);
    }
  else
    fprintf(stdout,"Le fichier2 a bien été ouvert\n\n");

  if(h==NULL)
    {
      perror("fichier3");
      exit(1);
    }
  else
    fprintf(stdout,"Le fichier3 a bien été ouvert\n\n");
	
	taille = 100;
     
  /* Allocation du buffer utilisé pour la recopie */
  lecture = (char *) malloc(taille*sizeof(char));

  /* On commence par recopier le premier fichier */
  while(fgets(lecture,taille,f)!=NULL)
	{
	printf(" f : %s \n",lecture);
    fputs(lecture,h);
	}

  /* Puis le deuxieme */
  while(fgets(lecture,taille,g)!=NULL)
    fputs(lecture,h);

  fprintf(stdout,"Les deux fichiers ont été recopiés avec succès dans le fichier3\n");

  return 0;
}
