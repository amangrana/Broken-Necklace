/*
 ID: dearxia1
 PROG: beads
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;

int n;
char nl[999] = {}, temp[399] = {};

int main()
{
//    ofstream fout ("beads.out");
//    ifstream fin ("beads.in");
    cin >> n;
    cin >> temp;
    strcpy(nl, temp);
    strcpy(nl+n, temp);
    int lft = 0, max = 0, lmax = 0, white = 0;
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
            lft ++;
            white ++;
            continue;
        }
        if (nl[i] == color) {
            lft ++;
            white = 0;
            continue;
        }
        color = nl[i];
        if (lmax + lft > max)
            max = lmax + lft;
        lmax = lft - white;
        lft = 1 + white;
        white = 0;
    }
    if (max > n || max == 0)
        max = n;
    cout << max << '\n';
    return 0;
}
