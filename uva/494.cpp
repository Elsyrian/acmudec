/*************************************************************************************************************************
 * 494
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
#include <string.h>
#include <stdio.h>
using namespace std;

#define MAX 1000

int countWords(char* text) {
    int words = 0;
    int i;
    bool inWord = false;

    for(i = 0; text[i]; i++) {
        if(isalpha(text[i])) {
            if(!inWord) {
                words++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }

    return words;
}

int main(void) {
    char text[MAX+1];
    int tmp;

    while(fgets(text, MAX+1, stdin)) {
        tmp = countWords(text);
        cout << tmp << endl;
    }

    return 0;
}
