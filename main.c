#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main()
{
    char * prenom = malloc(100 * sizeof(char));
    printf("Quel est ton prénom ? (choisis le bien 🤡)\n");
    scanf("%s", prenom);
    printf("Bonjour %s ! \nPour prouver que tu es bon dans un domaine (potentiellement le seul),\n", prenom);
    printf("nous te proposons de réussir ce niveau de Sokoban !\n\n");
    sleep(3);
    printf("Les touches sont les suivantes :\n [Z] pour monter d'une case\n [Q] pour aller à Gauche\n [S] pour aller en bas\n [D] pour aller à droite\n");
    printf("Bon jeu à toi !\n\n");
    sleep(3);
    printf(" ##########\n");
    printf(" #        #\n");
    printf(" #        #\n");
    printf(" #        #\n");
    printf(" #        #\n");
    printf(" #        #\n");
    printf(" #        #\n");
    printf(" #        #\n");
    printf(" #        #\n");
    printf(" ##########\n");
}

int main()
{
	char ** tableau = malloc(4 * sizeof(*tableau));
	tableau[3] = NULL;

	tableau[0] = str_cpy("La vie");
	tableau[1] = str_cpy("l'univers");
	tableau[2] = str_cpy("et tout le reste.");

	print_tab(tableau);

	int i = 0;

	while(tableau[i] != NULL)
	{
		free(tableau[i]);
		i = i + 1;
	}

	free(tableau);
	exit(0);
}