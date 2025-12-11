#include <algorithm>
#include <functional>
#include "frequency.hpp"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Frequency::Frequency():
    d_frequency {0.0} {
}

void Frequency::setFrequency(double newFreq){

    d_frequency = newFreq;
}

// ==============  helper functions for applyFrequencyTranslate  ============
int _time = 0;
double _frequency = 0;
int setTime() { return _time++; }
double genCarrier(double v) {return std::cos(2 * M_PI * _frequency * v); }
double translate(double val){ return val; }

/**
 * Apply frequency translate on the real input signal
 * @param input The real input signal
 * @param output The output signal
 */
void Frequency::applyFrequencyTranslate(const std::vector<double> &input, std::vector<double> &output){
    // -----------------------  prepare carrier  ----------------------------
    std::generate_n(output.begin(), input.size(), setTime); // setup time

    _frequency = getFrequency();
    std::transform(input.begin(), input.end(), output.begin(), genCarrier);

    // --------------------  apply carrier to input  ------------------------
    std::transform(input.begin(), input.end(),
        output.begin(), output.begin(), std::multiplies<double>());
}