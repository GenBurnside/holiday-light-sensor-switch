const int sensorPin = 0;

const int dark = 850;

int lightLevel;

void setup()
{
  Serial.begin(9600);
}


void loop()
{
  lightLevel = analogRead(sensorPin);
  
  String message = "";
  if (lightLevel < dark) {    
    message = "Day... no lights :(";
    message = message + " | " + lightLevel;
  } else {
    message = "Night... activate! :D";
    message = message + " | " + lightLevel;
  }
  
  Serial.println(message);
  delay(1000);
}
