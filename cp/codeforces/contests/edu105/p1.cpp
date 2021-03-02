#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool reg(string &str, map<char, int> &mp)
{
    vector<int> st(2);
    for (char ch : str)
    {
        st[mp[ch]]++;
        if (st[1] > st[0])
            return false;
    }
    return st[0] == st[1];
}
bool solve()
{
    string str;
    cin >> str;
    map<char, int> mp;
    vector<int> tmp = {0, 0, 1};
    for (int i = 0; i < 2; i++)
    {
        do
        {
            mp['A'] = tmp[0];
            mp['B'] = tmp[1];
            mp['C'] = tmp[2];
            if (reg(str, mp))
                return true;
        } while (next_permutation(tmp.begin(), tmp.end()));
        sort(tmp.begin(), tmp.end());
        tmp[1] = 1;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}