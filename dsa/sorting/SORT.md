# Sorting

## Table of Contents

- [Sort an array of 0s and 1s](#sort01s)
- [Sort an array of 0s, 1s and 2s](#sort012s)
- [Sort Dates](#sort-dates)
- [Merge Two Sorted Arrays](#merge-two-sorted-arrays)
- [Merge Sort](#merge-sort)
- [Quick Sort](#quick-sort)
- [Find Minimum in Rotated Sorted Array](#min-rotate-sort)

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
