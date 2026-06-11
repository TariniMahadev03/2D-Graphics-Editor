#include <stdio.h>
#include <stdlib.h>
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

int main()
{
    int choice;

    initializeCanvas();

    printf("===== 2D Graphics Editor =====\n");

printf("\n1. Draw Rectangle");
printf("\n2. Draw Line");
printf("\n3. Draw Triangle");
printf("\n4. Draw Circle");
printf("\n5. Display Canvas");
printf("\n6. Exit");
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
    drawLine(2, 2, 18, 18);
    printf("\nLine Drawn!\n");
    displayCanvas();
    break;

    case 3:
    drawTriangle(10, 2, 5, 10, 15, 10);
    printf("\nTriangle Drawn!\n");
    displayCanvas();
    break;

    case 4:
    drawCircle(20, 10, 5);
    printf("\nCircle Drawn!\n");
    displayCanvas();
    break;

case 5:
    displayCanvas();
    break;

case 6:
    return 0;

        default:
            printf("Invalid Choice!\n");
    }

    return 0;
}
