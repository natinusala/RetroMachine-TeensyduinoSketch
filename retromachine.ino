//Run with at least Serial & Joystick USB modes

typedef struct button
{
  int pin;
  int button;
} button_t;

//Digital pins buttons
button_t digital_buttons[] = {
  {0, 1}, //Y
  {1, 2}, //B
  {2, 3}, //A
  {3, 4}, //X
};

int digital_buttons_size = sizeof(digital_buttons) / sizeof(button_t);

int i;

void setup() {
  Serial.begin(9600);

  //Digital pins buttons
  for (i = 0; i < digital_buttons_size; i++)
  {
    pinMode(digital_buttons[i].pin, INPUT_PULLUP);
  }
}

void loop() 
{
  //Digital pins buttons
  for (i = 0; i < digital_buttons_size; i++)
  {
    if (digitalRead(digital_buttons[i].pin) == LOW)
    {
      Joystick.button(digital_buttons[i].button, 1);
    }
    else
    {
      Joystick.button(digital_buttons[i].button, 0);
    }
  }
}
