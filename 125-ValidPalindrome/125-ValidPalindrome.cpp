// Last updated: 5/17/2026, 5:52:15 PM
class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for (int i=0;i<s.length();i++) {
        if (isalnum(s[i])) {
            str += tolower(s[i]);
        }
    }
        return check(str, 0, str.length());
    }

private:
    bool check(string& s, int i, int n) {
        if (i >= n / 2) 
            return true;

        if (s[i] != s[n - i - 1])
            return false;

        return check(s, i + 1, n);
    }
};
