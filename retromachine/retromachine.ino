//Run with at least Serial & Joystick USB modes

typedef struct button
{
  int pin;
  int button;
} button_t;

void joystick_x(unsigned int value)
{
  Joystick.X(value);
}

void joystick_y(unsigned int value)
{
  Joystick.Y(value);
}

typedef struct joystick
{
  int pin_x;
  int pin_y;
  void (*func_x)(unsigned int);
  void (*func_y)(unsigned int);
} joystick_t;

//Buttons
button_t buttons[] = {
  {0, 1}, //Y
  {1, 2}, //B
  {2, 3}, //A
  {3, 4}, //X,
  {A0, 14}, //DPAD_UP
  {A1, 15}, //DPAD_UP
  {A2, 16}, //DPAD_UP
  {A3, 17}, //DPAD_UP,
  {4, 5}, //LB
  {5, 6}, //LT
  {6, 7}, //RB
  {7, 8}, //RT
  {12, 13}, //MENU
  {A8, 18}, //MUTE,
  {10, 11}, //VOL-
  {11, 12}, //VOL+,
  {8, 9}, //SELECT
  {9, 10} //START
};

int buttons_size = sizeof(buttons) / sizeof(button_t);

//Joysticks
joystick_t joysticks[] = {
  {A4, A5, joystick_x, joystick_y} //Left analog
};

int joysticks_size = sizeof(joysticks) / sizeof(joystick_t);

int i;

void setup() {
  Serial.begin(9600);

  //Digital pins buttons
  for (i = 0; i < buttons_size; i++)
  {
    pinMode(buttons[i].pin, INPUT_PULLUP);
  }
}

void loop()
{
  //Digital pins buttons
  for (i = 0; i < buttons_size; i++)
  {
    if (digitalRead(buttons[i].pin) == LOW)
    {
      Joystick.button(buttons[i].button, 1);
    }
    else
    {
      Joystick.button(buttons[i].button, 0);
    }
  }

  //Joysticks
  for (i = 0; i < joysticks_size; i++)
  {
    joystick_t joy = joysticks[i];
    joy.func_x(analogRead(joy.pin_x));
    joy.func_y(analogRead(joy.pin_y));
  }
}
