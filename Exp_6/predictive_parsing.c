#include <stdio.h>
#include <string.h>
#include <ctype.h>

char production[10][10], first[10][10], follow[10][10];
char table[10][10][10];
int n;

int main() {
    int i, j;
    char nonTerminals[10], terminals[10];

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (Example: E=TR):\n");
    for (i = 0; i < n; i++) {
        scanf("%s", production[i]);
    }

    printf("\nPredictive Parsing Table:\n");

    printf("\n-----------------------------\n");
    printf("Non-Terminal | Production\n");
    printf("-----------------------------\n");

    for (i = 0; i < n; i++) {
        printf("     %c       |   %s\n", production[i][0], production[i]);
    }

    printf("-----------------------------\n");

    printf("\nNOTE:\n");
    printf("1. If A → α and 'a' in FIRST(α), add A→α to M[A,a]\n");
    printf("2. If ε in FIRST(α), add A→α to M[A,b] for all b in FOLLOW(A)\n");

    return 0;
}
