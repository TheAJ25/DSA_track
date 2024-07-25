// You are given an array of words where each word consists of lowercase English letters.

// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

// Return the length of the longest possible word chain with words chosen from the given list of words.

 

// Example 1:

// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
// Example 2:

// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
// Example 3:

// Input: words = ["abcd","dbqca"]
// Output: 1
// Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
// ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 

// Constraints:

// 1 <= words.length <= 1000
// 1 <= words[i].length <= 16
// words[i] only consists of lowercase English letters.




class Solution {
public:

    int n;
    int dp[1001][1001];

    static bool myfunc(string &word1, string &word2){
        return word1.length()<word2.length();
    }

    bool isprede(string prev, string cur){
        int M = prev.length();
        int N = cur.length();

        if(M>=N || M != N - 1){
            return false;
        }

        int i=0;
        int j = 0;
        while(i<M && j<N){
            if(prev[i] == cur[j]){
                i++;
            }
            j++;
        }
        return i==M;
    }

    int solve(vector<string>& words, int cur, int prev){

        if(dp[cur][prev+1] != -1){
            return dp[cur][prev+1];
        }

        if(cur>=n){
            return 0;
        }

        int skip = solve(words, cur+1, prev);
        int take = 0;
        if(prev==-1 || isprede(words[prev], words[cur])){
            take = 1 + solve(words, cur+1, cur);
        }
        return dp[cur][prev+1] = max(take, skip);
    }

    int longestStrChain(vector<string>& words) {
        n = words.size();
        memset(dp, -1, sizeof(dp));
        sort(words.begin(), words.end(), myfunc);
        return solve(words, 0, -1);
    }
};
