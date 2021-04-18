#include "lcd.h"
#include "open_interface.h"
#include "timer.h"

double turn_left(oi_t *sensor_data, double degrees);
double turn_right(oi_t *sensor_data, double degrees);
double move_backwards(oi_t *sensor_data, double distance_mm);
double move_forward(oi_t *sensor_data, double distance_mm);

double move_forward(oi_t *sensor_data, double distance_mm)
{

    double sum = 0;
    oi_setWheels(200, 200);
    while (sum < distance_mm)
    {

        oi_update(sensor_data);


        sum += sensor_data->distance;
    }
    oi_setWheels(0, 0);
    return 0;
}

double turn_left(oi_t *sensor_data, double degrees)
{
    double sum = 0;

    degrees = -1.0 * degrees;
    oi_setWheels(-150, 150);

    while (sum > degrees)
    {
        oi_update(sensor_data);
        //oi_update(sensor_data);
        //if(degrees - sum <= 5){
        // turn_left(sensor_data, sum);

        // }

        sum += sensor_data->angle;
    }
    oi_setWheels(0, 0);
    return 0;

}

double turn_right(oi_t *sensor_data, double degrees)
{
    double sum = 0;
    degrees = 1.0 * degrees;
    oi_setWheels(150, -150);
    while (sum > degrees)
    {
        oi_update(sensor_data);
       // if (degrees + sum <= 5){
         //       turnright(sensor_data, sum);
    //}
            sum -= sensor_data->angle;
    }
    oi_setWheels(0, 0);
    return 0;

}
double move_backwards(oi_t *sensor_data, double distance_mm)
{

    double sum = 0;
    oi_setWheels(-200, -200);
    while (sum < distance_mm)
    {

        oi_update(sensor_data);

        sum -= sensor_data->distance;
    }
    oi_setWheels(0, 0);
    return 0;
}

