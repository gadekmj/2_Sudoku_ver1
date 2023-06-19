



#include <iostream>
#include <stdio.h>
#include <array>
#include <conio.h>
using namespace std;

#define N 9 //size of the sudoku


class Sudoku
{
private:
    int sudokuboard[N][N];
    bool constans[N][N];

public:
    Sudoku(int t[9][9])
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                sudokuboard[i][j] = t[i][j];
        }
    }
    void copy(int sudokuboard[N][N]) //copy sudoku to check in future whith argument i can edit
    {
        for (int w = 0; w < N; w++)
        {
            for (int k = 0; k < N; k++)
            {
                constans[w][k] = !(sudokuboard[w][k]);
            }
        }
    }
    void print(int sudokuboard[N][N]) // printing sudoku
    {
        for (int w = 0; w < N; w++)
        {
            for (int k = 0; k < N; k++)
            {
                cout << sudokuboard[w][k] << " ";
                if (k % 3 == 2) cout << " ";
            }
            cout << endl;
            if (w % 3 == 2) cout << endl;
        }
    }
    bool checkwin(int sudokuboard[N][N])
    {
        for (int w = 0; w < N; w++)
        {
            for (int k = 0; k < N; k++)
            {
                if (sudokuboard[w][k] == 0) return false;
            }
        }
        return true;
    }
    bool checkColumn(int sudokuboard[N][N], int k, int value)
    {
        for (int w = 0; w < N; w++)
        {
            if (sudokuboard[w][k] == value)
            {
                cout << "Number: " << value << " is already in column" << endl;
                return false;
            }
        }
        return true;
    }
    bool checkRow(int sudokuboard[N][N], int w, int value)
    {
        for (int k = 0; k < N; k++)
        {
            if (sudokuboard[w][k] == value)
            {
                cout << "Number: " << value << " is already in row" << endl;
                return false;
            }
        }
        return true;
    }
    bool checkcue(int sudokuboard[N][N], int initial_row, int initial_column, int value)//checking numers in small cue//poprawic
    {
        int rowset = 3 * (initial_row / 3);
        int columnset = 3 * (initial_column / 3);//(initial_column / 3.0 <= 1.0) ? 0 : ((initial_column / 3.0 <= 2.0) ? 3 : 6));
        for (int w = 0; w < 3; w++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (sudokuboard[w + rowset][k + columnset] == value)
                {
                    cout << "Number: " << value << " is already in cue" << endl;
                    return false;

                }
            }
        }
        return true;
    }
    void set(int sudokuboard[N][N], int w, int k, int value)
    {
        if (constans[--w][--k] == true)
        {
            system("cls");
            if (checkColumn(sudokuboard, k, value) && checkRow(sudokuboard, w, value) && checkcue(sudokuboard, w, k, value))
            {
                sudokuboard[w][k] = value;
                cout << "Value changed" << endl;
            }
        }
        else
        {
            system("cls");
            cout << "You can't change it because it's sudoku set value" << endl;
        }
    }
};
class Zestaw
{
private:
    int sudokuTab[9][9][9] =
    {
        {
         {4, 3, 7, 8, 0, 5, 0, 0, 2},//1 
         {9, 1, 0, 4, 0, 0, 0, 3, 0},
         {0, 8, 0, 0, 0, 1, 4, 7, 9},
         {0, 9, 1, 3, 0, 0, 0, 0, 0},
         {0, 0, 0, 5, 1, 0, 0, 8, 7},
         {0, 0, 0, 6, 9, 0, 0, 4, 3},
         {0, 2, 9, 0, 6, 8, 0, 0, 5},
         {1, 0, 0, 9, 4, 3, 0, 2, 0},
         {0, 0, 0, 0, 5, 0, 8, 0, 1}
        },
        {
         {0, 6, 8, 0, 1, 0, 0, 4, 7},//2
         {0, 0, 0, 6, 8, 0, 1, 0, 5},
         {0, 9, 7, 2, 0, 4, 8, 0, 3},
         {0, 8, 0, 0, 0, 0, 3, 1, 2},
         {7, 0, 4, 0, 0, 2, 9, 0, 0},
         {2, 0, 9, 0, 3, 0, 0, 7, 0},
         {0, 0, 6, 0, 4, 0, 7, 8, 0},
         {8, 5, 0, 0, 2, 0, 4, 3, 0},
         {0, 0, 0, 0, 0, 0, 5, 2, 0}
        },
        {
         {5, 6, 0, 9, 0, 0, 4, 0, 0},///3
         {0, 0, 0, 6, 8, 0, 9, 0, 0},
         {0, 0, 0, 0, 0, 4, 0, 8, 3},
         {6, 8, 5, 0, 7, 0, 0, 0, 0},
         {2, 1, 9, 0, 0, 0, 0, 0, 0},
         {7, 0, 0, 1, 0, 2, 0, 0, 0},
         {0, 2, 6, 3, 0, 5, 0, 0, 0},
         {0, 0, 0, 0, 0, 6, 0, 0, 0},
         {4, 7, 0, 8, 0, 1, 0, 5, 0}
        },
        {
         {4, 5, 9, 0, 0, 0, 0, 0, 0},///4
         {0, 0, 0, 0, 0, 0, 2, 0, 7},
         {7, 6, 0, 5, 0, 0, 0, 8, 4},
         {0, 0, 5, 0, 6, 0, 0, 0, 8},
         {0, 0, 3, 1, 8, 0, 4, 0, 9},
         {2, 0, 0, 3, 7, 0, 0, 0, 1},
         {0, 0, 0, 0, 0, 8, 0, 4, 0},
         {5, 0, 0, 0, 9, 6, 0, 3, 0},
         {0, 0, 0, 7, 0, 3, 0, 0, 0}
        },
        {
         {0, 8, 0, 6, 0, 0, 0, 0, 0},///5
         {0, 5, 0, 8, 3, 0, 9, 0, 0},
         {0, 1, 0, 0, 0, 0, 7, 0, 0},
         {0, 0, 0, 0, 0, 0, 2, 0, 0},
         {4, 2, 9, 0, 0, 3, 0, 0, 1},
         {0, 0, 1, 9, 2, 0, 0, 7, 0},
         {8, 0, 0, 0, 5, 0, 0, 9, 0},
         {0, 0, 0, 0, 9, 6, 8, 1, 0},
         {0, 0, 6, 0, 0, 0, 0, 5, 7}
        },
        {
         {0, 0, 6, 5, 0, 8, 4, 0, 0},///6
         {5, 2, 0, 0, 0, 1, 0, 0, 0},
         {0, 7, 8, 0, 0, 0, 0, 0, 1},
         {0, 0, 4, 0, 1, 0, 0, 8, 0},
         {9, 0, 0, 8, 2, 3, 0, 0, 5},
         {0, 5, 0, 0, 9, 0, 6, 0, 0},
         {1, 3, 0, 0, 0, 0, 2, 5, 0},
         {0, 0, 0, 0, 0, 0, 0, 7, 4},
         {0, 0, 5, 2, 0, 6, 3, 0, 0}
        },
        {
         {0, 0, 6, 0, 0, 5, 0, 0, 0},///7
         {0, 0, 8, 0, 0, 0, 0, 4, 5},
         {7, 0, 0, 0, 0, 0, 1, 0, 0},
         {0, 0, 0, 0, 0, 0, 6, 0, 3},
         {0, 0, 0, 0, 0, 0, 0, 5, 0},
         {0, 3, 0, 6, 0, 0, 9, 0, 0},
         {9, 6, 0, 0, 0, 1, 3, 0, 0},
         {1, 0, 0, 0, 0, 0, 0, 2, 0},
         {0, 0, 4, 0, 8, 2, 0, 0, 0}
        },
        {
         {0, 6, 0, 0, 0, 7, 0, 0, 0},///8
         {0, 1, 0, 0, 0, 0, 7, 0, 0},
         {4, 0, 0, 0, 6, 5, 0, 0, 9},
         {0, 0, 0, 0, 0, 0, 0, 4, 0},
         {3, 0, 4, 9, 0, 0, 0, 0, 0},
         {5, 0, 0, 0, 7, 2, 0, 0, 0},
         {0, 0, 0, 1, 0, 3, 0, 9, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 6},
         {2, 9, 0, 0, 0, 0, 5, 0, 0}
        },
        {
         {8, 5, 6, 4, 9, 2, 1, 0, 7},///9 control
         {2, 1, 3, 8, 6, 7, 5, 0, 0},
         {4, 7, 9, 5, 1, 3, 2, 6, 8},
         {3, 2, 4, 7, 5, 6, 9, 8, 1},
         {5, 6, 8, 9, 2, 1, 4, 7, 3},
         {7, 9, 1, 3, 4, 8, 6, 2, 5},
         {6, 8, 2, 1, 7, 5, 3, 9, 4},
         {1, 4, 7, 2, 3, 9, 8, 5, 6},
         {9, 3, 5, 6, 8, 4, 7, 1, 2}
        },
    };

public:
    int sudokuboard[9][9];
    Zestaw(int lvl)
    {
        for (int w = 0; w < N; w++)
        {
            for (int k = 0; k < N; k++)
            {
                sudokuboard[w][k] = sudokuTab[lvl][w][k];
            }
        }

    }
};




