#include "factorial.hpp"
int factorial(int val){
    if (val <= 1)
        return 1;
    else
        return factorial(val - 1) * val;
}
