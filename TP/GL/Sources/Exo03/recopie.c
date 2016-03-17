#include <stdio.h>
#include <stdlib.h>


int main()
{
  FILE * f = fopen("fichier1","r");
  FILE * g = fopen("fichier2","r");
  FILE * h = fopen("fichier3","w");
  char * lecture;
  int taille;

  /* On commence par v�rifier que les trois fichiers ont bien �t�
     ouverts */
  if(f==NULL)
    {
      perror("fichier1");
      exit(1);
    }
  else
    fprintf(stdout,"Le fichier1 a bien �t� ouvert\n\n");

  if(g==NULL)
    {
      perror("fichier2");
      exit(1);
    }
  else
    fprintf(stdout,"Le fichier2 a bien �t� ouvert\n\n");

  if(h==NULL)
    {
      perror("fichier3");
      exit(1);
    }
  else
    fprintf(stdout,"Le fichier3 a bien �t� ouvert\n\n");
	
	taille = 100;
     
  /* Allocation du buffer utilis� pour la recopie */
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

  fprintf(stdout,"Les deux fichiers ont �t� recopi�s avec succ�s dans le fichier3\n");

  return 0;
}
