#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

class hittable_list : public hittable {
  public:
    hittable_list();
    hittable_list(std::shared_ptr<hittable> object);
    void clear();
    void add(std::shared_ptr<hittable> object);
    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override;
  private:
    std::vector<std::shared_ptr<hittable>> objects;
};

#endif
