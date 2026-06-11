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
void displayPicture()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}
void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps;
    if(abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    float xin = dx / (float)steps;
    float yin = dy / (float)steps;

    float x = x1;
    float y = y1;

    int i;

    for(i = 0; i <= steps; i++)
    {
        if((int)x >= 0 && (int)x < COLS &&
           (int)y >= 0 && (int)y < ROWS)
        {
            screen[(int)y][(int)x] = '*';
        }

        x += xin;
        y += yin;
    }
}
void drawRectangle(int x, int y, int width, int height)
{
    int i, j;

    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            if(i == 0 || i == height-1 ||
               j == 0 || j == width-1)
                screen[y+i][x+j] = '*';
            else
                screen[y+i][x+j] = '-';
        }
    }
}

void drawTriangle(int x, int y, int h)
{
    int i, j;

    for(i = 0; i < h; i++)
    {
        for(j = -i; j <= i; j++)
        {
            if(i == h-1 || j == -i || j == i)
                screen[y+i][x+j] = '*';
            else
                screen[y+i][x+j] = '-';
        }
    }
}
void drawCircle(int xc, int yc, int r)
{
    int x, y;

    for(y = -r; y <= r; y++)
    {
        for(x = -r; x <= r; x++)
        {
            int d = x*x + y*y;

            if(d <= r*r)
            {
                if(xc+x >= 0 && xc+x < COLS &&
                   yc+y >= 0 && yc+y < ROWS)
                {
                    if(d >= (r-1)*(r-1))
                        screen[yc+y][xc+x] = '*';
                    else
                        screen[yc+y][xc+x] = '-';
                }
            }
        }
    }
}
void deleteArea(int x, int y, int width, int height)
{
    int i, j;

    for(i = y; i < y + height; i++)
    {
        for(j = x; j < x + width; j++)
        {
            if(i >= 0 && i < ROWS &&
               j >= 0 && j < COLS)
            {
                screen[i][j] = ' ';
            }
        }
    }
}


int main()
{
    int choice;

    clearScreen();

    do
    {
        printf("\n1. Add Rectangle");
        printf("\n2. Add Line");
        printf("\n3. Add Triangle");
        printf("\n4. Add Circle");
        printf("\n5. Delete Area");
        printf("\n6. Display Picture");
        printf("\n7. Clear Screen");
        printf("\n8. Exit");

        printf("\n\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            int x, y, w, h;

            printf("Enter x y width height: ");
            scanf("%d%d%d%d", &x, &y, &w, &h);

            drawRectangle(x, y, w, h);
        }

        else if(choice == 2)
        {
            int x1, y1, x2, y2;

            printf("Enter x1 y1 x2 y2: ");
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

            drawLine(x1, y1, x2, y2);
        }

        else if(choice == 3)
        {
            int x, y, h;

            printf("Enter top x y and height: ");
            scanf("%d%d%d", &x, &y, &h);

            drawTriangle(x, y, h);
        }

        else if(choice == 4)
        {
            int xc, yc, r;

            printf("Enter center x y and radius: ");
            scanf("%d%d%d", &xc, &yc, &r);

            drawCircle(xc, yc, r);
        }

        else if(choice == 5)
        {
            int x, y, w, h;

            printf("Enter x y width height to delete: ");
            scanf("%d%d%d%d", &x, &y, &w, &h);

            deleteArea(x, y, w, h);
        }

        else if(choice == 6)
        {
            displayPicture();
        }

        else if(choice == 7)
        {
            clearScreen();
            printf("Screen cleared!\n");
        }

    } while(choice != 8);

    return 0;
}
