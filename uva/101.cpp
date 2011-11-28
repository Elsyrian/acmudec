/*************************************************************************************************************************
 * 101 - The Blocks Problem
 * 
 *
 * Classification:
 *
 * Author:
 *   Javier Gonzalez Nova <javigonzalez@udec.cl>
 *
 * Description:
 *
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int N;

void remove_block_top(vii &Block, int a, int pos) {
    int tmp;
    tmp = Block[pos].back();
    while(tmp != a) {
        Block[Block[pos].back()].push_back(Block[pos].back());
        Block[pos].pop_back();
        tmp = Block[pos].back();
    }
}

bool is_on(vi Block, int a) {
    if(count(Block.begin(), Block.end(), a) == 1)
        return true;
    else
        return false;
}

void move_stack(vi &BlockA, vi &BlockB, int a) {
    stack<int> block_tmp;
    int tmp;
    tmp = BlockA.back();
    while(tmp != a) {
        block_tmp.push(tmp);
        BlockA.pop_back();
        tmp = BlockA.back();
    }
    block_tmp.push(tmp);
    BlockA.pop_back();
    while(!block_tmp.empty()) {
        BlockB.push_back(block_tmp.top());
        block_tmp.pop();
    }
}

void move_onto(vii &Block, int a, int b) {
    int i;
    int block_a, block_b;
    for(i = 0; i < N; i++) {
        if(is_on(Block[i], a)) {
            remove_block_top(Block, a, i);
            block_a = i;
        }
        if(is_on(Block[i], b)) {
            remove_block_top(Block, b, i);
            block_b = i;
        }
    }

    Block[block_a].pop_back();
    Block[block_b].push_back(a);
}

void move_over(vii &Block, int a, int b) {
    int i;
    int block_a, block_b;
    for(i = 0; i < N; i++) {
        if(is_on(Block[i], a)) {
            remove_block_top(Block, a, i);
            block_a = i;
        }
        if(is_on(Block[i], b)) {
            block_b = i;
        }
    }

    Block[block_a].pop_back();
    Block[block_b].push_back(a);
}

void pile_onto(vii &Block, int a, int b) {
    int i;
    int block_a, block_b;
    for(i = 0; i < N; i++) {
        if(is_on(Block[i], a)) {
            block_a = i;
        }
        if(is_on(Block[i], b)) {
            remove_block_top(Block, b, i);
            block_b = i;
        }
    }
    move_stack(Block[block_a], Block[block_b], a);
}

void pile_over(vii &Block, int a, int b) {
    int i;
    int block_a, block_b;
    for(i = 0; i < N; i++) {
        if(is_on(Block[i], a))
            block_a = i;
        if(is_on(Block[i], b))
            block_b = i;
    }
    move_stack(Block[block_a], Block[block_b], a);
}

int main(void) {
    char cmd1[5], cmd2[5];
    int a, b;
    int i, j;

    cin >> N;

    vii Block(N);
    Block.clear();
    for(i = 0; i < N; i++) {
        Block[i].push_back(i);
    }


    while(1) {
        cin >> cmd1;
        if(!strcmp(cmd1, "quit"))
            break;

        cin >> a >> cmd2 >> b;

        int block_a, block_b;
        for(i = 0; i < N; i++) {
            if(is_on(Block[i], a))
                block_a = i;
            if(is_on(Block[i], b))
                block_b = i;
        }

        if(block_a != block_b) {
            if(!strcmp(cmd1, "move")) {
                if(!strcmp(cmd2, "onto")) {
                    /*move a onto b*/
                    move_onto(Block, a, b);
                } else {
                    /*move a over b*/
                    move_over(Block, a, b);
                }
            } else {
                if(!strcmp(cmd2, "onto")) {
                    /*pile a onto*/
                    pile_onto(Block, a, b);
                } else {
                    /*pile a over*/
                    pile_over(Block, a, b);
                }
            }
        }
    }

    for(i = 0; i < N; i++) {
        cout << i << ":";
        for(j = 0; j < Block[i].size(); j++) {
            cout << " " << Block[i][j];
        }
        cout << endl;
    }

    return 0;
}
