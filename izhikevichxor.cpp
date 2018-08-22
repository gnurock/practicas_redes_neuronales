



/*



Aprende el XOR con el modelo izhikevich





*/

#include<stdio.h>
#include<math.h>

int main()
{
 int i, j, l, n, p, ep, epmin;
 float a, b, CC, d, vr, vt, c, k, vpeak, h, II, alfa, theta, pulsos, error, errmin, w1min, w2min;
 
 /* variables del and */
float  W[2];
float  E[4][2];
float  T[4];

 float v[1001];
 float u[1001];
 
 n = 1001;
 a = 0.03;
 b = -2;
 CC = 100;
 d =100;
 vr = -60;
 vt = -40;
 c = -50;
 k = 0.7;
 vpeak = 35;
 alfa = 0.2;
 theta = 52;
 errmin = 1000;


/* valores de arranque del XOR */
W[0] = 0.0;
W[1] = 0.0;


E[0][0] = 0;
E[0][1] = 0;
T[0] = 2;

E[1][0] = 0;
E[1][1] = 1;
T[1] = 5;

E[2][0] = 1;
E[2][1] = 0;
T[2] = 5;

E[3][0] = 1;
E[3][1] = 1;
T[3] = 2;


/* ciclo de aprendizaje epocas */

for ( ep=0; ep < 20; ep++)

{

 /* para los cuatro patrones p de ejemplo del XOR */
 
 error = 0;

 for ( p=0; p < 4; p++)
     {

     /* calcula la II */
     
     II = W[0] * E[p][0]  +  W[1] * E[p][1] + 1;
     II = II * II  + theta ;
     
     printf("epoca= %5d patron= %5d II= %8.3f ", ep, p, II);
     
     /* cuenta pulsos en un segundo */
     
     pulsos = 0;
     
     u[0] = 0;

     v[0] = vr;

     for(i=0; i < n-1; i++)
          {
            v[i+1] = v[i] + ( k* (v[i] - vr) * ( v[i] - vt) - u[i] + II) / CC;

            u[i+1] = u[i] + a * (b * ( v[i] - vr) - u[i]);

            /* printf("%5d  %8.3f  %8.3f  %5d \n ", i, v[i+1], u[i+1], cont); */

            if ( v[i+1] >= vpeak )
             {
              v[i+1] = c;

              u[i+1] = u[i+1] +  d;

              pulsos = pulsos + 1;

             }
        
          } /* fin cuenta pulsos */
          printf ("pulsos= %8.3f deseados= %8.3f \n", pulsos, T[p]);
          
          /* calcula nuevos pesos */
          W[0] = W[0] - alfa * E[p][0] * (  pulsos -  T[p]  ) * ( W[0] * E[p][0]  +  W[1] * E[p][1] + 1 );
          
          W[1] = W[1] - alfa * E[p][1] * (  pulsos -  T[p]  ) * ( W[0] * E[p][0]  +  W[1] * E[p][1] + 1 );
          
          printf ("w1= %8.3f w2= %8.3f \n", W[0], W[1]);
          
          error = error + abs( pulsos - T[p]) ;
           
          
      } /* fin ciclo patrones */
      
      if ( error < errmin) 
	   {
	      errmin = error;
	      epmin = ep;
	      w1min = W[0];
	      w2min = W[1];
       }
      
      printf ("error= %8.2f errmin= %8.2f en epoca= %5d w1= %8.3f w2= %8.3f \n", error, errmin, epmin, w1min, w2min);
      
  } /* fin ciclo aprendizaje */
  
 
} /* fin del main */



