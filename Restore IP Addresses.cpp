// A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
// Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

 

// Example 1:

// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]
// Example 2:

// Input: s = "0000"
// Output: ["0.0.0.0"]
// Example 3:

// Input: s = "101023"
// Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

// Constraints:

// 1 <= s.length <= 20
// s consists of digits only.





class Solution {
private:
    bool isValid(string s) {
        if (s[0] == '0' && s.length() > 1) {
            return false;  // Leading zeros are not allowed
        }
        if (stoi(s) > 255) {
            return false;  // Check if the segment is less than or equal to 255
        }
        return true;
    }

    void solve(int idx, string str, string curr, int parts, vector<string>& result) {
        if (parts == 4 && idx == str.length()) {
            curr.pop_back();  // Remove the last dot
            result.push_back(curr);
            return;
        }

        if (parts >= 4 || idx >= str.length()) {
            return;  // If parts exceed 4 or index exceeds string length, return
        }

        if (idx + 1 <= str.length()) {
            solve(idx + 1, str, curr + str.substr(idx, 1) + ".", parts + 1, result);
        }

        if (idx + 2 <= str.length() && isValid(str.substr(idx, 2))) {
            solve(idx + 2, str, curr + str.substr(idx, 2) + ".", parts + 1, result);
        }

        if (idx + 3 <= str.length() && isValid(str.substr(idx, 3))) {
            solve(idx + 3, str, curr + str.substr(idx, 3) + ".", parts + 1, result);
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        if (s.length() > 12) {
            return {};  // If the length of the string is greater than 12, return empty result
        }

        vector<string> result;
        solve(0, s, "", 0, result);
        return result;
    }
};
