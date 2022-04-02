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
    int n, a = 0, b = 0;
    string str;
    cin >> n >> str;
    for (char ch : str)
        if (ch == 'N')
            a++;
        else
            b++;
    if (a > b)
        return "Nutan";
    return "Tusla";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}