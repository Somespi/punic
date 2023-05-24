#include "punic.h"

Punic::~Punic() {
    summary();
}

template <typename Function>
bool Punic::assert(auto assertion, Function func, std::string named) {
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

void Punic::exitFailure(bool on_exit) {
    exiting = on_exit;
}

void Punic::summary() {
    if (failures == 0) {
        std::cout << GREEN << "All tests passed." << RESET << std::endl;
    }
    else {
        std::cout << YELLOW << "Tests passed with " << RED << failures << YELLOW << " fail(s)." << RESET << std::endl;
    }
}
