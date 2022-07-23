/*

You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Example 2:

Input: nums = [-1]
Output: [0]

Example 3:

Input: nums = [-1,-1]
Output: [0,0]

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104

*/

/* Solution */

class Solution {
public:
    
    // Merge Sort Approach
    
    int arr[100000];
    
    vector<int> countSmaller(vector<int>& nums) {
        
        vector<pair<int,int>> pairs;
        for(int i=0;i<nums.size();i++)
        {
            pairs.push_back({nums[i],i});
        }
        
        mergeSort(pairs,0,nums.size()-1);
        vector<int> res(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            res[i]=arr[i];
        }
        return res;
    }
    void mergeSort(vector<pair<int,int>>& pairs,int low,int high)
    {
        int mid=(low+high)/2;
        if(low<high)
        {
           
            mergeSort(pairs,low,mid);
            mergeSort(pairs,mid+1,high);
            merge(pairs,low,mid+1,high);
        }
    }
    
    void merge(vector<pair<int,int>>& pairs,int low,int mid,int high){
        
        int i=low;
        int j=mid;
        int count=0; 
        vector<pair<int,int>> temp(high-low+1);
        int k=0;
        while(i<=mid-1 && j<=high)
        {
            if(pairs[i].first<=pairs[j].first)
            {
                arr[pairs[i].second]+=count;
                temp[k++]={pairs[i++]};
            }
            else{
                count++;
                temp[k++]={pairs[j++]};
            }
        }
       
        while(i<=mid-1)
        {
            arr[pairs[i].second]+=count; 
            temp[k++]={pairs[i++]}; 
        }
        
        while(j<=high)
        {
            temp[k++]={pairs[j++]};
        }
        
        for(int i=0;i<k;i++)
        {
            pairs[low++]=temp[i];
        }
    }
};
