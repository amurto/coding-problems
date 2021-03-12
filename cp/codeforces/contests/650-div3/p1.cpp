#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string str;
        cin >> str;
        int i = 0;
        while (i < str.length())
        {
            cout << str[i];
            i = i + 2;
        }
        cout << str[str.length() - 1] << "\n";
    }
    return 0;
}