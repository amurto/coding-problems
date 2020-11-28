#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int same(string &A, string &B, int n, int start)
{
    int op = 0, c = 0;
    for (int i = start; i < n; i += 2)
    {
        if (A[i] == B[i])
        {
            op += (c > 0);
            c = 0;
        }
        else
            c++;
    }
    op += (c > 0);
    return op;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string A, B;
        cin >> A >> B;
        int n = A.length(), op = 0;
        op += same(A, B, n, 0) + same(A, B, n, 1);
        cout << op << "\n";
    }
    return 0;
}