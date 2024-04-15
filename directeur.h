
#ifndef DIRECTEUR_H
#define DIRECTEUR_H

typedef struct
{
	int ID;
	char MDP[30];
	char etablissement[50];
	int enregistre;
}directeur;

typedef struct{
	int ID;
	char MDP[30];
}responsable;

void remplirDirecteurs();
int rechercherDirecteur(int ID, char MDP[]);
int loginDirecteur();
int menuDirecteur();
void ajouterResponsable();
void remplirResponsables();
void afficherResponsables();
int rechercherResponsable(int ID, char mdp[]);
int loginResponsable();
int menuResponsable();
int choisirUtilisateur();



#endif
