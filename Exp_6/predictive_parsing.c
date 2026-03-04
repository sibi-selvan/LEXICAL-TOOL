#include <stdio.h>
#include <string.h>
#include <ctype.h>

char production[10][10], first[10][10], follow[10][10];
char table[10][10][10];
int n;

int main() {
    int i, j;
    char nonTerminals[10], terminals[10];
    FILE *fp;  // File pointer for output

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (Example: E=TR):\n");
    for (i = 0; i < n; i++) {
        scanf("%s", production[i]);
    }

    // Open output file
    fp = fopen("ll_1.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Print table header
    printf("\nPredictive Parsing Table:\n");
    fprintf(fp, "\nPredictive Parsing Table:\n");

    printf("\n-----------------------------\n");
    printf("Non-Terminal | Production\n");
    printf("-----------------------------\n");
    fprintf(fp, "\n-----------------------------\n");
    fprintf(fp, "Non-Terminal | Production\n");
    fprintf(fp, "-----------------------------\n");

    // Print productions
    for (i = 0; i < n; i++) {
        printf("     %c       |   %s\n", production[i][0], production[i]);
        fprintf(fp, "     %c       |   %s\n", production[i][0], production[i]);
    }

    printf("-----------------------------\n");
    fprintf(fp, "-----------------------------\n");

    // Print notes
    printf("\nNOTE:\n");
    printf("1. If A → α and 'a' in FIRST(α), add A→α to M[A,a]\n");
    printf("2. If ε in FIRST(α), add A→α to M[A,b] for all b in FOLLOW(A)\n");

    fprintf(fp, "\nNOTE:\n");
    fprintf(fp, "1. If A → α and 'a' in FIRST(α), add A→α to M[A,a]\n");
    fprintf(fp, "2. If ε in FIRST(α), add A→α to M[A,b] for all b in FOLLOW(A)\n");

    fclose(fp); // close file
    printf("\nOutput automatically saved to ll_1.txt\n");

    return 0;
}