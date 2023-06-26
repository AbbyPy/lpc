#include <stdio.h>

int main (){
	printf("inserisci nome file\n");
	char nomefile[50];
	scanf("%s",nomefile);
	FILE *file;
	file=fopen(nomefile,"w");
	fprintf(file,"1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4");
	fclose(file);
	file=fopen(nomefile,"r");
	int a[4][4];
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			fscanf(file,"%d",&a[i][j]);
		}
	}
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
	
	fclose(file);
	return 0;
}
