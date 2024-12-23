//  Question => Special binary strings are binary strings with the following two properties:
//  The number of 0's is equal to the number of 1's.
//  Every prefix of the binary string has at least as many 1's as 0's.
//  You are given a special binary string s.
//  Amoveconsists of choosing two consecutive, non-empty, special substrings of s, and
//  swapping them. Two strings are consecutive if the last character of the first string is
//  exactly one index before the first character of the second string.
//  Return the lexicographically largest resulting string possible after applying the
//  mentioned operations on the string.


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string makeLargestSpecial(string s) {
    if (s.length() <= 1) return s;

    vector<string> substrings;
    int count = 0, start = 0;
    
    for (int i = 0; i < s.length(); i++) {
        count += (s[i] == '1') ? 1 : -1;  
        
        if (count == 0) {
            string sub = s.substr(start + 1, i - start - 1);  
            substrings.push_back(makeLargestSpecial(sub)); 
            start = i + 1;  
        }
    }

    sort(substrings.rbegin(), substrings.rend());

    string result = "1";
    for (const string& sub : substrings) {
        result += sub;
    }
    result += "0";

    return result;
}

int main() {
    string s1 = "11011000";
    string s2 = "10";
    string s3 = "110100110";
    cout << "Largest Special Binary String for " << s3 << " : " << makeLargestSpecial(s3) << endl; 

    return 0;
}
