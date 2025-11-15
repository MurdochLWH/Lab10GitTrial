#include "FileIO.h"
#include "Statistics.h"
#include "Map.h"

void FileIO::read_data_files(const std::string& filename, EnvlogType& env_data){
    std::string rPath = filename.substr(0, filename.find_last_of('/'))+"/";
    std::fstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    Vector<std::string> filenames;
    std::string line;
    while (std::getline(inputFile, line)) {
        // Simple check to skip empty lines
        if (!line.empty()) {
            filenames.push_back(rPath+line);
        }
    }
    for(int i=0; i<filenames.size(); i++){
        read_met_data(filenames[i], env_data);
    }
}

void FileIO::read_met_data(const std::string& filename, EnvlogType& env_data) {
    std::fstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::string line;

    // 1. Read the header row
    if (!std::getline(inputFile, line)) return;

    Vector<std::string> header_tokens = split_line_by_comma(line);

    // 2. Add all headers into header_map
    Map<std::string, int> header_map;
    for (int i = 0; i < header_tokens.size(); ++i) {
        header_map.insert(header_tokens[i], i);
    }

    // 3. Check if ALL required fields exist (WAST, S, T, SR) and get their indices
    const std::string REQUIRED_FIELDS[] = {"WAST", "S", "T", "SR"};
    int indices[4];
    int max_index = -1;
    bool all_found = true;

    for (int i = 0; i < 4; ++i) {
        if (header_map.contains(REQUIRED_FIELDS[i])) {
            indices[i] = header_map.find(REQUIRED_FIELDS[i]);
            if (indices[i] > max_index) {
                max_index = indices[i];
            }
        } else {
            all_found = false;
            break;
        }
    }

    if (!all_found) {
        std::cerr << "Error: Required fields (WAST, S, T, SR) not found in header in file: " << filename << std::endl;
        return;
    }

    // Assign indices from the array for clarity in the rest of the function
    const int WAST_INDEX = indices[0];
    const int S_INDEX = indices[1];
    const int T_INDEX = indices[2];
    const int SR_INDEX = indices[3];

    // 5. Process Data Rows
    while (std::getline(inputFile, line)) {
        if (line.empty()) continue;

        Vector<std::string> data_tokens = split_line_by_comma(line);

        // Ensure the line has enough columns for ALL required indices
        if (data_tokens.size() <= max_index) {
            std::cerr << "Warning: Skipping malformed line with insufficient columns in file: " << filename << std::endl;
            continue;
        }

        std::string wast_token = data_tokens[WAST_INDEX];
        std::string s_token = data_tokens[S_INDEX];
        std::string t_token = data_tokens[T_INDEX];
        std::string sr_token = data_tokens[SR_INDEX];

        EnvRecType new_record;

        // Process WAST (Date and Time)
        std::stringstream ss(wast_token);
        std::string date_str, time_str;

        // Read Date and Time
        if (ss >> date_str && ss >> time_str) {

            std::stringstream date_ss(date_str);
            std::stringstream time_ss(time_str);

            // Assuming Date and Time classes have overloaded operator>>
            date_ss >> new_record.d;
            time_ss >> new_record.t;

            // Process Wind Speed, Temperature, and Radiation
            try {
                // 4. Process Wind Speed (S)
                if (!s_token.empty()||s_token!="N/A") {
                    new_record.speed = std::stof(s_token);
                } else {
                    new_record.speed = Statistics::nan;
                }

                // 5. Process Temperature (T)
                if (!t_token.empty()||t_token!="N/A") {
                    new_record.temp = std::stof(t_token);
                } else {
                    new_record.temp = Statistics::nan;
                }

                // 6. Process Solar Radiation (SR)
                if (!sr_token.empty()||sr_token!="N/A") {
                    new_record.rad = std::stof(sr_token);
                } else {
                    new_record.rad = Statistics::nan;
                }

                // Add to the Vector
                env_data.push_back(new_record);

            } catch (const std::exception& e) {
                // Handle non-numeric speed/temp/rad values
                std::cerr << "Warning: Non-numeric data encountered in row in file: " << filename << std::endl;
            }
        }
    }
    inputFile.close();
}

Vector<std::string> FileIO::split_line_by_comma(const std::string& line) {
    Vector<std::string> tokens = Vector<std::string>(0);
    std::stringstream ss(line);
    std::string token;

    while (std::getline(ss, token, ',')) {
        tokens.push_back(token);
    }

    // Handle the case where the last field is empty (e.g., line ends with ',')
    if (!line.empty() && line.back() == ',') {
        tokens.push_back("");
    }

    return tokens;
}

void FileIO::export_env_data(const std::string& filename,int year, Vector<EnvlogType> stats){
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "ERROR: Could not open file " << filename << " for writing." << std::endl;
        return;
    }
    outputFile << year << "\n";
    if(stats.size()==0){
        std::cout<<"No Data"<<std::endl;
        return;
    }
    for(int i=0; i<stats.size(); i++){
        if(stats[i][0].speed<=Statistics::nan && stats[i][0].temp<=Statistics::nan && stats[i][0].rad<=Statistics::nan){
            //std::cout<< Date::months[i] << ",No Data" <<std::endl;
        } else {
            outputFile << Date::months[i] << ",";
            if(stats[i][0].speed>Statistics::nan){
                outputFile<<Statistics::roundTo3DP(stats[i][0].speed*Statistics::TO_KM_PER_H)<<"("<<Statistics::roundTo3DP(stats[i][1].speed*Statistics::TO_KM_PER_H)<<", "<<Statistics::roundTo3DP(stats[i][2].speed*Statistics::TO_KM_PER_H)<<")";
            }
            outputFile<<",";
            if(stats[i][0].temp>Statistics::nan){
                outputFile<<Statistics::roundTo3DP(stats[i][0].temp)<<"("<<Statistics::roundTo3DP(stats[i][1].temp)<<", "<<Statistics::roundTo3DP(stats[i][2].temp)<<")";
            }
            outputFile<<",";
            if(stats[i][0].rad>Statistics::nan){
                outputFile<<Statistics::roundTo3DP(stats[i][0].rad*Statistics::TO_KWH_PER_M2);
            }
            outputFile<<"\n";
        }
    }
    outputFile.close();
    std::cout << "Data successfully exported to 'WindTempSolar.csv'." <<std::endl;
}

int FileIO::find_index(const Vector<std::string>& headers, const std::string& key) {
    for (int i = 0; i < headers.size(); ++i) {
        if (headers[i] == key) {
            return i;
        }
    }
    return -1; // Not found
}
