#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
const int K = 26;

string ch_to_str(char ch)
{
    string str = "";
    str.pb(ch);
    return str;
}

string create_str(vector<int> &cnt)
{
    string res = "";
    for (int i = 0; i < K; i++)
    {
        while (cnt[i] > 0)
        {
            cnt[i]--;
            res.pb(char(i + 'a'));
        }
    }
    return res;
}

string solve()
{
    string str, res = "";
    cin >> str;
    int n = str.length();
    vector<int> cnt(K), chs;
    for (char ch : str)
        cnt[ch - 'a']++;
    // all same chars
    for (int i = 0; i < K; i++)
        if (cnt[i] == n)
            return str;
    // some character exists only once
    for (int i = 0; i < K; i++)
    {
        if (cnt[i] > 0)
            chs.pb(i);
        if (cnt[i] == 1)
        {
            cnt[i]--;
            return ch_to_str(char(i + 'a')) + create_str(cnt);
        }
    }
    int a = chs[0], b = chs[1];
    // try to put aa at the beginning
    if (n - cnt[a] >= cnt[a] - 2)
    {
        res.pb(char(a + 'a'));
        res.pb(char(a + 'a'));
        cnt[a] -= 2;
        while (cnt[a] > 0)
        {
            while (b < K && cnt[b] == 0)
                b++;
            cnt[b]--;
            cnt[a]--;
            res.pb(char(b + 'a'));
            res.pb(char(a + 'a'));
        }
        return res + create_str(cnt);
    }
    // put ab
    res.pb(char(a + 'a'));
    res.pb(char(b + 'a'));
    cnt[a]--;
    cnt[b]--;
    if (chs.size() == 2)
    {
        while (cnt[b] > 0)
        {
            res.pb(char(b + 'a'));
            cnt[b]--;
        }
        while (cnt[a] > 0)
        {
            res.pb(char(a + 'a'));
            cnt[a]--;
        }
        return res;
    }
    int c = chs[2];
    while (cnt[a] > 0)
    {
        res.pb(char(a + 'a'));
        cnt[a]--;
    }
    res.pb(char(c + 'a'));
    cnt[c]--;
    res += create_str(cnt);
    return res;
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