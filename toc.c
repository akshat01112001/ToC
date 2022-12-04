#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <regex.h>

#define MAX_TOKENS 1000000
#define MAX_LINE_LENGTH 1000000
#define EXIT_SUCCESS 0
#define MAX_LIMIT 100
#define ll long long int

char tokens[MAX_TOKENS];
int num_tokens;

/**
Reads the passed input file line by line.
Removes all space type characters from the lines, including \n (Carriage Return). 
Modifies the global tokens and num_tokens variables. 
*/

void tokenize(char* filename) {

    FILE* in_file = fopen(filename, "r");

    char line[MAX_TOKENS];
    while (fgets(line, MAX_LINE_LENGTH, in_file)) {
        for (int i = 0; i < strlen(line); ++i) {
            if (line[i] == ' ' || line[i] == '\t' || line[i] == 10 /* ASCII 10 = Line Feed */ || line[i] == '\n') continue;
            tokens[num_tokens++] = line[i];
        }
    }
}

ll k=0;

void f(char *ch, ll i, ll n, char * output, char *set[])
{
    if (i == n - 1)
    {
        set[k++] = output + ch[i];
    }
    return f(ch,i+1,n,output+ch[i]+'+', set);
    return f(ch,i+1,n,output+ch[i]+'-',set);
    return f(ch,i+1,n,output+ch[i]+'*',set);
    return f(ch,i+1,n,output+ch[i]+'/',set);
}

int main(int argc, char **argv){

    if (argc < 2) {
        perror("Pass the name of the input file as the first parameter. e.g.: ./simulator input.txt");
        exit(EXIT_FAILURE);
    }
    tokenize(argv[1]);

    // for (ll i = 0; i < 2; i++){
    //     printf("%s", tokens[i]);
    // }

    ll i;
    char *set[MAX_LIMIT], *ch="abcdefghijklmnopqrstuvxyz";
    for (i = 0; i < MAX_LIMIT; i++){
        set[i] = (char *)malloc(1000*sizeof(char));
    }
    f(ch, 0, 26, "", set);
    // for (i = 0; i < 26; i++){
    //     printf("%s", *set[i]);
    // }

    return 0;
}