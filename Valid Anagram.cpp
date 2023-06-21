// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
  
  
  
  solution:

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp1;
        for(auto it1 : s){
            mp1[it1]++;
        }
        map<char, int> mp2;
        for(auto it2 : t){
            mp2[it2]++;
        }
        if(mp1 == mp2){
            return true;
        }
        else{
            return false;
        }
    }
};
