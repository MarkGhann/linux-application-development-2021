#include <gtest/gtest.h>

#include "buf.h"

TEST(LibBufferTest, InitClear) {
    float *a = 0;
    ASSERT_TRUE(buf_capacity(a) == 0);
    ASSERT_TRUE(buf_size(a) == 0);

    buf_push(a, 1.3f);
    ASSERT_TRUE(buf_size(a) == 1);
    ASSERT_TRUE(a[0] == (float)1.3f);

    buf_clear(a);
    ASSERT_TRUE(buf_size(a) == 0);
    ASSERT_TRUE(a != 0);

    buf_free(a);
    ASSERT_TRUE(a == 0);

    buf_clear(a);
    ASSERT_TRUE(buf_size(a) == 0);
    ASSERT_TRUE(a == 0);
}

TEST(LibBufferTest, PushFree) {
    /* buf_push(), [] operator */
    long *ai = 0;
    for (int i = 0; i < 10000; i++)
        buf_push(ai, i);

    ASSERT_TRUE(buf_size(ai) == 10000);

    int match = 0;
    for (int i = 0; i < (int)(buf_size(ai)); i++)
        match += ai[i] == i;

    ASSERT_TRUE(match == 10000);

    buf_free(ai);
}

TEST(LibBufferTest, GrowTruncFree) {
    /* buf_grow(), buf_trunc() */
    long *ai = 0;
    buf_grow(ai, 1000);
    ASSERT_TRUE(buf_capacity(ai) == 1000);
    ASSERT_TRUE(buf_size(ai) == 0);

    buf_trunc(ai, 100);
    ASSERT_TRUE(buf_capacity(ai) == 100);

    buf_free(ai);
}

TEST(LibBufferTest, PushTruncFree) {
    /* buf_pop() */
    float *a = 0;
    buf_push(a, 1.1);
    buf_push(a, 1.2);
    buf_push(a, 1.3);
    buf_push(a, 1.4);

    ASSERT_TRUE(buf_size(a) == 4);
    ASSERT_TRUE(buf_pop(a) == (float)1.4f);

    buf_trunc(a, 3);

    ASSERT_TRUE(buf_size(a) == 3);
    ASSERT_TRUE(buf_pop(a) == (float)1.3f);
    ASSERT_TRUE(buf_pop(a) == (float)1.2f);
    ASSERT_TRUE(buf_pop(a) == (float)1.1f);
    ASSERT_TRUE(buf_size(a) == 0);

    buf_free(a);
}