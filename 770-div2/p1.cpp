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

bool is_palindrome(string &str)
{
    int n = (int)str.length();
    for (int i = 0, j = n - 1; i < j; i++, j--)
        if (str[i] != str[j])
            return false;
    return true;
}
int solve()
{
    int n, k;
    string str;
    cin >> n >> k >> str;
    if (k == 0)
        return 1;
    if (is_palindrome(str))
        return 1;
    return 2;
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