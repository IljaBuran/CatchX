/* ATTENTION: 'position_x' and 'position_y' and reversed to normal logic of mathematica - not (x,y) */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#define esc 27
#define enter 13

#define SIZE 16 /* Size of playing board */

typedef struct
{
    int position_x;
    int position_y;
}Position;

void PrintTheArray(int array[SIZE][SIZE], bool isBeginning)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d", array[i][j]);  /* Prints playing board */
        }
        printf("\n");
    }
    
    printf("\n"); /* prints extra line */

    if (isBeginning == false) /* Prints controls on the beginning */ 
    {
        printf("Movement: WASD\nExit Game: ESC"); 
    }
}

int main()
{
    Position player_current, player_previous;                                                 /**/
    Position point_current, point_previous;                                                   /**/
    player_current.position_x = SIZE/2, player_current.position_y = SIZE/2;         /* Declaring variables */
    int array[SIZE][SIZE] = {{0}}; /* Sets 0s in whole array */                               /**/
    char character = '\0';                                                                    /**/

    // BEGIN
    array[player_current.position_x][player_current.position_y] = 1; /* Sets 1 as player's position */

    printf("PRESS ENTER TO START GAME");

    while(1) /* Loop waiting for ENTER to start game */
    {
        character = getche();
        if (character == enter)
        {
            system("cls"); PrintTheArray(array, false);
            break;
        }
        system("cls"); printf("PRESS ENTER TO START GAME");
    }

    

    while (character != esc) /* Game mechanism, ends when ESC is pressed */ 
    {
        
        character = getche(); /* Waits for player's movement (WASD) */
        
        switch(character) 
        {
            case 'w': /* UP */
                if (player_current.position_x != 0) /* Case: player IS NOT edge of playing board */
                {
                player_previous = player_current;                                        /* Sets player's player_current position as player_previous */
                    array[player_previous.position_x][player_previous.position_y] = 0;   /* Sets 0 to player_previous position */
                    player_current.position_x -= 1;                                      /* Changes position according to player's choice */
                    array[player_current.position_x][player_current.position_y] = 1;     /* Sets 1 to player_current position */
                }
                else /* Case: player IS on edge of playing board */
                {
                    player_previous = player_current;
                    array[player_previous.position_x][player_previous.position_y] = 0;
                    player_current.position_x = SIZE - 1;
                    array[player_current.position_x][player_current.position_y] = 1;
                }
                system("cls"); PrintTheArray(array, true);
                break;
            
            case 's': /* DOWN */
                if (player_current.position_x != SIZE - 1)
                {
                    player_previous = player_current;
                    array[player_previous.position_x][player_previous.position_y] = 0;
                    player_current.position_x += 1;
                    array[player_current.position_x][player_current.position_y] = 1;
                }
                else
                {
                    player_previous = player_current;
                    array[player_previous.position_x][player_previous.position_y] = 0;
                    player_current.position_x = 0;
                    array[player_current.position_x][player_current.position_y] = 1;
                }
                system("cls"); PrintTheArray(array, true);
                break;
            
            case 'd': /* RIGHT */
                if (player_current.position_y != SIZE - 1)
                {
                    player_previous = player_current;
                    array[player_previous.position_x][player_previous.position_y] = 0;
                    player_current.position_y += 1;
                    array[player_current.position_x][player_current.position_y] = 1;
                }
                else
                {
                    player_previous = player_current;
                    array[player_previous.position_x][player_previous.position_y] = 0;
                    player_current.position_y = 0;
                    array[player_current.position_x][player_current.position_y] = 1;
                }
                system("cls"); PrintTheArray(array, true);
                break;
            
            case 'a': /* LEFT */
                if (player_current.position_y != 0)
                {
                    player_previous = player_current;
                    array[player_previous.position_x][player_previous.position_y] = 0;
                    player_current.position_y -= 1;
                    array[player_current.position_x][player_current.position_y] = 1;
                }
                else
                {
                    player_previous = player_current;
                    array[player_previous.position_x][player_previous.position_y] = 0;
                    player_current.position_y = SIZE - 1;
                    array[player_current.position_x][player_current.position_y] = 1;
                }
                system("cls"); PrintTheArray(array, true);
                break;
            default:
                system("cls"); PrintTheArray(array, true);
        }
    }
    
    
    /* Programs exits with 0 */
    return 0;
}