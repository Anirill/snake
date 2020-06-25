#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


using namespace std;

bool gameOver;
const int width = 30;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail = 2;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void fruitSpawn()
{
    fruitX = rand() % (width - 1);
    fruitY = rand() % height;
    if(fruitX == 0) fruitX++;
 }


void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2 - 1;
    y = height / 2 - 1;
    tailX[0] = x;
    tailY[0] = y + 1;
    tailX[1] = x;
    tailY[1] = y + 2;
    fruitSpawn();
    score = 0;
}

void Draw()
{
    int tailDraw = 0;
    system("cls");
    cout << "Score: " << score << endl;

    for(int i = 0; i < width; i++)
    {
        cout << "#";
    }
    cout << endl;
    for(int i = 0; i < height ; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(j == 0 || j == (width - 1))
                cout << "#";
            else if(i == fruitY && j == fruitX)
                cout << "0";
            else if(i == y && j == x)
                cout << "@";
            else
            {
                for(int k = 0; k < nTail; k++)
                {
                    if(tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        tailDraw++;
                    }
                }
                if((tailDraw-- <= 0))
                {
                    cout << " ";
                    tailDraw = 0;
                }
            }
            if(i == (height/2 - 1) && j == (width/2 - 6) && gameOver)
            {
                cout << "Game Over!";
                j += 10;
            }
        }
        cout << endl;
    }


    for(int i = 0; i < width; i++)
    {
        cout << "#";
    }
//    cout << endl;
//    cout << fruitX;
//    cout << endl;
//    cout << fruitY;


}

void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'a':
                dir = LEFT;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 'x':
                gameOver = true;
                break;
            default:
                break;
        }
    }
}

void Logic()
{
    if(dir != STOP)
    {
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;
        for(int i = 1; i < nTail; i++)
        {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
        tailX[0] = x;
        tailY[0] = y;
    }
    switch(dir)
    {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case STOP:
            break;
    }
if(x <= 0 || x >= (width-1) || y < 0 || y >= height)
    gameOver = true;


if(x == fruitX && y == fruitY)
    {
        score += 10;
        nTail++;
        fruitSpawn();
    }



}


int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(200);

    }
    Draw();
    Sleep(500);
    while(!_kbhit()){;}

    return 0;
}
