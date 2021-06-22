// https://codeforces.com/contest/432/problem/D
// Prefixes and Suffixes

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Prefix Function from cp-algorithms
vector<int> prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pre(n);
    for (int i = 1; i < n; i++)
    {
        int j = pre[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pre[j - 1];
        if (s[i] == s[j])
            j++;
        pre[i] = j;
    }
    return pre;
}

void solve()
{
    string str;
    cin >> str;
    int n = str.length();
    if (n == 1)
    {
        cout << "1\n";
        cout << "1 1\n";
        return;
    }
    vector<int> pre = prefix_function(str);
    int cur = pre[n - 1];
    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
        cout << pre[i] << " ";
    // while (cur > 0)
    // {
    //     cout << cur << "\n";
    //     vis[cur - 1] = true;
    //     cur = pre[cur]-1;
    // }
    // vector<int> diff(n + 1);
    // for (int i = 1; i < n; i++)
    // {
    //     if (pre[i] > 0)
    //     {
    //         diff[0]++;
    //         diff[pre[i]]--;
    //     }
    // }
    // for (int i = 1; i < n; i++)
    //     diff[i] += diff[i - 1];
    // diff[n - 1]++;
    // vis[n-1] = true;
    // for (int i = 0; i < n; i++)
    //     if (vis[i])
    //         cout << i + 1 << " " << diff[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}