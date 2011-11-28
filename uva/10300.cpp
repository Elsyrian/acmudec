/*************************************************************************************************************************
 * 10300
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

#include <iostream> /*cin, cout*/
using namespace std;

int main(void) {
    int sizeFarm, animals, environment;
    int cases, farmers;
    int premium;

    while(cin >> cases) {
        while(cases--) {
            premium = 0;
            cin >> farmers;
            while(farmers--) {
                cin >> sizeFarm >> animals >> environment;
                premium += sizeFarm*environment;
            }
            cout << premium << endl;
        }
    }

    return 0;
}
