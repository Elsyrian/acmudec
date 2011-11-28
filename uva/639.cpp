/*************************************************************************************************************************
 * 639
 * 
 *
 * Classification: Dyanmic Programming
 *
 * Author:
 *   Javier Gonzalez Nova <javigonzalez@udec.cl>
 *
 * Description:
 *
 *
 */

#include <iostream>
#include <string.h>
#include <algorithm>
#define MAX 4
using namespace std;

int board[MAX][MAX];
int n;

void change(int row, int col, int flag) {
    for(int i = row; i < n && board[i][col] != -1; i++)
        board[i][col] += flag;
    for(int j = col; j < n && board[row][j] != -1; j++)
        board[row][j] += flag;
    for(int i = row; i >= 0 && board[i][col] != -1; i--)
        board[i][col] += flag;
    for(int j = col; j >= 0 && board[row][j] != -1; j--)
        board[row][j] += flag;

}

int solve(int rooks) {
    int mx = rooks;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 0) {
                change(i, j, 1);
                mx = max(solve(rooks+1), mx);
                change(i, j, -1);
            }
        }
    }

    return mx;
}

int main(void) {
    char c;

    while(1) {
        cin >> n;
        if(n == 0)
            break;

        memset(board, -1, sizeof(board));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> c;
                if(c == '.')
                    board[i][j] = 0;
            }
        }

        cout << solve(0) << endl;
    }

    return 0;
}
