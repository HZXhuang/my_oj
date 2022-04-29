#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//#define debug
float male[40],female[40];

int main()
{
    #ifdef debug
    freopen("debug/test1182.in", "r", stdin);
    freopen("debug/test1182.out", "w", stdout);
    #endif // debug
    int n,x = 0,y = 0;
    string sex;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> sex;
        if (sex == "male") scanf("%f", &male[x++]);
        else if (sex == "female") scanf("%f", &female[y++]);
    }
    sort(male, male + x);
    sort(female, female + y);
    for (int i = 0; i < x; i++) printf("%.2f ", male[i]);
    for (int i = y - 1; i >= 0; i--) printf("%.2f ", female[i]);

    return 0;
}
