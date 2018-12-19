#ifndef INCLUDED_GPIO_HELPER_HPP
#define INCLUDED_GPIO_HELPER_HPP

#include <unordered_map>
#include <map>

#define GPIO2  2
#define GPIO3  3
#define GPIO4  4
#define GPIO5  5
#define GPIO6  6
#define GPIO7  7
#define GPIO8  8
#define GPIO9  9
#define GPIO10 10
#define GPIO11 11
#define GPIO12 12
#define GPIO13 13
#define GPIO14 14
#define GPIO15 15
#define GPIO16 16
#define GPIO17 17
#define GPIO18 18
#define GPIO19 19
#define GPIO20 20
#define GPIO21 21
#define GPIO22 22
#define GPIO23 23
#define GPIO24 24
#define GPIO25 25
#define GPIO26 26
#define GPIO27 27

class GpioHelper
{
public:
  static int to_gpio(int pin);
private:
  static const std::map<int, int> gpio_pin_table; 
};

int GpioHelper::to_gpio(int pin)
{
  return gpio_pin_table.at(pin);
}

const std::map<int, int> GpioHelper::gpio_pin_table { 
{
  {3,  GPIO2 }, {5,  GPIO3 }, {7,  GPIO4 }, {8,  GPIO14},
  {10, GPIO15}, {11, GPIO17}, {12, GPIO18}, {13, GPIO27},
  {15, GPIO22}, {16, GPIO23}, {18, GPIO24}, {19, GPIO10},
  {21, GPIO9 }, {22, GPIO25}, {23, GPIO11}, {24, GPIO8 },
  {26, GPIO7 }, {29, GPIO5 }, {31, GPIO6 }, {32, GPIO12},
  {33, GPIO13}, {35, GPIO19}, {36, GPIO16}, {37, GPIO26}, 
  {38, GPIO20}, {40, GPIO21},
}};

#endif  // INCLUDED_GPIO_HELPER_HPP
