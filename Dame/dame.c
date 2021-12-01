/*Auteurs : GHAMRI - GUYOLLOT
 *Date de création : 09/04/2020
 *Date de modification : 14/04/2020*/

#include "dame.h"

int est_case_occupee(Position pos, Case c){
	if((pos & ((Position)1 << c)) != 0)
		return 1;
	return 0;
}

void placer_dame_position(Position *pos, Case c){
	*pos = *pos | ((Position)1 << c);
}

void afficher_ligne(Position pos, int cases){
	int i;
	for(i = 0; i < 8; i++){
		if(pos & ((Position)1 << (i + cases)))
			printf("+ ");
		else
			printf(". ");
	}
	printf("\n");
}

void afficher_position(Position pos){
	int i;
	for(i = 56; i >= 0; i-=8){
		afficher_ligne(pos, i);
	}
}

void calculer_cases_attaques(Position *pos, Case c){
	Case i;

	if(c % 8 != 0){
		for(i = c - 1; i%8 != 0; i--)
			placer_dame_position(pos, i);
		placer_dame_position(pos, i);
	}
	
	if((c + 1) % 8 != 0){
		for(i = c + 1; (i + 1) % 8 != 0; i++)
			placer_dame_position(pos, i);
		placer_dame_position(pos, i);
	}

	if(c >= 8){
		for(i = c - 8; i >= 8; i -= 8){
			placer_dame_position(pos, i);
		}
		placer_dame_position(pos, i);
	}

	if(c < 56){
		for(i = c + 8; i <= 56; i += 8)
			placer_dame_position(pos, i);
		placer_dame_position(pos, i);
	}

	if(c < 56 && (c+1) % 8 != 0){
		for(i = c + 9; i < 56 && (i + 1) % 8 != 0; i += 9)
			placer_dame_position(pos, i);
		placer_dame_position(pos, i);
	}

	if(c % 8 != 0 && c < 56){
		for(i = c + 7; i % 8 != 0 && i < 56; i += 7)
			placer_dame_position(pos, i);
		placer_dame_position(pos, i);
	}

	if(c % 8 != 0 && c > 7){
		for(i = c - 9; i % 8 != 0 && i > 7; i -= 9)
			placer_dame_position(pos, i);
		placer_dame_position(pos, i);
	}

	if(c > 7 && (c + 1) % 8 != 0){
		for(i = c - 7; i > 7 && (i + 1) % 8 != 0; i -= 7)
			placer_dame_position(pos, i);
		placer_dame_position(pos, i);
	}
	*pos = *pos & ~((Position)1 << c);
}


void init_tab_cases_attaquees(Position tab[64]){
	Case c;
	for(c = 0; c < 64; c++){
		calculer_cases_attaques(&tab[c], c);
	}
}

int est_sans_attaques_mutuelle(Position pos){
	Position attaques;
	attaques = 0;
	int i;
	for(i = 0; i < 64; i++){
		if(est_case_occupee(pos, i)){
			calculer_cases_attaques(&attaques, i);
		}
	}
	if(pos & attaques)
		return 0;
	return 1;
}

void init_couple(int tab[8]){
	int ordonnee;
	int ligne;
	ordonnee = 56;
	ligne = 0;
	for(ligne = 0; ligne < 8; ligne++){
		tab[ligne] = ordonnee;
		ordonnee -= 8;
	}
}

void retirer_dame_position(Position *pos, Case c){
	*pos = *pos & ~((Position)1 << c);
}
