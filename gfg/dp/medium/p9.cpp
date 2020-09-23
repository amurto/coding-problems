// https://practice.geeksforgeeks.org/problems/box-stacking/1
// Box Stacking

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class Box
{
public:
    int h, l, w;
    Box(int H, int L, int W)
    {
        h = H;
        l = L;
        w = W;
    }
};

bool compareBox(Box a, Box b)
{
    return (a.l * a.w) > (b.l * b.w);
}

int StackBox(vector<Box> &B, int *DP, int cur, int n)
{
    if (DP[cur] == 0)
    {
        for (int i = cur - 1; i >= 0; i--)
            if (B[i].l > B[cur].l && B[i].w > B[cur].w)
                DP[cur] = max(DP[cur], StackBox(B, DP, i, n) + B[cur].h);
        DP[cur] = max(DP[cur], B[cur].h);
    }
    return DP[cur];
}

int maxHeight(int height[], int width[], int length[], int n)
{
    vector<Box> B;
    for (int i = 0; i < n; i++)
    {
        B.pb(Box(height[i], max(length[i], width[i]), min(length[i], width[i])));
        B.pb(Box(width[i], max(length[i], height[i]), min(length[i], height[i])));
        B.pb(Box(length[i], max(height[i], width[i]), min(height[i], width[i])));
    }
    // Works even without sorting. Intitialize i as B.size()-1 in StackBox function
    sort(B.begin(), B.end(), compareBox);
    int MAX = 0, DP[B.size()];
    memset(DP, 0, sizeof(DP));
    for (int i = B.size() - 1; i >= 0; i--)
        MAX = max(MAX, StackBox(B, DP, i, n));
    return MAX;
}

int main()
{
    int n = 3;
    int height[] = {1, 4, 3};
    int width[] = {2, 5, 4};
    int length[] = {3, 6, 1};
    cout << maxHeight(height, width, length, n) << endl;
    return 0;
}