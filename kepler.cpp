#define _USE_MATH_DEFINES
#include <math.h>

#include "kepler.h"

static const double sqrt_G = 6.708e-8; // for M in Msun, a in pc, freq in year**-1 (time in year)

inline double cube(double x) {
    return x*x*x;
}

StellarBinary::StellarBinary(double m1 // mass of one star in Msun
                ,double m2 // mass of one star in Msun
                ,double eccentricity_in // eccentricity of binary 
                ,double separation // in pc 
                ) {

    double mtot = m1+m2;
    angular_freq = sqrt_G*sqrt((mtot)/cube(separation));
    
    eccentricity = eccentricity_in;

    double minor_major_axis_factor = sqrt(1-eccentricity*eccentricity);
    
    semi_major_axis_1 = separation*m2/mtot;
    semi_minor_axis_1 = minor_major_axis_factor*semi_major_axis_1;
    semi_major_axis_2 = separation*m1/mtot;
    semi_minor_axis_2 = minor_major_axis_factor*semi_major_axis_2;
    
    
}

double StellarBinary::eccentric_anomaly(
                         double mean_anomaly
                         ) {
    double cosE;
    double guess;
    double oldguess = M_PI;
    
    do {
        oldguess=guess;
        cosE = cos(oldguess);
        guess = (mean_anomaly - eccentricity * (oldguess*cosE - sin(oldguess)))
                /(1 - eccentricity*cosE);
//         std::cout << guess << std::endl;
    } while (fabs((oldguess-guess)/guess)>convergence_critera);
    
    
    return guess;
}

void StellarBinary::update(double t // time in years elapsed
                ) {
    double mean_anomaly = t*angular_freq;
    
    double theta = eccentric_anomaly(mean_anomaly);
    double costheta = cos(theta);
    double sintheta = sin(theta);
    double rad_factor = (1.-eccentricity*costheta);

    rad_1 = semi_major_axis_1*rad_factor;
    rad_2 = semi_major_axis_2*rad_factor;
    
    r_1[0] = semi_major_axis_1*costheta - eccentricity*semi_major_axis_1;
    r_1[1] = semi_minor_axis_1*sintheta;

    r_2[0] = -(semi_major_axis_2*costheta - eccentricity*semi_major_axis_2);
    r_2[1] = -(semi_minor_axis_2*sintheta);
    
}