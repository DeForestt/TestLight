#include "TestLight.h"

void run_suite(std::string suite_name, const std::function<void()>& suite_func) {
    std::replace(suite_name.begin(), suite_name.end(), '_', ' ');
    std::cout << "Running test suite: " << suite_name << std::endl;
    suite_func();
}

void run_test(std::string test_name, const std::function<void()>& test_func) {
    std::replace(test_name.begin(), test_name.end(), '_', ' ');
    try {
        test_func();
        std::cout << "\t[PASSED] " << test_name << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "\t[FAILED] " << test_name << " - " << e.what() << std::endl;
    }
}