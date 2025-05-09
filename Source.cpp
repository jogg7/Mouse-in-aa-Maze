#include <iostream>
#include <string>
#include <fstream>
#include "Coordinates.h"
#include <Windows.h>
#include <conio.h>
#include "MyRectangle.h"


using namespace std;

struct position
{
    int x;
    int y;
};

class MyStack
{
public:
    position arr[1000];
    int T;
    MyStack() { T = 0; }
    void push(int x, int y);
    position pop();
    position peek();
};


void MyStack::push(int x, int y)
{
    position p;
    p.x = x;
    p.y = y;
    arr[T] = p;
    T++;
}

position MyStack::pop()
{
    T--;
    return arr[T];
}

position MyStack::peek()
{
    return arr[T - 1];
}

MyStack S;
char board[22][50];
int value;
int xpos, ypos;
Coordinates C;

// returns false of xy same as top of stack
bool CheckTopStack(int x, int y)
{
    position p;
    p = S.peek();
    if (p.x == x && p.y == y)
        return false;
    return true;
}

//slows down mouse and lets user move
bool slowdown()
{
    double a = 0;
    while (a < 10)
    {
        if (_kbhit())
            return true;
        a = a + 1;
        Sleep(1);
    }
    return false;
}


int main()
{

    ifstream input("c:\\temp\\mazeinterface.txt");

    for (int i = 0; i < 22; i++)
        for (int j = 0; j < 50; j++)
            input >> board[i][j];

    system("cls");

    //set color of maze to aqua and background to black
    system("Color 0B");

    //display maze
    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (board[i][j] == '1')
                cout << char(219);
            else if (board[i][j] == '2')
                cout << char(176);
            else
                cout << " ";
        }
        cout << endl;
    }

    //For user player
    Coordinates j;

    //user player coordinates
    int x2 = 1;
    int y2 = 20;

    //hold keyboard input
    char keyboard;

    //hold console color 
    int endcolor;

    //hold text color
    int endcolor2;

    //x y coordinates for congrats screen
    int x, y;

    //for text output
    Coordinates z;

    //for control box output
    Coordinates f;

    //controls box
    MyRectangle R(60, 1, 28, 28, char(219), true, 9, 10);
    R.Draw();

    //Output box name
    f.gotoxy(66, 0);
    cout << "CONTROLS";

    //Movement controls
    f.gotoxy(62, 2);
    cout << "W - move up";
    f.gotoxy(62, 4);
    cout << "A - move left";
    f.gotoxy(62, 6);
    cout << "S - move down";
    f.gotoxy(62, 8);
    cout << "D - move right";

    //Controls to blow up wall
    f.gotoxy(62, 10);
    cout << "1 - blowup top";
    f.gotoxy(62, 12);
    cout << "2 - blowup right";
    f.gotoxy(62, 14);
    cout << "3 - blowup left";
    f.gotoxy(62, 16);
    cout << "4 - blowup below";

    //COntrols to add wall
    f.gotoxy(62, 18);
    cout << "5 - add wall top";
    f.gotoxy(62, 20);
    cout << "6 - add wall right";
    f.gotoxy(62, 22);
    cout << "7 - add wall left";
    f.gotoxy(62, 24);
    cout << "8 - add wall below";

    //Diplsay innovation color change maze
    f.gotoxy(62, 26);
    cout << "Space - Change Maze Color";

    xpos = 0;
    ypos = 1;

    while (1)
    {


        //display mouse
        C.gotoxy(xpos, ypos);
        cout << "*";

        //display user
        j.gotoxy(x2, y2);
        cout << "X";

        if (slowdown())
        {
            keyboard = _getch();

            //cout << (int)keyboard << endl;;


            //Blow up wall in direction user wants
            if (keyboard == 49) //1 is blow up top wall
            {
                if (y2 != 1)
                {
                    board[y2 - 1][x2] = '0';
                    j.gotoxy(x2, y2 - 1);
                    cout << " ";
                }
            }
            if (keyboard == 50) //2 is blow up right wall
            {
                if (x2 != 48)
                {
                    board[y2][x2 + 1] = '0';
                    j.gotoxy(x2 + 1, y2);
                    cout << " ";
                }
            }
            if (keyboard == 51) //3 is blow up left wall
            {
                if (x2 != 1)
                {
                    board[y2][x2 - 1] = '0';
                    j.gotoxy(x2 - 1, y2);
                    cout << " ";
                }
            }
            if (keyboard == 52) //4 is blow up bottom wall
            {
                if (y2 != 20)
                {
                    board[y2 + 1][x2] = '0';
                    j.gotoxy(x2, y2 + 1);
                    cout << " ";
                }
            }

            //add walls in user slected direction
            if (keyboard == 53) //5 is add top wall
            {
                if (y2 != 1)
                {
                    board[y2 - 1][x2] = '1';
                    j.gotoxy(x2, y2 - 1);
                    cout << char(219);
                }
            }
            if (keyboard == 54) //6 is add right wall
            {
                if (x2 != 48)
                {
                    board[y2][x2 + 1] = '1';
                    j.gotoxy(x2 + 1, y2);
                    cout << char(219);
                }
            }
            if (keyboard == 55) //7 is add left wall
            {
                if (x2 != 1)
                {
                    board[y2][x2 - 1] = '1';
                    j.gotoxy(x2 - 1, y2);
                    cout << char(219);
                }
            }
            if (keyboard == 56) //8 is add bottom wall
            {
                if (y2 != 20)
                {

                    board[y2 + 1][x2] = '1';
                    j.gotoxy(x2, y2 + 1);
                    cout << char(219);
                }
            }


            //Innovation chnages color of mazze
            if (keyboard == 32) //keyboard
            {
                //hold color choice
                int random = 0;

                //randomize color for maze
                random = rand() % 13;

                //color based on randomized number
                if (random == 5)
                {
                    system("Color 0A");
                }
                if (random == 4)
                {
                    system("Color 0C");
                }
                if (random == 3)
                {
                    system("Color 0D");
                }
                if (random == 2)
                {
                    system("Color 0E");
                }
                if (random == 1)
                {
                    system("Color 0F");
                }
                if (random == 6)
                {
                    system("Color 08");
                }
                if (random == 7)
                {
                    system("Color 04");
                }
                if (random == 8)
                {
                    system("Color 01");

                }
                if (random == 9)
                {
                    system("Color 0B");
                }
                if (random == 10)
                {
                    system("Color 03");
                }
                if (random == 11)
                {
                    system("Color 09");
                }
                if (random == 12)
                {
                    system("Color 07");
                }

            }
            else if (keyboard == 100) //move right
            {
                if (board[y2][x2 + 1] == '0')
                {
                    j.gotoxy(x2, y2);
                    cout << " ";
                    x2++;
                    j.gotoxy(x2, y2);
                    cout << "X";
                }
            }
            else if (keyboard == 97) //move left
            {
                if (board[y2][x2 - 1] == '0')
                {
                    j.gotoxy(x2, y2);
                    cout << " ";
                    x2--;
                    j.gotoxy(x2, y2);
                    cout << "X";
                }
            }
            else if (keyboard == 119) //move up
            {
                if (board[y2 - 1][x2] == '0')
                {
                    j.gotoxy(x2, y2);
                    cout << " ";
                    y2--;
                    j.gotoxy(x2, y2);
                    cout << "X";
                }
            }
            else if (keyboard == 115) // move down
            {
                if (board[y2 + 1][x2] == '0')
                {
                    j.gotoxy(x2, y2);
                    cout << " ";
                    y2++;
                    j.gotoxy(x2, y2);
                    cout << "X";
                }
            }
        }


        //when at end party screen
        if (xpos == 49 && ypos == 20)
        {
            for (int i = 1; i < 100; i++)
            {
                //clear screen
                system("cls");

                // Color of the console
                HANDLE console_color;
                console_color = GetStdHandle(
                    STD_OUTPUT_HANDLE);

                //randomize color for text and console
                endcolor = rand() % 50;
                endcolor2 = rand() % 50;

                //if not the same color 
                if (endcolor != endcolor2)
                {
                    //set color of console
                    SetConsoleTextAttribute(console_color, endcolor);

                    //randomize x and y locations for text
                    x = rand() % 75;
                    y = rand() % 75;

                    //position to cout text 
                    z.gotoxy(x, y);

                    //cout message
                    cout << endcolor2 << "CONGRATULATIONS, YOU WIN!";

                    //slow down
                    Sleep(500);
                }

            }


        }
        C.gotoxy(xpos, ypos);
        cout << " ";
        if ((board[ypos][xpos + 1] == '0') &&
            (CheckTopStack(xpos + 1, ypos)))
        {
            S.push(xpos, ypos);
            xpos++;
        }
        else if ((board[ypos + 1][xpos] == '0') &&
            (CheckTopStack(xpos, ypos + 1)))
        {
            S.push(xpos, ypos);
            ypos++;
        }
        else if ((board[ypos][xpos - 1] == '0') &&
            (CheckTopStack(xpos - 1, ypos)))
        {
            S.push(xpos, ypos);
            xpos--;
        }
        else if ((board[ypos - 1][xpos] == '0') &&
            (CheckTopStack(xpos, ypos - 1)))
        {
            S.push(xpos, ypos);
            ypos--;
        }
        else // dead end
        {
            C.gotoxy(xpos, ypos);
            cout << char(219);
            board[ypos][xpos] = '1';
            position p;
            p = S.pop();
            xpos = p.x;
            ypos = p.y;
            slowdown();
        }

    }

}
