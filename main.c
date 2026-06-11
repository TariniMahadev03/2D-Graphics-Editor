#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ROWS 25
#define COLS 80

char screen[ROWS][COLS];
void clearScreen()
{
    int i, j;
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            screen[i][j] = ' ';
        }
    }
}

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
void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x1;
    float y = y1;

    for(int i = 0; i <= steps; i++)
    {
        if((int)x >= 0 && (int)x < COLS &&
           (int)y >= 0 && (int)y < ROWS)
        {
            canvas[(int)y][(int)x] = '*';
        }

        x += xInc;
        y += yInc;
    }
}
void drawTriangle(int x1, int y1,
                  int x2, int y2,
                  int x3, int y3)
{
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}
void drawCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int d = 1 - r;

    while(x <= y)
    {
        if(yc+y >= 0 && yc+y < ROWS && xc+x >= 0 && xc+x < COLS)
            canvas[yc+y][xc+x] = '*';

        if(yc+y >= 0 && yc+y < ROWS && xc-x >= 0 && xc-x < COLS)
            canvas[yc+y][xc-x] = '*';

        if(yc-y >= 0 && yc-y < ROWS && xc+x >= 0 && xc+x < COLS)
            canvas[yc-y][xc+x] = '*';

        if(yc-y >= 0 && yc-y < ROWS && xc-x >= 0 && xc-x < COLS)
            canvas[yc-y][xc-x] = '*';

        if(yc+x >= 0 && yc+x < ROWS && xc+y >= 0 && xc+y < COLS)
            canvas[yc+x][xc+y] = '*';

        if(yc+x >= 0 && yc+x < ROWS && xc-y >= 0 && xc-y < COLS)
            canvas[yc+x][xc-y] = '*';

        if(yc-x >= 0 && yc-x < ROWS && xc+y >= 0 && xc+y < COLS)
            canvas[yc-x][xc+y] = '*';

        if(yc-x >= 0 && yc-x < ROWS && xc-y >= 0 && xc-y < COLS)
            canvas[yc-x][xc-y] = '*';

        if(d < 0)
            d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }

        x++;
    }
}
void saveCanvas()
{
    FILE *fp = fopen("canvas.txt", "w");

    if(fp == NULL)
    {
        printf("Error saving file!\n");
        return;
    }

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            fprintf(fp, "%c", canvas[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    printf("Canvas saved to canvas.txt\n");
}

int main()
{
    int choice;

    initializeCanvas();

printf("===== 2D Graphics Editor =====\n");

while(1)
{
    printf("\n\n1. Draw Rectangle");
    printf("\n2. Draw Line");
    printf("\n3. Draw Triangle");
    printf("\n4. Draw Circle");
    printf("\n5. Display Canvas");
    printf("\n6. Clear Canvas");
    printf("\n7. Save Canvas");
    printf("\n8. Exit");

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
       case 1:
{
    int x, y, width, height;

    printf("Enter x y width height: ");
    scanf("%d %d %d %d", &x, &y, &width, &height);

    drawRectangle(x, y, width, height);

    printf("\nRectangle Drawn!\n");
    displayCanvas();
    break;
}
    case 2:
{
    int x1, y1, x2, y2;

    printf("Enter x1 y1 x2 y2: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    drawLine(x1, y1, x2, y2);

    printf("\nLine Drawn!\n");
    displayCanvas();
    break;
}

    case 3:
{
    int x1, y1, x2, y2, x3, y3;

    printf("Enter x1 y1 x2 y2 x3 y3: ");
    scanf("%d %d %d %d %d %d",
          &x1, &y1, &x2, &y2, &x3, &y3);

    drawTriangle(x1, y1, x2, y2, x3, y3);

    printf("\nTriangle Drawn!\n");
    displayCanvas();
    break;
}

    case 4:
{
    int xc, yc, r;

    printf("Enter center x y and radius: ");
    scanf("%d %d %d", &xc, &yc, &r);

    drawCircle(xc, yc, r);

    printf("\nCircle Drawn!\n");
    displayCanvas();
    break;
}

case 5:
    displayCanvas();
    break;

case 6:
    initializeCanvas();
    printf("\nCanvas Cleared!\n");
    displayCanvas();
    break;

case 7:
    saveCanvas();
    break;

case 8:
    return 0;

default:
    printf("Invalid Choice!\n");
    break;

    }
}
    return 0;
}
