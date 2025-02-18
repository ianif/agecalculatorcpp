#include <iostream>
#include <ctime>

int main() {
    int birthYear, birthMonth, birthDay;
    std::cout << "Enter your date of birth (YYYY MM DD): ";
    std::cin >> birthYear >> birthMonth >> birthDay;

    // Get the current date using modern C++ chrono
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    auto* timeinfo = std::localtime(&time);
    
    int currentYear = timeinfo->tm_year + 1900;
    int currentMonth = timeinfo->tm_mon + 1;
    int currentDay = timeinfo->tm_mday;

    // Calculate age
    int age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }

    std::cout << "You are " << age << " years old." << std::endl;
    return 0;
}
user B edited from artemis