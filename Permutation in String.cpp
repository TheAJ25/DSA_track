// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

 

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
 

// Constraints:

// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.




class Solution {

public:
    bool equal(vector<int> vec1, vector<int> vec2){
        for(int i=0; i<26; i++){
            if(vec1[i] != vec2[i]){
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0);
        for(auto it: s1){
            freq1[it - 'a'] ++;
        }
        
        vector<int> freq2(26, 0);
        int i=0, j=0;

        while(j<s2.size()){
            freq2[s2[j] - 'a']++;

            if(j-i+1 == s1.size()){
                if(equal(freq1, freq2)){
                    return true;
                }
            }

            if(j-i+1 < s1.size()){
                j++;
            }

            else{
                freq2[s2[i] - 'a'] --;
                i++;
                j++;
            }
        }
        return false;
    }
};
