#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp;
	float pi = 3.1415;
	float pilido;
	if((fp = fopen("arquivo.bin", "wb")) == NULL)
	{
		printf("Erro na abertura do arquivo");
		exit(1);
	}
	if(fwrite(&pi, sizeof(float), 1,fp) != 1)
		printf("Erro na escrita do arquivo");
	fclose(fp);

	if((fp = fopen("arquivo.bin", "rb")) == NULL)
	{
		printf("Erro na abertura do arquivo");
		exit(1);
	}
	if(fread(&pilido, sizeof(float), 1,fp) != 1)
		printf("Erro na leitura do arquivo");
	printf("\nO valor de PI "
		"(lido do arquivo) eh: %f\n\n",
		pilido);
	fclose(fp);
	return(0);
}