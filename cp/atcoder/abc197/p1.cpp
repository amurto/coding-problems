#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    str.pb(str[0]);
    for (int i = 1; i < str.length(); i++)
        cout << str[i];
    return 0;
}