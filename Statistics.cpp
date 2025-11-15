#include "Statistics.h"

const float Statistics::nan = -999.0f;
const float Statistics::TO_KM_PER_H = 3.6f;
const float Statistics::TO_KWH_PER_M2 = 0.001f / 6;

float Statistics::calculate_sPCC(const Vector<float>& x, const Vector<float>& y){
    int xSize=0,ySize=0;
    Vector<float> x1(0),y1(0);
    float sum_of_product = 0.00f, x_sum_sq, y_sum_sq, x_mean, y_mean;
    for (float i : x){
        if(i>nan){
            xSize++;
            x1.push_back(i);
        }
    }
    for (float i : y){
        if(i>nan){
            ySize++;
            y1.push_back(i);
        }
    }
    if (xSize != ySize) return nan;
    if (xSize<1||ySize<1) return nan;
    x_mean = calculate_mean(x);
    y_mean = calculate_mean(y);
    x_sum_sq = calculate_sum_of_squares(x);
    y_sum_sq = calculate_sum_of_squares(y);
    for (int i = 0; i < x.size(); ++i) {
        float x_diff = x[i] - x_mean;
        float y_diff = y[i] - y_mean;
        sum_of_product += x_diff * y_diff;
    }
    float denominator = std::sqrt(x_sum_sq * y_sum_sq);
    if(denominator<=0.00f) return nan;
    return sum_of_product/denominator;
};

float Statistics::calculate_sample_sd(const Vector<float>& data) {
    if (data.size() <= 1) return nan;
    float mean = calculate_mean(data);
    if (mean <= nan) return nan;
    float sd = calculate_sum_of_squares(data);
    // Divide by (N-1) for sample standard deviation
    sd = std::sqrt(sd / (data.size() - 1));
    return sd;
}

float Statistics::calculate_MAD(const Vector<float>& data){
    if (data.size() <= 1) return nan;
    float mean = calculate_mean(data);
    if (mean <= nan) return nan;
    float mad = 0.00f;
    int n = 0;
    for (int i = 0; i < data.size(); ++i) {
        if(data[i]>nan){
            float diff = std::abs(data[i]-mean);
            mad += diff;
            n++;
        }
    }
    mad /= n;
    return mad;
}

float Statistics::calculate_sum_of_squares(const Vector<float>& data) {
    if (data.size() < 1) return nan;
    float mean = calculate_mean(data);
    if (mean <= nan) return nan;
    float sum_sq = 0.0f;
    for (float val : data) {
        float diff = val - mean;
        sum_sq += diff * diff;
    }
    return sum_sq;
}

float Statistics::calculate_mean(const Vector<float>& data) {
    if (data.size() == 0) return nan;
    float mean = calculate_sum(data);
    int dataSize = 0;
    for (float i : data){
        if(i>nan) dataSize++;
    }
    mean /= dataSize;
    return mean;
}

float Statistics::calculate_sum(const Vector<float>& data){
    if (data.size() == 0) return nan;
    float sum = 0.00f;
    for (int i = 0; i < data.size(); ++i) {
        if(data[i]>nan){
            sum += data[i];
        }
    }
    return sum;
}

float Statistics::roundTo3DP (float f){
    return round(f*1000)/1000;
}
