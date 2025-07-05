#include "DHT.h"  // Include the DHT11 library

#define DHTPIN 2  // DHT sensor is connected to pin 0
#define DHTTYPE DHT11  // DHT 11

DHT dht(DHTPIN, DHTTYPE);

int ORANGE_LED = 11;    // Attached the ORANGE_LED to pin 3
int YELLOW_LED = 12;    // Attached the YELLOW_LED to pin 4
int GREEN_LED = 13;     // Attached the GREEN_LED to pin 2
int BUZZER = 10;        // Attached the BUZZER to pin 5
int FAN = 9;           // Attached the FAN to pin 6

void setup()   // Put your setup code here, to run once:
{      
  // Initialize pins
  pinMode(ORANGE_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(FAN, OUTPUT);
  pinMode(DHTPIN, INPUT);
  Serial.begin(9600);    // Initialize serial communication
  dht.begin();           // Initialize DHT sensor
}

void loop()   // Put your main code here, to run repeatedly:
{   
  delay(2000);
  // Read temperature and humidity
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  if (isnan(humidity) || isnan(temperature)) {  // Check if the readings are valid
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Control LEDs, Fan, and buzzer based on humidity
  if (temperature >=40 || humidity >=60 ) 
  {
    digitalWrite(ORANGE_LED, HIGH);  // Orange LED on
    digitalWrite(GREEN_LED, LOW);    // Green LED off
    digitalWrite(YELLOW_LED, LOW);   // Yellow LED off
    digitalWrite(FAN, HIGH);         // Fan on
    digitalWrite(BUZZER, HIGH);      // Buzzer on
    delay(1000);   
  }
  else if (temperature >=20  && temperature < 40 || humidity >=40 && humidity <60) 
  {
    digitalWrite(ORANGE_LED, LOW);   // Orange LED off
    digitalWrite(GREEN_LED, LOW);    // Green LED off
    digitalWrite(YELLOW_LED, HIGH);  // Yellow LED on
    digitalWrite(FAN, LOW);          // Fan off
    digitalWrite(BUZZER, LOW);       // Buzzer off
    delay(1000);   
  }
  else 
  {  // When humidity is less than 25
    digitalWrite(ORANGE_LED, LOW);   // Orange LED off
    digitalWrite(GREEN_LED, HIGH);   // Green LED on
    digitalWrite(YELLOW_LED, LOW);   // Yellow LED off
    digitalWrite(FAN, LOW);          // Fan off
    digitalWrite(BUZZER, LOW);       // Buzzer off
    delay(1000);   
  }

  // Print the results to the serial monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
  
}
