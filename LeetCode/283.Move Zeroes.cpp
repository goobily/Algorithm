/*
283. Move Zeroes

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1=0, p2=0;
		for(; nums[p1]!=0 && p1<nums.size(); ++p1);
		for(p2=p1; p2<nums.size(); ++p2) {
			if(nums[p2] == 0) continue;
			nums[p1++] = nums[p2];
		}
		for(; p1<nums.size(); ++p1)
			nums[p1] = 0;
	}
};