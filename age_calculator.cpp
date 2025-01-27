#include <iostream>
#include <ctime>

int main() {
    int birthYear, birthMonth, birthDay;
    std::cout << "Enter your date of birth (YYYY MM DD): ";
    std::cin >> birthYear >> birthMonth >> birthDay;

    // Get the current date
    time_t t = time(0);
    tm* now = localtime(&t);
    
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
