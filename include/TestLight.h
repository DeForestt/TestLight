#ifndef TEST_LIGHT_H
#define TEST_LIGHT_H

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

#define TEST_SUITE(name) void suite_##name()
#define TEST_CASE(name) void test_##name()
#define RUN_TEST(name) run_test(#name, test_##name)
#define RUN_SUITE(name) run_suite(#name, suite_##name)
#define ASSERT_TRUE(condition) if (!(condition)) throw std::runtime_error("Assertion failed: " #condition)
#define ASSERT_FALSE(condition) if (condition) throw std::runtime_error("Assertion failed: " #condition)
#define ASSERT_EQUAL(expected, actual) if ((expected) != (actual)) throw std::runtime_error("Assertion failed: " #expected " != " #actual)

void run_suite(std::string suite_name, const std::function<void()>& suite_func);

void run_test(std::string test_name, const std::function<void()>& test_func);

#endif