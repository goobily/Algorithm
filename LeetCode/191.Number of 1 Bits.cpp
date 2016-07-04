/*
191. Number of 1 Bits

Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
    }
};

*/

class Solution {
public:
/*********************************************/ //方法1，4ms
    int hammingWeight(uint32_t n) {
        int num = 0;
        while(n) {
            if (n % 2 == 1)
                ++num;
            n /= 2;
        }
        return num;
    }
/*********************************************/ //方法1，8ms	
	int hammingWeight(uint32_t n) {
        int num = 0;
        while(n) {
            ++ num;
            n &= n-1;
        }
        return num;
    }
	
};