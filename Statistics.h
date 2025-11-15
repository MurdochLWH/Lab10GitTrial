#ifndef STATISTICS_H_INCLUDED
#define STATISTICS_H_INCLUDED

#include <cmath>
#include "Vector.h"

class Statistics {
public:
    const static float nan;
    const static float TO_KM_PER_H;
    const static float TO_KWH_PER_M2;
    /** @brief Function to calculate sample Pearson Correlation Coefficient from vectors of float
    * @param x - const Vector<float>&
    * @param y - const Vector<float>&
    * @return float
    */
    static float calculate_sPCC(const Vector<float>& x, const Vector<float>& y);
    /** @brief Function to calculate Mean Absolute Deviation from vector of float
    * @param data - const Vector<float>&
    * @return float
    */
    static float calculate_MAD(const Vector<float>& data);
    /** @brief Function to calculate sample standard deviation from vector of float
    * @param data - const Vector<float>&
    * @return float
    */
    static float calculate_sample_sd(const Vector<float>& data);
    /** @brief Function to calculate sum of squares from vector of float
    * @param data - const Vector<float>&
    * @return float
    */
    static float calculate_sum_of_squares(const Vector<float>& data);
    /** @brief Function to calculate mean from vector of float
    * @param data - const Vector<float>&
    * @return float
    */
    static float calculate_mean(const Vector<float>& data);
    /** @brief Function to calculate sum from vector of float
    * @param data - const Vector<float>&
    * @return float
    */
    static float calculate_sum(const Vector<float>& data);
    /** @brief Function round a float value to 3 decimal place
    * @param f - float
    * @return float
    */
    static float roundTo3DP (float f);
};

#endif // STATISTICS_H_INCLUDED
