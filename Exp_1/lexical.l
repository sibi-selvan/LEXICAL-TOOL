%{
#include <stdio.h>
#include <stdlib.h>

FILE *fp;
%}

%%

[0-9]+                 { 
                            printf("NUMBER: %s\n", yytext); 
                            fprintf(fp, "NUMBER: %s\n", yytext);
                        }

[a-zA-Z_][a-zA-Z0-9_]* { 
                            printf("IDENTIFIER: %s\n", yytext); 
                            fprintf(fp, "IDENTIFIER: %s\n", yytext);
                        }

[ \t\n]+                ;   /* ignore whitespace */

.                       { 
                            printf("SYMBOL: %s\n", yytext); 
                            fprintf(fp, "SYMBOL: %s\n", yytext);
                        }

%%

int main() {
    // Open output file
    fp = fopen("lexical_output.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter text to analyze (Ctrl+D to end):\n");
    yylex();

    fclose(fp);
    printf("\nLexical analysis output saved to lexical_output.txt\n");
    return 0;
}