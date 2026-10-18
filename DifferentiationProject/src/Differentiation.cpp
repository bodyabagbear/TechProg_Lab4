#include "Differentiation.h"

extern "C" {
    double forwardDifference(double fx_plus_h, double fx, double h) {
        if (h == 0.0) return 0.0; 
        return (fx_plus_h - fx) / h;
    }

    double backwardDifference(double fx, double fx_minus_h, double h) {
        if (h == 0.0) return 0.0;
        return (fx - fx_minus_h) / h;
    }

    double centralDifference(double fx_plus_h, double fx_minus_h, double h) {
        if (h == 0.0) return 0.0;
        return (fx_plus_h - fx_minus_h) / (2.0 * h);
    }

    double secondDerivative(double fx_plus_h, double fx, double fx_minus_h, double h) {
        if (h == 0.0) return 0.0;
        return (fx_plus_h - 2.0 * fx + fx_minus_h) / (h * h);
    }
}