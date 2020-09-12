// Interleaved Strings
// https://practice.geeksforgeeks.org/problems/interleaved-strings/1

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int DP[101][101][101];

int isSubseq(string A, string B, string C, int a, int b, int c)
{
    if (a == A.length() && b == B.length())
        return 1;
    if (c == C.length())
        return 0;
    if (DP[a][b][c] < 0)
    {
        int a1 = 0, a2 = 0, a3 = 0;
        if (C[c] == A[a])
            a1 = isSubseq(A, B, C, a + 1, b, c + 1);
        if (C[c] == B[b])
            a2 = isSubseq(A, B, C, a, b + 1, c + 1);
        if (C[c] != A[a] && C[c] != B[b])
            a3 = isSubseq(A, B, C, a, b, c + 1);
        DP[a][b][c] = max(a1, max(a2, a3));
    }
    return DP[a][b][c];
}

bool isInterleave(string A, string B, string C)
{
    memset(DP, -1, sizeof(DP));
    return isSubseq(A, B, C, 0, 0, 0);
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string A, B, C;
        cin >> A >> B >> C;
        if (isInterleave(A, B, C))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}