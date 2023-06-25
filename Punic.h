#ifndef PUNIC_H
#define PUNIC_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <functional>

class Punic {
private:
    int tests = 0;
    int failures = 0;
    bool exiting = false;
    std::function<void()> failedAction;
    std::function<void()> passedAction;
    std::function<void()> faliedAllAction;
    std::function<void()> passedAllAction;

public:
    ~Punic() {
        summary();
    }

    template <class T>
    bool assert(T assertion, std::function<T()> function, std::string named = "Unnamed") {
        tests += 1;
        T result = function();
        bool testResult = result == assertion;

        std::cout << "Test <" << named << "> #" << tests << " : " << (testResult ? "PASSED" : "FAILED") << RESET << std::endl;

        if (!testResult) {
            failures += 1;
            std::cout << "  - " << "Expected: " << assertion << std::endl;
            std::cout << "  - " << YELLOW << "Actual:   " <<  result <<  std::endl;
            if (failedAction)
                failedAction();
        } else {
            if (passedAction)
                passedAction();
        }

        if (!testResult && exiting) {
            std::cerr << "Test failure. Exiting the program." << std::endl;
            std::exit(1);
        }

        return testResult;
    }

    void exitOnFailure(bool on_exit) {
        exiting = on_exit;
    }

    void whenFailed(std::function<void()> action) {
        failedAction = action;
    }

    void whenPassed(std::function<void()> action) {
        passedAction = action;
    }

    void whenAllFailed(std::function<void()> action) {
        faliedAllAction = action;
    }

    void whenAllPassed(std::function<void()> action) {
        passedAllAction = action;
    }

private:
    void summary() {
        if (failures == 0) {
            std::cout << "All tests passed." << std::endl;
            if (passedAllAction)
                passedAllAction();
        }
        else {
            std::cout << "Tests passed with " << failures << " fail(s)." << std::endl;
        } 
        if(failures == tests) 
            if (faliedAllAction)
                faliedAllAction();
        
    }
};

#endif

