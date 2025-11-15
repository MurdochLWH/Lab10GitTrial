#ifndef ENVTYPES_H_INCLUDED
#define ENVTYPES_H_INCLUDED

#include "Date.h"
#include "Time.h"
#include "Vector.h"

typedef struct {
    ///Constructor
    EnvRecType();
    ///Date of Environment Record
    Date d;
    ///Time of Environment Record
    Time t;
    ///Wind Speed (10min Mean) 10m (m/s)
    float speed;
    ///Ambient Air Temperature 1m (Degrees Celcius)
    float temp;
    ///Solar Radiation (10min Avg) (W/m^2)
    float rad;
} EnvRecType;

///Enum of stats
enum class Stats{
    speed = 0,
    temp = 1,
    rad = 2,
};

///Define EnvlogType as Vector of EnvRecType
typedef Vector<EnvRecType> EnvlogType;

///EnvRecType Comparision Operator >
bool operator > (const EnvRecType& L, const EnvRecType& R);

///EnvRecType Comparision Operator <
bool operator < (const EnvRecType& L, const EnvRecType& R);

///EnvRecType Comparision Operator ==
bool operator == (const EnvRecType& L, const EnvRecType& R);

#endif // ENVTYPES_H_INCLUDED
