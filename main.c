/*
  WiFi Based Forest Fire ALERT SYSTEM without LCD
*/

int flameSensorPin = A0; // Input pin for flame sensor
const int buzzerPin = 6;
const int ledPin = 13;
int flameValue = 0; // Store value from flame sensor

void setup() {
  Serial.begin(115200);

  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);

  wificonfig();

  delay(3000);
  digitalWrite(ledPin, HIGH);
  delay(100);
}

void loop() {
  delay(10);
  flameValue = analogRead(flameSensorPin);
  Serial.print("Flame Sensor Value: ");
  Serial.println(flameValue);

  if (flameValue < 300) {
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    sendAlert("FIRE DETECTED @ FOREST ;");
  } else if (flameValue > 500) {
    digitalWrite(buzzerPin, LOW);
  }

  delay(1000); // Wait before the next read
}

void sendAlert(const char* message) {
  String command = "AT+CIPSEND=0," + String(strlen(message));
  Serial.println(command);
  delay(500);
  Serial.println(message);
}

void wificonfig() {
  Serial.println("AT");
  delay(500);
  Serial.println("ATE0");
  delay(500);
  Serial.println("AT+CWMODE=1");
  delay(500);
  Serial.println("AT+CIPMUX=1");
  delay(500);
  Serial.println("AT+CIPSERVER=1,80");
  delay(500);
  Serial.print("AT+CWJAP=");
  Serial.write('"');
  Serial.print("fire"); // WiFi SSID
  Serial.write('"');
  Serial.print(',');
  Serial.write('"');
  Serial.print("monitor1234"); // WiFi password
  Serial.write('"');
  Serial.println();
  delay(3000); // wait for connection
}
