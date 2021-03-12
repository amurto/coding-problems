#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    int m, cur = 25;
    string str;
    cin >> str >> m;
    int n = str.length();
    vector<int> cnt(26), b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (char ch : str)
        cnt[ch - 'a']++;
    string res(m, ' ');
    bool op = true;
    while (op)
    {
        vector<int> zeros;
        for (int i = 0; i < m; i++)
            if (b[i] == 0)
                zeros.pb(i);
        int sz = zeros.size();
        while (cur >= 0 && cnt[cur] < sz)
            cur--;
        vector<int> tmp = b;
        for (int z : zeros)
            for (int i = 0; i < m; i++)
                tmp[i] -= abs(i - z);
        for (int z : zeros)
        {
            res[z] = (char)(cur + 'a');
            tmp[z] = -1;
        }
        cur--;
        b = tmp;
        if (count(b.begin(), b.end(), 0) == 0)
            op = false;
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