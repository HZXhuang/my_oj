#include <bits/stdc++.h>
using namespace std;

bool judge(string &str, int &idx)
{
    if(str[1] > '9') return false;
    for (int i = 1; i < str.size(); i++)
    {
        if(str[i] == 'C') {
            idx = i;
            return true;
        }
    }
    return false;
}

int pow2(int x, int y)
{
    if (y == 0) return 1;
    int sum = 1;
    for (int i = 0; i < y; i++)
    {
        sum *= x;
    }
    return sum;
}

int main()
{
    int num;
    cin >> num;
    while(num-->0)
    {
        string str;
        int idx;
        cin >> str;
        if (str[0] == 'R' && judge(str, idx))
        {
            stack<char> st;
            int col = atoi(&str[idx + 1]);
            while (col > 0)
            {
                if (col % 26 == 0) { // 当列有Z时特判，这点非常重要
                    st.push((char)(26 + 64));
                    col = col / 26 - 1;
                }
                else {
                    st.push((char)(col % 26 + 64));
                    col = col / 26;
                }

            }
            while (!st.empty())
            {
                cout << st.top();
                st.pop();
            }
            cout << str.substr(1, idx - 1) << endl;
        }
        else {
            cout << 'R';
            int count1 = 0, col = 0;
            for (int i = 0; i < str.size(); i++)
            {
                if (str[i] <= '9') {
                    cout << str[i];
                    count1++;
                }
            }
            cout << 'C';
            int beg = str.size() - count1 - 1;
            for (int i = beg; i >=0; i--)
            {
                col += (int)(str[i] - 'A' + 1) * pow2(26, abs(i - beg));
            }
            cout << col << endl;
        }
    }

    return 0;
}
