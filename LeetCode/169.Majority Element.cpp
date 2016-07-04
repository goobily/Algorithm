/*
169. Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.

You may assume that the array is non-empty and the majority element always exist in the array.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
    }
};
*/

class Solution {
public:
/*********************************************/ //方法1，16 ms
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int cnt = 0;
        for(int i=0; i<nums.size(); ++i) {
            if(cnt == 0) {
                majority = nums[i];
                cnt++;
            }
            else {
                nums[i] == majority ? cnt++ : cnt--;
                if(cnt > nums.size()/2) return majority;
            }
        }
        return majority;
    }
/*********************************************/ //方法2，28 ms	
	int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for(int i=0; i<nums.size(); ++i) {
            if ((m[nums[i]] ++) >= nums.size()/2 )
                return nums[i];
        }
    }
};