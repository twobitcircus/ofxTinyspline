#include "tinyspline.h"
#include "CuTest.h"

void fequals_test_zero(CuTest* tc)
{
    CuAssertTrue(tc, ts_fequals(0.f, 0.f) == 1);
    CuAssertTrue(tc, ts_fequals(-0.f, 0.f) == 1);
    CuAssertTrue(tc, ts_fequals(0.f, -0.f) == 1);
}

void fequals_test_equals(CuTest* tc)
{
    CuAssertTrue(tc, ts_fequals(1.f, 1.f) == 1);
    CuAssertTrue(tc, ts_fequals(2.f, 2.f) == 1);
    CuAssertTrue(tc, ts_fequals(1000.f, 1000.f) == 1);
    CuAssertTrue(tc, ts_fequals(1000000.f, 1000000.f) == 1);

    CuAssertTrue(tc, ts_fequals(-1.f, -1.f) == 1);
    CuAssertTrue(tc, ts_fequals(-2.f, -2.f) == 1);
    CuAssertTrue(tc, ts_fequals(-1000.f, -1000.f) == 1);
    CuAssertTrue(tc, ts_fequals(-1000000.f, -1000000.f) == 1);
}

void fequals_test_unequals(CuTest* tc)
{
    CuAssertTrue(tc, ts_fequals(0.f, 1.f) == 0);
    CuAssertTrue(tc, ts_fequals(1.f, 0.f) == 0);
    CuAssertTrue(tc, ts_fequals(0.f, 2.f) == 0);
    CuAssertTrue(tc, ts_fequals(2.f, 0.f) == 0);
    CuAssertTrue(tc, ts_fequals(0.f, 1000.f) == 0);
    CuAssertTrue(tc, ts_fequals(1000.f, 0.f) == 0);
    CuAssertTrue(tc, ts_fequals(0.f, 1000000.f) == 0);
    CuAssertTrue(tc, ts_fequals(1000000.f, 0.f) == 0);

    CuAssertTrue(tc, ts_fequals(1.f, 2.f) == 0);
    CuAssertTrue(tc, ts_fequals(2.f, 1.f) == 0);
    CuAssertTrue(tc, ts_fequals(200.f, 300.f) == 0);
    CuAssertTrue(tc, ts_fequals(300.f, 200.f) == 0);
    CuAssertTrue(tc, ts_fequals(20000.f, 30000.f) == 0);
    CuAssertTrue(tc, ts_fequals(30000.f, 20000.f) == 0);

    CuAssertTrue(tc, ts_fequals(0.f, -1.f) == 0);
    CuAssertTrue(tc, ts_fequals(-1.f, 0.f) == 0);
    CuAssertTrue(tc, ts_fequals(0.f, -2.f) == 0);
    CuAssertTrue(tc, ts_fequals(-2.f, 0.f) == 0);
    CuAssertTrue(tc, ts_fequals(0.f, -1000.f) == 0);
    CuAssertTrue(tc, ts_fequals(-1000.f, 0.f) == 0);
    CuAssertTrue(tc, ts_fequals(0.f, -1000000.f) == 0);
    CuAssertTrue(tc, ts_fequals(-1000000.f, 0.f) == 0);

    CuAssertTrue(tc, ts_fequals(-1.f, -2.f) == 0);
    CuAssertTrue(tc, ts_fequals(-2.f, -1.f) == 0);
    CuAssertTrue(tc, ts_fequals(-200.f, -300.f) == 0);
    CuAssertTrue(tc, ts_fequals(-300.f, -200.f) == 0);
    CuAssertTrue(tc, ts_fequals(-20000.f, -30000.f) == 0);
    CuAssertTrue(tc, ts_fequals(-30000.f, -20000.f) == 0);

    CuAssertTrue(tc, ts_fequals(1.f, -1.f) == 0);
    CuAssertTrue(tc, ts_fequals(-1.f, 1.f) == 0);
    CuAssertTrue(tc, ts_fequals(2.f, -2.f) == 0);
    CuAssertTrue(tc, ts_fequals(-2.f, 2.f) == 0);
    CuAssertTrue(tc, ts_fequals(1000.f, -1000.f) == 0);
    CuAssertTrue(tc, ts_fequals(-1000.f, 1000.f) == 0);
    CuAssertTrue(tc, ts_fequals(1000000.f, -1000000.f) == 0);
    CuAssertTrue(tc, ts_fequals(-1000000.f, 1000000.f) == 0);

    CuAssertTrue(tc, ts_fequals(200.f, -586.f) == 0);
    CuAssertTrue(tc, ts_fequals(-586.f, 200.f) == 0);
}

void fequals_test_small(CuTest* tc)
{
    /* This should be the minimum difference that should
     * be supported by fequals */
    CuAssertTrue(tc, ts_fequals(0, 0.0001f) == 0);
    CuAssertTrue(tc, ts_fequals(1, 1.0001f) == 0);
    CuAssertTrue(tc, ts_fequals(2, 2.0001f) == 0);
    CuAssertTrue(tc, ts_fequals(1000, 1000.0001f) == 0);
    CuAssertTrue(tc, ts_fequals(-0, -0.0001f) == 0);
    CuAssertTrue(tc, ts_fequals(-1, -1.0001f) == 0);
    CuAssertTrue(tc, ts_fequals(-2, -2.0001f) == 0);
    CuAssertTrue(tc, ts_fequals(-1000, -1000.0001f) == 0);

}

CuSuite* get_fequals_suite()
{
    CuSuite* suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, fequals_test_zero);
    SUITE_ADD_TEST(suite, fequals_test_equals);
    SUITE_ADD_TEST(suite, fequals_test_unequals);
    SUITE_ADD_TEST(suite, fequals_test_small);

    return suite;
}