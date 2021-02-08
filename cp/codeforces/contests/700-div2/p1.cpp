#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

char change(char ch, int c)
{
    if (c == 0)
    {
        if (ch == 'a')
            return 'b';
        return 'a';
    }
    if (ch == 'z')
        return 'y';
    return 'z';
}
string solve()
{
    string str;
    cin >> str;
    int n = str.length(), cur = 0;
    for (int i = 0; i < n; i++)
    {
        str[i] = change(str[i], cur);
        cur ^= 1;
    }
    return str;
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