Problem Link: https://leetcode.com/problems/container-with-most-water/description/

>>> Two pointer

    int maxArea(vector<int>& height) {
        long long area=0;
        int n = height.size();
        for(int i=0, j=n-1; i<j;)
        {
            int tmp = min(height[i],height[j])*(j - i);
            if(tmp > area)area = tmp;
            if(height[i] > height[j])j--;
            else i++;
        }
        return area;
    }
