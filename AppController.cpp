#include "AppController.h"
#include "FileIO.h"

AppController::AppController(DataProcessor& dataPro, ConsoleView& consoleView):_dataPro(dataPro),_consoleView(consoleView){

}

void AppController::run(){
    int quit = 0;
    while(quit == 0){
        _consoleView.displayMenu();
        int option = _consoleView.getMenuOption();
        switch(option){
            case 1:{
                Date d = _consoleView.getMonthYearInput();
                _consoleView.displayOption1(d,_dataPro.monthWindStat(d));
                break;
            }
            case 2:{
                int year = _consoleView.getYearInput();
                _consoleView.displayOption2(year, _dataPro.yearTempStat(year));
                break;
            }
            case 3:{
                int month = _consoleView.getMonthInput();
                _consoleView.displayOption3(month, _dataPro.monthSPCC(month));
                break;
            }
            case 4:{
                int year = _consoleView.getYearInput();
                FileIO::export_env_data("WindTempSolar.csv", year, _dataPro.yearEnvStat(year));
                break;
            }
            case 5:{
                quit = 1;
                std::cout << "Exiting Program..." << std::endl;
                break;
            }
            default:{
                break;
            }
        }
    }
}
