#include "EnvTypes.h"
EnvRecType::EnvRecType()
    : d(),
      t(),
      speed(0.0f),
      temp(0.0f),
      rad(0.0f)
{}

bool operator > (const EnvRecType& L, const EnvRecType& R){
    return L.d > R.d;
}

bool operator < (const EnvRecType& L, const EnvRecType& R){
    return L.d < R.d;
}

bool operator == (const EnvRecType& L, const EnvRecType& R){
    return L.d == R.d;
}
