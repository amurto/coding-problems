#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void increase(string &cur)
{
    int sz = cur.length();
    if (count(cur.begin(), cur.end(), 'z') == sz)
    {
        string tmp = "";
        for (int i = 0; i < sz; i++)
            tmp.pb('a');
        tmp.pb('a');
        cur = tmp;
    }
    else
    {
        int c = 1;
        for (int i = sz - 1; c && i >= 0; i--)
        {
            if (cur[i] == 'z')
                cur[i] = 'a';
            else
            {
                cur[i]++;
                c = 0;
            }
        }
    }
}

bool is_substr(string &str, string &cur, int n)
{
    int sz = cur.length();
    for (int i = 0; i < n - sz + 1; i++)
        if (str.substr(i, sz) == cur)
            return true;
    return false;
}

string solve()
{
    int n;
    string str, cur = "a";
    cin >> n >> str;
    while (is_substr(str, cur, n))
        increase(cur);
    return cur;
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