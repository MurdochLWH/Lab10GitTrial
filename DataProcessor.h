#ifndef DATAPROCESSOR_H_INCLUDED
#define DATAPROCESSOR_H_INCLUDED

#include "Vector.h"
#include "Date.h"
#include "Statistics.h"
#include "EnvTypes.h"
#include "Map.h"
#include "Bst.h"

class DataProcessor{
private:
    ///Holds base data set
    const EnvlogType& _data;
    const Map<int, Map<int, Bst<EnvRecType>>> Mdata;

public:
    /** @brief Constructor with base data set
    */
    DataProcessor(const EnvlogType& data);

    /** @brief Function to filter vector of wind speed stats from base dataset based on month and year
    * @param month - Date
    * @return Vector<float>
    */
    Vector<float> monthWindStat(Date month)const;
    /** @brief Function to filter vector of vectors of temperature stats from base dataset based on year
    * @param year - int
    * @return Vector<Vector<float>>
    */
    Vector<Vector<float>> yearTempStat(int year)const;
    /** @brief Function to filter vector of radiation stats from base dataset based on year
    * @param year - int
    * @return Vector<float>
    */
    Vector<float> yearRadStat(int year)const;
    /** @brief Function to calculate sPCC combinations from base dataset based on month only
    * @param month - int
    * @return Vector<float>
    */
    Vector<float> monthSPCC(int month)const;
    /** @brief Function to filter vector of all stats from base dataset based on year
    * @param year - int
    * @return Vector<EnvlogType>
    */
    Vector<EnvlogType> yearEnvStat(int year)const;

    /** @brief Function to filter EnvlogType with all stats from base dataset based on month and year
    * @param month - Date
    * @return EnvlogType
    */
    EnvlogType filterByMonthYear(Date month)const;
    /** @brief Function to filter EnvlogType with all stats from base dataset based on month only
    * @param month - Date
    * @return EnvlogType
    */
    EnvlogType filterByMonth(int month)const;
    /** @brief Function to filter vector of EnvlogType with all stats from base dataset based on year only
    * @param year - int
    * @return Vector<EnvlogType>
    */
    Vector<EnvlogType> filterByYear(int year)const;
    /** @brief Function to filter vector of specified statistics from provided dataset
    * @param data - const EnvlogType&
    * @param stat - Stats
    * @return Vector<float>
    */
    Vector<float> filterByStat(const EnvlogType& data, Stats stat) const;
    /** @brief Function to filter vector of rad data to remove invalid values
    * @param data - const Vector<float>&
    * @param stat - Stats
    * @return Vector<float>
    */
    Vector<float> filterInvalidRad(const Vector<float>& data) const;
};

#endif // DATAPROCESSOR_H_INCLUDED
