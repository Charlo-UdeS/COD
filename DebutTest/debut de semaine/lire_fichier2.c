#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LARGEUR 3
#define MAX_HAUTEUR 3
#define MAX_VALEUR 9

int pgm_lire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR],int *p_lignes, int *p_colonnes, int *p_maxval)    
{
	
	FILE *fichier_lue = fopen(nom_fichier,"r");   
 
	
		fscanf(fichier_lue,"%d",p_lignes); 
		fscanf(fichier_lue,"%d",p_colonnes); 
		fscanf(fichier_lue,"%d",p_maxval);
	printf("%d \n",*p_lignes);
	printf("%d \n",*p_colonnes);
	printf("%d \n",*p_maxval);
		for (int i=0;i<*p_colonnes;i++){
			for (int j=0;j<*p_lignes;j++){
				fscanf(fichier_lue,"%d",&matrice[i][j]);	
			}
		}
	for (int i=0;i<3;i++){
			for (int j=0;j<3;j++){
			//rintf("%d \n",matrice[i][j]);
		}
    }
    
  fclose(fichier_lue);  
    return 0;
}

int pgm_ecrire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
               int lignes, int colonnes, 
               int maxval)
{
    
    FILE *fichier_ecris = fopen(nom_fichier,"w"); 
    
    fprintf(fichier_ecris,"%d %d\n%d\n",lignes,colonnes,maxval);
    
    for (int i=0;i<colonnes;i++){
		for (int j=0;j<lignes;j++){
			fprintf(fichier_ecris,"%d",matrice[i][j]);	
		}
		fprintf(fichier_ecris,"\n");
	}
    
    
    fclose(fichier_ecris);
    return 0;
}

int main (void)
{
	int maxval;
	int lignes ;
	int colonnes; 
	int matrice1[][];
	// int buffer;
	
	printf("allo");
	int var1;
	int var2;
	
	#define LINESZ 1024
    char buff[LINESZ];
	printf("%s","allo debut");
    
    FILE *fic = fopen ("test.pgm", "r");
	if (fic != NULL) {

		//Read Header 1
		(fgets (buff, LINESZ, fic)) {
		sscanf(buff,"%d %d",&lignes, &colonnes);
		printf("%d %d \n",var1, var2); 		

		matrice1 = new int[lignes][colonnes]


		//Read Header 2
		(fgets (buff, LINESZ, fic)) {
		sscanf(buff,"%d ",&maxval);
		printf("%d \n",maxval); 		


		
		while (fgets (buff, LINESZ, fic)) {
			sscanf(buff,"%d %d",&var1, &var2);
			printf("%d %d \n",var1, var2); 		
		}
	}
	fclose (fic); 

	printf("allo fin");


//	pgm_lire("une_seule_ligne.txt", matrice1,&lignes, &colonnes, &maxval );
	
//	pgm_ecrire("copy.pgm",matrice1,lignes,colonnes,maxval);
               return 0;
}

//une_seule_ligne.txt
//test.PGM
