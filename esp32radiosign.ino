const int RED_RELAY = 21;
const int BLUE_RELAY = 19;
const int GREEN_RELAY = 18;

const int ON = 1;
const int OFF = 0;

enum COLOR
{
  GREEN,
  RED,
  WHITE
};

void displayColor(int red, int green, int blue)
{
  digitalWrite(RED_RELAY, red);
  digitalWrite(GREEN_RELAY, green);
  digitalWrite(BLUE_RELAY, blue);
}

void setup()
{
  pinMode(RED_RELAY, OUTPUT);
  pinMode(GREEN_RELAY, OUTPUT);
  pinMode(BLUE_RELAY, OUTPUT);

  COLOR color = (COLOR)random(0, 3);

  switch (color)
  {
    case RED:
      displayColor(ON, OFF, OFF);
      break;

    case GREEN:
      displayColor(OFF, ON, OFF);
      break;

    default: // white
      displayColor(ON, ON, ON);
      break;
  }
}

void loop()
{
}
