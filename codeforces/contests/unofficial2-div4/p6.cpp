#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    int n;
    cin >> n;
    vector<int> score(2);
    int cur = 0;
    if (n % 2 == 1)
    {
        score[1] = 2 * n - 1;
        n--;
    }
    n *= n;
    while (n > 0)
    {
        score[cur] += 4;
        cur ^= 1;
        n -= 4;
    }
    if (score[0] > score[1])
        return "Alice";
    else if (score[0] < score[1])
        return "Bob";
    return "Draw";
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