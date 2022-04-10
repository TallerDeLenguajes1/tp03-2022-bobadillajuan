
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

char *Buff; 
char *V[5];

Buff= (char *) malloc(100*sizeof(char));

for (int i = 0; i < 5; i++)
{
printf("Ingrese el nombre %i : ", i+1);
gets(Buff);
V[i] = (char *) malloc((strlen(Buff)+1)*sizeof(char));
strcpy(V[i],Buff);
}

printf("Lo nombres son:");
for (int i = 0; i < 5; i++)
{
    puts (V[i]);
}

free(Buff);

for (int i = 0; i < 5; i++)
{
    free(V[i]);
}



return 0;
}