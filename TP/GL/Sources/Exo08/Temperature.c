#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
  if(argc!=2) {
    fprintf(stderr,"Cette fonction prend en entrée un entier (la température en degré Farenheit)\n");
    exit(1);
  }

	int iTmp=5/9*(atoi(argv[1])-32);

  fprintf(stderr,"%d degrés Farenheit correspondent à %d degrés Celsius\n",
	  atoi(argv[1]),iTmp);

  return 0;
}
