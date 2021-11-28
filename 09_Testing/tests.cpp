#include <gtest/gtest.h>

#include "buf.h"

TEST(LibBufferTest, InitClear) {
    float *a = 0;
    ASSERT_NE(buf_capacity(a) == 0, 0);
    ASSERT_NE(buf_size(a) == 0, 0);

    buf_push(a, 1.3f);
    ASSERT_NE(buf_size(a) == 1, 0);
    ASSERT_NE(a[0] == (float)1.3f, 0);

    buf_clear(a);
    ASSERT_NE(buf_size(a) == 0, 0);
    ASSERT_NE(a != 0, 0);

    buf_free(a);
    ASSERT_NE(a == 0, 0);

    buf_clear(a);
    ASSERT_NE(buf_size(a) == 0, 0);
    ASSERT_NE(a == 0, 0);
}

// int
// main(int argc, char **argv)

//     /* buf_push(), [] operator */
//     long *ai = 0;
//     for (int i = 0; i < 10000; i++)
//         buf_push(ai, i);
//     TESTBUF("size 10000", buf_size(ai) == 10000);
//     int match = 0;
//     for (int i = 0; i < (int)(buf_size(ai)); i++)
//         match += ai[i] == i;
//     TESTBUF("match 10000", match == 10000);
//     buf_free(ai);

//     /* buf_grow(), buf_trunc() */
//     buf_grow(ai, 1000);
//     TESTBUF("grow 1000", buf_capacity(ai) == 1000);
//     TESTBUF("size 0 (grow)", buf_size(ai) == 0);
//     buf_trunc(ai, 100);
//     TESTBUF("trunc 100", buf_capacity(ai) == 100);
//     buf_free(ai);

//     /* buf_pop() */
//     buf_push(a, 1.1);
//     buf_push(a, 1.2);
//     buf_push(a, 1.3);
//     buf_push(a, 1.4);
//     TESTBUF("size 4", buf_size(a) == 4);
//     TESTBUF("pop 3", buf_pop(a) == (float)1.4f);
//     buf_trunc(a, 3);
//     TESTBUF("size 3", buf_size(a) == 3);
//     TESTBUF("pop 2", buf_pop(a) == (float)1.3f);
//     TESTBUF("pop 1", buf_pop(a) == (float)1.2f);
//     TESTBUF("pop 0", buf_pop(a) == (float)1.1f);
//     TESTBUF("size 0 (pop)", buf_size(a) == 0);
//     buf_free(a);

// }
