#ifndef _INTERVAL_H
#define _INTERVAL_H

#include "constants.h"

class interval {
  public:
    interval();
    interval(double _min, double _max);
    bool contains(double x) const;
    bool surrounds(double x) const;
    double getMin() const;
    double getMax() const;
    void setMin(const double& minValue);
    void setMax(const double& maxValue);
    void setMin(double&& minValue);
    void setMax(double&& maxValue);
  private:
    static const interval empty;
    static const interval universe;
    double min;
    double max;
};

#endif
