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
    Position current;
    Position previous;
    current.position_x = SIZE/2, current.position_y = SIZE/2; /* Declaring variables */
    int array[SIZE][SIZE] = {{0}}; 
    char character = '\0';

    // BEGIN
    array[current.position_x][current.position_y] = 1; /* Sets 1 as player's position  */

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
                if (current.position_x != 0) /* Case: player IS NOT edge of playing board */
                {
                previous = current;                                        /* Sets player's current position as previous */
                    array[previous.position_x][previous.position_y] = 0;   /* Sets 0 to previous position */
                    current.position_x -= 1;                               /* Changes position according to player's choice */
                    array[current.position_x][current.position_y] = 1;     /* Sets 1 to current position */
                }
                else /* Case: player IS on edge of playing board */
                {
                    previous = current;
                    array[previous.position_x][previous.position_y] = 0;
                    current.position_x = SIZE - 1;
                    array[current.position_x][current.position_y] = 1;
                }
                system("cls"); PrintTheArray(array, true);
                break;
            
            case 's': /* DOWN */
                if (current.position_x != SIZE - 1)
                {
                    previous = current;
                    array[previous.position_x][previous.position_y] = 0;
                    current.position_x += 1;
                    array[current.position_x][current.position_y] = 1;
                }
                else
                {
                    previous = current;
                    array[previous.position_x][previous.position_y] = 0;
                    current.position_x = 0;
                    array[current.position_x][current.position_y] = 1;
                }
                system("cls"); PrintTheArray(array, true);
                break;
            
            case 'd': /* RIGHT */
                if (current.position_y != SIZE - 1)
                {
                    previous = current;
                    array[previous.position_x][previous.position_y] = 0;
                    current.position_y += 1;
                    array[current.position_x][current.position_y] = 1;
                }
                else
                {
                    previous = current;
                    array[previous.position_x][previous.position_y] = 0;
                    current.position_y = 0;
                    array[current.position_x][current.position_y] = 1;
                }
                system("cls"); PrintTheArray(array, true);
                break;
            
            case 'a': /* LEFT */
                if (current.position_y != 0)
                {
                    previous = current;
                    array[previous.position_x][previous.position_y] = 0;
                    current.position_y -= 1;
                    array[current.position_x][current.position_y] = 1;
                }
                else
                {
                    previous = current;
                    array[previous.position_x][previous.position_y] = 0;
                    current.position_y = SIZE - 1;
                    array[current.position_x][current.position_y] = 1;
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