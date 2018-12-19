#include <wiringPi.h>
#include <vector>

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
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(18, 0);
  
  digitalWrite(17, 1);
  digitalWrite(22, 1);
  digitalWrite(19, 1);
  digitalWrite(6,  1);
  digitalWrite(5,  1);
  digitalWrite(27, 1);
  digitalWrite(26, 1);
  digitalWrite(13, 1);
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

  digitalWrite(14, 1);
  digitalWrite(15, 1);
  digitalWrite(18, 1);
  
  digitalWrite(17, 0);
  digitalWrite(22, 0);
  digitalWrite(19, 0);
  digitalWrite(6,  0);
  digitalWrite(5,  0);
  digitalWrite(27, 0);
  digitalWrite(26, 0);
  digitalWrite(13, 0);
  
  clear();

  // test code
  std::vector<int> digs = {14, 15, 18};
  for (int i = 0; i < 3; ++i) 
  {
    digitalWrite(digs[i], 1);
    for (int j = 0; j < pins.size(); ++j)
    {
      test(j);
    }
    clear();
  }

  delay(950);

  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(18, 0);

  return 0;
}
