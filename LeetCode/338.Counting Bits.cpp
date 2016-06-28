/*
338. Counting Bits
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
Show Hint 
Credits:
Special thanks to @ syedee for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

class Solution {
public:

/*********************************************/ //方法1，160 ms
    int bits1(int n)
    {
    	int res = 0;
    	while(n)
    	{
    		if(n%2 == 1)
    			res++;
    		n /= 2;
    	}
    	return res;
    }
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
    	for(int i=0; i<=num; ++i)
    	{
    		res[i] = bits1(i);
    	}
    	return res;
    }
/*********************************************/	 //方法2，132 ms
	vector<int> countBits(int num) {
        vector<int> res(num+1,0);
    	res[0] = 0;
    	for(int i=0; i<=num; ++i)
    	{
    		if(i%2 == 1)
    			res[i] = res[i/2] + 1;
    		else
    			res[i] = res[i/2];
    	}
    	return res;
    }
/*********************************************/	
};