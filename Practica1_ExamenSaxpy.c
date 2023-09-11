#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

void get_walltime(double* wcTime) {
   struct timeval tp;
   gettimeofday(&tp ,NULL);
   *wcTime=(tp.tv_sec + tp.tv_usec/1000000.0);
}
//HACER KIJ para 10,000 y 5,000
int main (int argc, char* argv[]) {
 int i, j, k, n=10000;
 printf("Matriz de %d X %d\n", n, n);
 int **matrizA, **matrizB, **matrizC;
 double S1, E1, L1;

 // Inicializando  matrices
 	matrizA = (int **) malloc(n*sizeof(int *));
 	matrizB = (int **) malloc(n*sizeof(int *));
 	matrizC = (int **) malloc(n*sizeof(int *));

 	for (i =0; i<n; i++){
 	*(matrizA+i)= (int *) malloc(n*sizeof(int));
 	*(matrizB+i)= (int *) malloc(n*sizeof(int));
 	*(matrizC+i)= (int *) malloc(n*sizeof(int));
 	}
 	get_walltime(&L1);
 	printf("Se terminaron de inicializar las matrices\n");
 //Llenando matrices
 	for (i =0; i<n;++i)
 	{
 	for (j=0 ;j<n; ++j)
 	{
 	matrizA[i][j]=rand()%6;
 	matrizB[i][j]=rand()%6;
 	}
  }
 get_walltime(&S1);
 printf("Se terminaron de llenar las matrices\n");
 for(j=0; j<n; ++j)
 {
 for(k=0; k<n; ++k)
 {
 for(i=0; i<n; ++i)
 {
 matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
 }
 }
 }
 get_walltime (&E1);
 printf( "Tiempo de llenado de matrices: %f s\n", (S1-L1)) ;
 printf( "Tiempo método jki: %f s\n", (E1-S1));
// Limpia la memoria asignada con malloc
 for (i = 0; i < n; ++i) {
    free(matrizA[i]);
    free(matrizB[i]);
    free(matrizC[i]);
 }
 free(matrizA);
 free(matrizB);
 free(matrizC);
 return 0 ;
 }