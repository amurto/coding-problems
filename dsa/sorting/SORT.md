# Sorting
https://leetcode.com/problems/sort-an-array/

## Table of Contents

- [Sort an array of 0s and 1s](#sort01s)
- [Sort an array of 0s, 1s and 2s](#sort012s)
- [Sort Dates](#sort-dates)
- [Bubble Sort](#bubble-sort)
- [Selection Sort](#selection-sort)
- [Insertion Sort](#insertion-sort)
- [Merge Two Sorted Arrays](#merge-two-sorted-arrays)
- [Merge Sort](#merge-sort)
- [Quick Sort](#quick-sort)
- [Quick Select (Kth smallest/largest element)](#quick-select)
- [Find Minimum in Rotated Sorted Array](#min-rotate-sort)
- [Count Sort](#count-sort)
- [Pairs with given sum](#pair-sum)

<div id="sort01s">

## Sort an array of 0s and 1s

```cpp
void sort01s(vector<int> &nums)
{
    for (int j = 0, i = 0; j < nums.size(); j++)
        if (nums[j] == 0)
            swap(nums[i++], nums[j]);
}
```

</div>

<div id="sort012s">

## Sort an array of 0s, 1s and 2s

```cpp
void sort012s(vector<int> &nums)
{
    int i = 0, j = 0, k = nums.size() - 1;
    while (j <= k)
    {
        if (nums[j] == 0)
            swap(nums[i++], nums[j++]);
        else if (nums[j] == 2)
            swap(nums[j], nums[k--]);
        else
            j++;
    }
}
```

</div>

<div id="sort-dates">

## Sort Dates

```cpp
struct Date
{
    string fulldate;
    int day, mon, year;
    Date(string fd) : fulldate(fd)
    {
        int d = stoi(fd);
        year = d % 10000;
        d /= 10000;
        mon = d % 100;
        d /= 100;
        day = d;
    }
};

bool compare(Date *d1, Date *d2)
{
    if (d1->year == d2->year)
        if (d1->mon == d2->mon)
            return (d1->day < d2->day);
        else
            return (d1->mon < d2->mon);
    else
        return (d1->year < d2->year);
}

int main()
{
    string fd;
    int n, d, m, y;
    cin >> n;
    vector<Date *> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> fd;
        arr[i] = new Date(fd);
    }
    sort(arr.begin(), arr.end(), compare);
    for (Date *date : arr)
        cout << date->fulldate << "\n";
    return 0;
}
```

</div>

<div id="bubble-sort">

## Bubble Sort

```cpp
void bubblesort(vector<int> &nums)
{
    // n passes
    int n = nums.size();
    for (int pass = n - 1; pass >= 0; pass--)
        for (int j = 0; j < pass; j++)
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
}

// Modified Bubble Sort
void modifiedbubblesort(vector<int> &nums)
{
    // n passes
    int n = nums.size();
    for (int pass = n - 1; pass >= 0; pass--)
    {
        bool isSort = true;
        for (int j = 0; j < pass; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                isSort = false;
                swap(nums[j], nums[j + 1]);
            }
        }
        if (isSort)
            break;
    }
}
```

</div>

<div id="selection-sort">

## Selection Sort

```cpp
void selectionsort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (nums[j] < nums[minIdx])
                minIdx = j;
        swap(nums[i], nums[minIdx]);
    }
}
```

</div>

<div id="insertion-sort">

## Insertion Sort

```cpp
void insertionsort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        int cur = nums[i], j = i - 1;
        while (j >= 0 && nums[j] > cur)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = cur;
    }
}
```

</div>

## Selection Sort

```cpp
void selectionsort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (nums[j] < nums[minIdx])
                minIdx = j;
        swap(nums[i], nums[minIdx]);
    }
}
```

</div>

<div id="merge-two-sorted-arrays">

## Merge Two Sorted Arrays

https://leetcode.com/problems/merge-sorted-array/

```cpp
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0)
        if (nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    while (j >= 0)
        nums1[k--] = nums2[j--];
}
```

</div>

<div id="merge-sort">

## Merge Sort

```cpp
void merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> arr(high - low + 1);
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high)
    {
        if (nums[i] < nums[j])
            arr[k++] = nums[i++];
        else
            arr[k++] = nums[j++];
    }
    while (i <= mid)
        arr[k++] = nums[i++];
    while (j <= high)
        arr[k++] = nums[j++];
    for (int idx = 0; idx < arr.size(); idx++)
        nums[low + idx] = arr[idx];
}

void mergesort(vector<int> &nums, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergesort(nums, low, mid);
        mergesort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
}

mergesort(nums, 0, nums.size() - 1);
```

</div>

<div id="quick-sort">

## Quick Sort

```cpp
int partition(vector<int> &nums, int low, int high)
{
    int pivot = nums[high], i = low;
    for (int j = low; j < high; j++)
        if (nums[j] < pivot)
            swap(nums[i++], nums[j]);
    swap(nums[i], nums[high]);
    return i;
}

void quicksort(vector<int> &nums, int low, int high)
{
    if (low < high)
    {
        int pi = partition(nums, low, high);
        quicksort(nums, low, pi - 1);
        quicksort(nums, pi + 1, high);
    }
}

quicksort(nums, 0, nums.size() - 1);
```

</div>

<div id="quick-select">

## Quick Select (Kth smallest/largest element in array)

```cpp
// Kth smallest element
int partition(vector<int> &nums, int low, int high)
{
    int pivot = nums[high], i = low;
    for (int j = low; j < high; j++)
        if (nums[j] <= pivot)
            swap(nums[i++], nums[j]);
    swap(nums[i], nums[high]);
    return i;
}

// Kth largest element
int partition(vector<int> &nums, int low, int high)
{
    int pivot = nums[high], i = low;
    for (int j = low; j < high; j++)
        if (nums[j] >= pivot)
            swap(nums[i++], nums[j]);
    swap(nums[i], nums[high]);
    return i;
}

int quickselect(vector<int> &nums, int low, int high, int k)
{
    if (low < high)
    {
        int pi = partition(nums, low, high);
        if (pi == k)
            return nums[k];
        else if (pi > k)
            return quickselect(nums, low, pi - 1, k);
        else
            return quickselect(nums, pi + 1, high, k);
    }
    return nums[k];
}

cout << quickselect(nums, k, 0, n - 1) << "\n";
```

</div>

<div id="min-rotate-sort">

## Find Minimum in Rotated Sorted Array

https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

```cpp
int findMin(vector<int> &nums)
{
    int beg = 0, end = nums.size() - 1;
    if (nums[end] >= nums[beg])
        return nums[beg];
    while (beg <= end)
    {
        int mid = beg + (end - beg) / 2;
        if (nums[mid] > nums[mid + 1])
            return nums[mid + 1];
        if (nums[mid] < nums[mid - 1])
            return nums[mid];
        if (nums[mid] > nums[0])
            beg = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}
```

</div>

<div id="count-sort">

## Count Sort
```cpp
vector<int> countsort(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    // Find Min, Max
    int MIN = INT_MAX, MAX = INT_MIN;
    for (int val : nums)
    {
        MIN = min(MIN, val);
        MAX = max(MAX, val);
    }
    
    // Make Map of range Min to Max
    vector<int> MAP(MAX - MIN + 1, 0);

    // Count frequency of every element
    for (int val : nums)
        MAP[val - MIN]++;

    for (int i = 1; i < MAX - MIN + 1; i++)
        MAP[i] += MAP[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        ans[MAP[nums[i] - MIN] - 1] = nums[i];
        MAP[nums[i] - MIN]--;
    }
    return ans;
}
```
</div>

<div id="pair-sum">

## Count Pairs with given sum

```cpp
// Using Map to store frequency
int getPairsCount(vector<int> nums, int sum)
{
    unordered_map<int, int> MAP;
    int pairs = 0;
    for (int val : nums)
    {
        pairs += MAP[sum - val];
        MAP[val]++;
    }
    return pairs;
}

// Sorting and using two pointers
int getPairsCountSort(vector<int> nums, int sum)
{
    int pairs = 0, beg = 0, end = nums.size() - 1;
    sort(nums.begin(), nums.end());
    while (beg < end)
    {
        if (nums[beg] + nums[end] > sum)
            end--;
        else if (nums[beg] + nums[end] < sum)
            beg++;
        else
        {
            int cbeg = beg, x = nums[beg], cend = end, y = nums[end];
            while (beg < end && nums[beg] == x)
                beg++;
            while (end >= beg && nums[end] == y)
                end--;
            if (x == y)
            {
                int temp = beg - cbeg + cend - end - 1;
                pairs += temp * (temp + 1) / 2;
            }
            else
                pairs += (beg - cbeg) * (cend - end);
        }
    }
    return pairs;
}
```
</div>