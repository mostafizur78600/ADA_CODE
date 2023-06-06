#include <stdio.h>
#include <string.h>

// Utility function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the longest common subsequence of two strings
void longest_common_subsequence(char X[], char Y[]) {
    int m = strlen(X); // Length of string X
    int n = strlen(Y); // Length of string Y

    // Create a table to store the lengths of the longest common subsequences
    int lcs_table[m+1][n+1];

    // Build the lcs_table bottom-up
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                lcs_table[i][j] = 0; // Base case: empty string, LCS length is 0
            else if (X[i-1] == Y[j-1])
                lcs_table[i][j] = lcs_table[i-1][j-1] + 1; // Characters match, increment the length
            else
                lcs_table[i][j] = max(lcs_table[i-1][j], lcs_table[i][j-1]); // Characters do not match, take the maximum length
        }
    }

    // Length of the longest common subsequence
    int length = lcs_table[m][n];

    // Reconstruct the longest common subsequence
    char lcs[length+1]; // Array to store the longest common subsequence
    lcs[length] = '\0'; // Null-terminate the array
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs[length-1] = X[i-1]; // Add the character to the subsequence
            i--;
            j--;
            length--;
        }
        else if (lcs_table[i-1][j] > lcs_table[i][j-1])
            i--; // Move towards the direction of a larger subsequence
        else
            j--;
    }

    // Print the longest common subsequence
    printf("Longest Common Subsequence: %s\n", lcs);
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    longest_common_subsequence(X, Y);

    return 0;
}
