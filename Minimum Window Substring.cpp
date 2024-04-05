// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring
//  of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
 

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.





class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (auto it: t){
            mp[it]++;
        }
        int left = 0;
        int right = 0;
        int count = t.size();
        int minlen = INT_MAX;
        int minleft;
        while(right<s.size()){
            if(mp[s[right]]>0){
                count --;
            }
            mp[s[right]]--;
            right ++;

            while(count == 0){
                if(right-left < minlen){
                    minleft = left;
                    minlen = right-left;
                }
                mp[s[left]] ++;
                if(mp[s[left]]>0){
                    count ++;
                }
                left ++;
            }
        }
        if(minlen != INT_MAX){
            return s.substr(minleft, minlen);
        }
        return "";
    }
};
