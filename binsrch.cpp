#include<bits/stdc++.h>
using namespace std; 

int binsrch(vector<int>& nums,int target,int start,int end)
{
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(target<nums[mid])
        end=mid-1;
        else if(target>nums[mid])
        start=mid+1;
        else
        return mid;
    }
    return -1;
}

int main()
{
    vector<int> nums={2,3,4,5,6,7,8,9,10,56};
    int ans=binsrch(nums,0,0,nums.size()-1);
    cout<<nums[ans];
    return 0;
}