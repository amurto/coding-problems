#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    string str;
    cin >> str;
    int n = str.length();
    vector<int> st(26);
    ll inv = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = str[i] - 'a' - 1; j >= 0; j--)
            inv += st[j];
        st[str[i] - 'a']++;
    }
    ll add = inv;
    if (add & 1)
        add--;
    return inv + add;
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