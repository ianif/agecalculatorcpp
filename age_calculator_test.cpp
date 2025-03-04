

#include <iostream>
#include <cassert>
#include "age_calculator.cpp"

void testValidAge() {
    // Test case 1: Normal case
    assert(calculateAge(2000, 1, 1) >= 23);
    
    // Test case 2: Edge case - birthday today
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    int currentYear = now->tm_year + 1900;
    assert(calculateAge(currentYear, now->tm_mon + 1, now->tm_mday) == 0);
}

void testInvalidDates() {
    bool exceptionThrown = false;
    try {
        calculateAge(2000, 13, 1);  // Invalid month
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);

    exceptionThrown = false;
    try {
        calculateAge(2000, 1, 32);  // Invalid day
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
}

int main() {
    std::cout << "Running tests..." << std::endl;
    testValidAge();
    testInvalidDates();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
