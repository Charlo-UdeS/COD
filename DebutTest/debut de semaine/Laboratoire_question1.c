#include <stdio.h>
#include <string.h>


int main()
{
	int lignes=0;
	int colonnes=0;
	int maxval=0;
	char fichier_entree[128],fichier_sortie[128];
	struct RGB {
		int valeurR;
		int valeurG;
		int valeurB;
	};
	struct RGB matrice [256][256];
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
		
		
		for(int i=0;i<*p_lignes;i++)//i=ligne
		{
			for(int j=0;j<*p_colonnes;j++)//j=colonnes
			{
			fscanf(flot_entree,"%d",&matrice[i][j].valeurR);
			fscanf(flot_entree,"%d",&matrice[i][j].valeurG);
			fscanf(flot_entree,"%d",&matrice[i][j].valeurB);
			}
		}
		fprintf(flot_sortie,"%s\n",fichier_type);
		fprintf(flot_sortie,"%d %d \n%d",*p_lignes,*p_colonnes,*p_maxval);
		for(int i=0;i<*p_lignes;i++)
		{
			fprintf(flot_sortie,"\n");
			for(int j=0;j<*p_colonnes;j++)
			{
			fprintf(flot_sortie,"[%d %d %d]",matrice[i][j]);
			}
		}
	}
	printf("allo");
	return 0;
}
