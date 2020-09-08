#include <iostream>
#include "kepler.h"
#include <math.h>
#include <memory>

int main() {
//     double eccentricity = 0.9;
//     double semi_major_axis = 1./sqrt(1.-eccentricity*eccentricity);

   std::unique_ptr<StellarBinary> sb = std::make_unique<StellarBinary>(50.,50.,0.9,1.);

    for ( int it = 0 ; it<200 ; it++ ) {
    
        double t = it*1.e5;
        sb->update(t);
        
        std::cout << t;
        std::cout << " " << sb->r_1[0] << " " << sb->r_1[1] << " " << sb->rad_1;
        std::cout << " " << sb->r_2[0] << " " << sb->r_2[1] << " " << sb->rad_2;
        std::cout << std::endl;
//         binary_pos(150.,150.,0.1,1.,it*1.e5);

//         double mean_anomaly = it*.1;
//         std::cout << mean_anomaly << " ";
//         double theta = eccentric_anomaly(mean_anomaly,eccentricity);
// //         double rad = semi_major_axis*(1.-eccentricity*eccentricity)/(1+eccentricity*cos(theta));
//         double rad = semi_major_axis*(1.-eccentricity*cos(theta));
//         std::cout << semi_major_axis*cos(theta) - eccentricity*semi_major_axis <<  " " << sin(theta) <<  " " << rad << std::endl;
// //         std::cout << semi_major_axis*cos(theta) <<  " " << sin(theta) << std::endl;
    }

    return 0;
}