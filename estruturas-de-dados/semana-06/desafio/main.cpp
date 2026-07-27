#include <iostream>
#include <string>
#include <iomanip>

#include "measurement_avl.h"

int main() {
    MeasurementAVL avl;
    std::string cmd;

    while (std::cin >> cmd) {
        
        if (cmd == "ADD") {
            long long ts;
            double v;

            std::cin >> ts >> v;
            avl.add(ts, v);
        } 
        
        else if (cmd == "REMOVE") {
            long long ts;

            std::cin >> ts;
            avl.remove(ts);
        } 
        
        else if (cmd == "RANGE") {
            long long t1, t2;
            std::cin >> t1 >> t2;
            
            auto res = avl.range(t1, t2);
            std::cout << "count=" << res.count << "\n";
            
            double mean = (res.count == 0) ? 0.0 : (res.sum / res.count);
            std::cout << std::setprecision(10) << "mean=" << mean << "\n";
        } 
        
        else if (cmd == "END") {
            break;
        } 
        
        else {
            // Ingora
        }
    }
}