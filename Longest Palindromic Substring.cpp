// Given a string s, return the longest 
// palindromic
 
// substring
//  in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.















class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1) {
            return s;
        }

        string lps = ""; // Initialize lps to an empty string

        for (int i = 0; i < s.length(); i++) {  // Start from index 0
            // Consider odd length palindromes
            int low = i;
            int high = i;
            while (low >= 0 && high < s.length() && s[low] == s[high]) {
                low--;
                high++;
            }
            string palindrome = s.substr(low + 1, high - low - 1);  // Extract the palindrome substring
            if (palindrome.length() > lps.length()) {
                lps = palindrome;  // Update lps only if the new palindrome is longer
            }

            // Consider even length palindromes
            low = i;
            high = i + 1;
            while (low >= 0 && high < s.length() && s[low] == s[high]) {
                low--;
                high++;
            }
            palindrome = s.substr(low + 1, high - low - 1);  // Extract the palindrome substring
            if (palindrome.length() > lps.length()) {
                lps = palindrome;  // Update lps only if the new palindrome is longer
            }
        }

        return lps;  // Return the longest palindrome found
    }
};
