#include <cmath>
#include "Date.h"
#include "Time.h"
#include "Vector.h"
#include "EnvTypes.h"
#include "DataProcessor.h"
#include "FileIO.h"
#include "AppController.h"
#include "ConsoleView.h"


using namespace FileIO;
int main()
{
    EnvlogType env_data;
    ConsoleView console;
    const std::string datafilename = "data/data_source.txt";

    // Open and read the data file
    std::ifstream inputFile(datafilename);
    if (!inputFile.is_open()) {
        std::cerr << "Fatal Error: Could not open file " << datafilename << std::endl;
        std::cerr << "Please ensure the file path is correct." << std::endl;
        return 1;
    }

    std::cout << "--- Reading data from " << datafilename << " ---" << std::endl;
    read_data_files(datafilename, env_data);
    inputFile.close();

    std::cout << "Successfully read " << env_data.size() << " valid environment records." << std::endl;

    if (env_data.size() == 0) {
        std::cout << "No valid data to perform calculations." << std::endl;
        return 0;
    }

    DataProcessor dataPro(env_data);

    // Menu
    AppController app = AppController(dataPro, console);
    app.run();

    return 0;
}
