
#ifndef DOCUMENT_H
#define DOCUMENT_H

typedef struct{
	char nomAuteur[40];
	char datePub[10];
}article;

typedef struct{
	char nomAuteur[40];
	char nomEditeur[40];
	char dateEdi[10];
}livre;

typedef struct{
	int  frequence;
}magazine;

typedef struct document{
	char titre [30];
	char localisation[20];
	int code;
	int nbrExp;
	article* art;
	livre* liv;
	magazine* mag;
	struct document* ds;
}document;

int verifieridDoc(document *tete,int code);
int verifierIdPreDoc(int code);
document* remplirDoc(char type[]);
void remplirfichDoc(document* tete,char file[]);
void affichDocs();
#endif
