/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

    non decreasing array is given
    two numbers equal to a sum, need to be find out

    Approach 1. 
    left and right pointer
    
    for every number-
        if sum is greater than the sum 
            decrese the right--
        else if - equal
            return the indexes.
        else
            left++

*/

    vector<int> twoSum(vector<int>& tar, int n) {
        vector<int> res;
        int left = 0, right = tar.size()-1;
        for( int i = 0; i < tar.size(); i++) {
            if( tar[left] + tar[right] < n) {
                left++;
            } else if( tar[left] + tar[right] > n ) {
                right--;
            } else {
                res.push_back(left+1);
                res.push_back(right+1);
                break;
            }
        }
        return res;
    }

/*
    Approach 2.
    keep a track of numbers and its index in map

    for every number-
        if n - nums[i] is present in map
            reuturn indexes
        else 
            insert values in map
*/
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int n = nums.size();
        unordered_map<int,int> mp;
        
        for( int i=0; i<n; i++){
            if( mp.find( target - nums[i]) != mp.end()){
                res.push_back( min(i+1,mp[target - nums[i]]));
                res.push_back( max(i+1,mp[target- nums[i]]));
                return res;
            }
            else{
                mp[nums[i]] = i+1;
            }
        }
        return res;
    }