#include <stdio.h>
#include <stdlib.h>
#include "kmp.h"

int str(char *string)
{
    unsigned int length = 0;
    while (string[length] != '\0') {
	++length;
    }
    return length;
}

int kmp(char s[], char p[])
{
    int i, j, N, M;
    N = str(s);
    M = str(p);

    int *d = (int*)malloc(M * sizeof(int));

    d[0] = 0;
    for(i = 1, j = 0; i < M; i++)
    {
	while(j > 0 && p[j] != p[i])
	    j = d[j-1];
	if(p[j] == p[i])
	    j++;
	d[i] = j;
    }

    for(i = 0, j = 0; i < N; i++)
    {
	while(j > 0 && p[j] != s[i])
	    j = d[j - 1];
	if(p[j] == s[i])
            j++;
	if(j == M)
        {
	    free(d);
            return i - j + 1;
        }
    }
    free(d);
    return -1;
}