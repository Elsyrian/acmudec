/************************************************************
*	4921 	Voting
*	http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&page=show_problem&problem=2922
*
*	Problema facil, no mucho que decir.
*
*
*
*/

#include <stdio.h>

int main() {

    int yes,no,ab,tot,i;
    char votes[100];

    while(1) {
        scanf("%s",votes);
        if(votes[0] == '#') break;
        yes = no = ab = tot = i = 0;

        while(votes[i] != '\0') {
            if(votes[i] == 'Y') yes++;
            if(votes[i] == 'N') no++;
            if(votes[i] == 'A') ab++;
            tot++;
            i++;
        }

        if(ab*2 >= tot) printf("need quorum\n");
        else if(yes > no) printf("yes\n");
        else if(yes == no) printf("tie\n");
        else printf("no\n");
    }

    return 0;
}
