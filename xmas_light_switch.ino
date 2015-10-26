const int sensorPin = 0;
const int relayPin = 7;

const int dark = 850;

const int checkTime = 5000;
const int lightTime = 10000;

int lightLevel;

void setup()
{
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
}


void loop()
{
  lightLevel = analogRead(sensorPin);
  
  String message = "";
  if (lightLevel < dark) {    
    message = "Day... no lights :(";
    message = message + " | " + lightLevel;
    digitalWrite(relayPin, LOW);
  } else {
    message = "Night... activate! :D";
    message = message + " | " + lightLevel;
    digitalWrite(relayPin, HIGH);
    delay(lightTime)
  }
  
  Serial.println(message);
  delay(checkTime);
}
