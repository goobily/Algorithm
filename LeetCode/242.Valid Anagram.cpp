/*
242. Valid Anagram

Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

*/

class Solution {
public:
/*********************************************/ //方法1，12 ms
    bool isAnagram(string s, string t) {
        int arr[26] = {0};
        for(int i=0; i<s.length(); ++i)
            arr[s[i]-'a']++;
        for(int i=0; i<t.length(); ++i)
            arr[t[i]-'a']--;
        for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
            if(arr[i] != 0) return false;
        return true;
    }
/*********************************************/ //方法1，76 ms   
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};