int main() {
    int w, k, value, lvl, i=0;
    string menu = "";
   
   
    while (menu != "exit")
    {
        cout << "     SUDOKU GAME MENU" << endl << "To begin game type('start') " << endl << "To end   game type('exit')" << endl;
        cin >> menu;
        system("cls");
        if (menu != "exit") 
        {
            cout << "Set Sudoku hard level(1-9):" << endl;
            cin >> lvl;
            Zestaw zestaw(lvl - 1);
            Sudoku sudoku(zestaw.sudokuboard);
            sudoku.copy(zestaw.sudokuboard);
            while (!sudoku.checkwin(zestaw.sudokuboard)) //rozwiazywanie sudoku
            {
                cout << "Sudoku lvl: " << lvl << endl;
                sudoku.print(zestaw.sudokuboard);
                cout << endl << "Set row and column you want change(1-9): ";
                cin >> w >> k;
                cout << endl << "Set value: ";

                cin >> value;
                if (w > 9 || k > 9 || value > 9|| w > 9 || k > 9 || value > 9)
                {
                system("cls");
                cout << "One of parameters was out of range" << endl;
                continue;
                }
                sudoku.set(zestaw.sudokuboard, w, k, value);
            }
            if (sudoku.checkwin(zestaw.sudokuboard) == 1) 
            {
                system("cls");
                cout << "You correctly solved sudoku lvl: " << lvl << endl;
            }
                
        }
        else cout << "Come back soon :)" << endl;
    }
}