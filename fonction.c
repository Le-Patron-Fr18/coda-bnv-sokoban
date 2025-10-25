#include <stdlib.h>
#include <stdio.h>
#include "str_cpy.h"
#include "fonction.h"
#include "print_tab.h"

char** tableau(void)
{
    char **tab = malloc(11 * sizeof(*tab));
    tab[10] = NULL;

    // Création du tableau avec les murs et les éléments du jeu
    char *niveau[] = {
        "############",
        "#          #",
        "#          #",
        "#          #",
        "#          #",
        "#    P     #",  // P représente le joueur
        "#    B     #",  // B représente la boîte (Box)
        "#    X     #",  // X représente la cible
        "#          #",
        "############"
    };

    // Copie de chaque ligne dans le tableau
    for(int i = 0; i < 10; i++) {
        tab[i] = str_cpy((char*)niveau[i]);
    }

    return tab;
}












//Logique du tableau (back)




// Fonction pour trouver la position du joueur
void trouve_joueur(char **board, int *x, int *y) {
    for(int i = 0; board[i] != NULL; i++) {
        for(int j = 0; board[i][j] != '\0'; j++) {
            if(board[i][j] == 'P') {
                *x = i;
                *y = j;
                return;
            }
        }
    }
}

// Fonction pour vérifier si le jeu est perdu
int est_perdu(char **board) {
    int pos_x, pos_y;
    trouve_joueur(board, &pos_x, &pos_y);
    
    // Le joueur perd s'il est sur une case qui contient un X (cible)
    if(board[pos_x][pos_y] == 'X') {
        return 1;  // Perdu !
    }
    return 0;  // Pas perdu
}

// Fonction pour vérifier si le jeu est gagné
int est_gagne(char **board) {
    // On cherche une boîte sur une cible (W)
    for(int i = 0; board[i] != NULL; i++) {
        for(int j = 0; board[i][j] != '\0'; j++) {
            if(board[i][j] == 'W') {  // W = boîte sur cible
                return 1;  // Gagné !
            }
        }
    }
    return 0;  // Pas encore gagné
}

// Fonction pour déplacer le joueur et la boîte
int deplacer_joueur(char **board, char direction) {
    int x, y;
    trouve_joueur(board, &x, &y);
    
    int new_x = x;
    int new_y = y;
    int box_x, box_y;
    
    // Calculer la nouvelle position selon la direction
    switch(direction) {
        case 'z': // Haut
            new_x = x - 1;
            box_x = new_x - 1;
            box_y = new_y;
            break;
        case 's': // Bas
            new_x = x + 1;
            box_x = new_x + 1;
            box_y = new_y;
            break;
        case 'q': // Gauche
            new_y = y - 1;
            box_x = new_x;
            box_y = new_y - 1;
            break;
        case 'd': // Droite
            new_y = y + 1;
            box_x = new_x;
            box_y = new_y + 1;
            break;
        default:
            return 0;
    }
    
    // Vérifier si le mouvement est valide (pas de mur)
    if(board[new_x][new_y] == '#') {
        return 0;
    }
    
    // Si on pousse une boîte
    if(board[new_x][new_y] == 'B') {
        // Vérifier si la boîte peut être poussée (pas de mur ou d'autre boîte)
        if(board[box_x][box_y] == '#' || board[box_x][box_y] == 'B') {
            return 0;
        }
        // Déplacer la boîte
        if(board[box_x][box_y] == 'X') {
            board[box_x][box_y] = 'W';  // W représente une boîte sur une cible
        } else {
            board[box_x][box_y] = 'B';
        }
    }
    
    // Effectuer le déplacement du joueur
    board[x][y] = ' ';      // Effacer l'ancienne position
    board[new_x][new_y] = 'P';  // Placer le joueur à la nouvelle position
    
    return 1;
}


//fonction d'affichage du personnage 
// void affichage_perso()




//fonction de la caisse en mouvement

//fonction d'affichage de la caisse