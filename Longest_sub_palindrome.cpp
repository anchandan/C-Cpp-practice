class Solution {
public:
    bool isPalindrome(string str)
    {
        for(int i = 0 ; i < str.size() ; i++)
        {
            if(str[i] != str[str.size() - i - 1])
            {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        string longestsubpalindrome;
        longestsubpalindrome +=s[0];
        string current_substring = longestsubpalindrome;
        for(int i = 1 ; i < s.size() ; i++)
        {
            current_substring += s[i];
            if(isPalindrome(current_substring))
            {
                if(longestsubpalindrome.size() < current_substring.size())
                {
                    longestsubpalindrome = current_substring;
                }
            }
            else
            {
                string r = current_substring.substr(i);
                current_substring = r;
            }
        }
        return longestsubpalindrome;
    }
};