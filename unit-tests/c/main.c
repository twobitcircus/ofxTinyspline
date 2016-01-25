#include "CuTest.h"
#include <stdio.h>

void main(void)
{
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}