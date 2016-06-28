/*
13. Roman to Integer
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
    int romanToInt(string s) {
        
    }
};

*/

class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        int pre = 0;
        int index = 0;
        bool error = false;
        int sum = 0;
        for(; index<len && !error; ++index)
        {
            switch(s[index]) {
            case 'I' :
                sum += 1;
                if(pre < 1)
                    sum -= 2*pre;
                pre = 1;
                break;
            case 'V':
                sum += 5;
                if(pre < 5)
                    sum -= 2*pre;
                pre = 5;
                break;
            case 'X':
                sum += 10;
                if(pre < 10)
                    sum -= 2*pre;
                pre = 10;
                break;
            case 'L':
                sum += 50;
                if(pre < 50)
                    sum -= 2*pre;
                pre = 50;
                break;
            case 'C':
                sum += 100;
                if(pre < 100)
                    sum -= 2*pre;
                pre = 100;
                break;
            case 'D':
                sum += 500;
                if(pre < 500)
                    sum -= 2*pre;
                pre = 500;
                break;
            case 'M':
                sum += 1000;
                if(pre < 1000)
                    sum -= 2*pre;
                pre = 1000;
                break;
            default:
                cout << "Not Roman Numeral\n";
                error = true;
                sum = 0;
                break;
            }
    
        }
    
        return sum;
    }
};