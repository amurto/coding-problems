// https://codeforces.com/contest/1200/problem/E
// Compress Words

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int prefix(string &str1, string &str2)
{
    int sz = str1.length(), len = str2.length(), cur = 0;
    vector<int> lps(sz);
    if (str1[0] == str2[0])
        lps[0] = ++cur;
    for (int j = 1; j < sz;)
    {
        if (cur == len)
            cur = 0;
        if (str1[j] == str2[cur])
        {
            lps[j] = ++cur;
            j++;
        }
        else
        {
            if (cur == 0)
                lps[j++] = 0;
            else
                cur = lps[cur - 1];
        }
    }
    return lps.back();
}

string solve()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> pre(n);
    for (int i = 1; i < n; i++)
        pre[i] = prefix(arr[i - 1], arr[i]);
    string res = arr[0];
    for (int i = 1; i < n; i++)
        for (int j = pre[i]; j < arr[i].length(); j++)
            res.pb(arr[i][j]);
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