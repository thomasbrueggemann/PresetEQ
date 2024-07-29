#include <Arduino.h>
#include "Button2.h"

#define BAUD_RATE 115200

#define FOOTSWITCH_1_PIN 10
#define FOOTSWITCH_2_PIN 11
#define FOOTSWITCH_3_PIN 14
#define FOOTSWITCH_4_PIN 12

#define AMP_CHANNEL_RELAY_1_PIN 9
#define AMP_CHANNEL_RELAY_2_PIN 8
#define AMP_CHANNEL_RELAY_3_PIN 7
#define AMP_CHANNEL_RELAY_4_PIN 6

#define EQ_RELAY_1_PIN 5
#define EQ_RELAY_2_PIN 4
#define EQ_RELAY_3_PIN 3
#define EQ_RELAY_4_PIN 2

Button2 footswitch1;
Button2 footswitch2;
Button2 footswitch3;
Button2 footswitch4;

void handleTap(Button2 &btn)
{
  if (btn == footswitch1)
  {
    Serial.println("1 clicked");
    setAmpChannelRelay(1);
    setEQRelay(1);
  }
  else if (btn == footswitch2)
  {
    Serial.println("2 clicked");
    setAmpChannelRelay(2);
    setEQRelay(2);
  }
  else if (btn == footswitch3)
  {
    Serial.println("3 clicked");
    setAmpChannelRelay(3);
    setEQRelay(3);
  }
  else if (btn == footswitch4)
  {
    Serial.println("4 clicked");
    setAmpChannelRelay(4);
    setEQRelay(4);
  }
}

void handleDoubleTap()
{
  Serial.println("Double tap");
  digitalWrite(EQ_RELAY_1_PIN, LOW);
  digitalWrite(EQ_RELAY_2_PIN, LOW);
  digitalWrite(EQ_RELAY_3_PIN, LOW);
  digitalWrite(EQ_RELAY_4_PIN, LOW);
}

void setAmpChannelRelay(int footswitch)
{
  if (footswitch == 1)
  {
    digitalWrite(AMP_CHANNEL_RELAY_1_PIN, HIGH);
    digitalWrite(AMP_CHANNEL_RELAY_2_PIN, LOW);
    digitalWrite(AMP_CHANNEL_RELAY_3_PIN, LOW);
    digitalWrite(AMP_CHANNEL_RELAY_4_PIN, LOW);
  }
  else if (footswitch == 2)
  {
    digitalWrite(AMP_CHANNEL_RELAY_1_PIN, LOW);
    digitalWrite(AMP_CHANNEL_RELAY_2_PIN, HIGH);
    digitalWrite(AMP_CHANNEL_RELAY_3_PIN, LOW);
    digitalWrite(AMP_CHANNEL_RELAY_4_PIN, LOW);
  }
  else if (footswitch == 3)
  {
    digitalWrite(AMP_CHANNEL_RELAY_1_PIN, LOW);
    digitalWrite(AMP_CHANNEL_RELAY_2_PIN, LOW);
    digitalWrite(AMP_CHANNEL_RELAY_3_PIN, HIGH);
    digitalWrite(AMP_CHANNEL_RELAY_4_PIN, LOW);
  }
  else if (footswitch == 4)
  {
    digitalWrite(AMP_CHANNEL_RELAY_1_PIN, LOW);
    digitalWrite(AMP_CHANNEL_RELAY_2_PIN, LOW);
    digitalWrite(AMP_CHANNEL_RELAY_3_PIN, LOW);
    digitalWrite(AMP_CHANNEL_RELAY_4_PIN, HIGH);
  }
}

void setEQRelay(int footswitch)
{
  if (footswitch == 1)
  {
    digitalWrite(EQ_RELAY_1_PIN, HIGH);
    digitalWrite(EQ_RELAY_2_PIN, LOW);
    digitalWrite(EQ_RELAY_3_PIN, LOW);
    digitalWrite(EQ_RELAY_4_PIN, LOW);
  }
  else if (footswitch == 2)
  {
    digitalWrite(EQ_RELAY_1_PIN, LOW);
    digitalWrite(EQ_RELAY_2_PIN, HIGH);
    digitalWrite(EQ_RELAY_3_PIN, LOW);
    digitalWrite(EQ_RELAY_4_PIN, LOW);
  }
  else if (footswitch == 3)
  {
    digitalWrite(EQ_RELAY_1_PIN, LOW);
    digitalWrite(EQ_RELAY_2_PIN, LOW);
    digitalWrite(EQ_RELAY_3_PIN, HIGH);
    digitalWrite(EQ_RELAY_4_PIN, LOW);
  }
  else if (footswitch == 4)
  {
    digitalWrite(EQ_RELAY_1_PIN, LOW);
    digitalWrite(EQ_RELAY_2_PIN, LOW);
    digitalWrite(EQ_RELAY_3_PIN, LOW);
    digitalWrite(EQ_RELAY_4_PIN, HIGH);
  }
}

void setup()
{
  Serial.begin(BAUD_RATE);

  footswitch1.begin(FOOTSWITCH_1_PIN);
  footswitch1.setTapHandler(handleTap);
  footswitch1.setDoubleClickHandler(handleDoubleTap);

  footswitch2.begin(FOOTSWITCH_2_PIN);
  footswitch2.setTapHandler(handleTap);
  footswitch2.setDoubleClickHandler(handleDoubleTap);

  footswitch3.begin(FOOTSWITCH_3_PIN);
  footswitch3.setTapHandler(handleTap);
  footswitch3.setDoubleClickHandler(handleDoubleTap);

  footswitch4.begin(FOOTSWITCH_4_PIN);
  footswitch4.setTapHandler(handleTap);
  footswitch4.setDoubleClickHandler(handleDoubleTap);
}

void loop()
{
  footswitch1.loop();
  footswitch2.loop();
  footswitch3.loop();
  footswitch4.loop();
}
