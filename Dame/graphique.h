/*Auteurs : GHAMRI - GUYOLLOT
 *Date de création : 09/04/2020
 *Date de modification : 14/04/2020*/

#ifndef __GRAPHIQUE__
#define __GRAPHIQUE__

#include "structures.h"
#include "include.h"

/*Fonction affichant à l'aide de ncurses les lignes pairs de l'échiquier*/ 
void afficher_ligne_position_pair(Position pos, int ligne, int cases);

/*Fonction affichant à l'aide de ncurses les lignes impairs de l'échiquier*/
void afficher_ligne_position_impair(Position pos, int ligne, int cases);

/*Fonction se servant des deux précédentes afin d'afficher l'échiquier complet sur le terminal à l'aide de ncurses*/
void affiche_grille_position(Position pos);

/*Fonction affichant une case de vérification disponible à tout instant de jeu*/
void affiche_demande_verification();

/*Fonction affichant la case de vérification en vert si le résultat de la vérification est bonne
(donc aucune dame ne s'attaque), et en rouge sinon*/
void affiche_resultat_verification(Position pos);

/*Fonction affichant un message lors de la victoire du joueur*/
void affiche_victoire();


#endif