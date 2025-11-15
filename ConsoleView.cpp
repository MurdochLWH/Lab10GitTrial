#include "ConsoleView.h"

void ConsoleView::displayMenu() const{
    std::cout<< "\n==========Main Menu==========" <<std::endl;
    std::cout<< "1. Average and sample standard deviation of wind speed of specified month and year." <<std::endl;
    std::cout<< "2. Average and sample standard deviation of ambient air temperature for each month of specified year." <<std::endl;
    std::cout<< "3. Calculate Pearson Correlation Coefficient for specified month with combination of 2 data fields" <<std::endl;
    std::cout<< "4. Export average, standard deviation and mean absolute deviation of wind speed(km/h) and ambient air temperature, with total solar radiation in kWh/m^2 for each month of a specified year." <<std::endl;
    std::cout<< "5. Exit program." <<std::endl;
}

int ConsoleView::getMenuOption() const{
    int option;
    while(true){
        std::cout<< "Enter a option number:" <<std::endl;
        if(std::cin >> option){
            char next_char = std::cin.peek();
            if ((next_char == '\n' || next_char == EOF || next_char == ' ')&& option > 0 && option <= 5){
                return option;
            }else {
                    std::cout << "Invalid input. Please enter only a whole number between 1-5, without extra characters." << std::endl;
                    clearInput();
            }
        }else{
            std::cout << "Invalid input. Please enter only a whole number between 1-5, without extra characters." << std::endl;
            clearInput();
        }
    }
}

int ConsoleView::getYearInput() const{
    int year;
    while(true){
        clearInput();
        std::cout<< "Enter year in number:" <<std::endl;
        if(std::cin >> year){
            char next_char = std::cin.peek();
            if (next_char == '\n' || next_char == EOF || next_char == ' '){
                return year;
            } else {
                std::cout << "Invalid input. Please enter only a whole number, without extra characters." << std::endl;
            }
        }else {
            std::cout << "Invalid input. Please enter only a whole number, without extra characters." << std::endl;
        }
    }
}

int ConsoleView::getMonthInput() const{
    int month;
    while(true){
        clearInput();
        std::cout<< "Enter month in number:" <<std::endl;
        if(std::cin >> month){
            char next_char = std::cin.peek();
            if ((next_char == '\n' || next_char == EOF || next_char == ' ')&& month>0 && month<13){
                return month;
            } else {
                std::cout << "Invalid input. Please enter a valid month in number, without extra characters." << std::endl;
            }
        }else {
            std::cout << "Invalid input. Please enter a valid month in number, without extra characters." << std::endl;
        }
    }
}

Date ConsoleView::getMonthYearInput() const{
    int year, month;
    year = getYearInput();
    while(true){
        clearInput();
        std::cout<< "Enter month in number:" <<std::endl;
        if(std::cin >> month){
            char next_char = std::cin.peek();
            if ((next_char == '\n' || next_char == EOF || next_char == ' ')&& month>0 && month<13){
                return Date(1, month, year);
            } else {
                std::cout << "Invalid input. Please enter a valid month in number, without extra characters." << std::endl;
            }
        }else {
            std::cout << "Invalid input. Please enter a valid month in number, without extra characters." << std::endl;
        }
    }
}

void ConsoleView::displayOption1(Date d, Vector<float> stats) const{
    if(stats[0]<=-999.0f || stats[1]<=-999.0f){
        std::cout<< d << ": No Data" <<std::endl;
    } else {
        std::cout<< d << ":" <<std::endl;
        std::cout<< "Average speed: " << Statistics::roundTo3DP(stats[0]*Statistics::TO_KM_PER_H) << " km/h" <<std::endl;
        std::cout<< "Sample stdev: " << Statistics::roundTo3DP(stats[1]*Statistics::TO_KM_PER_H) <<std::endl;
    }
}

void ConsoleView::displayOption2(int year, Vector<Vector<float>> stats) const{
    std::cout<< year <<std::endl;
    for(int i=0; i<stats.size(); i++){
        if(stats[i][0]<=-999.0f || stats[i][1]<=-999.0f){
            std::cout<< Date::months[i] << ": No Data" <<std::endl;
        } else {
            std::cout<< Date::months[i] << ": average: " << Statistics::roundTo3DP(stats[i][0]) << " degrees C, stdev: " << Statistics::roundTo3DP(stats[i][1]) <<std::endl;
        }
    }
}

void ConsoleView::displayOption3(int month, Vector<float> stats) const{
    std::string STstring, SRstring, TRstring;
    STstring = stats[0] <= Statistics::nan ? "nan" : std::to_string(Statistics::roundTo3DP(stats[0])).substr(0,5);
    SRstring = stats[1] <= Statistics::nan ? "nan" : std::to_string(Statistics::roundTo3DP(stats[1])).substr(0,5);
    TRstring = stats[2] <= Statistics::nan ? "nan" : std::to_string(Statistics::roundTo3DP(stats[2])).substr(0,5);
    std::cout<< "Sample Pearson Correlation Coefficient for "<< Date::months[month-1] <<std::endl;
    std::cout<< "S_T : " << STstring <<std::endl;
    std::cout<< "S_R : " << SRstring <<std::endl;
    std::cout<< "T_R : " << TRstring <<std::endl;
}

void ConsoleView::clearInput() const{
    std::cin.clear();
    std::cin.ignore(256, '\n');
}
