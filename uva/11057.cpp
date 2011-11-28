/*************************************************************************************************************************
 * 11057
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
#include <stdlib.h>
using namespace std;

int main(void) {
    vector<int> books;
    int n;
    int diff;
    int booki, bookj;
    int m;
    char blankLine[2];

    while(cin >> n) {
        books.clear();
        diff = -1;
        for(int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            books.push_back(tmp);
        }
        cin >> m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && (books[i]+books[j] == m)) {
                    if(diff == -1) {
                        diff = abs(books[i]-books[j]);
                        booki = i;
                        bookj = j;
                    } else if((abs(books[i]-books[j]) < diff) && (i < j)) {
                        diff = abs(books[i]-books[j]);
                        booki = i;
                        bookj = j;
                    }
                }
            }
        }
        cin.getline(blankLine, 2);
        cout << "Peter should buy books whose prices are " << min(books[booki], books[bookj]) << " and " << max(books[booki], books[bookj]) << "." << endl << endl;
    }

    return 0;
}
