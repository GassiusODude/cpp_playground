#include <iostream>
#include <cmath>
#include <vector>

class Frequency{
    public:
        Frequency();
        double getFrequency(){ return d_frequency; }
        void setFrequency(double newFreq);
        void applyFrequencyTranslate(const std::vector<double> &input, std::vector<double> &output);
    private:
        double d_frequency;
};