#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, k, dis = 0;
    string str;
    cin >> n >> k >> str;
    for (int i = 1; i < n; i++)
        if (str[i - 1] == str[i])
            dis += 2;
        else
            dis++;
    for (int i = 0; i < k; i++)
    {
        int id;
        cin >> id;
        id--;
        if (id > 0)
        {
            if (str[id - 1] == str[id])
                dis -= 2;
            else
                dis--;
        }
        if (id < n)
        {
            if (str[id] == str[id + 1])
                dis -= 2;
            else
                dis--;
        }
        if (str[id] == '0')
            str[id] = '1';
        else
            str[id] = '0';
        if (id > 0)
        {
            if (str[id - 1] == str[id])
                dis += 2;
            else
                dis++;
        }
        if (id < n)
        {
            if (str[id] == str[id + 1])
                dis += 2;
            else
                dis++;
        }
        cout << dis << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}