#include <unity.h>
#include "cbuffer.h"

cbuffer_t buff;

void setUp(void) {
    cbuffer_init(&buff);
}

void tearDown(void) {
    
}

void test_circular_buffer_empty_after_init() {
    TEST_ASSERT_TRUE(cbuffer_empty(&buff));
}

void main(void) {
    UNITY_BEGIN();
    test_circular_buffer_empty_after_init();
    UNITY_END();
}
