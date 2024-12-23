// Question => Given an input string (s) and a pattern (p), implement wildcard pattern matching with
//  support for '?' and '*' where:
//  '?' Matches any single character.
//  '*' Matches any sequence of characters (including the empty sequence).
//  The matching should cover the entire input string (not partial)


#include <iostream>
#include <vector>
using namespace std;

bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();
    
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    
    dp[0][0] = true; 
    
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1]; 
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}

int main() {
    cout << boolalpha;
    cout << "Test Case 1: " << isMatch("aa", "a") << endl; 
    cout << "Test Case 2: " << isMatch("aa", "*") << endl; 
    cout << "Test Case 3: " << isMatch("cb", "?a") << endl; 
    cout << "Test Case 4: " << isMatch("aa", "a*") << endl; 
    cout << "Test Case 5: " << isMatch("adceb", "*a*b") << endl; 
    cout << "Test Case 6: " << isMatch("acdcb", "a*c?b") << endl; 
    
    return 0;
}
