// https://codeforces.com/contest/254/problem/C
// Anagram

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.length(), k = 26, op = 0;
    vector<int> req(k), rem(k), rep(k);
    for (char ch : t)
        req[ch - 'A']++;
    for (char ch : s)
        rem[ch - 'A']++;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        if (rem[i] > req[i])
            rep[i] = rem[i] - req[i];
        else if (rem[i] < req[i])
        {
            int cnt = req[i] - rem[i];
            while (cnt-- > 0)
                pq.push(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (pq.empty() || rep[s[i] - 'A'] == 0)
            continue;
        int tp = pq.top();
        if (tp < (s[i] - 'A') || rem[s[i] - 'A'] == rep[s[i] - 'A'])
        {
            rep[s[i] - 'A']--;
            rem[s[i] - 'A']--;
            s[i] = (char)('A' + tp);
            pq.pop();
            op++;
        }
        else
            rem[s[i] - 'A']--;
    }
    cout << op << "\n"
         << s << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    solve();
    return 0;
}