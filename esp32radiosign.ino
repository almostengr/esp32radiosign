const int BLUE_RELAY = 2;
const int GREEN_RELAY = 1;
const int RED_RELAY = 0;

const int ON = 1;
const int OFF = 0;

enum COLOR
{
    GREEN,
    RED,
    WHITE
};

int randomTime()
{
    return random(2, 60) * 1000;
}

void displayColor(int red, int green, int blue)
{
    digitalWrite(RED_RELAY, red);
    digitalWrite(GREEN_RELAY, green);
    digitalWrite(BLUE_RELAY, blue);
}

unsigned long previousTime = 0;
int delayTime = randomTime();
COLOR color = WHITE;

void setup()
{
    pinMode(RED_RELAY, OUTPUT);
    pinMode(GREEN_RELAY, OUTPUT);
    pinMode(BLUE_RELAY, OUTPUT);
}

void loop()
{
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

    if (millis() - previousTime >= delayTime)
    {
        color = (COLOR)random(0, 3);
        previousTime = millis();
    }
}
