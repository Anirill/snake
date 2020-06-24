#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;

bool gameOver;
const int width = 30;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;


void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2 - 1;
    y = height / 2 - 1;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw()
{
    system("cls");
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
                cout << " ";

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
    }
if(x <= 0 || x >= (width-1) || y <= 0 || y >= (height-1))
    gameOver = true;
if(x == fruitX && y == fruitY)
    {
        score++;
        fruitX = rand() % width;
        fruitY = rand() % height;
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
        _sleep(100);

    }

    return 0;
}
