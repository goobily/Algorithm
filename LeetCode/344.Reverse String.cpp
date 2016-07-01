#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseString(string s)
    {
        int str_len = s.length();
        for (int i = 0; i < str_len/2; ++i)
        {
            swap(s[i], s[str_len - i - 1]);
        }
        return s;
    }

    void swap(char &a, char &b)
    {
        char tmp = a;
        a = b;
        b = tmp;
    }
};

int main()
{
    //char * ch = "hello";
    string s;
    while (cin >> s)
    {
        cout << "origin:  "<< s << endl;
        Solution SS;
        cout << "reverse: " << SS.reverseString(s) << endl;
    }
    return 0;
}