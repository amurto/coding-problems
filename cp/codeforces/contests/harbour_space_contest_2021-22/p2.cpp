#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string get_substr(string &str, int l, int r, bool rev)
{
    string s = str.substr(l, r - l + 1);
    if (rev)
        reverse(s.begin(), s.end());
    return s;
}

bool solve()
{
    string str, t;
    cin >> str >> t;
    int n = str.length(), m = t.length();
    for (int i = 0; i < n; i++)
    {
        int id = 0;
        for (int j = i; id < m && j < n; j++)
        {
            if (str[j] == t[id])
            {
                id++;
                if (id == m)
                    return true;
                int ptr = id;
                for (int k = j - 1; ptr < m && k >= 0; k--)
                {
                    if (str[k] == t[ptr])
                    {
                        ptr++;
                        if (ptr == m)
                            return true;
                    }
                    else
                        break;
                }
            }
            else
                break;
        }
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