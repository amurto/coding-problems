#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '6')
            str[i] = '9';
        else if (str[i] == '9')
            str[i] = '6';
    }
    return str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}