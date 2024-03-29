/********
Fichier: gestion_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/

#include <stdio.h>
#include "bibliotheque_images.h"

int image1[MAX_HAUTEUR][MAX_LARGEUR];
int image2[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB1[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB2[MAX_HAUTEUR][MAX_LARGEUR];

int main()
{
    int lignes1, colonnes1;
    int lignes2, colonnes2;
    int maxval;
    int histogramme[MAX_VALEUR+1];
    char nom1[MAX_CHAINE], nom2[MAX_CHAINE];
    struct MetaData metadonnees;

	int retour;
	
	strcpy(nom1, "Sherb1.pgm");
	strcpy(nom2, "Sherb2.pgm");

    printf("-> Debut!\n");

	// exemple d'appel de fonction
    retour = pgm_lire(nom1, image1, 
                      &lignes1, &colonnes1, 
                      &maxval, &metadonnees);

	// exemple de traitement d'un code de retour (erreur ou reussite)
	printf("-> Retour: ");
	if (retour == OK)
		printf("-> OK");
	else
		printf("-> ERREUR : %d", retour);
	printf("\n");

	// autre exemple d'appel de fonction
    pgm_ecrire(nom2, image1, 
               lignes1, colonnes1, 
               maxval, metadonnees);

    printf("-> Fin!\n");

    return 0;
}
