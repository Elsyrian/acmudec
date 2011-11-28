/*************************************************************************************************************************
 * 694
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
using namespace std;

long long n;
long long limit;

int Lothar(long long A) {
    if(A == 1 ||(A > limit)) {
        if(A == 1)
            n++;
        return 0;
    } else {
        n++;
        if(A%2 == 0) {
            Lothar(A/2);
        } else {
            Lothar((3*A)+1);
        }
    }
}

int main(void) {
    long long a;
    int cases = 1;

    while(1) {
        cin >> a >> limit;
        if(a == -1 && limit == -1)
            break;

        n = 0;
        Lothar(a);
        cout << "Case " << cases++ << ": A = " << a << ", limit = " << limit << ", number of terms = " << n << endl;
    }

    return 0;
}
