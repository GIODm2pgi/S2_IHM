#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <math.h>

#include "rdjpeg.h"

#define BINS 4

void print_histogram (char *argv[]) {
	int i,j,k,l,n,nx,ny,nb;
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

	float h[BINS*BINS*BINS] = {};

	for (j = 0; j < cim.nx; j++) {       /* ligne par ligne */
		for (i = 0; i < cim.ny; i++) {   /* pixel par pixel */
			int r = ((int) cim.r[i][j] * BINS) / 256;
			int g = ((int) cim.g[i][j] * BINS) / 256;
			int b = ((int) cim.b[i][j] * BINS) / 256;
			int k = r + BINS*g + BINS*BINS*b;
			h[k] += 1.0;
		}
	}

	k=0;
	for (l = 0 ; l < BINS; l++) {
		for (j = 0 ; j < BINS; j++) {
			for (i = 0 ; i < BINS; i++) {
				printf("%f ",h[k] / ((float) cim.nx*cim.ny));
				k++;
			}
			printf("\n");
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

	print_histogram(argv);

	//print_color_plan(argv);
	exit(0);
}
