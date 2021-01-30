#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c;
    vector<int> p(2);
    cin >> p[0] >> p[1] >> c;
    while (p[c] > 0)
    {
        p[c]--;
        c ^= 1;
    }
    c == 1 ? cout << "Takahashi\n" : cout << "Aoki\n";
    return 0;
}