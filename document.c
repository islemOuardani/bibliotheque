#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "document.h"

int verifieridDoc(document *tete,int code)
{
	document* i=tete;
	int e=0;
	while(i!=NULL&&e!=1)
	{
		if(i->code==code)
			e=1;
		else
		i=i->ds;
	}
	return e;
}

int verifierIdPreDoc(int code)
{
	document* li;
	FILE* fichier=NULL;
	fichier=fopen("livre","r");
	if(fichier!=NULL)
	{
		li=(document*)malloc(sizeof(document));
		li->liv=(livre*)malloc(sizeof(livre));
        do
		{
			fscanf(fichier,"%s\n%s\n%d\n%d\n%s\n%s\n%s\n\n\n",&li->titre,&li->localisation,&li->code,&li->nbrExp,&li->liv->nomAuteur,&li->liv->nomEditeur,&li->liv->dateEdi);
			if(li->code==code)
			return 1;
		}while(!feof(fichier));
		fclose(fichier);
		free(li);
	}
	fichier=fopen("article","r");
	if(fichier!=NULL)
	{
		li=(document*)malloc(sizeof(document));
		li->art=(article*)malloc(sizeof(article));
		do
		{
			fscanf(fichier,"%s\n%s\n%d\n%d\n%s\n%s\n\n\n",&li->titre,&li->localisation,&li->code,&li->nbrExp,&li->art->nomAuteur,&li->art->datePub);
			if(li->code==code)
			return 1;
		}while(!feof(fichier));
		fclose(fichier);
		free(li);
	}
	fichier=fopen("magazine","r");
	if(fichier!=NULL)
	{
		li=(document*)malloc(sizeof(document));
		li->mag=(magazine*)malloc(sizeof(magazine));
		do
		{
			fscanf(fichier,"%s\n%s\n%d\n%d\n%d\n\n\n",&li->titre,&li->localisation,&li->code,&li->nbrExp,&li->mag->frequence);
			if(li->code==code)
			return 1;
		}while(!feof(fichier));
		fclose(fichier);
	}
	return 0;
}

document* remplirDoc(char type[])
{
	int nbDoc,i;
	document *tDoc,*di,*dii;
	printf("\nSaisir le nombre des %ss a ajouter: ",type);
	scanf("%d",&nbDoc);
	if(nbDoc>0)
	{
		tDoc=(document*)malloc(sizeof(document));
		printf("\n\nTitre : ");
		scanf("%s",&tDoc->titre);
		printf("Localisation : ");
	    scanf("%s",&tDoc->localisation);
		do
		{
		    printf("Code : ");
		    scanf("%d",&tDoc->code);
		}while(verifierIdPreDoc(tDoc->code)==1);
		printf("Nombre d'exemplaires : ");
		scanf("%d",&tDoc->nbrExp);
		if(strcmp(type,"livre")==0)
		{
			tDoc->mag=NULL;
			tDoc->art=NULL;
			tDoc->liv=(livre*)malloc(sizeof(livre));
			printf("Nom de l'auteur : ");
			scanf("%s",&tDoc->liv->nomAuteur);
			printf("Nom d'editeur : ");
			scanf("%s",&tDoc->liv->nomEditeur);
			printf("Date d'edition : ");
			scanf("%s",&tDoc->liv->dateEdi);
		}
		else if(strcmp(type,"article")==0)
		{
			tDoc->liv=NULL;
			tDoc->mag=NULL;
			tDoc->art=(article*)malloc(sizeof(article));
			printf("Nom d'auteur : ");
			scanf("%s",&tDoc->art->nomAuteur);
			printf("Date de publication : ");
			scanf("%s",&tDoc->art->datePub);
		}
		else if(strcmp(type,"magazine")==0)
		{
		    tDoc->liv=NULL;
		    tDoc->art=NULL;
		    tDoc->mag=(magazine*)malloc(sizeof(magazine));
		    printf("Frequence de parution : ");
		    scanf("%d",&tDoc->mag->frequence);
		}
		tDoc->ds=NULL;
		dii=tDoc;
		for(i=2;i<=nbDoc;i++)
		{
			di=(document*)malloc(sizeof(document));
		    printf("\n\nTitre : ");
		    scanf("%s",&di->titre);
		    printf("Localisation : ");
	        scanf("%s",&di->localisation);
		    do
		    {
		        printf("Code : ");
		        scanf("%d",&di->code);
		    }while(verifierIdPreDoc(di->code)==1||verifieridDoc(tDoc,di->code)==1);
		    printf("Nombre d'exemplaires : ");
		    scanf("%d",&di->nbrExp);
		    if(strcmp(type,"livre")==0)
		    {

				di->mag=NULL;
			    di->art=NULL;
				di->liv=(livre*)malloc(sizeof(livre));
			    printf("Nom de l'auteur : ");
			    scanf("%s",&di->liv->nomAuteur);
			    printf("Nom d'editeur : ");
			    scanf("%s",&di->liv->nomEditeur);
			    printf("Date d'edition : ");
			    scanf("%s",&di->liv->dateEdi);
		    }
		    else if(strcmp(type,"article")==0)
		    {
			    di->liv=NULL;
			    di->mag=NULL;
			    di->art=(article*)malloc(sizeof(article));
			    printf("Nom d'auteur : ");
			    scanf("%s",&di->art->nomAuteur);
			    printf("Date de publication : ");
			    scanf("%s",&di->art->datePub);
		    }
		    else if(strcmp(type,"magazine")==0)
		    {
		        di->liv=NULL;
		        di->art=NULL;
		        di->mag=(magazine*)malloc(sizeof(magazine));
		        printf("Frequence de parution : ");
		        scanf("%d",&di->mag->frequence);
		    }
		    di->ds=NULL;
		    dii->ds=di;
		    dii=di;
		}
	}
	return (tDoc);
}

