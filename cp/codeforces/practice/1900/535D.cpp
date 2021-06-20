// https://codeforces.com/contest/535/problem/D
// Tavas and Malekas

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

// Binary Exponentiation O(logn)
// n^m mod p
int power(int n, int m, int p)
{
    int res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res;
}

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

int solve()
{
    int n, m, v;
    string p;
    cin >> n >> m >> p;
    int k = p.length();
    vector<int> arr(n), dp(n);
    for (int i = 0; i < m; i++)
    {
        cin >> v;
        arr[v - 1]++;
    }
    string str(n, '0');
    int cur = -1;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        while (!pq.empty() && pq.top() == i)
            pq.pop();
        if (pq.empty())
            cur = -1;
        if (arr[i] > 0)
        {
            cur = 0;
            pq.push(i + k);
        }
        if (cur >= 0)
            str[i] = p[cur++];
    }
    vector<int> pre = prefix_function(p);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        // If current matching has reached end of pat, use link to previous prefix
        if (j == k)
            j = pre[j - 1];
        // Same character, then increase current match
        if (str[i] == p[j])
            j++;
        else
        {
            // Iterate over previous prefix matches
            while (j > 0 && str[i] != p[j])
                j = pre[j - 1];
            // Update j if a valid match is found, else no prefix exists at current char
            j += (str[i] == p[j]);
        }
        dp[i] = j;
    }
    for (int i = 0; i < n; i++)
        if (arr[i] > 0 && dp[i + k - 1] != k)
            return 0;
    int cnt = count(str.begin(), str.end(), '0');
    return power(26, cnt, MOD);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}