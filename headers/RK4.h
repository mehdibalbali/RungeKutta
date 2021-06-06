struct az{
  double a ; 
  double z ; 
};

struct az RK4(double t, struct az old, double h,double (*rhs)(double, double, double));
double Fct(double t, double a, double z);