void remplirfichDoc(document* tete,char file[])
{
	FILE* fichier=NULL;
	document* pi=tete;
	fichier=fopen(file,"a");
	if(fichier==NULL)
	    printf("Desole! Une erreure s'est produite! Merci d'essayer ulterieurement ou de contacter le service technique!");
	else
	{
		if(strcmp(file,"livre")==0)
		{
			while(pi!=NULL)
		    {
			    fprintf(fichier,"%s\n%s\n%d\n%d\n%s\n%s\n%s\n\n\n",pi->titre,pi->localisation,pi->code,pi->nbrExp,pi->liv->nomAuteur,pi->liv->nomEditeur,pi->liv->dateEdi);
   	            pi=pi->ds;
		    }
	    }
	    else if(strcmp(file,"article")==0)
	    {
	    	while(pi!=NULL)
		    {
			    fprintf(fichier,"%s\n%s\n%d\n%d\n%s\n%s\n\n\n",pi->titre,pi->localisation,pi->code,pi->nbrExp,pi->art->nomAuteur,pi->art->datePub);
   	            pi=pi->ds;
		    }
		}
		else if(strcmp(file,"magazine")==0)
		{
			while(pi!=NULL)
		    {
			    fprintf(fichier,"%s\n%s\n%d\n%d\n%d\n\n\n",pi->titre,pi->localisation,pi->code,pi->nbrExp,pi->mag->frequence);
   	            pi=pi->ds;
		    }
		}
		fclose(fichier);
	}
}

void affichDocs()
{
	FILE* fichier;
	document* li;
	fichier=fopen("livre","r");
	if(fichier!=NULL)
	{
		li=(document*)malloc(sizeof(document));
		li->liv=(livre*)malloc(sizeof(livre));
        do
		{
			fscanf(fichier,"%s\n%s\n%d\n%d\n%s\n%s\n%s\n\n\n",&li->titre,&li->localisation,&li->code,&li->nbrExp,&li->liv->nomAuteur,&li->liv->nomEditeur,&li->liv->dateEdi);
			printf("Livre: %s\n%s\n%d\n%d\n%s\n%s\n%s\n\n\n",li->titre,li->localisation,li->code,li->nbrExp,li->liv->nomAuteur,li->liv->nomEditeur,li->liv->dateEdi);
		}while(!feof(fichier));
		fclose(fichier);
		free(li);
	}
	fichier=fopen("article","r");
	if(fichier!=NULL)
	{
		li=(document*)malloc(sizeof(document));
		li->liv=(livre*)malloc(sizeof(livre));
        do
		{
			fscanf(fichier,"%s\n%s\n%d\n%d\n%s\n%s\n\n\n",&li->titre,&li->localisation,&li->code,&li->nbrExp,&li->art->nomAuteur,&li->art->datePub);
			printf("Article: %s\n%s\n%d\n%d\n%s\n%s\n\n\n",li->titre,li->localisation,li->code,li->nbrExp,li->art->nomAuteur,li->art->datePub);
		}while(!feof(fichier));
		fclose(fichier);
		free(li);
	}
	fichier=fopen("magazine","r");
	if(fichier!=NULL)
	{
		li=(document*)malloc(sizeof(document));
		li->mag=(magazine*)malloc(sizeof(magazine));
		do
		{
			fscanf(fichier,"%s\n%s\n%d\n%d\n%d\n\n\n",&li->titre,&li->localisation,&li->code,&li->nbrExp,&li->mag->frequence);
			printf("%s\n%s\n%d\n%d\n%d\n\n\n",li->titre,li->localisation,li->code,li->nbrExp,li->mag->frequence);
		}while(!feof(fichier));
		fclose(fichier);
	}

}

