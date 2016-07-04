/*
217. Contains Duplicate
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
    }
};
*/

class Solution {
public:
/*********************************************/ //方法1，104 ms
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> m;
        for(int i=0; i<nums.size(); ++i) {
            if(m.find(nums[i]) != m.end()) return true;
            m[nums[i]] = true;
        }
        return false;
    }
/*********************************************/ //方法2，48 ms
	bool containsDuplicate(vector<int>& nums) {
       unordered_map<int, bool> m;
        for (auto item : nums) {
            if (m.find(item) != m.end()) return true;
            m[item]=true;
        }
        return false;
    }
/*********************************************/ //方法3，56 ms	
	 bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;
        for(int i=0; i<nums.size(); ++i)
            m[nums[i]] = 0;
        for(int i=0; i<nums.size(); ++i)
            m[nums[i]] ++;
        for(int i=0; i<nums.size(); ++i) {
            if (m[nums[i]] != 1) return true;
        }
        return false;
    }
};

