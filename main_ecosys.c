#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ecosys.h"
#include <unistd.h>

#define NB_PROIES 20
#define NB_PREDATEURS 20
#define T_WAIT 40000


  /* Parametres globaux de l'ecosysteme (externes dans le ecosys.h)*/
float p_ch_dir=0.01;
float d_proie=1;
float d_predateur=1;
float p_manger=0.2;
float p_reproduce=0.01;
float energie=50;


int main(void) {
  srand(time(NULL));
  int i,j;

  Animal *les_proies = NULL;
  Animal *les_predateurs = NULL;

  for (i=0; i < NB_PREDATEURS; i++){
    ajouter_animal(rand()%SIZE_X, rand()%SIZE_Y, &les_predateurs);
  }
  for (j=0; j < NB_PREDATEURS; j++){
    ajouter_animal(rand()%SIZE_X, rand()%SIZE_Y, &les_proies);
  }


  while(1){
    clear_screen();
    afficher_ecosys(les_proies,les_predateurs);
    rafraichir_proies(&les_proies);
    rafraichir_predateurs(&les_predateurs,&les_proies);
    if (!les_proies)
	printf("Toutes les proies sont mortes\n");
    if (!les_predateurs)
	printf("Tous les predateurs sont morts\n");
    if (!les_proies && !les_predateurs)	break;
    usleep(T_WAIT);
  }
  return 0;
}
