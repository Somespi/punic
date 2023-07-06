#include "Punic.h"

std::string toUpperCase(const std::string& str) {
    std::string upperStr = str;
    for (char& c : upperStr) {
        if (std::isalpha(c)) {
            c = std::toupper(c);
        }
    }
    return upperStr;
}



void testCases() {
    Punic p;
    p.assert<std::string>("hELLO", [](){ return toUpperCase("Hello"); }, "Uppercase conversion");
    p.assert<std::string>("123", [](){ return toUpperCase("123"); }, "Uppercase conversion of numbers");
    p.assert<std::string>("!@#", [](){ return toUpperCase("!@#"); }, "Uppercase conversion of special characters");

}

int main() {
    testCases();
    return 0;
}