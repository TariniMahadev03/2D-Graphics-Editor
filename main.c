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
    printf("===== 2D Graphics Editor =====\n\n");

    initializeCanvas();

    /* Test rectangle */
    drawRectangle(5, 3, 10, 4);

    displayCanvas();

    return 0;
}
