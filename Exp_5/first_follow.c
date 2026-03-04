#include <stdio.h>
#include <ctype.h>
#include <string.h>

int n;
char productions[10][10];
int m = 0;
FILE *fp;  // File pointer for output

void findFirst(char c);
void findFollow(char c);

int main() {
    int i;
    char c;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (Example: E=TR):\n");
    for (i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }

    printf("Enter non-terminal to find FIRST and FOLLOW: ");
    scanf(" %c", &c);

    // Open output file
    fp = fopen("first_follow_output.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Print FIRST to console and file
    printf("\nFIRST(%c) = { ", c);
    fprintf(fp, "FIRST(%c) = { ", c);
    findFirst(c);
    printf("}\n");
    fprintf(fp, "}\n");

    m = 0;

    // Print FOLLOW to console and file
    printf("FOLLOW(%c) = { ", c);
    fprintf(fp, "FOLLOW(%c) = { ", c);
    findFollow(c);
    printf("}\n");
    fprintf(fp, "}\n");

    fclose(fp); // close file
    printf("\nOutput automatically saved to first_follow_output.txt\n");

    return 0;
}

void findFirst(char c) {
    int i;

    if (!isupper(c)) {
        printf("%c ", c);
        fprintf(fp, "%c ", c);
        return;
    }

    for (i = 0; i < n; i++) {
        if (productions[i][0] == c) {
            if (!isupper(productions[i][2])) {
                printf("%c ", productions[i][2]);
                fprintf(fp, "%c ", productions[i][2]);
            } else {
                findFirst(productions[i][2]);
            }
        }
    }
}

void findFollow(char c) {
    int i, j;

    if (productions[0][0] == c) {
        printf("$ ");
        fprintf(fp, "$ ");
    }

    for (i = 0; i < n; i++) {
        for (j = 2; j < strlen(productions[i]); j++) {
            if (productions[i][j] == c) {
                if (productions[i][j+1] != '\0') {
                    findFirst(productions[i][j+1]);
                }
                if (productions[i][j+1] == '\0' && c != productions[i][0]) {
                    findFollow(productions[i][0]);
                }
            }
        }
    }
}