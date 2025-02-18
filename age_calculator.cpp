#include <iostream>
#include <ctime>
#include <stdexcept>

int main() {
    int birthYear, birthMonth, birthDay;
    std::cout << "Enter your date of birth (YYYY MM DD): ";
    std::cin >> birthYear >> birthMonth >> birthDay;

    // Validate input
    if (birthMonth < 1 || birthMonth > 12 || birthDay < 1 || birthDay > 31) {
        std::cerr << "Invalid date input." << std::endl;
        return 1;
    }

    // Get the current date
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    
    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;

    // Calculate age
    int age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }

    std::cout << "You are " << age << " years old." << std::endl;
    return 0;
}
NEW