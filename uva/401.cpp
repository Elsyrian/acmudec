/*************************************************************************************************************************
 * 401
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
#include <stdlib.h>
#include <string.h>
#define MAX 1000
using namespace std;

typedef vector<char> vc;

bool is_palindrome(char* word) {
    vc backward;
    int i;
    int l;

    l = strlen(word);
    for(i = 0; i < l; i++) {
        backward.push_back(word[l-i-1]);
    }

    for(i = 0; i < word[i]; i++) {
        if(word[i] != backward[i])
            return false;
    }
    return true;
}

char reverse(char letter) {
    switch(letter) {
        case 'A': return 'A';
        case 'E': return '3';
        case 'H': return 'H';
        case 'I': return 'I';
        case 'J': return 'L';
        case 'L': return 'J';
        case 'M': return 'M';
        case 'O': return 'O';
        case 'S': return '2';
        case 'T': return 'T';
        case 'U': return 'U';
        case 'V': return 'V';
        case 'W': return 'W';
        case 'X': return 'X';
        case 'Y': return 'Y';
        case '1': return '1';
        case '8': return '8';
        case 'Z': return '5';
        case '2': return 'S';
        case '3': return 'E';
        case '5': return 'Z';
        default: return '0';
    }
}

bool is_mirrored(char* word) {
    int i;
    char tmp[MAX+1];
    strcpy(tmp, word);
    for(i = 0; word[i]; i++) {
        if(reverse(word[i]) != '0') {
            word[i] = reverse(word[i]);
        }else{
            return false;
        }
    }

    vc backward;
    int l;

    l = strlen(word);
    for(i = 0; i < l; i++) {
        backward.push_back(word[l-i-1]);
    }

    for(i = 0; i < tmp[i]; i++) {
        if(tmp[i] != backward[i])
            return false;
    }
    return true;
}

int main(void) {
    char word[MAX+1];

    while(cin >> word) {
        char tmp[MAX+1];
        strcpy(tmp, word);
        if(is_palindrome(word)) {
            if(is_mirrored(word))
                cout << tmp << " -- is a mirrored palindrome.";
            else
                cout << tmp << " -- is a regular palindrome.";
        } else {
            if(is_mirrored(word))
                cout << tmp <<  " -- is a mirrored string.";
            else
                cout << tmp << " -- is not a palindrome.";
        }
        cout << endl;
        cout << endl;
    }
    return 0;
}
