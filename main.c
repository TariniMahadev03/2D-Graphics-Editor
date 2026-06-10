#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

/* Fill canvas with underscores */
void initializeCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

/* Display canvas */
void displayCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}

/* Draw a filled rectangle */
void drawRectangle(int x, int y, int width, int height)
{
    for(int i = y; i < y + height && i < ROWS; i++)
    {
        for(int j = x; j < x + width && j < COLS; j++)
        {
            canvas[i][j] = '*';
        }
    }
}

int main()
{
    int choice;

    initializeCanvas();

    printf("===== 2D Graphics Editor =====\n");

    printf("\n1. Draw Rectangle");
    printf("\n2. Display Canvas");
    printf("\n3. Exit");
    printf("\nEnter choice: ");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            drawRectangle(5, 3, 10, 4);
            printf("\nRectangle Drawn!\n");
            displayCanvas();
            break;

        case 2:
            displayCanvas();
            break;

        case 3:
            return 0;

        default:
            printf("Invalid Choice!\n");
    }

    return 0;
}
