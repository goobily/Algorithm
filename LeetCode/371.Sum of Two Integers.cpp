#include <iostream>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int getSum_Iter(int a, int b)
    {
        while (b != 0)
        {
            int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }

    int getSum_Cur(int a, int b)
    {
        if (b == 0)
            return a;
        return getSum_Cur(a^b, (a&b) << 1);
    }

    int getSum(int a, int b)
    {
        if (rand() % 2) {
            cout << "getSum_Iter result:";
            return getSum_Iter(a, b);
        }
        else {
            cout << "getSum_Cur result:";
            return getSum_Cur(a, b);
        }
    }
};

int main()
{
    Solution SS;
    int a, b;
    while (cin >> a >> b)
    {
        cout << SS.getSum(a, b);
    }
    return 0;
}