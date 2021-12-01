/*Auteurs : GHAMRI - GUYOLLOT
 *Date de création : 09/04/2020
 *Date de modification : 14/04/2020*/

#include "graphique.h"

void afficher_ligne_position_pair(Position pos, int ligne, int cases){
	int i;
	init_pair(1, COLOR_RED, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_BLUE);
	for(i = 0; i < 8; i++){
		if(i % 2 == 0)
			attron(COLOR_PAIR(1));
		else
			attron(COLOR_PAIR(2));
		if(pos & ((Position)1 << (i + cases)))
			mvprintw(LINES/2 - 4 + ligne, COLS/2 - 12 + 3*i, " X ");
		else
			mvprintw(LINES/2 - 4 + ligne, COLS/2 - 12 + 3*i, "   ");
	}
	attroff(COLOR_PAIR(1));
	attroff(COLOR_PAIR(2));
}

void afficher_ligne_position_impair(Position pos, int ligne, int cases){
	int i;
	init_pair(1, COLOR_RED, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_BLUE);
	for(i = 0; i < 8; i++){
		if(i % 2 == 0)
			attron(COLOR_PAIR(2));
		else
			attron(COLOR_PAIR(1));
		if(pos & ((Position)1 << (i + cases)))
			mvprintw(LINES/2 - 4 + ligne, COLS/2 - 12 + 3*i, " X ");
		else
			mvprintw(LINES/2 - 4 + ligne, COLS/2 - 12 + 3*i, "   ");
	}
	attroff(COLOR_PAIR(1));
	attroff(COLOR_PAIR(2));
}


void affiche_grille_position(Position pos){
	int i;
	int cases;
	cases = 56;
	char lettre;
	int nombre;
	lettre = 'A';
	nombre = 8;
	for(i = 0; i < 8; i++){
		mvprintw(LINES/2 - 4 + i, COLS/2 - 14, "%d", nombre);
		nombre--;
		mvprintw(LINES/2 + 4, COLS/2 - 12 + 3*i, " %c ", lettre);
		lettre++;
	}
	for(i = 0; i < 8; i++){
		if(i % 2 == 0)
			afficher_ligne_position_pair(pos, i, cases);
		else
			afficher_ligne_position_impair(pos, i, cases);
		cases -= 8;
	}
}

void affiche_demande_verification(){
	mvprintw(0, COLS - 21, "                ");
	mvprintw(1, COLS - 21, " VERIFICATION ?   ");
	mvprintw(2, COLS - 21, "                ");
	mvvline(0, COLS - 22, 0, 3);
	mvhline(3, COLS - 21, 0, 17);
	mvvline(0, COLS - 5, 0, 3);
	mvaddch(3, COLS - 22, ACS_LLCORNER);
	mvaddch(3, COLS-5, ACS_LRCORNER);
}

void affiche_resultat_verification(Position pos){
	init_pair(3, COLOR_BLACK, COLOR_GREEN);
	init_pair(4, COLOR_BLACK, COLOR_RED);
	if(est_sans_attaques_mutuelle(pos) == 0)
		attron(COLOR_PAIR(4));
	else
		attron(COLOR_PAIR(3));
	mvprintw(0, COLS - 21, "                ");
	mvprintw(1, COLS - 21, " VERIFICATION ?  ");
	mvprintw(2, COLS - 21, "                ");
	mvvline(0, COLS - 22, 0, 3);
	mvhline(3, COLS - 21, 0, 17);
	mvvline(0, COLS - 5, 0, 3);
	mvaddch(3, COLS - 22, ACS_LLCORNER);
	mvaddch(3, COLS-5, ACS_LRCORNER);
	attroff(COLOR_PAIR(3));
	attroff(COLOR_PAIR(4));
}


void affiche_victoire(){
	mvprintw(LINES/2 - 1, COLS/2 - 3, "Bravo !");
	mvprintw(LINES/2, COLS/2 - 20, "Vous avez placé correctement vos 8 dames !");
}