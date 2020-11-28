#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve(string &str, int n)
{
    int L , R;
    cin >> L >> R;
    L--;
    R--;
    for (int i=0; i<L; i++)
        if (str[i] == str[L])
            return true;
    for (int j=n-1; j>R; j--)
        if (str[j] == str[R])
            return true;
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
    {
        int n, q;
        cin >> n >> q;
        string str;
        cin >> str;
        while (q-- > 0)
        {
            solve(str, n) ? cout << "YES\n" : cout << "NO\n";
        }
    }
    return 0;
}