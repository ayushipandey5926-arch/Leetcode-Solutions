class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int n = nums.size(), count = 0;
    int presum = 0;
    unordered_map<int, int> prefixcount;
    prefixcount[0]=1;
    for(int i=0; i<n; i++) {
        presum += nums[i];
        int remove = presum-k;
        count += prefixcount[remove];
        prefixcount[presum]+=1;
    }

    return count;
}
};