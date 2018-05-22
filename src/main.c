#include "kmp.h"
#include "kmp.c"

int main(int argc, char *argv[])
{
    FILE *in;
    int N = 10000;
    char str[N];
    int counter = 1;
    int position;

    if (argc != 3) {
	printf("Invalid argument\n");
	return -1;
    }

    in = fopen(argv[2], "r");
    if (in == NULL) {
	printf("Error open file\n");
	return -1;
    }

    while (!feof(in)) {
	fgets(str, 10000, in);
	position = kmp(str, argv[1]);
	if (position > 0){
	    printf("%d: %d\n", counter, position + 1);
	}
	counter++;
    }
    fclose(in);

    return 0;
}