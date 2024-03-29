#include "tests/tests.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

void *ft_memset(void *b, int , size_t len);

typedef void *(*func_t)(void *, int, size_t);
typedef struct {
	func_t ref;
	func_t to_test;
	const char *name;
} test_data_t;

test_state_t single_test(char *p, int c, size_t s, const test_data_t *data) {
	char s1[s];
	char s2[s];
	memcpy(s1, p, s);
	memcpy(s2, p, s);
	char* ref = data->ref(s1, c, s);
  	char* ret = data->to_test(s2, c, s);
	if (ref != s1 || ret != s2 || memcmp(s1, s2, s)) {
		dprintf(2, "[FAIL] %1$s(%2$.10s) -> %3$p, %4$s != ft_%1$s(%2$.10s) -> %5$p, %6$s\n", data->name, p, ref, s1, ret, s2);
		return TEST_FAIL;
	}
	return TEST_SUCCESS;
}


test_state_t run_test(const test_data_t *data) {
	test_state_t ret = TEST_SUCCESS;
	
	if (single_test("123456", 'a', 6, data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("123\0 56", 'a', 7, data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("123", 0, 0, data) == TEST_FAIL)
		ret = TEST_FAIL;
	if (single_test("", 50, 0, data) == TEST_FAIL)
		ret = TEST_FAIL;
	return ret;
}

int main()
{
	TEST_ARR_BEGIN(test_data_t, tests, 1)
		TEST_DATA(memset)
	TEST_ARR_END

	RUN_TESTS(tests);
	return TEST_SUCCESS;
}
