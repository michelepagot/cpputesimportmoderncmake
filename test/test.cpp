#include "CppUTest/TestHarness.h"


#ifdef __cplusplus
extern "C" {
#endif

#include "lib.h"

#ifdef __cplusplus
}
#endif

TEST_GROUP(TestLib)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(TestLib, addTest)
{
    LONGS_EQUAL(5, add(3,2));

}

