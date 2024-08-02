#include <iostream>
#include <algorithm>

using namespace std;

// Dynamic programming array to store the counts of 0 and 1 up to 100 digits
long long dp[2][100];

int main() {
    string s;
    cin >> s;

    // Reverse the input string
    reverse(s.begin(), s.end());
    int n = s.size();

    // Initialize the base cases for dp array based on the first digit of the reversed string
    if (s[0] == '0') {
        // If the first digit is 0, no bulbs need to be switched off
        dp[0][0] = 0;  
        // If the first digit is 0, one bulb needs to be switched on
        dp[1][0] = 1;
    }
    else {
        // If the first digit is 1, one bulb needs to be switched off
        dp[0][0] = 1;
        // If the first digit is 1, no bulbs need to be switched on
        dp[1][0] = 0;
    }

    // Iterate through the string to fill the dp array
    for (int i = 1; i < n; ++i) {
        // If the current digit is 0
        if (s[i] == '0') {
            // The count of 0 remains the same as the previous digit
            dp[0][i] = dp[0][i - 1];
            // The count of 1 is the count of 1 from the previous digit plus 2^i
            dp[1][i] = dp[1][i - 1] + (1ll << i);
        }
        // If the current digit is 1
        else {
            // The count of 0 is the count of 1 from the previous digit plus 2^i
            dp[0][i] = dp[1][i - 1] + (1ll << i);
            // The count of 1 remains the same as the previous digit
            dp[1][i] = dp[0][i - 1];
        }
    }

    // Output the count of bulbs that need to be switched off to turn them all on
    cout << dp[0][n - 1] << "\n";
}