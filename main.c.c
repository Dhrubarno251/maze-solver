#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 10

struct Player
{
    int x;
    int y;
    int steps;
};

struct Maze
{
    char grid[HEIGHT][WIDTH];
};

void showIntro();
void initializeMaze(struct Maze *m);
void generatePath(struct Maze *m);
void placePlayer(struct Maze *m, struct Player *p);
void displayMaze(struct Maze *m, struct Player *p);
void movePlayer(struct Maze *m, struct Player *p, int dx, int dy);
void gameLoop(struct Maze *m, struct Player *p);
void clearScreen();
void delay(int milliseconds);

int main()
{
    srand(time(NULL));

    struct Maze maze;
    struct Player player;

    char playAgain;

    do
     {
        showIntro();
        initializeMaze(&maze);
        generatePath(&maze);
        placePlayer(&maze, &player);
        gameLoop(&maze, &player);

        printf("\nPlay again? (Y/N): ");
        playAgain = getch();
     }
    while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThanks for playing!\n");
    return 0;
}

void showIntro()
{
    clearScreen();
    printf("===================================\n");
    printf("         MAZE SOLVER GAME          \n");
    printf("===================================\n");
    printf("Controls:\n");
    printf("W - Move Up\n");
    printf("S - Move Down\n");
    printf("A - Move Left\n");
    printf("D - Move Right\n");
    printf("Q - Quit Game\n");
    printf("Press any key to start...\n");
    getch();
}

void initializeMaze(struct Maze *m)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            m->grid[i][j] = '#';
        }
    }
}

void generatePath(struct Maze *m)
{
    int x = 0, y = 0;
    m->grid[y][x] = ' ';

    while (x != WIDTH - 1 || y != HEIGHT - 1)
    {
        if (x < WIDTH - 1 && (y == HEIGHT - 1 || rand() % 2 == 0))
        {
            x++;
        }
    else if (y < HEIGHT - 1)
        {
            y++;
        }
        m->grid[y][x] = ' ';
    }

    m->grid[0][0] = 'P';
    m->grid[HEIGHT - 1][WIDTH - 1] = 'E';
}

void placePlayer(struct Maze *m, struct Player *p)
{
    p->x = 0;
    p->y = 0;
    p->steps = 0;
}

void displayMaze(struct Maze *m, struct Player *p)
{
    clearScreen();

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (i == p->y && j == p->x)
            {
                printf("P");
            }
           else
            {
                printf("%c", m->grid[i][j]);
            }
        }
        printf("\n");
    }

    printf("Steps: %d\n", p->steps);
    printf("Controls: W/A/S/D to move, Q to quit.\n");
}

void movePlayer(struct Maze *m, struct Player *p, int dx, int dy)
{
    int newX = p->x + dx;
    int newY = p->y + dy;

    if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT)
    {
        char nextCell = m->grid[newY][newX];
        if (nextCell == ' ' || nextCell == 'E')
        {
            p->x = newX;
            p->y = newY;
            p->steps++;
        }
    }
}

void gameLoop(struct Maze *m, struct Player *p)
{
    while (1)
    {
        displayMaze(m, p);

        if (p->x == WIDTH - 1 && p->y == HEIGHT - 1)
        {
            printf("\nCongratulations! You reached the end in %d steps!\n", p->steps);
            break;
        }

        char move = getch();
        switch (move)
        {
            case 'w':
            case 'W':
                movePlayer(m, p, 0, -1);
                break;
            case 's':
            case 'S':
                movePlayer(m, p, 0, 1);
                break;
            case 'a':
            case 'A':
                movePlayer(m, p, -1, 0);
                break;
            case 'd':
            case 'D':
                movePlayer(m, p, 1, 0);
                break;
            case 'q':
            case 'Q':
                printf("\nGame Quit. See you next time!\n");
                exit(0);
        }
    }
}

void clearScreen()
{
    system("cls");
}

void delay(int milliseconds)
{
    Sleep(milliseconds);
}


