#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./headers/RK4.h"
#include "./headers/fonctions_utiles.h"


int main(int argc, char * argv[]){
  int  totalSteps, nbrRes, interval;
  double h, length;
  double *t, *a, *z,x0 ,y0;
  struct az old;
  
  getArgs(argc, argv, &h, &length, &interval);
  
  printf("donnez la valeur de X0:");
  scanf("%lf",&x0);
  printf("donnez la valeur de y0:");
  scanf("%lf",&y0);

  totalSteps = length/h;
  printf("Total steps: %d\n", totalSteps);
  nbrRes = totalSteps/interval+1; // nombres de resultats a afficher 
  printf("Output size: %d points\n", nbrRes);
  
  t = (double *)malloc(nbrRes * sizeof(double));
  a = (double *)malloc(nbrRes * sizeof(double));
  z = (double *)malloc(nbrRes * sizeof(double));

  t[0] = 0; 
  a[0] = x0;
  z[0] = y0;

  double t_old;
  t_old = t[0];
  old.a = a[0];
  old.z = z[0];
  
  for (int i=1; i<nbrRes; i++) {
    for(int j=0; j<interval; j++) {
      t_old += h; 
      old = RK4(t_old, old, h, Fct);
    }
    t[i] = t_old;
    a[i] = old.a;
    z[i] = old.z; 
  }

  writeFileOutput (t, a, z, nbrRes, "Resultats.txt");
  
  free(t);
  free(a);
  free(z);
  
  return 0;
}

