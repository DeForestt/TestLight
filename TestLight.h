#pragma once

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

void run_suite(const std::string& suite_name, const std::function<void()>& suite_func) {
    auto suite_name_copy = suite_name;
    std::replace(suite_name_copy.begin(), suite_name_copy.end(), '_', ' ');
    std::cout << "Running test suite: " << suite_name << std::endl;
    suite_func();
}

void run_test(const std::string& test_name, const std::function<void()>& test_func) {
    auto test_name_copy = test_name;
    std::replace(test_name_copy.begin(), test_name_copy.end(), '_', ' ');
    try {
        test_func();
        std::cout << "\t[PASSED] " << test_name << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "\t[FAILED] " << test_name << " - " << e.what() << std::endl;
    }
}