#include "../header.h"

class TicTacToe {
public:
    TicTacToe(int n) {
        diag = anti = 0;
        rows.resize(n);
        cols.resize(n);
        iswin = 0;
        len = n;
    }

    int move(int row, int col, int player) {
        if (iswin > 0) {
            return iswin;
        }
        int addint = player == 1 ? 1 : -1;
        rows[row] += addint;
        cols[col] += addint;
        if (row == col) {
            diag += addint;
        }
        if (row == len - 1 - col) {
            anti += addint;
        }
        if (rows[row] == len || cols[col] == len || diag == len || anti == len) {
            iswin = 1;
            return 1;
        }
        else if (rows[row] == -len || cols[col] == -len || diag == -len || anti == -len) {
            iswin = 2;
            return 2;
        }
        return 0;
    }
    
private:
    vector<int> rows, cols;
    int diag, anti;
    int iswin, len;
};

int main()
{
    TicTacToe ttt(3);
    ttt.move(0, 0, 1);
    ttt.move(0, 2, 2);
    ttt.move(2, 2, 1);
    ttt.move(1, 1, 2);
    ttt.move(2, 0, 1);
    ttt.move(1, 0, 2);
    ttt.move(2, 1, 1);
    return 0;
}