#include "commonfunctions.h"

int main(int argc, char* argv[])

{

    FILE *Output=fopen("backtrack_output.txt", "w+");

    FILE *fp = fopen(argv[1], "r");

    

    doOperation(fp,Output);



return 0;

}
