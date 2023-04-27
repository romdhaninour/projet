#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enigme.h"


int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *ecran = SDL_SetVideoMode(1080, 900 , 32, SDL_HWSURFACE);
    SDL_Event event;
    enigme e;
    initialisation_enigme(&e, "fichier.txt");

    printf("%d", e.aleatoire);

    int cond = 1; 
    int scan_res = 0;
    int continuer = 1;
    while (continuer)
    {
        if (cond == 1) {
            initialisation_enigme(&e, "fichier.txt");
            affichage_enigme(e, ecran);
            cond = 0;
        }
        if (scan_res == 1) {
            afficher_resultat(ecran, &e);
            cond = 1; 
            scan_res = 0;
        }
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    continuer = 0;
                    break;
                case SDL_KEYDOWN:
                    if (cond == 0) { 
                        reponse_utilisateur(&e, event);
                        if (e.affiche == 1) {
                            scan_res = 1;
                        }
                    }
                    break;
            }
        }
    }
    SDL_FreeSurface(e.image);
    SDL_FreeSurface(e.image_gagner);
    SDL_FreeSurface(e.image_perdu);
    SDL_Quit();
    return 0;
}



