/*Auteurs : GHAMRI - GUYOLLOT
 *Date de création : 09/04/2020
 *Date de modification : 14/04/2020*/

#ifndef __DAME__
#define __DAME__

#include "structures.h"
#include "include.h"

/*Fonction vérifiant si une case de l'échiquier est occupé par une dame, renvoyant 1 si c'est le cas, 0 sinon*/
int est_case_occupee(Position pos, Case c);

/*Fonction plaçant une dame sur l'échiquier sur la case choisie*/
void placer_dame_position(Position *pos, Case c);

/*Fonction affichant une ligne de l'échiquier sur la sortie standard*/
void afficher_ligne(Position pos, int cases);

/*Fonction affichant l'échiquier complet sur la sortie standrad*/
void afficher_position(Position pos);

/*Fonction calculant les cases sensibles à une attaque d'une dame se trouvant sur une certaine case*/
void calculer_cases_attaques(Position *pos, Case c);

/*Fonction initialisant le tableau des cases attaquées par chaque case de l'échiquier*/
void init_tab_cases_attaquees(Position tab[64]);

/*Fonction vérifiant que les dames présentes sur l'échiquier ne s'attaquent pas mutuellement, renvoie 1 si c'est le cas, 0 sinon*/
int est_sans_attaques_mutuelle(Position pos);

/*Fonction initialisant un tableau qui à chaque ligne associe la case la plus à gauche*/
void init_couple(int tab[8]);

/*Fonction permettant de retirer une dame présente sur l'échiquier*/
void retirer_dame_position(Position *pos, Case c);

#endif