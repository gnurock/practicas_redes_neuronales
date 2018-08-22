/* PERCEP.c

Paradigma Perceptron


*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <io.h>


int main()
{

/* variables  */
int  w[2] =  {400,800};
int  E[4][2]
 = {{0,0}, {0,1},{1,0},{1,1}
                 }; 
int  T[4] = {0,0,0,1}; 
int  teta;
int  p;
int  i;
int  ii;
int  sal1, sal2;
int  flag, iter;

/* valores de arranque */

teta = 200;

iter = 0;


/* loop infinito hasta cumplir la condicion */
for (ii=0; ii < 300; ii++)
{

 /* para los 4 patrones p de ejemplo */
 printf("No.Epoch  Patron teta    salPP    SalRN    Objetivo \n");
 iter += 1;
 flag = 0;
 for ( p=0; p < 4; p++)
 {

  /* calcula la salida de la red */
  sal1 = 0;
  for ( i=0; i < 2; i++)
   sal1 += w[i] * E[p][i];

  /* aplica valor de umbral */
  if (sal1 > teta )
  {
   sal2 = 1;
  }
  else
  {
   sal2 = 0;
  }

  /* compara sal2 contra el objetivo T */
  if ( sal2 != T[p] )
  {

   /* es necesario modificar pesos y teta */
   flag = 1;
   teta += -( T[p] - sal2); 
   for ( i=0; i < 2; i++)
    w[i] += (T[p] - sal2) * E[p][i] ;
  }
 /* resultados */

 printf("%5d   %5d   %5d   %5d   %5d  %5d \n",
                  iter, p+1, teta, sal1, sal2, T[p] );
 } /* fin del for de cuatro patrones */

 /* condicion de terminacion */
 /* gets(k); */
 if ( flag == 0 ) break;
} /* fin loop infinito */

 printf("Resultado: ");
 for ( i=0; i < 2; i++) printf(" w%d = %d ", i+1, w[i]);
 printf(" theta = %d ", teta);
} /* fin del main */
