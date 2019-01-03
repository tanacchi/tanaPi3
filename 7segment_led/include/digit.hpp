#ifndef INCLUDED_DIGIT_HPP
#define INCLUDED_DIGIT_HPP

#include <unordered_map>
#include <vector>
#include <bitset>

#include <gpio_pin.hpp>
#include <gpio_helper.hpp>

using ledset = std::bitset<8>;

class Digit
{
public:
  Digit(int pin_a, int pin_b, int pin_c, int pin_d, int pin_e, int pin_f, int pin_g, int pin_dp);

  static const ledset get_ledset(int number);
private:
  int pin_a_, pin_b_, pin_c_, pin_d_, pin_e_, pin_f_, pin_g_, pin_dp_;

  std::vector<GpioPin> pins;

  static const ledset led_a, led_b, led_c, led_d, led_e, led_f, led_g, led_dp;

  static const std::unordered_map<int, ledset> number_led_table;
//  static const std::unordered_map<int, >
};

const ledset Digit::led_a {"00000001"};
const ledset Digit::led_b {"00000010"};
const ledset Digit::led_c {"00000100"};
const ledset Digit::led_d {"00001000"};
const ledset Digit::led_e {"00010000"};
const ledset Digit::led_f {"00100000"};
const ledset Digit::led_g {"01000000"};
const ledset Digit::led_dp{"10000000"};

const std::unordered_map<int, ledset> Digit::number_led_table {
{
  {0, led_a | led_b | led_c | led_d | led_e | led_f         },
  {1,         led_b | led_c                                 },
  {2, led_a | led_b |         led_d | led_e |         led_g },
  {3, led_a | led_b |         led_d |                 led_g },
  {4,         led_b | led_c |                 led_f | led_g },
  {5, led_a |         led_c | led_d |         led_f | led_g },
  {6, led_a |         led_c | led_d | led_e | led_f | led_g },
  {7, led_a | led_b | led_c                                 },
  {8, led_a | led_b | led_c | led_d | led_e | led_f | led_g },
  {9, led_a | led_b | led_c | led_d |         led_f | led_g },
}};

Digit::Digit(int pin_a, int pin_b, int pin_c, int pin_d, int pin_e, int pin_f, int pin_g, int pin_dp)
  : pins{pin_a, pin_b, pin_c, pin_d, pin_e, pin_f, pin_g, pin_dp}
{
}

const ledset Digit::get_ledset(int number)
{
  return number_led_table.at(number);
}

#endif  // INCLUDED_DIGIT_HPP
