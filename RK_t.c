#include <stdio.h>
#include <math.h>
  
#include "./headers/RK4.h"
 
 
/* fonction qui calcule  la valeur de la gravité en fonction de a et z 
   (z''(t) = -gravité )
*/
double Fct(double t, double a, double z) {
  //gravite = 9.81;
  double gravite = -(a * z);


  return gravite ;
}
   
/*
  Runge - Kutta 4th order for 2nd Order ODEs.
  (Follows Newton's 2nd Law formalism)
  t : independent variable
  a : intervale de temps entre deux positions 
  z : la position 
  
  Returns new, calculated solutions for a and z,
  nicely packed into a structure.  
*/

struct az RK4(double t, struct az old, double h, double (*Fct)(double, double, double)){
  double  k[4], l[4];
  struct az new;
  
  k[0] = h*old.z;
  l[0] = h*Fct(t, old.a, old.z);

  k[1] = h*(old.z + 0.5*l[0]);
  l[1] = h*Fct(t + 0.5*h, old.a + 0.5*h, old.z + 0.5*k[0]);

  k[2] = h*(old.z + 0.5*l[1]);
  l[2] = h*Fct(t + 0.5*h, old.a + 0.5*h, old.z + 0.5*k[1]);

  k[3] = h*((old.z + l[2]));
  l[3] = h*Fct(t + h, old.a + h, old.z + k[2]);
  
  new.a = old.a + (1.0/6.0)*(k[0] + 2*k[1] + 2*k[2] + k[3]);
  new.z = old.z + (1.0/6.0)*(l[0] + 2*l[1] + 2*l[2] + l[3]);  

  return new;   
}
