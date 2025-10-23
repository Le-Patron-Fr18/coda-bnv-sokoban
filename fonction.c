#include <stdlib.h>
#include <stdio.h>

//affichage tableau (front)


int print_tab(char **tab)
{
    int i = 0;

    while(tab[i] != NULL)
    {
        int j = 0;

        while(tab[i][j] != '\0')
        {
            printf("%c", tab[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}


//Logique du tableau (back)




//fonction du personnage en mouvement 
int mouvement()
{
void personnage_mouvement(char **board, int bouge);           //fonction du personnage en mouvement 

if (z && bouge +1)                                   //haut 
{
    return -1;
}
if (s && bouge +1)                                       //bas
{
    return -1;
}
if (q && bouge +1)                                   //gauche 
{
    return -1;
}
if (s && bouge +1)                                   //droite
{
    return -1;
}
else 
{
    return 0;
}

    return(0);
}


//fonction d'affichage du personnage 
char perso;



//fonction de la caisse en mouvement

//fonction d'affichage de la caisse 

