const int sensorPin = 0;
const int relayPin = 7;

const int dark = 850;

const int checkTime = 300000; //check every 5 minutes
const long lightTime = 21600000; //light up for 6 hours
const long restTime = 43200000; //sleep for 12 hours

int lightLevel;

void setup()
{
  pinMode(relayPin, OUTPUT);
}


void loop()
{
  lightLevel = analogRead(sensorPin);
  
  if (lightLevel < dark) {    
    digitalWrite(relayPin, LOW);
    delay(checkTime);
  } else {
    digitalWrite(relayPin, HIGH);
    delay(lightTime);
    digitalWrite(relayPin, LOW);
    delay(restTime);
  }
}
