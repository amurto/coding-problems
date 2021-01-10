// https://codeforces.com/contest/677/problem/C
// Vanya and Label

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;
unordered_map<char, int> sym;
void init()
{
    for (char i = '0'; i <= '9'; i++)
        sym[i] = i - '0';
    int j = 10;
    for (char i = 'A'; i <= 'Z'; i++, j++)
        sym[i] = j;
    for (char i = 'a'; i <= 'z'; i++, j++)
        sym[i] = j;
    sym['-'] = 62;
    sym['_'] = 63;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    string str;
    cin >> str;
    int res = 1;
    for (char ch : str)
    {
        int cur = sym[ch];
        for (int i = 0; i < 6; i++)
            if (!((1 << i) & cur))
                res = (res * 1ll * 3) % MOD;
    }
    cout << res << "\n";
    return 0;
}