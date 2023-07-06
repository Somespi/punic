#include "Punic.h"

void Punic::exitOnFailure(bool on_exit) {
    exiting = on_exit;
}

void Punic::whenFailed(std::function<void()> action) {
    failedAction = action;
}

void Punic::whenPassed(std::function<void()> action) {
    passedAction = action;
}

void Punic::whenAllFailed(std::function<void()> action) {
    faliedAllAction = action;
}

void Punic::whenAllPassed(std::function<void()> action) {
    passedAllAction = action;
}

void Punic::summary() {
    if (failures == 0) {
        std::cout << "All tests passed." << std::endl;
        if (passedAllAction)
            passedAllAction();
    }
    else {
        std::cout << "Tests passed with " << failures << " fail(s)." << std::endl;
    }
    if (failures == tests)
        if (faliedAllAction)
            faliedAllAction();
}
