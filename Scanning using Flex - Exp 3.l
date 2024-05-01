%{
#include <stdio.h>
int alphabet_count = 0;
int string_count = 0;
int word_count = 0;
int char_count = 0;
%}

%%
[a-zA-Z]   { alphabet_count++; char_count++; }
[^ \t\n]+  { string_count++; char_count += yyleng; }
[^ \t\n]+  { word_count++; char_count += yyleng; }
\n         { word_count++; char_count++; }

%%

int main() {
    yylex();
    printf("Alphabets: %d\n", alphabet_count);
    printf("Strings: %d\n", string_count);
    printf("Words: %d\n", word_count);
    printf("Characters: %d\n", char_count);
    return 0;
}