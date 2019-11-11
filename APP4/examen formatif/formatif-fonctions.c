/*********************************************************
Fichier     : formatif-fonctions.c
Auteur      : Domingo Palao Munoz
Date        : 30 octobre 2019
Description : description: fichier avec les fonctions
**********************************************************/

/////////////////////////////////////////////////////////////////////////////////
// Le solutionnaire est une maniere de resoudre le probleme. Il est possible et
// tres probable que votre solution ne soit pas exactement pareille a la notre.
// Si le resultat obtenu est valide et que vous respectez les normes de
// programmation et les noms de fonctions et parametres, votre solution est correcte.
/////////////////////////////////////////////////////////////////////////////////

#include "formatif-fonctions.h"

// Lire un fichier selon le format indique
int lireFichier(char fichier[], 
                struct PrenomPopularite tableauPrenomPopularite[])
{
  FILE *fichier_lu =fopen(fichier,"r");
  int i=0; //compteur pour la position dans le tableau
  if (fichier_lu == NULL)
	{
		return 0;
	}
  
	while(!feof(fichier_lu))
		{
			fscanf(fichier_lu,"%s %s",tableauPrenomPopularite[i].prenom, tableauPrenomPopularite[i].popularite);
			i++ ;
		}
		fclose(fichier_lu);
    return 1;	// lecture reussie
}

// chercher votreNom dans les deux tableaux et affiche les messages
int chercherNom(struct PrenomPopularite tableauPrenomPopulariteGarcons[],
                struct PrenomPopularite tableauPrenomPopulariteFilles[], 
                char votreNom[])
{
	int parametre=0;
	int position;
	
	//on cherche chez les filles
	if (chercherNomTableau(tableauPrenomPopulariteFilles,votreNom,&position))
	{
	afficheMessageNomTrouve(votreNom,position,FILLES,tableauPrenomPopulariteFilles[position].popularite);	
	parametre=1;
	}
    else 
	{
		afficheMessageNomNonTrouve(votreNom,FILLES);
    }
    
    //on cherche chez les gars
    
    if(chercherNomTableau(tableauPrenomPopulariteGarcons,votreNom,&position))
    {
		afficheMessageNomTrouve(votreNom,position,GARCONS,tableauPrenomPopulariteGarcons[position].popularite);
		parametre=1;
	}
	else
	{
		afficheMessageNomNonTrouve(votreNom,GARCONS);
	}
	
	return parametre;
}

// Cherche votreNom dans un tableau et retourne la position dans un parametre
int chercherNomTableau(struct PrenomPopularite tableauPrenomPopularite[MAX_NOMS],
                       char votreNom[TAILLE_NOMS], 
                       int *position)
{
	position=0;
	for (int i=0;i<MAX_NOMS;i++)
		{
			if (strcmp(votreNom,tableauPrenomPopularite[i].prenom)==0)
			{
				*position = i;
				return *position;
			}
		}
  
    return 0;
}

// Afficher le mesage lors que le nom a ete trouve
void afficheMessageNomTrouve(char nom[TAILLE_NOMS], 
                             int position,
                             char sexe[TAILLE_POPULARITE], 
                             char popularite[TAILLE_POPULARITE])
{
  printf("%s se trouve à la position %d des noms les plus populaire chez les %s avec %s occurences",nom,position,sexe,popularite);
}

//Afficher le message lors que le nom n'a pas ete trouve
void afficheMessageNomNonTrouve(char nom[TAILLE_NOMS], 
                                char sexe[TAILLE_POPULARITE])
{
    printf("%s ne fait pas partie des 1000 prenoms les plus populaire chez les %s",nom,sexe);
}

//Creer le rapport de 5 noms plus populaires
int creerRapport(char nomFichier[], 
                 char sexe[], 
                 int nombreElementsRapport,
                 struct PrenomPopularite tableauPrenomPopularite[])
{
   
    
    return 1;
}
