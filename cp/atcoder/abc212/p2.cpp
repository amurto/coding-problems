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
    string str;
    cin >> str;
    vector<int> nxt(10);
    for (int i = 0; i < 10; i++)
        nxt[i] = (i + 1) % 10;
    bool s = true, f = true;
    for (int i = 1; i < 4; i++)
    {
        if (str[i - 1] != str[i])
            s = false;
        if (nxt[str[i - 1] - '0'] != str[i] - '0')
            f = false;
    }
    if (s || f)
        return "Weak";
    return "Strong";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}