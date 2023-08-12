// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(256, -1);
        int left, right, length;
        left = 0; 
        right = 0;
        length = 0;
        int n = s.size();

        while(right < n){
            if(v[s[right]] != -1){
                left = max(v[s[right]] + 1, left);
            }
            
            v[s[right]] = right;
            
            length = max(length, right - left + 1);
            right++;
        }
        
        return length;
    }
};
