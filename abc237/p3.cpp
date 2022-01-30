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

bool is_palindrome(string str)
{
    int n = (int)str.length();
    for (int i = 0, j = n - 1; i < j; i++, j--)
        if (str[i] != str[j])
            return false;
    return true;
}

bool solve()
{
    string str;
    cin >> str;
    if (is_palindrome(str))
        return true;
    int n = (int)str.length();
    int l = 0, r = n - 1, la = 0, ra = 0;
    while (str[l] == 'a')
    {
        la++;
        l++;
    }
    while (str[r] == 'a')
    {
        ra++;
        r--;
    }
    if (la <= ra && is_palindrome(str.substr(l, r - l + 1)))
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}