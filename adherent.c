#include <stdio.h>
#include <stdlib.h>
#include "adherent.h"
#include <string.h>

int verifierid(adherent *tete,int id)
{
	adherent* i=tete;
	int e=0;
	while(i!=NULL&&e!=1)
	{
		if(i->id==id)
			e=1;
		else
		i=i->adhSuiv;
	}
	return e;
}

int verifierIdPre(int id)
{
	adherent* li;
	FILE* fichier=NULL;
	fichier=fopen("etudiant","r");
	if(fichier!=NULL)
	{
		li=(adherent*)malloc(sizeof(adherent));
		do
		{
			fscanf(fichier,"%s\t%s\n%s\t%d\n%s\n%d\t%d\n\n\n",&li->nom,&li->prenom,&li->type,&li->id,&li->adresse,&li->nbrEmpruntP,&li->nbrEmpruntC);
			if(li->id==id)
			return 1;
		}while(!feof(fichier));
		fclose(fichier);
		free(li);
	}
	fichier=fopen("enseignant","r");
	if(fichier!=NULL)
	{
		li=(adherent*)malloc(sizeof(adherent));
		do
		{
			fscanf(fichier,"%s\t%s\n%s\t%d\n%s\n%d\t%d\n\n\n",&li->nom,&li->prenom,&li->type,&li->id,&li->adresse,&li->nbrEmpruntP,&li->nbrEmpruntC);
			if(li->id==id)
			return 2;
		}while(!feof(fichier));
		fclose(fichier);
		free(li);
	}
	fichier=fopen("visiteur","r");
	if(fichier!=NULL)
	{
		li=(adherent*)malloc(sizeof(adherent));
		do
		{
			fscanf(fichier,"%s\t%s\n%s\t%d\n%s\n%d\t%d\n\n\n",&li->nom,&li->prenom,&li->type,&li->id,&li->adresse,&li->nbrEmpruntP,&li->nbrEmpruntC);
			if(li->id==id)
			return 3;
		}while(!feof(fichier));
		fclose(fichier);
		free(li);
	}
	return 0;
}

adherent* chercherID(int id)
{
	FILE* fichier;
	adherent* a;
	int x;
	if(verifierIdPre(id)==1)
	{
		fichier=fopen("etudiant","r");
		a=(adherent*)malloc(sizeof(adherent));
		do
		{
			fscanf(fichier,"%s\t%s\n%s\t%d\n%s\n%d\t%d\n\n\n",&a->nom,&a->prenom,&a->type,&a->id,&a->adresse,&a->nbrEmpruntP,&a->nbrEmpruntC);
			if(a->id==id)
			return (a);
		}while(!feof(fichier));
		fclose(fichier);
	}
	if(verifierIdPre(id)==2)
	{
		fichier=fopen("enseignant","r");
		a=(adherent*)malloc(sizeof(adherent));
		do
		{
			fscanf(fichier,"%s\t%s\n%s\t%d\n%s\n%d\t%d\n\n\n",&a->nom,&a->prenom,&a->type,&a->id,&a->adresse,&a->nbrEmpruntP,&a->nbrEmpruntC);
			if(a->id==id)
			return (a);
		}while(!feof(fichier));
		fclose(fichier);
	}
	if(verifierIdPre(id)==1)
	{
		fichier=fopen("visiteur","r");
		a=(adherent*)malloc(sizeof(adherent));
		do
		{
			fscanf(fichier,"%s\t%s\n%s\t%d\n%s\n%d\t%d\n\n\n",&a->nom,&a->prenom,&a->type,&a->id,&a->adresse,&a->nbrEmpruntP,&a->nbrEmpruntC);
			if(a->id==id)
			return (a);
		}while(!feof(fichier));
		fclose(fichier);
	}
}

