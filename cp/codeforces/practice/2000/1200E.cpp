// https://codeforces.com/contest/1200/problem/E
// Compress Words

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

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

string solve()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    string res = arr[0];
    for (int i = 1; i < n; i++)
    {
        vector<int> pre = prefix_function(arr[i]);
        int sz = res.length(), m = arr[i].length();
        int id = max(0, sz - m), j = 0;
        string tmp = res.substr(id, min(sz, m));
        for (char ch : tmp)
        {
            if (j == m)
                j = pre[j - 1];
            if (ch == arr[i][j])
                j++;
            else
            {
                while (j > 0 && ch != arr[i][j])
                    j = pre[j - 1];
                j += (ch == arr[i][j]);
            }
        }
        if (j < m)
            res += arr[i].substr(j, m - j);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}