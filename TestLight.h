#pragma once

#include <iostream>
#include <string>
#include <functional>

#define TEST_CASE(name) void name()
#define RUN_TEST(name) run_test(#name, name)

void run_test(const std::string& test_name, const std::function<void()>& test_func) {
    try {
        test_func();
        std::cout << "[PASSED] " << test_name << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "[FAILED] " << test_name << " - " << e.what() << std::endl;
    }
}