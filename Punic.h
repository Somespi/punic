#ifndef PUNIC_H
#define PUNIC_H


#include <string>
#include <iostream>
#include <cstdlib>
#include "colors.h"


class  Punic {
private:
    int tests = 0;
    int failures = 0;
    bool exiting = false;

public:
    ~Punic() {
        summary();
    }

    template <typename Function>
    bool assert(auto assertion, Function func, std::string named = "Unnamed") {
        tests += 1;
        auto returns = func();
        bool result = returns == assertion;

        std::cout << BOLD << "Test <" << YELLOW << named << WHITE << "> #" << tests << " : " << (result ? GREEN : RED) << (result ? "PASSED" : "FAILED") << RESET << std::endl;

        if (!result) {
            failures += 1;
            std::cout << "  - " << YELLOW << "Expected: " << MAGENTA << assertion << RESET << std::endl;
            std::cout << "  - " << YELLOW << "Actual:   " << MAGENTA << returns << RESET << std::endl;

        }

        if (!result && exiting) {
            std::cerr << RED << "Test failure. Exiting the program." << RESET << std::endl;
            std::exit(1);
        }

        return result;
    }

    void exitFailure(bool on_exit) {
        exiting = on_exit;
    }

private:
    void summary() {
        if (failures == 0) {
            std::cout << GREEN << "All tests passed." << RESET << std::endl;
        }
        else {
            std::cout << YELLOW << "Tests passed with " << RED << failures << YELLOW << " fail(s)." << RESET << std::endl;
        }
    }
};
#endif
