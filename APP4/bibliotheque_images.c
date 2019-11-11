/********
Fichier: bibliotheque_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/

#include "bibliotheque_images.h"

int pgm_lire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
             int *p_lignes, int *p_colonnes, 
             int *p_maxval, struct MetaData *p_metadonnees)
{
	
	FILE *fichier_lu = fopen(nom_fichier,"r");
	
	if (fichier_lu == NULL)
		return ERREUR_FICHIER;
	
	
	char car = '\0';
	fscanf(fichier_lu,"%c", &car);
	
	
	if (car == '#') {
		char ligne[MAX_CHAINE];
		fscanf(fichier_lu, "%s", ligne);
		int retour = extraire_metadata(ligne, p_metadonnees);
		if (retour != 0)
		{
			fclose(fichier_lu);
			return retour;
		}
		
		//saute le chagement de ligne et passe au prochain caractere
		fscanf(fichier_lu,"%c", &car);
		fscanf(fichier_lu,"%c", &car);
	}
	
	if (car == 'P' ) {
		fscanf(fichier_lu, "%c", &car);
		if (car != '2') {
			fclose(fichier_lu);
			return ERREUR_FORMAT;
		} 
	} else {
		fclose(fichier_lu);
		return ERREUR_FORMAT;
	}
	
	fscanf(fichier_lu, "%d", p_colonnes);
	fscanf(fichier_lu, "%d", p_lignes);
	fscanf(fichier_lu, "%d", p_maxval);
	
	for (int i=0; i<*p_lignes; i++)
	{
		for (int j=0; j<*p_colonnes; j++)
		{
			fscanf(fichier_lu, "%d", &matrice[i][j]);
		}
	}
	
	fclose(fichier_lu);
    return OK;
}

int pgm_ecrire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
               int lignes, int colonnes, 
               int maxval, struct MetaData metadonnees)
{
    FILE *fichier = fopen(nom_fichier, "w");
    
    if (fichier == NULL)
		return ERREUR_FICHIER;
    
    char metadata[MAX_CHAINE];
    ecrire_metadata(metadata, metadonnees);
    
    if (metadata[0]!='\0')
    {
		fprintf(fichier, "#");
		fputs(metadata, fichier);
		fputs("\n", fichier);
	}
    fputs("P2\n", fichier);
    fprintf(fichier,"%d %d\n%d\n",colonnes, lignes, maxval);
    
    for (int i=0; i<lignes; i++)
	{
		for (int j=0; j<colonnes; j++)
		{
			fprintf(fichier, "%d ", matrice[i][j]);
		}
		fputs("\n", fichier);
	}
    
    fclose(fichier);
    return OK;
}

int extraire_metadata(char ligne[MAX_CHAINE], struct MetaData * p_metadonnees)
{
	int i=0;
	while (ligne[i] != ';' && ligne[i] != '\0')
	{
		p_metadonnees->auteur[i] = ligne[i];
		i++;
	}
	if (ligne[i] == '\0')
		return ERREUR_FORMAT;
	p_metadonnees->auteur[i]='\0';
	
	i++;
	int debut = i;
	while (ligne[i] != ';')
	{
		p_metadonnees->dateCreation[i-debut] = ligne[i];
		i++;
	}
	if (ligne[i] == '\0')
		return ERREUR_FORMAT;
	p_metadonnees->dateCreation[i]='\0';
	
	if (strlen(p_metadonnees->dateCreation)>10)
	{
		return ERREUR_FORMAT;
	} else {
		int retour = verifieDate(p_metadonnees->dateCreation);
		if (retour != 0)
			return retour;
	}
	
	
	i++;
	debut = i;
	while (ligne[i] != ';')
	{
		p_metadonnees->lieuCreation[i-debut] = ligne[i];
		i++;
	}
	p_metadonnees->lieuCreation[i]='\0';
	return 0;
}

int ecrire_metadata(char ligne[MAX_CHAINE], struct MetaData metadonnees){

	if (metadonnees.auteur[0] == '\0' && metadonnees.dateCreation[0] == '\0' && metadonnees.lieuCreation[0] == '\0')
	{
		ligne[0] = '\0';
		return 0;
	}
	strcpy(ligne,metadonnees.auteur);
	int length =  strlen(ligne);
	ligne[length] = ';';
	
	strcpy(ligne + length + 1, metadonnees.dateCreation);
	length =  strlen(ligne);
	ligne[length] = ';';
	
	strcpy(ligne + length + 1, metadonnees.lieuCreation);
	return 0;
}
int verifieDate(date[11])
{
	if (!isdigit(date[0]))
		return ERREUR_FORMAT;
	if (!isdigit(date[1]))
		return ERREUR_FORMAT;
	if (!isdigit(date[2]))
		return ERREUR_FORMAT;
	if (!isdigit(date[3]))
		return ERREUR_FORMAT;
	if (char[4]!='-')
		return ERREUR_FORMAT;
	if (!isdigit(date[5]))
		return ERREUR_FORMAT;
	if (!isdigit(date[6]))
	{
		if (date[6]!='-')
			return ERREUR_FORMAT;
		else
		{
		if (!isdigit(date[7]))
			return ERREUR_FORMAT;
		if ((!isdigit(date[8])) && (date[8] != '\0'))
			return ERREUR_FORMAT;
		}	
	} else {
		if (date[7]!='-')
			return ERREUR_FORMAT;
		if (!isdigit(date[8]))
			return ERREUR_FORMAT;
		if ((!isdigit(date[9])) && (date[9] != '\0'))
			return ERREUR_FORMAT;
	}
	return OK;
}

int ppm_lire(
char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR],
int *p_lignes, int *p_colonnes, i



int ppm_ecrire(
char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR],
int lignes, int colonnes, int maxval, struct MetaData metadonnees);


