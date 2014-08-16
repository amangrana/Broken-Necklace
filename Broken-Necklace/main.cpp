/*
 ID: dearxia1
 PROG: beads
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int n;
char nl[999] = {}, temp[399] = {};

int main()
{
//    ofstream fout ("beads.out");
//    ifstream fin ("beads.in");
    cin >> n >> temp;
    strcpy(nl, temp);
    strcat(nl, temp);
    int left = 0, max = 0, lsum = 0, white = 0;
    char color = 'x';  //x means uncheck
    for (int i = 0; i < n; i++) {
        if (temp[i] != 'w')
        {
            color = temp[i];
            break;
        }
    }
    if (color == 'x')    // all white
    {
        cout << n << '\n';
        return 0;
    }
    for (int i = 0; i < 2 * n; i++) {
        if (nl[i] == 'w') {
            left ++;
            white ++;
            continue;
        }
        if (nl[i] == color) {
            left ++;
            white = 0;
            continue;
        }
        color = nl[i];
        if (lsum + left > max)
            max = lsum + left;
        lsum = left - white;
        /*in case adding the white beads adjacent to the break point twice, 
         we only add them from the right side*/
        
        left = 1 + white;        //taking white beads on the left in account
        white = 0;
    }
    if (max > n || max == 0)
        max = n;
    cout << max << '\n';
    return 0;
}
