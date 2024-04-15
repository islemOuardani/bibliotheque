#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date.h"

int verifierMaj()
{
	FILE* fichier;
	char date[10];
	char buffer[10];
	time_t timestamp = time( NULL );
    struct tm * pTime = localtime( & timestamp );
	fichier=fopen("date.txt","r");
	if(fichier == NULL)
	printf("Desole! Une erreure s'est produite! Merci d'essayer ulterieurement ou de contacter le service technique!");
    else
    {
    	fscanf(fichier,"%s",&date);
		fclose(fichier);
        strftime( buffer, 20, "%d/%m/%Y", pTime );
    	if(strcmp(date,buffer)==0)
    	{
		    return -1;
		}
    	else
		{
			fichier=fopen("date.txt","w");
			fprintf(fichier,"%s",buffer);
    	    fclose(fichier);
            return 1;
		}
	}
}
