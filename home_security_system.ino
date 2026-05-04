#include <DHT.h>

// Pin definitions
#define TRIG_PIN    9
#define ECHO_PIN    10
#define DHT_PIN     7
#define DHT_TYPE    DHT11
#define LIGHT_PIN   A0
#define WATER_PIN   A1
#define RED_LED     2
#define YELLOW_LED  3
#define BLUE_LED    4
#define BUZZER      5

// Sensor thresholds
#define INTRUSION_THRESHOLD_IN  15    // distance in inches triggering alert
#define WATER_THRESHOLD         300   // analog 0-1023; above = water detected
#define LIGHT_THRESHOLD         400   // analog 0-1023; below = low light

DHT dht(DHT_PIN, DHT_TYPE);

float getDistanceInches() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.0133;
}

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  float distance = getDistanceInches();
  int   water    = analogRead(WATER_PIN);
  int   light    = analogRead(LIGHT_PIN);
  float temp     = dht.readTemperature();

  bool intrusion = distance < INTRUSION_THRESHOLD_IN;
  bool flooding  = water > WATER_THRESHOLD;
  bool dark      = light < LIGHT_THRESHOLD;

  // Serial output
  if (!isnan(temp)) Serial.println((int)temp);
  if (flooding)     Serial.println("Warning! Water detected!");
  if (dark)         Serial.println("Automated light is on!");

  // LEDs and buzzer
  digitalWrite(RED_LED,    intrusion || flooding);
  digitalWrite(YELLOW_LED, !intrusion && !flooding);
  digitalWrite(BLUE_LED,   dark);
  digitalWrite(BUZZER,     intrusion);

  delay(1000);
}
