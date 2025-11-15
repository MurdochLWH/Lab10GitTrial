
#ifndef FileIO_H
#define FileIO_H

#include "Date.h"
#include "Time.h"
#include "Vector.h"
#include "EnvTypes.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>


namespace FileIO {
    /** @brief Helper function to split line by (,) into Vector of string
    * @param line - const std::string&
    * @return Vector<std::string>
    */
    Vector<std::string> split_line_by_comma(const std::string& line);
    /** @brief Helper function to find position of string from Vector<string>
    * @param headers - const Vector<std::string>&
    * @param key - const std::string&
    * @return int
    */
    int find_index(const Vector<std::string>& headers, const std::string& key);
    /** @brief Read a file via filename, and read all files listed within, and insert it into EnvlogType provided.
    * @param filename - const std::string&
    * @param env_data - EnvlogType&
    * @return void
    */
    void read_data_files(const std::string& filename, EnvlogType& env_data);
    /** @brief Read a file via filename and insert it into EnvlogType provided.
    * @param filename - const std::string&
    * @param env_data - EnvlogType&
    * @return void
    */
    void read_met_data(const std::string& filename, EnvlogType& env_data);
    /** @brief Write a file via filename and insert EnvlogType provided into the file.
    * @param filename - const std::string&
    * @param stats - Vector<EnvlogType>
    * @return void
    */
    void export_env_data(const std::string& filename, int year, Vector<EnvlogType> stats);
}


#endif
