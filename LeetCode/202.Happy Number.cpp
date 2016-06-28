/*
202. Happy Number
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Credits:
Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

class Solution {
public:
    bool isHappy(int n) {
        
    }
};

*/

class Solution {
public:
    int SqureSum(int n)
    {
    	int sum = 0;
    	while(n/10) {
    		int t = n%10;
    		sum += t*t;
    		n /= 10;
    	}
    	sum += n*n;
    	return sum;
    }
    bool isHappy(int n) {
        map<int, bool> mExist;
    	int sum = SqureSum(n);
    	while(sum!=1 && mExist.find(sum) == mExist.end())
    	{
    		mExist[sum] = true;
    		sum = SqureSum(sum);
    		
    	}
    	return sum==1 ? true:false;
    }
};