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
    /* test zero with positive */
    CuAssertTrue(tc, ts_fequals(0.f, 1.f) == 0);
    CuAssertTrue(tc, ts_fequals(1.f, 0.f) == 0);
    CuAssertTrue(tc, ts_fequals(0.f, 2.f) == 0);
    CuAssertTrue(tc, ts_fequals(2.f, 0.f) == 0);
    CuAssertTrue(tc, ts_fequals(0.f, 1000.f) == 0);
    CuAssertTrue(tc, ts_fequals(1000.f, 0.f) == 0);
    CuAssertTrue(tc, ts_fequals(0.f, 1000000.f) == 0);
    CuAssertTrue(tc, ts_fequals(1000000.f, 0.f) == 0);

    /* test both positive*/
    CuAssertTrue(tc, ts_fequals(1.f, 2.f) == 0);
    CuAssertTrue(tc, ts_fequals(2.f, 1.f) == 0);
    CuAssertTrue(tc, ts_fequals(200.f, 300.f) == 0);
    CuAssertTrue(tc, ts_fequals(300.f, 200.f) == 0);
    CuAssertTrue(tc, ts_fequals(20000.f, 30000.f) == 0);
    CuAssertTrue(tc, ts_fequals(30000.f, 20000.f) == 0);

    /* test zero with negative */
    CuAssertTrue(tc, ts_fequals(0.f, -1.f) == 0);
    CuAssertTrue(tc, ts_fequals(-1.f, 0.f) == 0);
    CuAssertTrue(tc, ts_fequals(0.f, -2.f) == 0);
    CuAssertTrue(tc, ts_fequals(-2.f, 0.f) == 0);
    CuAssertTrue(tc, ts_fequals(0.f, -1000.f) == 0);
    CuAssertTrue(tc, ts_fequals(-1000.f, 0.f) == 0);
    CuAssertTrue(tc, ts_fequals(0.f, -1000000.f) == 0);
    CuAssertTrue(tc, ts_fequals(-1000000.f, 0.f) == 0);

    /* test both negative */
    CuAssertTrue(tc, ts_fequals(-1.f, -2.f) == 0);
    CuAssertTrue(tc, ts_fequals(-2.f, -1.f) == 0);
    CuAssertTrue(tc, ts_fequals(-200.f, -300.f) == 0);
    CuAssertTrue(tc, ts_fequals(-300.f, -200.f) == 0);
    CuAssertTrue(tc, ts_fequals(-20000.f, -30000.f) == 0);
    CuAssertTrue(tc, ts_fequals(-30000.f, -20000.f) == 0);

    /* test one positive one negative */
    CuAssertTrue(tc, ts_fequals(1.f, -1.f) == 0);
    CuAssertTrue(tc, ts_fequals(-1.f, 1.f) == 0);
    CuAssertTrue(tc, ts_fequals(2.f, -2.f) == 0);
    CuAssertTrue(tc, ts_fequals(-2.f, 2.f) == 0);
    CuAssertTrue(tc, ts_fequals(1000.f, -1000.f) == 0);
    CuAssertTrue(tc, ts_fequals(-1000.f, 1000.f) == 0);
    CuAssertTrue(tc, ts_fequals(1000000.f, -1000000.f) == 0);
    CuAssertTrue(tc, ts_fequals(-1000000.f, 1000000.f) == 0);

    /* test some random values without same same abs value */
    CuAssertTrue(tc, ts_fequals(200.f, -586.f) == 0);
    CuAssertTrue(tc, ts_fequals(-586.f, 200.f) == 0);
    CuAssertTrue(tc, ts_fequals(-98744.f, 13818.f) == 0);
    CuAssertTrue(tc, ts_fequals(-13818.f, 98744.f) == 0);
}

void fequals_test_small(CuTest* tc)
{
    /* tests around 0 */
    CuAssertTrue(tc, ts_fequals(0, 0.0001f) == 0);
    CuAssertTrue(tc, ts_fequals(0, -0.0001f) == 0);
    CuAssertTrue(tc, ts_fequals(0, 0.00001f) == 1);
    CuAssertTrue(tc, ts_fequals(0, -0.00001f) == 1);

    /* tests between 0 and max */
    CuAssertTrue(tc, ts_fequals(100, 100.0001f) == 0);
    CuAssertTrue(tc, ts_fequals(100, 99.9999f) == 0);
    CuAssertTrue(tc, ts_fequals(100, 100.00001f) == 1);
    CuAssertTrue(tc, ts_fequals(100, 99.99999f) == 1);

    CuAssertTrue(tc, ts_fequals(-100, -100.0001f) == 0);
    CuAssertTrue(tc, ts_fequals(-100, -99.9999f) == 0);
    CuAssertTrue(tc, ts_fequals(-100, -100.00001f) == 1);
    CuAssertTrue(tc, ts_fequals(-100, -99.99999f) == 1);

    CuAssertTrue(tc, ts_fequals(1000, 1000.0001f) == 0);
    CuAssertTrue(tc, ts_fequals(1000, 999.9999f) == 0);
    CuAssertTrue(tc, ts_fequals(1000, 1000.00001f) == 1);
    CuAssertTrue(tc, ts_fequals(1000, 999.99999f) == 1);

    CuAssertTrue(tc, ts_fequals(-1000, -1000.0001f) == 0);
    CuAssertTrue(tc, ts_fequals(-1000, -999.9999f) == 0);
    CuAssertTrue(tc, ts_fequals(-1000, -1000.00001f) == 1);
    CuAssertTrue(tc, ts_fequals(-1000, -999.99999f) == 1);

    /* tests around max */
    CuAssertTrue(tc, ts_fequals(-2047, -2047.0001f) == 0);
    CuAssertTrue(tc, ts_fequals(-2048, -2047.9999f) == 0);
    CuAssertTrue(tc, ts_fequals(-2047, -2047.00001f) == 1);
    CuAssertTrue(tc, ts_fequals(-2048, -2047.99999f) == 1);

    CuAssertTrue(tc, ts_fequals(2047, 2047.0001f) == 0);
    CuAssertTrue(tc, ts_fequals(2048, 2047.9999f) == 0);
    CuAssertTrue(tc, ts_fequals(2047, 2047.00001f) == 1);
    CuAssertTrue(tc, ts_fequals(2048, 2047.99999f) == 1);
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