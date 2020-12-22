#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string str;
        cin >> str;
        int n = str.length(), s = 0, sf = 0;
        ll res = 0;
        map<int, int> pre;
        pre[0] = 1;
        for (char ch : str)
            if (ch != '?')
                s ^= (1 << (ch - 'a'));
        for (char ch : str)
        {
            if (ch == '?')
                sf ^= (1 << 26);
            else
                sf ^= (1 << (ch - 'a'));
            res += pre[sf ^ s];
            for (int i = 0; i < 26; i++)
                res += pre[sf ^ s ^ (1 << 26) ^ (1 << i)];
            pre[sf]++;
        }
        cout << res << "\n";
    }
    return 0;
}