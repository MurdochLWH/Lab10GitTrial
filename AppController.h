#ifndef APPCONTROLLER_H_INCLUDED
#define APPCONTROLLER_H_INCLUDED

#include "DataProcessor.h"
#include "ConsoleView.h"
#include "Statistics.h"
#include <iostream>

class AppController {
public:
    /** @brief Constructor for AppController
   * @param dataPro - DataProcessor&
   * @param consoleView - ConsoleView&
   */
    AppController(DataProcessor& dataPro, ConsoleView& consoleView);

    /** @brief Executes the main application in a loop. */
    void run();

private:
    DataProcessor& _dataPro;
    ConsoleView& _consoleView;
};

#endif // APPCONTROLLER_H_INCLUDED
