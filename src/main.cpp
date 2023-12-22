#include <iostream>
#include <algorithm>
#include "constants.h"
#include "color.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"

constexpr double ASPECT_RATIO = 16.0 / 9.0;
constexpr int IMAGE_WIDTH = 400;
//Floor at 1 to prevent integer casting from providing height of 0
constexpr int IMAGE_HEIGHT = std::max(1, static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO));

color lerp(double a, color start_color, color end_color){
  return (1.0-a) * start_color + a * end_color;
}

double hit_sphere(const point3& center, double radius, const ray& ray){
  vec3 oc = ray.origin() - center;
  double a = ray.direction().length_squared();
  double half_b = dot(oc, ray.direction());
  double c = oc.length_squared() - radius*radius;
  double discriminant = half_b*half_b - a*c;

  //No real solutions
  if(discriminant < 0){
    return -1.0;
  }

  //Only find the FIRST point of intersection
  return (-half_b - sqrt(discriminant)) / a;
}

color ray_color(const ray& r, const hittable& world) {
  hit_record rec;

  if (world.hit(r, 0, infinity, rec)) {
    return 0.5 * (rec.getNormal() + color(1,1,1));
  }

  vec3 unit_direction = unit_vector(r.direction());
  auto a = 0.5*(unit_direction.v1() + 1.0);
  return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

int main(){
  hittable_list world;

  world.add(std::make_shared<sphere>(point3(0,0,-1), 0.5));
  world.add(std::make_shared<sphere>(point3(0,-100.5,-1), 100));

  double viewport_height = 2.0;
  double viewport_width = viewport_height * (static_cast<double>(IMAGE_WIDTH) / IMAGE_HEIGHT);

  point3 camera_center = point3(0, 0, 0);

  vec3 viewport_u = vec3(viewport_width, 0, 0);
  vec3 viewport_v = vec3(0, -viewport_height, 0);
  vec3 pixel_delta_u = viewport_u / IMAGE_WIDTH;
  vec3 pixel_delta_v = viewport_v / IMAGE_HEIGHT;

  //Vector in -Z dir from camera center to center of viewport (magnitude represents focal length)
  vec3 focal_length = vec3(0, 0, -1.0);

  point3 viewport_upper_left = camera_center + focal_length - viewport_u/2 - viewport_v/2;
  point3 pixel00_loc = viewport_upper_left + pixel_delta_u/2 + pixel_delta_v/2;

  std::cout << "P3\n" << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n255\n";

  for(int row = 0; row < IMAGE_HEIGHT; row++){
    std::clog << "\rScanlines remaining: "
      << (IMAGE_HEIGHT - row)
      << ' '
      << std::flush;
  
    for(int col = 0; col < IMAGE_WIDTH; col++){
      vec3 pixel_center = pixel00_loc + (col*pixel_delta_u) + (row*pixel_delta_v);
      //Create vector from camera center to center of current pixel
      vec3 ray_direction = pixel_center - camera_center;
      ray ray(camera_center, ray_direction);
      color pixel_color = ray_color(ray, world);

      //Normalizing colors to {0..255} mapping
      write_pixel(std::cout, pixel_color);
    }
  }
  std::clog << "\rDone.                 \n";
}
