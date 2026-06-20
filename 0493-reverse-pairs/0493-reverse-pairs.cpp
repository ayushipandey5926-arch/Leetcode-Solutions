class Solution {
public:
void MergeSort(vector<int> &nums, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid+1;

    

    while(left<=mid && right<=high) {
        if(nums[left]<= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    while(left<=mid) {
        temp.push_back(nums[left]);
        left++;
    } 

    while(right<=high) {
        temp.push_back(nums[right]);
        right++;
    }

    for(int i= low; i<=high; i++) {
        nums[i] = temp[i-low];
    }
}

int countreverse(vector<int> &nums, int low, int mid, int high) {
    int right = mid+1;
    int count = 0;

    for(int i=low; i<=mid; i++) {
        while(right <= high && (long long)nums[i] > 2LL*nums[right]) right++; 
        count += (right - (mid + 1));
    }
    return count;
}

int mergeSort(vector<int> &nums, int low, int high) {
    int count = 0;
    if(low>=high) return count;
    int mid = (low+high)/2;

    count+=mergeSort(nums, low, mid);
    count+=mergeSort(nums, mid+1, high);
    count+=countreverse(nums, low, mid, high);
    MergeSort(nums, low, mid, high);
    return count;
}
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};