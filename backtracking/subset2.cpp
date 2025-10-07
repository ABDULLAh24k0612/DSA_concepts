class Solution {
public:

void getallsubsets(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>> &allsubsets){
    if(i==nums.size()){
        allsubsets.push_back({ans});
        return;
    }

    ans.push_back(nums[i]);
    getallsubsets(nums,ans,i+1,allsubsets);
    ans.pop_back();
    int idx=i+1;
    while(idx<nums.size()&&nums[idx]==nums[idx-1]){
        idx++;
    }
    getallsubsets(nums,ans,idx,allsubsets);

}
void bubbleSort(vector<int> &nums) {
    for(int i = 0; i < nums.size() - 1; i++) {
        for(int j = 0; j < nums.size() - i - 1; j++) {
            if(nums[j] > nums[j+1]) {
             swap(nums[j], nums[j+1]);
            }
        }
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> allsubsets;
        bubbleSort(nums);
        getallsubsets(nums,ans,0,allsubsets);
        return allsubsets;
    }
};
