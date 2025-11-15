#ifndef CONSOLEVIEW_H_INCLUDED
#define CONSOLEVIEW_H_INCLUDED

#include <iostream>
#include <string>
#include "Statistics.h"
#include "EnvTypes.h"
#include "Date.h"

class ConsoleView {
public:
    /** @brief Displays the main menu options to the user. */
    void displayMenu() const;

    /** @brief Gets and validates the user's menu choice.
     * @return int - Valid menu option (1-5).
     */
    int getMenuOption() const;

    /** @brief Gets and validates a year input from the user.
     * @return int - Valid year.
     */
    int getYearInput() const;

    /** @brief Gets and validates a month input from the user.
     * @return int - Valid month.
     */
    int getMonthInput() const;

    /** @brief Gets and validates a month/year input from the user.
     * @return Date - Date object with day fixed to 1.
     */
    Date getMonthYearInput() const;

    /** @brief Displays the option 1 output to the user. */
    void displayOption1(Date d, Vector<float> stats) const;

    /** @brief Displays the option 2 output to the user. */
    void displayOption2(int year, Vector<Vector<float>> stats) const;

    /** @brief Displays the option 3 output to the user. */
    void displayOption3(int month, Vector<float> stats) const;

    /** @brief Displays the option 4 output to the user. */
    void displayOption4(Vector<EnvlogType> stats) const;

private:
    /** @brief Utility function to clear bad input state. */
    void clearInput() const;
};

#endif // CONSOLEVIEW_H_INCLUDED
