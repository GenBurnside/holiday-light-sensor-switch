const int sensorPin = 0;
const int relayPin = 7;

const int dark = 850;

const int checkTime = 300000; //check every 5 minutes
const int lightTime = 21600000; //light up for 6 hours
const int restTime = 43200000; //sleep for 12 hours

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
    delay(checkTime);
  } else {
    message = "Night... activate! :D";
    message = message + " | " + lightLevel;
    digitalWrite(relayPin, HIGH);
    delay(lightTime);
    digitalWrite(relayPin, LOW);
    delay(restTime);
  }
  
  Serial.println(message);
}
