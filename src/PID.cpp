#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double kp, double kd, double ki)
{
    Kp = kp;
    Kd = kd;
    Ki = ki;

    p_error = 0;
    i_error = 0;
    d_error = 0;

    is_first_cte = true;
}

void PID::UpdateError(double cte)
{
    if (is_first_cte) {
        is_first_cte = false;
        p_error = cte;
    }
    i_error += cte;
    d_error = cte - p_error;
    p_error = cte;
}

double PID::TotalError()
{
    return -Kp * p_error  - Kd * d_error - Ki * i_error;
}
