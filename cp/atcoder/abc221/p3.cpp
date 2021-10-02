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

ll solve()
{
    string n;
    cin >> n;
    ll res = 0;
    int sz = n.length();
    sort(n.begin(), n.end());
    do
    {
        for (int i = 0; i < sz - 1; i++)
        {
            string s1 = n.substr(0, i + 1), s2 = n.substr(i + 1, sz - i);
            if (s1[0] != '0' && s2[0] != '0')
            {
                int num1 = stoi(s1), num2 = stoi(s2);
                res = max(res, num1 * 1ll * num2);
            }
        }
    } while (next_permutation(n.begin(), n.end()));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}