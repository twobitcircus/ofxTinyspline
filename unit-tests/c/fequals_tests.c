#include "tinyspline.h"
#include "CuTest.h"

void fequals_test_zero(CuTest *tc)
{
    CuAssertTrue(tc, ts_fequals(0.f, 0.f) == 1);
}

CuSuite* get_fequals_suite()
{
    CuSuite* suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, fequals_test_zero);

    return suite;
}