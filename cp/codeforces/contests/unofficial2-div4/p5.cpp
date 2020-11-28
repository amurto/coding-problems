#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string str, t;
    cin >> str >> t;
    ll res = 0;
    int last = -1;
    for (int L = 0, R = 1; R < n; L++, R++)
    {
        if (str[L] == t[0] && str[R] == t[1])
            last = L;
        res += last + 1;
    }
    cout << res << "\n";
    return 0;
}