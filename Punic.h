#ifndef PUNIC_H
#define PUNIC_H


#include <string>
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include "colors.h"


class  Punic {
private:
    int tests = 0;
    int failures = 0;
    bool exiting = false;

public:
    ~Punic();

    template <typename Function>
    bool assert(auto assertion, Function func, std::string named = "Unnamed");

    void exitFailure(bool on_exit);

private:
    void summary();
};
#endif
