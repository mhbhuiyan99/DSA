
Problem Link: https://www.codingninjas.com/studio/problems/quick-sort_983625

#include <bits/stdc++.h> 

int find(vector<int> &arr, int l, int h)
{
    int i = l;
    int j = h;

    while(i < j)
    {
        while(arr[i] <= arr[l] and i < h) // asume that, pivot = arr[l]
            i++;
        while(arr[j] > arr[l] and j > l)
            j--;
        
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[l]);
    return j;
}

void qSort(vector<int> &arr, int l, int h)
{
    if(l < h)
    {
        int pivot = find(arr, l, h);
        qSort(arr, l, pivot-1);
        qSort(arr, pivot+1, h);
    }
}
vector<int> quickSort(vector<int> arr)
{
    qSort(arr, 0, arr.size() - 1);
    return arr;
}
