#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    string str;
    cin >> n >> x >> str;
    for (char ch : str)
    {
        if (ch == 'o')
            x++;
        else
            x--;
        x = max(x, 0);
    }
    cout << x << "\n";
    return 0;
}