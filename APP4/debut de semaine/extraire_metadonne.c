#include <stdio.h>
#include <string.h>


int main()
{
	int lignes=0;
	int colonnes=0;
	int maxval=0;
	char fichier_entree[128],fichier_sortie[128];
	

	int matrice [256][256];
	FILE *flot_entree,*flot_sortie;
	int *p_lignes=&lignes;
	int *p_colonnes=&colonnes;
	int *p_maxval=&maxval;
	char fichier_type[128];
	
	strcpy(fichier_entree, "test.pgm");
	strcpy(fichier_sortie, "copy.pgm");
	
	
	
	flot_entree=fopen(fichier_entree,"r");
	flot_sortie=fopen(fichier_sortie,"w");
	
	if (flot_entree == NULL || flot_sortie == NULL)
	{
		printf("erreur ouverture fichiers");
		return -1;
	}
	else
	{	
		fscanf(flot_entree,"%s",fichier_type);
		printf("%s",fichier_type);
		fscanf(flot_entree,"%d %d %d",p_lignes,p_colonnes,p_maxval);
		printf("\n");

		
		for(int i=0;i<*p_lignes;i++)//i=ligne
		{
			for(int j=0;j<*p_colonnes;j++)//j=colonnes
			{
			fscanf(flot_entree,"%d",&matrice[i][j]);
		
			}
		}
		
		
		
		int lignes1=3; 
		int colonnes1=6;
		int lignes2=7;
		int colonnes2=8;
		
		
		lignes = lignes2-lignes1+1;
		colonnes = colonnes2-colonnes1+1;
		
		
		for (int i=0; i<lignes;i++)
		{
			puts("");
			for (int j=0; j<colonnes;j++)
			{
				printf("[ %d, %d ]",i,j);
				printf("[%d, %d ]*",i+lignes1,j+colonnes1);	
			
				 matrice[i][j] = matrice[i+lignes1][j+colonnes1]   ;
			
			}
		}
		
		
		/*
		for (int i=lignes1; i<=lignes2; i++)
		{   
			
			printf("\n");
			for (int j=colonnes1; j<=colonnes2; j++)
			{
			printf("[ %d, %d ]",x,y);
			printf("[%d, %d ]*",i,j);	
			
				 matrice[x][y] = matrice[i][j]   ;
			
			}
		y++;	
		x++;
		}
		*/
		
		
		
		fprintf(flot_sortie,"%s\n",fichier_type);
		fprintf(flot_sortie,"%d %d \n%d",*p_lignes,*p_colonnes,*p_maxval);
		for(int i=0;i<*p_lignes;i++)
		{	
			printf("\n");
			fprintf(flot_sortie,"\n");
			for(int j=0;j<*p_colonnes;j++)
			{
			fprintf(flot_sortie,"%d ",matrice[i][j]);
			printf("%d ",matrice[i][j]);
			}
		}
	}
	return 0;
}
