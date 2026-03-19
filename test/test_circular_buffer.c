#include <unity.h>
#include <stdio.h>
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
void test_circular_buffer_add_items() {
    cbuffer_add(&buff, 1);
    TEST_ASSERT_FALSE(cbuffer_empty(&buff));
    cbuffer_add(&buff, 2);
    TEST_ASSERT_FALSE(cbuffer_empty(&buff));
    TEST_ASSERT_TRUE(cbuffer_get(&buff) == 1);
    TEST_ASSERT_TRUE(cbuffer_get(&buff) == 2);
}
void test_circular_buffer_full() {
    //test to add items to a full buffer and see if it full
    //no add items with for loop from 0 to the buffer size
    for (int i = 0; i < BUFFER_SIZE-1; i++) {
        cbuffer_add(&buff, i);
    }
    TEST_ASSERT_TRUE(cbuffer_full(&buff));

}
void test_circular_buffer_get_items_after_full() {
    
    for (int i = 0; i < BUFFER_SIZE-1; i++) {
        cbuffer_add(&buff, i);
    }
    TEST_ASSERT_TRUE(cbuffer_full(&buff));

    for (int i = 0; i < BUFFER_SIZE-1; ++i)
    {
        TEST_ASSERT_TRUE(cbuffer_get(&buff) == i);
    }
    TEST_ASSERT_TRUE(cbuffer_empty(&buff));
}
void test_circular_buffer_clear() {
cbuffer_add(&buff, 1);
cbuffer_add(&buff, 2);
cbuffer_clear(&buff);
TEST_ASSERT_TRUE(cbuffer_empty(&buff));
TEST_ASSERT_FALSE(cbuffer_get(&buff) == 1);
TEST_ASSERT_FALSE(cbuffer_get(&buff) == 2);
TEST_ASSERT_TRUE(cbuffer_get(&buff) == NULL); 
}

void main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_circular_buffer_empty_after_init);
    RUN_TEST(test_circular_buffer_add_items);
    RUN_TEST(test_circular_buffer_full);
    RUN_TEST(test_circular_buffer_get_items_after_full);
    RUN_TEST(test_circular_buffer_clear);
    UNITY_END();
}
