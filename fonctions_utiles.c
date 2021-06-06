#include <stdio.h>
#include <stdlib.h>

int getArgs(int argc, char **argv, double *step, double *totalTime, int *interval){
  if (argc == 4) {
    sscanf(argv[1],"%lf",&(*step) );
    sscanf(argv[2],"%lf",&(*totalTime) );
    sscanf(argv[3],"%d",&(*interval) );
  }
  else {
    printf("Usage:\n\n");
    printf("./RKutta <timestep> <length> <output interval>\n\n");
    exit(-1);
  }
  return 0;
}



void writeFileOutput (double *t, double *a, double *z,int size, char *filename_output) {
  FILE *outputFile;
  outputFile = fopen(filename_output, "w");

  for(int i=0; i<size; i++) {
    fprintf(outputFile, "%f\t%.10f\t%.10f\t\n", t[i], a[i], z[i]);
  }

  fclose(outputFile);
}
