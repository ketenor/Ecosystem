#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ecosys.h"

#define NB_PROIES 20
#define NB_PREDATEURS 20

/* Parametres globaux de l'ecosysteme (externes dans le ecosys.h)*/
float p_ch_dir=0.01;
float d_proie=1;
float d_predateur=1;
float p_manger=0.2;
float p_reproduce=0.01;
float energie=50;


int main(void) {
  srand(time(NULL));
  Animal *liste_proie = creer_animal(rand()%SIZE_X,rand()%SIZE_Y,energie) ;
  Animal *liste_predateur = creer_animal(rand()%SIZE_X,rand()%SIZE_Y,energie);
  int nb_proies = NB_PROIES, nb_predateurs = NB_PREDATEURS;
  int i = 0;
  int y = 0;
  while(i < NB_PROIES-1)
  {
	  liste_proie=ajouter_en_tete_animal(liste_proie, creer_animal(rand()%SIZE_X, rand()%SIZE_Y, energie));
	  i++;
  }
  while(y < NB_PREDATEURS-1)
  {
	  liste_predateur=ajouter_en_tete_animal(liste_predateur, creer_animal(rand()%SIZE_X, rand()%SIZE_Y, energie));
	  y++;
  }

  afficher_ecosys(liste_proie,liste_predateur);
  reproduce(&liste_proie);
  reproduce(&liste_predateur);
  bouger_animaux(liste_proie);
  bouger_animaux(liste_predateur);
  afficher_ecosys(liste_proie,liste_predateur);

  liberer_liste_animaux(liste_proie);
  liberer_liste_animaux(liste_predateur);

  return 0;
}
