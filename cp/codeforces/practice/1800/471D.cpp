// https://codeforces.com/contest/471/problem/D
// MUH and Cube Walls

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Prefix Function from cp-algorithms
vector<int> prefix_function(vector<int> s)
{
    int n = (int)s.size();
    vector<int> pre(n);
    for (int i = 1; i < n; i++)
    {
        int j = pre[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pre[j - 1];
        if (j == 0 || s[i] == s[j])
            j++;
        pre[i] = j;
    }
    return pre;
}

int solve()
{
    int n, w;
    cin >> n >> w;
    vector<int> a(n), b(w), diffA(n), diffB(w);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < w; i++)
        cin >> b[i];
    if (w > n)
        return 0;
    for (int i = 1; i < n; i++)
        diffA[i] = a[i] - a[i - 1];
    for (int i = 1; i < w; i++)
        diffB[i] = b[i] - b[i - 1];
    int cnt = 0, j = 0;
    vector<int> pre = prefix_function(diffB);
    for (int i : diffA)
    {
        if (j == w)
        {
            j = pre[j - 1];
            cnt++;
        }
        if (i == diffB[j])
            j++;
        else
        {
            while (j > 0 && i != diffB[j])
                j = pre[j - 1];
            j++;
        }
    }
    cnt += (j == w);
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}