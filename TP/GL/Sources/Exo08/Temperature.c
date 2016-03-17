#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
  if(argc!=2) {
    fprintf(stderr,"Cette fonction prend en entrée un entier (la température en degré Farenheit)\n");
    exit(1);
  }
	float iTmp=atof(argv[1]);
	printf("%f jj\n",iTmp);

	iTmp= (5./9.)*(iTmp-32.);
printf("%f jj\n",iTmp);
  fprintf(stderr,"%d degrés Farenheit correspondent à %d degrés Celsius\n",
	  atoi(argv[1]),iTmp);

  return 0;
}
