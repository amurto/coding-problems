#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    int n;
    cin >> n;
    if (n == 1)
        return "1";
    int tmp = n, cur = 2;
    string str1 = "", str2 = "";
    while (tmp > 0)
    {
        str1.pb('0' + cur);
        if (cur > tmp)
            str1 = "-1";
        tmp -= cur;
        if (cur == 2)
            cur = 1;
        else
            cur = 2;
    }
    tmp = n;
    cur = 1;
    while (tmp > 0)
    {
        str2.pb('0' + cur);
        if (cur > tmp)
            str2 = "-1";
        tmp -= cur;
        if (cur == 2)
            cur = 1;
        else
            cur = 2;
    }
    if (str1 == "-1")
        str1 = str2;
    else
    {
        if (str2 != "-1")
        {
            int sz1 = (int)str1.length(), sz2 = (int)str2.length();
            if (sz1 < sz2)
                str1 = str2;
            else if (sz1 == sz2)
                str1 = max(str1, str2);
        }
    }
    return str1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}