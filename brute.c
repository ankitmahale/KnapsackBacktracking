
#include<math.h>

#include "commonfunctions.h"

int main(int argc, char* argv[])
{
    int n=0;
	int W=0;

	int i=0;

	FILE *Output=fopen("brute_output.txt", "w+");
    FILE *fp = fopen(argv[1], "r");
	bruteforce(fp,Output);
    return 0;
}
