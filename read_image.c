#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <math.h>

#include "rdjpeg.h"

#define BINS 4

void print_histogram (char *argv[], int print_default, int print_libsvm) {
  int i,j,l,k;
  CIMAGE cim;

  // Lecture de l'image en input
  read_cimage(argv[1],&cim);

  // Remplissage du tableau h
  float h[BINS*BINS*BINS] = {};
  for (j = 0; j < cim.ny; j++) {
    for (i = 0; i < cim.nx; i++) {
      int r = ((cim.r[i][j] * BINS) / 256.0);
      int g = ((cim.g[i][j] * BINS) / 256.0);
      int b = ((cim.b[i][j] * BINS) / 256.0);
      int k = r + BINS*g + BINS*BINS*b;
      h[k] += 1.0;
    }
  }

  // Normalisation
  for (i = 0 ; i < BINS*BINS*BINS; i++){
    h[i] /= ((float) cim.nx*cim.ny);
  }

  // Affichage du tableau au format standard
  if (print_default == 1){
    k=0;
    for (l = 0 ; l < BINS; l++) {
      for (j = 0 ; j < BINS; j++) {
	for (i = 0 ; i < BINS; i++) {
	  printf("%f ",h[k]);
	  k++;
	}
	printf("\n");
      }
      printf("\n");
    }
  }

  // Affichage du tableau au format libsvm
  if (print_libsvm == 1){
    k=0;
    printf("%d",k++);
    for (i = 0; i < BINS*BINS*BINS; i++){
      if (h[i] > 0){
	printf(" %d:%f",k,h[i]);
      }
      k++;
    }
    printf("\n");
  }

}

void print_color_plan (char *argv[]) {
  int i,j,n,nx,ny,nb;
  CIMAGE cim;
  /*------------------------------------------------*/
  /* lecture d'une image requ�te                    */
  /*------------------------------------------------*/
  read_cimage(argv[1],&cim);
  /*------------------------------------------------*/
  /* affichage des valeurs pour le premier bloc 8x8 */
  /* comme exemple de traitement                    */
  /*------------------------------------------------*/
  printf("Largeur de l'image : %d\n",cim.nx);
  printf("Heuteur de l'image : %d\n",cim.ny);
  printf("Plan rouge du premier bloc 8x8 :\n");
  for (j = 0; j < 8; j++) {       /* ligne par ligne */
    printf("  ");
    for (i = 0; i < 8; i++) {   /* pixel par pixel */
      printf("%4d",cim.r[i][j]);
    }
    printf("\n");
  }
  printf("Plan vert du premier bloc 8x8 :\n");
  for (j = 0; j < 8; j++) {       /* ligne par ligne */
    printf("  ");
    for (i = 0; i < 8; i++) {   /* pixel par pixel */
      printf("%4d",cim.g[i][j]);
    }
    printf("\n");
  }
  printf("Plan bleu du premier bloc 8x8 :\n");
  for (j = 0; j < 8; j++) {       /* ligne par ligne */
    printf("  ");
    for (i = 0; i < 8; i++) {   /* pixel par pixel */
      printf("%4d",cim.b[i][j]);
    }
    printf("\n");
  }
  /*------------------------------------------------*/
}

int main(int argc, char *argv[]) {

  print_histogram(argv,0,1);

  //print_color_plan(argv);
  exit(0);
}
