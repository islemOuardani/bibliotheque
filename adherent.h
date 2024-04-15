#ifndef ADHERENT_H
#define ADHERENT_H

typedef struct adherent{
	char nom[20];
	char prenom[20];
	int id;
	char adresse[50];
	char type[15];
	int nbrEmpruntC;
	int nbrEmpruntP;
	struct adherent* adhSuiv;
}adherent;


int verifierid(adherent *tete,int id);
int verifierIdPre(int id);
void remplirfich(adherent* tete,char file[]);
adherent* chercherID(int id);
adherent* remplir(char type[]);
void supprimerAdh();
#endif
