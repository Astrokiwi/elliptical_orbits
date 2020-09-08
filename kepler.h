

// double eccentric_anomaly(
//                          double mean_anomaly
//                          ,double eccentricity
//                          ,double convergence_critera=1.e-6
//                          );
// 
// void binary_pos(
//                 double m1 // mass of one star in Msun
//                 ,double m2 // mass of one star in Msun
//                 ,double eccentricity // eccentricity of binary 
//                 ,double semi_major_axis // semi-major-axis of entire binary
//                 ,double t // time in years elapsed
//                 );


class StellarBinary {
    private:
        double angular_freq;
    
        double semi_major_axis_1,semi_minor_axis_1,semi_major_axis_2,semi_minor_axis_2;
        
        double eccentricity;

        double eccentric_anomaly(double mean_anomaly);

    public:
        StellarBinary(double m1 // mass of one star in Msun
                ,double m2 // mass of one star in Msun
                ,double eccentricity_in // eccentricity of binary 
                ,double separation // in pc 
                );
        
        void update(double t);
        
        double rad_1,rad_2;
        double r_1[2],r_2[2];
        
        double convergence_critera = 1.e-6;
};