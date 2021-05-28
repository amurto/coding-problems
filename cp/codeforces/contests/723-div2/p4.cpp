#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll swaps(string &str, vector<int> st, vector<int> freq)
{
    ll s = 0;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        int cur = str[i] - 'A';
        int j = 0;
        while (j < st.size() && st[j] != cur)
        {
            s += 1ll * freq[j];
            j++;
        }
        freq[j]--;
    }
    return s;
}

string solve()
{
    string str;
    cin >> str;
    vector<int> cnt(26), st;
    for (char ch : str)
        cnt[ch - 'A']++;
    for (int i = 0; i < 26; i++)
        if (cnt[i] > 0)
            st.pb(i);
    vector<vector<int>> perms;
    vector<ll> op;
    int itr = 0;
    sort(st.begin(), st.end());
    do
    {
        vector<int> freq;
        for (int i : st)
            freq.pb(cnt[i]);
        perms.pb(st);
        op.pb(swaps(str, st, freq));
        itr++;
    } while (next_permutation(st.begin(), st.end()));
    int id = 0;
    for (int i = 0; i < op.size(); i++)
        if (op[i] > op[id])
            id = i;
    string res = "";
    for (int i = 0; i < st.size(); i++)
    {
        int t = cnt[perms[id][i]];
        char ch = char('A' + perms[id][i]);
        while (t-- > 0)
            res.pb(ch);
    }
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