adherent* remplir(char type[])
{
	int nbAdh,i;
	adherent *tAdh,*ei,*eii;
	printf("\nSaisir le nombre des %ss: ",type);
	scanf("%d",&nbAdh);
	if(nbAdh>0)
	{
		tAdh=(adherent*)malloc(sizeof(adherent));
		printf("\n\nNom : ");
		scanf("%s",&tAdh->nom);
		printf("Prenom : ");
	    scanf("%s",&tAdh->prenom);
		do
		{
		    printf("ID : ");
		    scanf("%d",&tAdh->id);
		}while(verifierIdPre(tAdh->id)==1||verifierIdPre(tAdh->id)==2||verifierIdPre(tAdh->id)==3);
		printf("Adresse : ");
		scanf("%s",&tAdh->adresse);
		strcpy(tAdh->type, type);
		tAdh->nbrEmpruntC=0;
		tAdh->nbrEmpruntP=0;
		tAdh->adhSuiv=NULL;
		eii=tAdh;
		for(i=2;i<=nbAdh;i++)
		{
			ei=(adherent*)malloc(sizeof(adherent));
		    printf("\n\nNom : ");
		    scanf("%s",&ei->nom);
		    printf("Prenom : ");
		    scanf("%s",&ei->prenom);
		    do
			{
				printf("ID : ");
		        scanf("%d",&ei->id);
			}while((verifierid(tAdh,ei->id)==1)||verifierIdPre(tAdh->id)==1||verifierIdPre(tAdh->id)==2||verifierIdPre(tAdh->id)==3);
		    printf("Adresse : ");
		    scanf("%s",&ei->adresse);
		    strcpy(ei->type, type);
		    ei->nbrEmpruntC=0;
		    ei->nbrEmpruntP=0;
		    ei->adhSuiv=NULL;
		    eii->adhSuiv=ei;
		    eii=ei;
		}
	}
	return (tAdh);
}

void remplirfich(adherent* tete,char file[])
{
	FILE* fichier=NULL;
	adherent* li=tete;
	fichier=fopen(file,"a");
	if(fichier==NULL)
	    printf("Desole! Une erreure s'est produite! Merci d'essayer ulterieurement ou de contacter le service technique!");
	else
	{
		while(li!=NULL)
		{
			fprintf(fichier,"%s\t%s\n%s\t%d\n%s\n%d\t%d\n\n\n",li->nom,li->prenom,li->type,li->id,li->adresse,li->nbrEmpruntP,li->nbrEmpruntC);
			li=li->adhSuiv;
		}
		fclose(fichier);
	}
}

void supprimerAdh()
{
	FILE *fichier,*ftemp;
	int id,x;
	adherent *a,*ai;
	printf("\n\n\n\n\n\nSaisir l'ID de l'adherent a supprimer : ");
	scanf("%d",&id);
	if(verifierIdPre(id)==0)
	printf("Desole cet adherent n'existe pas! ");
	else if(verifierIdPre(id)==1)
	{
		a=chercherID(id);
		printf("Etes-vous sur de supprimer %s %s de la liste des étudiants ?\n 1) OUI\n 2) NON\n",a->prenom,a->nom);
        scanf("%d",&x);
		if(x==1)
		{
			fichier=fopen("etudiant","r");
		    ftemp=fopen("etudianttemp","w");
		    ai=(adherent*)malloc(sizeof(adherent));
		    do
		    {
		    	fscanf(fichier,"%s\t%s\n%s\t%d\n%s\n%d\t%d\n\n\n",&ai->nom,&ai->prenom,&ai->type,&ai->id,&ai->adresse,&ai->nbrEmpruntP,&ai->nbrEmpruntC);
		    	if(ai->id!=id)
		    	{
		    		fprintf(ftemp,"%s\t%s\n%s\t%d\n%s\n%d\t%d\n\n\n",ai->nom,ai->prenom,ai->type,ai->id,ai->adresse,ai->nbrEmpruntP,ai->nbrEmpruntC);
				}
			}while(feof(fichier));
		    fclose(fichier);
		    fclose(ftemp);
		    remove("etudiant");
		    rename("etudianttemp","etudiant");
		}
	}
}
