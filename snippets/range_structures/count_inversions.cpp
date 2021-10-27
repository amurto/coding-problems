#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll merge(vector<int> &arr, vector<int> &temp, int left, int mid,
         int right)
{
    int i = left, j = mid, k = left;
    ll inv_count = 0;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            inv_count += 1ll * (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    return inv_count;
}

ll _mergeSort(vector<int> &arr, vector<int> &temp, int left, int right)
{
    ll inv_count = 0;
    if (right > left)
    {
        int mid = left + (right - left) / 2;
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

ll count_inversions(vector<int> arr, int n)
{
    vector<int> temp(n);
    return _mergeSort(arr, temp, 0, n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll inv = count_inversions(arr, n);
    return 0;
}