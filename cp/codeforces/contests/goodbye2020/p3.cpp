#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    string str;
    cin >> str;
    int n = str.length(), c = 0;
    if (n == 1)
        return 0;
    if (str[1] == str[0])
    {
        str[1] = '1';
        c++;
    }
    for (int i = 2; i < n; i++)
    {
        if (str[i] == str[i - 2] || str[i] == str[i - 1])
        {
            str[i] = '1';
            c++;
        }
    }
    return c;
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