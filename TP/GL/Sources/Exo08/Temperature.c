#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
  if(argc!=2) {
    fprintf(stderr,"Cette fonction prend en entr�e un entier (la temp�rature en degr� Farenheit)\n");
    exit(1);
  }
	float iTmp=atof(argv[1]);
	printf("%f jj\n",iTmp);

	iTmp= (5./9.)*(iTmp-32.);
printf("%f jj\n",iTmp);
  fprintf(stderr,"%d degr�s Farenheit correspondent � %d degr�s Celsius\n",
	  atoi(argv[1]),iTmp);

  return 0;
}
