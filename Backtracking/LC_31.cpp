//https://www.nayuki.io/page/next-lexicographical-permutation-algorithm


class Solution {
public:
  
    void nextPermutation(vector<int>& nums) 
    {
      
      if( nums.empty())
        return ;
      
      int n = nums.size(); 
      int i;
      int j;
      //Starting from end of the list, look for a weakly decresing subsequence
      //This subsequence is basically the last highest order permutation itself
      //i.e there are no other "next higher" permutation possible for this seubsequence
      // e.g 0,1,2,5,3,3,0
      
      for(i = n - 1; i >= 0; i --)
      { 
        if(nums[i-1] >= nums[i])
          continue;
        else
          break;
      }
      
      //if no such subsequence is found, that means the entire input
      //is already the last highest permutation. so reverse it
      if ( i == 0){
        reverse(nums.begin(), nums.end());
        return;
      }
        
      //get the pivot point which in our example is "2"
      int pivot = i - 1;
      
      //now compare the pivot with the lowest interger of the 
      //weakly decreasing subsequence such that there exists a
      //number which is just slightly higher than the pivot
      
      //Note how we search from end so that if there are duplicates, then the
      //duplicate to the right-most hand side of the subsequence 
      //has to be swapped with the pivot
      for(j = n-1 ; j >= i; j--){
        if(nums[j] > nums[pivot])
          break;
      }
      
      //jth index is the lowest such value in the subsequence such that
      //nums[j] > pivot
      
      //now swap the pivot with the jth index
      swap(nums[pivot], nums[j]);
      
      //num reverse the subsequence until pivot+1th index
      reverse(nums.begin() + (pivot + 1), nums.end());
      
      return ;
    }
};
