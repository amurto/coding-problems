#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int countHomogenous(string s)
{
    int n=s.length(), cur = 1, MOD = 1e9 + 7;
    long long res = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            cur = 1;
            res++;
        }
        else
        {
            res += cur + 1;
            cur++;
        }
        res %= MOD;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    cout << countHomogenous(s) << "\n";
    return 0;
}