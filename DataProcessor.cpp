#include "DataProcessor.h"
#include <iterator>
#include <utility>
DataProcessor::DataProcessor(const EnvlogType& data) : _data(data)
{
    for(int i=0;i<data.size();i++){
        int year = data[i].d.GetYear();
        int month = data[i].d.GetMonth();
        if(!Mdata.contains(year)){
            Mdata.insert(year);
        }
        Map<int, Bst<EnvRecType>>yearMap = Mdata.find(year);
        if(!yearMap.contains(month)){
            Mdata.
        }

    }
}

Vector<float> DataProcessor::monthWindStat(Date month) const{
    EnvlogType filtered = filterByMonthYear(month);
    Vector<float> stats, wind;
    wind = filterByStat(filtered, Stats::speed);
    stats.push_back(Statistics::calculate_mean(wind));
    stats.push_back(Statistics::calculate_sample_sd(wind));
    return stats;
}

Vector<Vector<float>> DataProcessor::yearTempStat(int year) const{
    Vector<EnvlogType> filtered = filterByYear(year);
    Vector<Vector<float>> stats, temp;
    for(int i=0;i<filtered.size();i++){
        temp.push_back(filterByStat(filtered[i], Stats::temp));
    }
    for(int i=0;i<temp.size();i++){
        stats.push_back(Vector<float>());
        stats[i].push_back(Statistics::calculate_mean(temp[i]));
        stats[i].push_back(Statistics::calculate_sample_sd(temp[i]));
    }
    return stats;
}

Vector<float> DataProcessor::yearRadStat(int year) const{
    Vector<EnvlogType> filtered = filterByYear(year);
    Vector<float> stats, monthRad;
    for(int i=0; i<filtered.size(); i++){
        monthRad = filterInvalidRad(filterByStat(filtered[i],Stats::rad));
        stats.push_back(Statistics::calculate_sum(monthRad));
    }
    return stats;
}

Vector<float> DataProcessor::monthSPCC(int month)const{
    EnvlogType filtered = filterByMonth(month);
    Vector<float> wind, temp, rad, stats;
    float S_T, S_R, T_R;
    wind = filterByStat(filtered, Stats::speed);
    temp = filterByStat(filtered, Stats::temp);
    rad = filterByStat(filtered, Stats::rad);
    S_T = Statistics::calculate_sPCC(wind, temp);
    S_R = Statistics::calculate_sPCC(wind, rad);
    T_R = Statistics::calculate_sPCC(temp, rad);
    stats.push_back(S_T);
    stats.push_back(S_R);
    stats.push_back(T_R);
    std::cout << wind.size() << temp.size() << rad.size() << std::endl;
    std::cout << S_T << S_R << T_R << std::endl;
    return stats;
}

Vector<EnvlogType> DataProcessor::yearEnvStat(int year) const{
    Vector<EnvlogType> stats(12);
    Vector<Vector<float>> temp = yearTempStat(year);
    Vector<float> radData = yearRadStat(year);
    int noData=0;
    for(int i=0; i<12; i++){
        EnvlogType data = filterByMonthYear(Date(1,i+1,year));
        Vector<float> windData = filterByStat(data, Stats::speed);
        Vector<float> tempData = filterByStat(data, Stats::temp);
        Vector<float> wind = monthWindStat(Date(1,i+1,year));
        EnvRecType m, sd, mad;
        m.rad=radData[i];
        m.speed=wind[0];
        m.temp=temp[i][0];
        sd.speed=wind[1];
        sd.temp=temp[i][1];
        mad.speed=Statistics::calculate_MAD(windData);
        mad.temp=Statistics::calculate_MAD(tempData);
        stats[i].push_back(m);
        stats[i].push_back(sd);
        stats[i].push_back(mad);
        if(m.rad<=-999.0f &&m.speed<=-999.0f &&m.temp<=-999.0f){
            noData++;
        }
    }
    if (noData>=12) return Vector<EnvlogType>();
    return stats;
}

EnvlogType DataProcessor::filterByMonthYear(Date month) const{
    EnvlogType filtered;
    for(int i=0; i<_data.size(); i++){
        if(_data[i].d.GetMonth()==month.GetMonth() && _data[i].d.GetYear()==month.GetYear()){
            filtered.push_back(_data[i]);
        }
    }
    return filtered;
}

EnvlogType DataProcessor::filterByMonth(int month) const{
    EnvlogType filtered;
    for(int i=0; i<_data.size(); i++){
        if(_data[i].d.GetMonth()==month){
            filtered.push_back(_data[i]);
        }
    }
    return filtered;
}

Vector<EnvlogType> DataProcessor::filterByYear(int year) const{
    Vector<EnvlogType> filtered(12);
    EnvlogType yearData;
    for (const EnvRecType& record : _data) {
        if (record.d.GetYear() == year) {
            int month_index = record.d.GetMonth() - 1; // 0 for Jan, 11 for Dec
            filtered[month_index].push_back(record);
        }
    }
    return filtered;
}

Vector<float> DataProcessor::filterByStat(const EnvlogType& data, Stats stat) const{
    Vector<float> filtered;
    switch(stat){
    case Stats::speed:
        for(int i=0;i<data.size();i++){
            if(data[i].speed >= -999.0f)
                filtered.push_back(data[i].speed);
        }
        break;
    case Stats::temp:
        for(int i=0;i<data.size();i++){
            if(data[i].temp >= -999.0f)
                filtered.push_back(data[i].temp);
        }
        break;
    case Stats::rad:
        for(int i=0;i<data.size();i++){
            if(data[i].rad >= -999.0f){
                filtered.push_back(data[i].rad);
            }
        }
        break;
    default:
        break;
    }
    return filtered;
}

Vector<float> DataProcessor::filterInvalidRad(const Vector<float>& data)const{
    Vector<float> filtered;
     for(int i=0;i<data.size();i++){
        if(data[i] >= 100)
            filtered.push_back(data[i]);
    }
    return filtered;
}
