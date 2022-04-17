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

string calc(string str, vector<int> &moves, int n, int k)
{
    if (k < 0)
    {
        string res(n, '0');
        return res;
    }
    int prev = str[0] - '0', f = 0;
    for (int i = 1; k > 0 && i < n; i++)
    {
        int cur = (str[i] - '0') ^ f;
        if (cur != prev)
        {
            if (prev == 0)
            {
                moves[i]++;
                f ^= 1;
                prev = 1;
                k--;
            }
            else
            {
                if (k > 1)
                {
                    moves[i]++;
                    f ^= 1;
                    prev = 0;
                    k--;
                }
            }
        }
    }
    string res = str;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += moves[i];
    for (int i = 0; i < n; i++)
    {
        int t = (sum - moves[i]) & 1;
        if (t == 1)
        {
            if (res[i] == '1')
                res[i] = '0';
            else
                res[i] = '1';
        }
    }
    if (k > 0 && res[0] == '0')
    {
        int id = n - 1;
        for (int i = 0; i < n; i++)
            if (res[i] == '1')
                id = min(id, i);
        moves[id]++;
        for (int i = 0; i < n; i++)
        {
            if (i != id)
            {
                if (res[i] == '1')
                    res[i] = '0';
                else
                    res[i] = '1';
            }
        }
        k--;
    }
    moves[0] += k;
    k %= 2;
    if (k & 1)
    {
        for (int i = 1; i < n; i++)
        {
            if (res[i] == '1')
                res[i] = '0';
            else
                res[i] = '1';
        }
    }
    return res;
}

void solve()
{
    int n, k;
    string str, res1 = "", res2 = "";
    cin >> n >> k >> str;
    vector<int> moves1(n), moves2(n);
    string str2 = str;
    for (int i = 1; i < n; i++)
        if (str2[i] == '1')
            str2[i] = '0';
        else
            str2[i] = '1';
    res1 = calc(str, moves1, n, k);
    res2 = calc(str2, moves2, n, k - 1);
    moves2[0]++;
    if (res1 < res2)
    {
        swap(res1, res2);
        swap(moves1, moves2);
    }
    cout << res1 << "\n";
    for (int x : moves1)
        cout << x << " ";
    cout << "\n";
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