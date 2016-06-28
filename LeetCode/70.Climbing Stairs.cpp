/*
70. Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Subscribe to see which companies asked this question

class Solution {
public:
    int climbStairs(int n) {
        
    }
};

*/

class Solution {
public:
    int climbStairs(int n) {
        if(n<=0) return -1;
        else if(n<=3) return n;
        else
        {
            int f0 = 2;
            int f1 = 3;
            for(int i=4; i<=n; ++i)
            {
                int t = f0 + f1;
                f0 = f1;
                f1 = t;
            }
            return f1;
        }
    }
};

