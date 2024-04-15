#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directeur.h"

void remplirDirecteurs()
{
	FILE* fichier = NULL;
	directeur *di;
	int i;
	fichier=fopen("directeur.txt","w");
	if (fichier != NULL)
	{
		di=(directeur*)malloc(sizeof(directeur));
		for (i=0;i<3;i++)
		{
			printf("Saisir l' ID du directeur: ");
			scanf("%d",&di->ID);
			printf("Saisir le MDP: ");
			scanf("%s",&di->MDP);
			printf("Saisir l'etablissement: ");
			scanf("%s",&di->etablissement);
			printf("Enregistre?");
			scanf("%d",&di->enregistre);
			fprintf(fichier,"%d\n%s\n%s\n%d\n\n",di->ID,di->MDP,di->etablissement,di->enregistre);
		}
		free(di);
		fclose(fichier);
	}
}
int rechercherDirecteur(int ID, char MDP[])
{
	FILE* fichier = NULL;
	directeur di;
	fichier=fopen("directeur.txt","r");
	if (fichier != NULL)
	{
		do
		{
			fscanf(fichier,"%d\n%s\n%s\n%d\n\n",&di.ID,&di.MDP,&di.etablissement,&di.enregistre);
			if((strcmp(di.MDP,MDP)==0)&&(ID == di.ID))
			{
				return 1;
			}
		}while(!feof(fichier));
	    fclose(fichier);
	}
	else
	    printf("ERREUR! On peut pas ouvrir ce fichier! Merci de contacter le service technique!");
	return 0;
}
int loginDirecteur()
{
	int id,e=1;
	char mdp[30];
	//FILE* fichier = NULL;
	//fichier=fopen("directeur.txt","r");
	//if(fichier!=NULL)
	//{
		while(e!=3)
		{
			printf("LOGIN: ");
		    scanf("%d",&id);
		    printf("Mot de passe: ");
		    scanf("%s",&mdp);
		    if (rechercherDirecteur(id,mdp)==1)
		        return 1;
		    else
			{
		    	printf("Login ou mot de passe est incorrecte please try again\n\n\n\n\n\n\n\n\n");
		    	e=e+1;
			}
		}
		printf("LOGIN: ");
		scanf("%d",&id);
		printf("Mot de passe: ");
		scanf("%s",&mdp);
		if (rechercherDirecteur(id,mdp)==1)
		    return 1;
		else
		{
		    printf("Desole! Essayer dans quelques minutes.\n");
		    e=e+1;
		}
        //fclose(fichier);
	//}
	return 0;
}
int menuDirecteur()
{
	int x,i;
	x=loginDirecteur();
	if(x==1)
	{
		do
		{
			printf("\t\t1-Ajouter un responsable\n");
		    printf("\t\t2-Supprimer un responsable\n");
		    printf("\t\t0-LOGOUT\n");
		    scanf("%d",&i);
		}while(i<0&&i>2);
	}
	return i;
}
void ajouterResponsable()
{
	FILE* fichier = NULL;
	responsable *ri;
	int i;
	fichier=fopen("responsable.txt","w");
	if (fichier != NULL)
	{
		ri=(responsable*)malloc(sizeof(responsable));
		printf("Saisir l' ID du responsable: ");
		scanf("%d",&ri->ID);
		printf("Saisir le MDP: ");
		scanf("%s",&ri->MDP);
		fprintf(fichier,"%d\n%s\n\n",ri->ID,ri->MDP);
		free(ri);
		fclose(fichier);
	}
}
void remplirResponsable()
{
	responsable *ri;
	FILE* fichier=NULL;
	int i,n,j,e;
	printf("Saisir le nombre des responsable de la bibliotheque: ");
	scanf("%d",&n);
	ri=(responsable*)malloc(n*sizeof(responsable));
	for(i=0;i<n;i++)
	{
	    do
	    {
	    	e=0;
	    	printf("Saisir l'identifiant du responsable NUM%d : ",i+1);
		    scanf("%d",&ri[i].ID);
		    printf("Saisir le mot de passe du responsable: ");
		    scanf("%s",&ri[i].MDP);
		    for(j=0;j<i;j++)
		    {
		    	if(ri[j].ID==ri[i].ID)
		    	{
		    	    printf("Cet identifiant existe deja!\n");
		    	    e=1;
				}
			}
		}while(e==1);
	}
	fichier=fopen("responsable.txt","w");
	if(fichier==NULL)
	    printf("Desole un erreur s'est produit veuillez contacter notre staff technique, merci.");
	else
	{
		for(i=0;i<n;i++)
	    {
	    	fprintf(fichier,"%d\n%s\n\n",ri[i].ID,ri[i].MDP);
	    }
	    fclose(fichier);
	}
}
int rechercherResponsable(int ID, char MDP[])
{
	FILE* fichier = NULL;
	responsable ri;
	fichier=fopen("responsable.txt","r");
	if (fichier != NULL)
	{
		do
		{
			fscanf(fichier,"%d\n%s\n\n",&ri.ID,&ri.MDP);
			if((strcmp(ri.MDP,MDP)==0)&&(ID == ri.ID))
			{
				return 1;
			}
		}while(!feof(fichier));
	    fclose(fichier);
	}
	else
	    printf("ERREUR! On peut pas ouvrir ce fichier! Merci de contacter le service technique!");
	return 0;
}
int menuResponsable()
{
	int i;
	do
	{
		printf("\n\n\n\n\n\n\n\n\n-----------MENU-----------\n");
	    printf("\t1)Ajouter un adherent.\n");
	    printf("\t2)Ajouter un document.\n");
	    printf("\t3)Supprimer un adherent.\n");
	    printf("\t5)Supprimer un document.\n");
	    printf("\t6)Modifier un adherent.\n");
	    printf("\t7)Modifier un document.\n");
	    printf("\t8)Afficher la liste des adherents.\n");
	    printf("\t9)Afficher la liste des documents.\n");
	    printf("\t0)Logout.\n");
	    scanf("%d",&i);
	}while(i<0&&i>8);
	return i;
}
int choisirUtilisateur()
{
	int id,x,y,e=1;
	char mdp[30];
	while(e!=3)
	{
		printf("\n\nLOGIN: ");
	    scanf("%d",&id);
	    printf("\nMot de passe: ");
	    scanf("%s",&mdp);
   	    x=rechercherDirecteur(id,mdp);
   	    y=rechercherResponsable(id,mdp);
   	    if(x==1)
   	        return 1;
   	    else
	    {
            if(y==1)
                return 0;
            else
            {
		        printf("Login ou mot de passe est incorrecte please try again\n\n\n\n\n\n\n\n\n");
		        e=e+1;
		    }
	    }
	}
	printf("\n\nLOGIN: ");
	scanf("%d",&id);
	printf("\nMot de passe: ");
	scanf("%s",&mdp);
   	x=rechercherDirecteur(id,mdp);
   	y=rechercherResponsable(id,mdp);
   	if(x==1)
   	    return 1;
   	else
	{
        if(y==1)
            return 0;
		else
		{
		    printf("Desole! Essayer dans quelques minutes.\n");
		    e=e+1;
		    return -1;
		}
    }
}
