#ifndef INCLUDED_GPIO_PIN_HPP
#define INCLUDED_GPIO_PIN_HPP

class GpioPin
{
public:
  enum PinState
  {
    High, Low
  };
  
  GpioPin(int gpio_number, PinState initial_state = PinState::Low);
  void set(PinState state) const;
  static int to_i(PinState state);

private:
  const int gpio_number_;
};

GpioPin::GpioPin(int gpio_number, PinState initial_state)
  : gpio_number_{gpio_number}
{
  pinMode(gpio_number_, OUTPUT);
  set(initial_state);
}

void GpioPin::set(PinState state) const
{
  digitalWrite(gpio_number_, to_i(state));
}

int GpioPin::to_i(PinState state)
{
  return state == PinState::Low ? 0 : 1;
}

#endif // INCLUDED_GPIO_PIN_HPP
