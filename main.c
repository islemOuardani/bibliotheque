#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "directeur.h"
#include "date.h"
#include "adherent.h"
#include "document.h"
#define numEtab "Institut Superieur des Sciences Appliquees et Technologies de Sousse"


int bibliotheque()
{
	int x,y,m,h;
	printf("\n\n\t\tBonjour et bienvenue a la bibliotheque\n%s\n\n\n",numEtab);
	x=choisirUtilisateur();
	if(x==-1)
		return 0;
	else if (x==1)
	{
		y=menuDirecteur();
	}
	else
	{
		adherent* tete;
		document* tDoc;
		m=verifierMaj();
		y=menuResponsable();
		switch(y)
		{
			case 1:{
				printf("\n\n\nAjouter: \n\t1)Etudiants\n\t2)Enseignants\n\t3)Visiteurs\n");
				scanf("%d",&h);
				switch(h)
				{
					case 1:{
						tete=remplir("etudiant");
					    remplirfich(tete,"etudiant");
					    free(tete);
						break;
					}
					case 2:{
						tete=remplir("enseignant");
						remplirfich(tete,"enseignant");
				    	free(tete);
						break;
					}
					case 3:{
						tete=remplir("visiteur");
				    	remplirfich(tete,"visteur");
				    	free(tete);							
						break;
					}	
				}
					break;
			}
				case 2: {
				    printf("\n\n\nAjouter: \n\t1)Livres\n\t2)Articles\n\t3)Magazine\n");
					scanf("%d",&h);
					switch(h)
					{
					    case 1:{
							tDoc=remplirDoc("livre");
					    	remplirfichDoc(tDoc,"livre");
					    	free(tDoc);
							break;
						}
						case 2:{
							tDoc=remplirDoc("article");
					    	remplirfichDoc(tDoc,"article");
					    	free(tDoc);
							break;
						}
						case 3:{
							tDoc=remplirDoc("magazine");
					    	remplirfichDoc(tDoc,"magazine");
					    	free(tDoc);
							break;
						}
					}
					break;
				}
				case 3: {
					supprimerAdh();
					break;
				}
				break;
				case 9: affichDocs();
				case 0: {
				    x=bibliotheque();
				    if (x==0)
				    return 0;
					break;
				}

			}
		//}while(y>=0);
	}
}

int main()
{
	int x,h;
	FILE *fRes=NULL;
	fRes=fopen("responsable.txt","r");
	system("COLOR 8F");
	if(fRes==NULL)
	{
		fclose(fRes);
		printf("\t\tCher directeur bienvenue sur notre application! \n\n\n\tPriere de vous connecter afin d'enregistrer votre etablissement.\n\n\n");
		x=loginDirecteur();
		if(x==1)
		{
			remplirResponsable();
			return 0;
		}
		else
		     return 0;
	}
	else
	{
		fclose(fRes);
	    h=bibliotheque();
	    if(h==0)
	    return 0;
    }
}
