#ifndef FORECAST_RECORD_H_
#define FORECAST_RECORD_H_

#include <Arduino.h>

typedef struct
{ // For current Day and Day 1, 2, 3, etc
    int Dt;
    String Period;
    String Icon;
    String Trend;
    String Main0;
    String Forecast0;
    String Forecast1;
    String Forecast2;
    String Description;
    String Time;
    String Country;
    float lat;
    float lon;
    float TemperatureOutdoor;
    float TemperatureIndoor;
    float Feelslike;
    float HumidityOutdoor;
    float HumidityIndoor;
    float High;
    float Low;
    float Winddir;
    float Windspeed;
    float Rainfall;
    float Snowfall;
    float Pop;
    float Pressure;
    int Cloudcover;
    int Visibility;
    int Sunrise;
    int Sunset;
    int Timezone;
} Forecast_record_type;

#endif /* ifndef FORECAST_RECORD_H_ */
