
Problem Link: https://www.codingninjas.com/studio/problems/merge-sort_920442

void merge(vector<int> &arr, int l, int m , int h)
{
    vector<int> tmp;
    int left = l;
    int right = m+1;

    while(left <= m and right <= h)
    {
        if(arr[left] < arr[right])
        {
            tmp.push_back(arr[left]);
            left++;
        }
        else
        {
            tmp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= m) tmp.push_back(arr[left]), left++;
    while(right <= h) tmp.push_back(arr[right]), right++;

    for(int i = l; i<= h; i++)
    {
        arr[i] = tmp[i - l];
    }
}

void mS(vector<int> &arr, int l , int h)
{
    if(l == h) return;
    int m = (l + h) >> 1;

    mS(arr, l, m);
    mS(arr, m+1, h);

    merge(arr, l, m, h);
}

void mergeSort(vector < int > & arr, int n) {
    mS(arr, 0 , n-1);
}
