#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 1;
int seq[N];
void init()
{
    seq[0] = 9;
    seq[1] = 8;
    for (int i = 2; i < N; i++)
        seq[i] = (seq[i - 1] + 1) % 10;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cout << seq[i];
        cout << "\n";
    }
    return 0;
}