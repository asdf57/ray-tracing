#include "interval.h"

const interval interval::empty(+infinity, -infinity);
const interval interval::universe(-infinity, +infinity);

interval::interval() : min(+infinity), max(-infinity) {}

interval::interval(double _min, double _max) : min(_min), max(_max) {}

bool interval::contains(double x) const{
    return min <= x && x <= max;
}

bool interval::surrounds(double x) const{
    return min < x && x < max;
}

double interval::getMin() const {
    return min;
}

double interval::getMax() const {
    return max;
}

void interval::setMin(const double& minValue) {
    min = minValue;
}

void interval::setMax(const double& maxValue) {
    max = maxValue;
}

void interval::setMin(double&& minValue) {
    min = std::move(minValue);
}

void interval::setMax(double&& maxValue) {
    max = std::move(maxValue);
}
