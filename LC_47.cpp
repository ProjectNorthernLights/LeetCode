class Solution {
public:
    void permuteHelper(int begin, vector<int>nums, vector<vector<int>> &result){
      if(begin == nums.size()-1)
      {
        //base
        result.push_back(nums);
      }
      else
      {
        for(int i= begin; i < nums.size(); i ++ )
        {
          //take care of duplicates i.e skip
          //careful of the below if condiiton, since the input set
          //itself is its own permutation
          if(i != begin && nums[i] == nums[begin])
            continue;
          swap(nums[i],nums[begin]);
          permuteHelper(begin+1, nums, result);
        }
      }
      
      return;
    }
      
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> result;
      
      //sort it so all duplicates are in continuos positions
      sort(nums.begin(), nums.end()); 
      
      int begin = 0;
      permuteHelper(begin, nums, result);
      
      return result;
    }
};
