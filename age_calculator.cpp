#include <iostream>
#include <ctime>
#include <stdexcept>
#include <chrono>

int main() {
    int birthYear, birthMonth, birthDay;
    std::cout << "Enter your date of birth (YYYY MM DD): ";
    std::cin >> birthYear >> birthMonth >> birthDay;

    // Validate input
    if (birthMonth < 1 || birthMonth > 12 || birthDay < 1 || birthDay > 31) {
        std::cerr << "Invalid date input." << std::endl;
        return 1;
    }

    // Get the current date using more modern C++ chrono
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&t);
    
    int currentYear = localTime->tm_year + 1900;
    int currentMonth = localTime->tm_mon + 1;
    int currentDay = localTime->tm_mday;

    // Calculate age with simplified logic
    int age = currentYear - birthYear - ((currentMonth < birthMonth || 
             (currentMonth == birthMonth && currentDay < birthDay)) ? 1 : 0);

    std::cout << "You are " << age << " years old." << std::endl;
    return 0;
}