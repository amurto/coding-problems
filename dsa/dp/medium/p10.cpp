// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0
// Egg Dropping Puzzle

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int DP[101][10001];

// Linear Search
int LED(int K, int N)
{
    if (N == 0 || N == 1)
        return N;
    if (K == 1)
        return N;
    if (DP[K][N] < 0)
    {
        int ans = INT_MAX;
        for (int i = 1; i <= N; i++)
            ans = min(ans, 1 + max(LED(K - 1, i - 1), LED(K, N - i)));
        DP[K][N] = ans;
    }
    return DP[K][N];
}

// Binary Search
int BED(int K, int N)
{
    if (N == 0 || N == 1)
        return N;
    if (K == 1)
        return N;
    if (DP[K][N] < 0)
    {
        int low = 1, high = N;
        while (low + 1 < high)
        {
            int mid = (low + high) / 2;
            int m1 = BED(K - 1, mid - 1), m2 = BED(K, N - mid);
            if (m1 < m2)
                low = mid;
            else if (m1 > m2)
                high = mid;
            else
                low = high = mid;
        }
        DP[K][N] = 1 + min(max(BED(K - 1, low - 1), BED(K, N - low)), max(BED(K - 1, high - 1), BED(K, N - high)));
    }
    return DP[K][N];
}

int superEggDrop(int K, int N)
{
    memset(DP, -1, sizeof(DP));
    return BED(K, N);
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int k, n;
        cin >> k >> n;
        cout << superEggDrop(k, n) << endl;
    }
    return 0;
}