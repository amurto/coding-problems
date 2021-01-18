// https://codeforces.com/contest/959/problem/C
// Mahmoud and Ehab and the wrong algorithm

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void incorrect(int n)
{
    if (n <= 5)
    {
        cout << "-1\n";
        return;
    }
    for (int i = 2; i <= n - 2; i++)
        cout << 1 << " " << i << "\n";
    cout << n - 2 << " " << n - 1 << "\n";
    cout << n - 2 << " " << n << "\n";

}
void correct(int n)
{
    for (int i = 2; i <= n; i++)
        cout << "1 " << i << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    incorrect(n);
    correct(n);
    return 0;
}