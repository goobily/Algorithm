/*
326. Power of Three
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

class Solution {
public:
    bool isPowerOfThree(int n) {
        
    }
};

*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
    	double logres = log10(n) / log10(3);
    	if(logres - (int)logres == 0)
    		return true;
    	return false;
    }
};
