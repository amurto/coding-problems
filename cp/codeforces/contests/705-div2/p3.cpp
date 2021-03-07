#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool valid(vector<int> &st, int k)
{
    for (int i = 0; i < 26; i++)
        if (st[i] % k > 0)
            return false;
    return true;
}

bool pos(vector<int> &st, int n, int k)
{
    int req = 0;
    for (int i = 0; i < 26; i++)
    {
        if (st[i] == 0)
            continue;
        int c = k * ((st[i] + k - 1) / k);
        req += c - st[i];
    }
    return req <= n && ((n - req) % k == 0);
}

string fx(vector<int> &st, int n, int k)
{
    string tmp;
    for (int i = 25; i >= 0; i--)
    {
        if (st[i] == 0)
            continue;
        int c = k * ((st[i] + k - 1) / k);
        while (st[i] < c)
        {
            tmp.pb((char)(i + 'a'));
            st[i]++;
        }
    }
    int len = tmp.size();
    while (len < n)
    {
        tmp.pb('a');
        len++;
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

string solve()
{
    int n, k;
    string str;
    cin >> n >> k >> str;
    if (n % k > 0)
        return "-1";
    vector<int> st(26);
    for (char ch : str)
        st[ch - 'a']++;
    if (valid(st, k))
        return str;
    for (int i = n - 1; i >= 0; i--)
    {
        int cur = str[i] - 'a';
        st[cur]--;
        for (int j = cur + 1; j < 26; j++)
        {
            st[j]++;
            if (pos(st, n - (i + 1), k))
            {
                string res;
                for (int idx = 0; idx < i; idx++)
                    res.pb(str[idx]);
                res.pb((char)(j + 'a'));
                return res + fx(st, n - (i + 1), k);
            }
            st[j]--;
        }
    }
    return "-1";
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