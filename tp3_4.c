#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

char *Buff; 
int cantidad;

Buff= (char *) malloc(100*sizeof(char));

printf("\nIngrese la cantidad de nombres que va a cargar: ");
scanf("%i", &cantidad);
fflush(stdin);

char *V[cantidad];

for (int i = 0; i < cantidad; i++)
{
fflush(stdin);
printf("Ingrese el nombre %i : ", i+1);
gets(Buff);
V[i] = (char *) malloc((strlen(Buff)+1)*sizeof(char));
strcpy(V[i],Buff);
}

printf("Lo nombres son:");
for (int i = 0; i < cantidad; i++)
{
    puts (V[i]);
}

free(Buff);

for (int i = 0; i < cantidad; i++)
{
    free(V[i]);
}



return 0;
}