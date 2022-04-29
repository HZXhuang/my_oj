#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
//#define debug 1
char young[100][10];
struct person
{
    char ID[10] = {0};
    int age;
};
person old[100];

int main()
{
    #ifdef debug
    freopen("debug/test1183.in", "r", stdin);
    freopen("debug/test1183.out", "w", stdout);
    #endif // debug
    int n,x = 0, y = 0,temp;
    char id[10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", id);
        scanf("%d", &temp);
        if (temp >= 60) {
            strcpy(old[x].ID, id);
            old[x].age = temp;
            x += 1;
        }
        else {
            strcpy(young[y++], id);
        }
    }
    bool ok;
    for (int i = x - 1; i > 0; i--) {
        ok = true;
        for (int j = 0; j < i; j++) {
            if (old[j].age < old[j + 1].age) {
                swap(old[j + 1], old[j]);
                ok = false;
            }
        }
        if (ok) break;
    }
    for (int i = 0; i < x; i++) {
        printf("%s\n", old[i].ID);
    }
    for (int i = 0; i < y; i++) printf("%s\n", young[i]);

    return 0;
}
