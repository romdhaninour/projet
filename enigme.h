#ifndef ENIGME_H
#define ENIGME_H

#define NB_QUESTIONS 3

typedef struct 
{

SDL_Surface *image,*image_gagner,*image_perdu;
SDL_Rect pos,posBG;
int aleatoire;
int votre_reponse;
int bonne_reponse;
int affiche; 
int answered_correctly;
int reponses_correctes[NB_QUESTIONS];
}enigme;


void initialisation_enigme(enigme *e,char *nom_fichier);
void affichage_enigme(enigme e, SDL_Surface *ecran);
int reponse_utilisateur(enigme *enig,SDL_Event event);
void afficher_resultat(SDL_Surface *ecran,enigme *e);

#endif



