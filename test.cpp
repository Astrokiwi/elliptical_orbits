#include <iostream>
#include "kepler.h"
#include <math.h>
#include <memory>

int main() {
    std::unique_ptr<StellarBinary> sb = std::make_unique<StellarBinary>(50.,50.,0.9,1.);

    for ( int it = 0 ; it<200 ; it++ ) {
    
        double t = it*1.e5;
        sb->update(t);
        
        std::cout << t;
        std::cout << " " << sb->r_1[0] << " " << sb->r_1[1] << " " << sb->rad_1;
        std::cout << " " << sb->r_2[0] << " " << sb->r_2[1] << " " << sb->rad_2;
        std::cout << std::endl;
    }

    return 0;
}