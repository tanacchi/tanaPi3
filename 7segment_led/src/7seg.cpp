#include <iostream>
#include <wiringPi.h>
#include <vector>

#include <digit.hpp>
#include <gpio_helper.hpp>

std::vector<int> pins = {17, 22, 19, 6, 5, 27, 26, 13};

void test(int pin)
{
  for (int i = 0; i < pins.size(); ++i)
  {
    if (i == pin) {
      digitalWrite(pins[i], 0);
      delay(100);
    } else {
      digitalWrite(pins[i], 1);
    }
  }
}

void clear()
{
  digitalWrite(GpioHelper::to_gpio( 8), 0);
  digitalWrite(GpioHelper::to_gpio(10), 0);
  digitalWrite(GpioHelper::to_gpio(12), 0);

  digitalWrite(GpioHelper::to_gpio(11), 1);
  digitalWrite(GpioHelper::to_gpio(15), 1);
  digitalWrite(GpioHelper::to_gpio(35), 1);
  digitalWrite(GpioHelper::to_gpio(31), 1);
  digitalWrite(GpioHelper::to_gpio(29), 1);
  digitalWrite(GpioHelper::to_gpio(13), 1);
  digitalWrite(GpioHelper::to_gpio(37), 1);
  digitalWrite(GpioHelper::to_gpio(33), 1);
}

int main()
{
  if (wiringPiSetupGpio() == -1)
  {
    return -1;
  }

  // Anode pins
  pinMode(14, OUTPUT);  // dig 1
  pinMode(15, OUTPUT);  // dig 2
  pinMode(18, OUTPUT);  // dig 3

  // Cathode pins
  pinMode(17, OUTPUT);  // a
  pinMode(22, OUTPUT);  // b
  pinMode(19, OUTPUT);  // c
  pinMode(6,  OUTPUT);  // d
  pinMode(5,  OUTPUT);  // e
  pinMode(27, OUTPUT);  // f
  pinMode(26, OUTPUT);  // g
  pinMode(13, OUTPUT);  // dp

  clear();

  ledset digit = Digit::get_ledset(7);

  digitalWrite(14, 1);
  digitalWrite(15, 1);
  digitalWrite(18, 1);
  
  while (true) 
  {
    for (std::size_t i{0}; i < digit.size(); ++i)
    {
      if (digit[i]) 
      {
        digitalWrite(pins[i], 0);
      } 
      else {
        digitalWrite(pins[i], 1);
      }
      std::cout << digit[i]  << std::endl;
    }
    std::cout << "=======" << std::endl;
  }

  return 0;
}
