#ifndef PUNIC_H
#define PUNIC_H

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLD "\033[1m"          /* Bold */


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

    template <class T, class Function>
    bool assert(T assertion, Function function, std::string named = "Unnamed") {
        tests += 1;
        T result = function();
        bool testResult = result == assertion;

        std::cout << BOLD << "Test <" << YELLOW << named << WHITE << "> #" << tests << " : " << (testResult ? GREEN : RED) << (testResult ? "PASSED" : "FAILED") << RESET << std::endl;

        if (!testResult) {
            failures += 1;
            std::cout << "  - " << YELLOW << "Expected: " << MAGENTA << assertion << RESET << std::endl;
            std::cout << "  - " << YELLOW << "Actual:   " << MAGENTA << result << RESET << std::endl;
            if (failedAction)
                failedAction();
        } else {
            if (passedAction)
                passedAction();
        }

        if (!testResult && exiting) {
            std::cerr << RED << "Test failure. Exiting the program." << RESET << std::endl;
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
            std::cout << GREEN << "All tests passed." << RESET << std::endl;
            if (passedAllAction)
                passedAllAction();
        }
        else {
            std::cout << YELLOW << "Tests passed with " << RED << failures << YELLOW << " fail(s)." << RESET << std::endl;
        } 
        if(failures == tests) 
            if (faliedAllAction)
                faliedAllAction();
        
    }
};

#endif

