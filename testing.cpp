#include <ctime>
#include <string>
#include <iostream>

struct Apartment
{
    int number;
    std::string owner;
    std::string condition;
    std::time_t when;
    std::time_t when2;
};

int main()
{
    Apartment ap;

    std::cout << "Enter the apartment number: " << std::endl;
    std::cin >> ap.number;

    std::cout << "Enter the name of the owner: " << std::endl;
    std::cin >> ap.owner;

    std::cout << "Enter the condition: " << std::endl;
    std::cin >> ap.condition;

    ap.when = std::time(0);// set the time to now
    ap.when2 = std::time(20);


    std::cout << "Record created on: " << std::ctime(&ap.when) << std::endl;
}
