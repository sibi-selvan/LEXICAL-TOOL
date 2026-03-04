#include <stdio.h>
#include <string.h>

int main() {
    char production[100], commonPrefix[100], rest[100];
    char nonTerminal;
    int i = 0, j = 0, k;

    // Input the production
    printf("Enter Production for Left Factoring (Example: A=abc/abd): ");
    scanf("%s", production);

    // Open output file
    FILE *fp = fopen("Exp_4/output.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    nonTerminal = production[0];

    // Find common prefix between alternatives
    int slashPos = 0;
    while (production[slashPos] != '/' && production[slashPos] != '\0') {
        slashPos++;
    }

    j = 2; // after '='
    k = 2; // after '='
    int prefixLen = 0;

    // Compare characters of first two alternatives
    while (production[j] != '/' && production[k + slashPos - 2] != '\0' &&
           production[j] == production[k + slashPos - 2]) {
        commonPrefix[prefixLen++] = production[j];
        j++;
    }
    commonPrefix[prefixLen] = '\0';

    // Get rest of alternatives
    j = 2 + prefixLen;
    int m = 0;
    while (production[j] != '\0') {
        if (production[j] != '/')
            rest[m++] = production[j];
        else
            rest[m++] = '|';
        j++;
    }
    rest[m] = '\0';

    // Prepare left-factored output
    char output1[200], output2[200];
    sprintf(output1, "%c -> %s%c'\n", nonTerminal, commonPrefix, nonTerminal);
    sprintf(output2, "%c' -> %s | ε\n", nonTerminal, rest);

    // Print to console
    printf("\nGrammar after Left Factoring:\n");
    printf("%s", output1);
    printf("%s", output2);

    // Save to file
    fprintf(fp, "Grammar after Left Factoring:\n");
    fprintf(fp, "%s", output1);
    fprintf(fp, "%s", output2);

    fclose(fp);
    printf("\nOutput automatically saved to Exp_4/output.txt\n");
    return 0;
}