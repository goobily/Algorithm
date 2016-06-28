/*
171. Excel Sheet Column Number

Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

class Solution {
public:
    int titleToNumber(string s) {
        int size = s.length();
        if (size == 0) return 0;
        int sum = 0;
        for (int i=0; i<size; ++i) {
            int n = toupper(s[i]) - 'A' + 1;
            sum = sum*26 + n;
        }
        return sum;
    }
};