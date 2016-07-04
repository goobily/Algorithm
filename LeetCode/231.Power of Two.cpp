/*
231. Power of Two
Given an integer, write a function to determine if it is a power of two.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
    }
};

*/

class Solution {
public:
/*********************************************/ //方法1，8 ms
    bool isPowerOfTwo(int n) {
        int cnt = 0;
    	for(; n>0; n = n>>1)
    	{
    		if(n & 1)
    			++cnt;
    		if(cnt > 1)
    			return false;
    	}
    	return cnt==1;
    }
/*********************************************/ //方法2，8 ms	
	bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return !(n&(n-1));
    }
	
};

