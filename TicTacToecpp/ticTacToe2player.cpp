//Program to implement tictactoe game for two players.
//Author - Vedika Udgir

#include <iostream>
#include <stdbool.h>
using namespace std;

class TicTacToe2Player
{
private:
    char matrix[3][3] = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}};
    int i, j;

    void player1()
    {
        cout << "\nPLAYER 1: \n";
        do
        {
            cout << "\nEnter row - ";
            cin >> i;
        } while (i < 0 || i > 2);
        do
        {
            cout << "\nEnter coloumn - ";
            cin >> j;
        } while (j < 0 || j > 2);

        if (matrix[i][j] == '_')
        {
            matrix[i][j] = 'X';
        }
        else
        {
            player1();
        }
    }
    void player2()
    {
        cout << "\nPLAYER 2: \n";
        cout << "\nEnter row - ";
        cin >> i;
        cout << "\nEnter coloumn - ";
        cin >> j;

        if (matrix[i][j] == '_')
        {
            matrix[i][j] = 'O';
        }
        else
        {
            player2();
        }
    }

    int gameend()
    {
        for (int i = 0; i < 3; i++)
        {
            if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][2] != '_')
            {
                return matrix[i][2] == 'X' ? 0 : 1;
            }
            if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[2][i] != '_')
            {
                return matrix[2][i] == 'X' ? 0 : 1;
            }
        }
        if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[0][0] != '_')
        {
            return (matrix[0][0] == 'X') ? 0 : 1;
        }
        if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[0][2] != '_')
        {
            return (matrix[0][2] == 'X') ? 0 : 1;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (matrix[i][j] == '_')
                {
                    return 2;
                }
            }
        }
        return -1;
    }

    void printMatrix()
    {
        for (int u = 0; u < 3; u++)
        {
            for (int v = 0; v < 3; v++)
            {
                cout << " " << matrix[u][v] << " ";
            }
            cout << endl;
        }
    }

public:
    void gameplay()
    {
        do
        {
            player1();
            printMatrix();
            if (gameend() == 0)
            {
                cout << "\nPlayer 1 wins!!!";
                return;
            }
            player2();
            printMatrix();
            if (gameend() == 1)
            {
                cout << "\nPlayer 2 wins!!!";
                return;
            }
            if (gameend() == -1)
            {
                cout << "\nDRAW";
                return;
            }
        } while (true);
    }
};

int main()
{
    TicTacToe2Player x;
    x.gameplay();
}
