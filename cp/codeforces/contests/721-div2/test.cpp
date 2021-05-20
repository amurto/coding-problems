#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string winner(int a, int b)
{
    if (a < b)
        return "ALICE";
    else if (a > b)
        return "BOB";
    return "DRAW";
}

string solve()
{
    int n, a = 0, b = 0, c = 0;
    string str;
    cin >> n >> str;
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            str[i] = str[j] = '1';
            c++;
        }
        i++;
        j--;
    }
    b = c;
    int z = count(str.begin(), str.end(), '0');
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