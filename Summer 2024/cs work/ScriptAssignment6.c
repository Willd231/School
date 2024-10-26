/*
William Dellinger 
Script Assigment 6
7/21/24*/
#include <stdio.h>
#include <string.h>

//find the length of the longest common subsequence
int lcs(char* X, char* Y, int m, int n, char* lcsStr) {
    int L[m + 1][n + 1];

    // Building the L[m+1][n+1] table in bottom-up fashion
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
            }
        }
    }

    // Following code is used to print LCS
    int index = L[m][n];

    // Create a character array to store the lcs string
    lcsStr[index] = '\0'; // Set the terminating character

    
    int i = m, j = n;
    while (i > 0 && j > 0) {
        // If current character is same, then
        // current character is part of LCS
        if (X[i - 1] == Y[j - 1]) {
        lcsStr[index - 1] = X[i - 1]; // Put current character in result
        i--;
        j--;
            index--; // reduce values of i, j and index
        }
        // If not the same find the larger of two and go in the direction of larger value
        else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return L[m][n];
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);


    char lcsStr[m + n + 1];

    printf("Length of LCS is %d\n", lcs(X, Y, m, n, lcsStr));
    printf("LCS of %s and %s is %s\n", X, Y, lcsStr);

    return 0;
}
