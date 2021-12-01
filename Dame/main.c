/*Auteurs : GHAMRI - GUYOLLOT
 *Date de création : 09/04/2020
 *Date de modification : 14/04/2020*/


#include "graphique.h"
#include "dame.h"

int main(){
	Position pos = 0;
	int souris_x, souris_y;
	int nb_dame;
	Case c;
	int touche;
	int couple[8];
	init_couple(couple);
	nb_dame = 0;
	MEVENT ev;
	initscr();
	start_color();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
	while(1){
		affiche_grille_position(pos);
		affiche_demande_verification();
		touche = getch();
		if(touche == KEY_MOUSE && getmouse(&ev) == OK){
			souris_x = ev.x;
			souris_y = ev.y;
			if(souris_x >= COLS - 22 && souris_x <= COLS - 5 && souris_y <= 3 && souris_y >= 0){
				clear();
				affiche_grille_position(pos);
				affiche_resultat_verification(pos);
				refresh();
				usleep(1000000);
				if(est_sans_attaques_mutuelle(pos) && nb_dame == 8)
					break;
			}
			souris_x -= (COLS/2 - 12);
			souris_x /= 3;
			souris_y -= (LINES/2 - 4);
			if(souris_y >= 0 && souris_y <= 7 && souris_x >= 0 && souris_x <= 7){
				c = couple[souris_y] + souris_x;
				if(est_case_occupee(pos, c) && nb_dame > 0){
					retirer_dame_position(&pos, c);
					nb_dame -= 1;
				}
				else if(nb_dame < 8){
					placer_dame_position(&pos, c);
					nb_dame += 1;
				}
				clear();
			}
		}
		refresh();
	}
	clear();
	affiche_victoire();
	refresh();
	usleep(3000000);
	endwin();
	return 1;
}