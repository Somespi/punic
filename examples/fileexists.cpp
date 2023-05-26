#include "../punic.h"
#include <fstream>

bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

void testFileExists() {
    Punic p;
    p.whenFailed([](){
        std::ofstream logFile("test_log.txt", std::ios::app);
        logFile << "Test failed! Check the implementation." << std::endl;
        logFile.close();

    });

    p.whenPassed([](){
        std::ofstream logFile("test_log.txt", std::ios::app);
        logFile << "Test passed! The implementation is correct." << std::endl;
        logFile.close();
    });

    
    p.assert<bool>(true, [](){ return fileExists("test.txt"); }, "File exists");
    p.assert<bool>(false, [](){ return fileExists("nonexistent.txt"); }, "File does not exist");

}

int main() {
    testFileExists();

    return 0;
}
