#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
  if(argc!=2) {
    fprintf(stderr,"Cette fonction prend en entr�e un entier (la temp�rature en degr� Farenheit)\n");
    exit(1);
  }
	int iTmp=atoi(argv[1]);
	printf("%d jj\n",iTmp);

	iTmp= (iTmp-32);
printf("%d jj\n",iTmp);
  fprintf(stderr,"%d degr�s Farenheit correspondent � %d degr�s Celsius\n",
	  atoi(argv[1]),iTmp);

  return 0;
}
