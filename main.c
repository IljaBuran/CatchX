/* ATTENTION: 'position_x' and 'position_y' and reversed to normal logic of mathematica - not (x,y) */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#define esc 27
#define enter 13

#define SIZE 10 /* Size of playing board */

typedef struct
{
    int position_x;
    int position_y;
}Position;

void PrintPlayingBoard(char array[SIZE][SIZE], bool isBeginning, int points)
{
    for (size_t i = 0; i < SIZE + 2; i++)
    {
        printf("#");
    }
    
    printf("\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("#");
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c", array[i][j]);  /* Prints playing board */
        }
        printf("#");
        printf("\n");
    }

    for (size_t i = 0; i < SIZE + 2; i++)
    {
        printf("#");
    }
    
    printf("\n\n"); /* prints extra 2 lines */

    if (isBeginning == false) /* Prints controls on the beginning */ 
    {
        printf("Movement: WASD\nExit Game: ESC"); 
    }
    else
    {
        printf("Points: %d\n\n", points);
    }
}

void QuitSeq()
{
    for (float i = 1.0; i > 0.0; i = i - 0.1)
    {
        printf("%.1f\n", i);
        Sleep(80);
    }
}

int main()
{
    Position player;                                                                  /**/
    Position point;                                                                   /**/
    player.position_x = SIZE/2, player.position_y = SIZE/2;         /* Declaring variables */
    char array[SIZE][SIZE]; memset(array, ' ', sizeof(array));                      /* Sets 0s in whole array */
    char character = '\0';                                                                    /**/
    int points = 0, moves = 0;                                                                /**/

    // BEGIN
    array[player.position_x][player.position_y] = 'O'; /* Sets 1 as player's position */

    printf("PRESS ENTER TO START GAME");

    while(1) /* Loop waiting for ENTER to start game */
    {
        character = getche();
        if (character == enter)
        {
            point.position_x = rand() % SIZE;
            point.position_y = rand() % SIZE;
            array[point.position_x][point.position_y] = 'X';
            system("cls"); PrintPlayingBoard(array, false, points);
            break;
        }
        if (character == esc)
        {
            QuitSeq();
            return 0;
        }
        system("cls"); printf("PRESS ENTER TO START GAME");
    }

    

    while (character != esc) /* Game mechanism, ends when ESC is pressed */ 
    {
        
        character = getche(); /* Waits for player's movement (WASD) */
        
        switch(character) 
        {
            case 'w': /* UP */
                if (player.position_x != 0) /* Case: player IS NOT edge of playing board */
                {
                    array[player.position_x][player.position_y] = ' ';   /* Sets ' ' to player_previous position */
                    player.position_x -= 1;                              /* Changes position according to player's choice */
                    array[player.position_x][player.position_y] = 'O';   /* Sets 'O' to player position */
                    moves++;
                }
                else /* Case: player IS on edge of playing board */
                {
                    array[player.position_x][player.position_y] = ' ';
                    player.position_x = SIZE - 1;
                    array[player.position_x][player.position_y] = 'O';
                    moves++;
                }
                system("cls"); PrintPlayingBoard(array, true, points);
                break;
            
            case 's': /* DOWN */
                if (player.position_x != SIZE - 1)
                {
                    array[player.position_x][player.position_y] = ' ';
                    player.position_x += 1;
                    array[player.position_x][player.position_y] = 'O';
                    moves++;
                }
                else
                {
                    array[player.position_x][player.position_y] = ' ';
                    player.position_x = 0;
                    array[player.position_x][player.position_y] = 'O';
                    moves++;
                }
                system("cls"); PrintPlayingBoard(array, true, points);
                break;
            
            case 'd': /* RIGHT */
                if (player.position_y != SIZE - 1)
                {
                    array[player.position_x][player.position_y] = ' ';
                    player.position_y += 1;
                    array[player.position_x][player.position_y] = 'O';
                    moves++;
                }
                else
                {
                    array[player.position_x][player.position_y] = ' ';
                    player.position_y = 0;
                    array[player.position_x][player.position_y] = 'O';
                    moves++;
                }
                system("cls"); PrintPlayingBoard(array, true, points);
                break;
            
            case 'a': /* LEFT */
                if (player.position_y != 0)
                {
                    array[player.position_x][player.position_y] = ' ';
                    player.position_y -= 1;
                    array[player.position_x][player.position_y] = 'O';
                    moves++;
                }
                else
                {
                    array[player.position_x][player.position_y] = ' ';
                    player.position_y = SIZE - 1;
                    array[player.position_x][player.position_y] = 'O';
                    moves++;
                }
                system("cls"); PrintPlayingBoard(array, true, points);
                break;
            default:
                system("cls"); PrintPlayingBoard(array, true, points);
        }
        
        if (player.position_x == point.position_x && player.position_y == point.position_y)
        {
            points += 1;
            if (points == 10)
            {
                system("cls"); PrintPlayingBoard(array, true, points);
                printf("Moves: %d\n", moves);
                printf("You won!\n");
                while(1) /* Loop waiting for ENTER to start game */
                {
                    printf("Press 'r' for repeat or 'ESC' to quit'");
                    character = getche();
                    if (character == 'r')
                    {
                        points = 0;
                        moves = 0;
                        break;
                    }
                    if (character == esc)
                    {
                        QuitSeq();
                        return 0;
                    }
                    system("cls"); PrintPlayingBoard(array, true, points);
                    printf("Moves: %d\n", moves);
                    printf("You won!\n");
                }
            }
            point.position_x = rand() % SIZE;
            point.position_y = rand() % SIZE;
            array[point.position_x][point.position_y] = 'X';
            system("cls"); PrintPlayingBoard(array, true, points);
        }
    }
    
    QuitSeq();
    
    /* Programs exits with 0 */
    return 0;
}