// https://codeforces.com/contest/701/problem/C
// They Are Everywhere

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

vector<int> F(52), cur(52);

int val(char ch)
{
    if (ch <= 'Z')
        return ch - 'A';
    return ch - 'a' + 26;
}
bool check()
{
    for (int i = 0; i < 52; i++)
        if (F[i] > cur[i])
            return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string str;
    cin >> n >> str;
    for (char ch : str)
        F[val(ch)] |= 1;

    int last = 0, res = n;
    for (int i = 0; i < n; i++)
    {
        cur[val(str[i])]++;
        while (check() && last < i && cur[val(str[last])] > 1)
            cur[val(str[last++])]--;
        if (check())
            res = min(res, i - last + 1);
    }
    cout << res << "\n";
    return 0;
}