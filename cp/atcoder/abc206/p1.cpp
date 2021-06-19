#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    double v = 1.08 * n;
    if (v >= 207.0)
        cout << ":(\n";
    else if (v >= 206.0)
        cout << "so-so\n";
    else
        cout << "Yay!\n";
    return 0;
}