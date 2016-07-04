/*
168. Excel Sheet Column Title

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
	
class Solution {
public:
    string convertToTitle(int n) {
        
    }
};

*/

class Solution {
public:
/*********************************************/ //方法1
    string convertToTitle(int n) {
        string table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string s = "";
        stack<char> stack_;
        do {
            stack_.push(table[(n-1)%26]);
            n -= (n-1)%26;
            n /= 26;
        }while(n);
        while(stack_.size() != 0) {
            s += stack_.top();
            stack_.pop();
        }
        return s;
    }
/*********************************************/ //方法2
	string convertToTitle(int n) {
        if(n<=0) return "";
        string s = "";
        while(n) {
            int buf = (n-1) % 26;
            char ch = 'A' + buf;
            s.insert(s.begin(), ch);
            n -= buf;
            n /= 26;
        }
        return s;
	}
	
};