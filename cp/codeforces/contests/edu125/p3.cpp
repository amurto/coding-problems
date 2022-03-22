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

void solve()
{
    int n;
    string str;
    cin >> n >> str;
    int c = 0, r = n, itr = 0;
    bool pos = true;
    while (itr < n && pos)
    {
        if (itr == n - 1)
            pos = false;
        else
        {
            if ((str[itr] == '(' && str[itr + 1] == ')') || (str[itr] == str[itr + 1]))
            {
                itr += 2;
                c++;
                r -= 2;
            }
            else
            {
                int tmp = itr + 1;
                while (tmp < n && str[tmp] != ')')
                    tmp++;
                if (tmp == n)
                    pos = false;
                else
                {
                    tmp++;
                    c++;
                    r -= (tmp - itr);
                    itr = tmp;
                }
            }
        }
    }
    cout << c << " " << r << "\n";
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