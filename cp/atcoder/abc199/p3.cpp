#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    int n, q, t, a, b;
    string str;
    cin >> n >> str >> q;
    vector<string> seq(2);
    vector<int> flip = {0, 1};
    for (int i = 0; i < n; i++)
        seq[0].pb(str[i]);
    for (int i = n; i < 2 * n; i++)
        seq[1].pb(str[i]);
    while (q-- > 0)
    {
        cin >> t >> a >> b;
        if (t == 1)
        {
            a--;
            b--;
            int s1 = flip[0], s2 = flip[1];
            if (b < n)
            {
                swap(seq[s1][a], seq[s1][b]);
            }
            else if (a >= n)
            {
                a -= n;
                b -= n;
                swap(seq[s2][a], seq[s2][b]);
            }
            else
            {
                b -= n;
                swap(seq[s1][a], seq[s2][b]);
            }
        }
        else
            swap(flip[0], flip[1]);
    }
    string res = "";
    for (int e : flip)
        for (char ch : seq[e])
            res.pb(ch);
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