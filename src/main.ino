#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(12, 11, 5, 4, 3, 6);

void setup() {

  lcd.begin(16, 2);

  dht.begin();

  Serial.begin(9600);

  lcd.setCursor(0,0);
  lcd.print("Weather Station");

  delay(2000);

  lcd.clear();
}

void loop() {

  float humidity = dht.readHumidity();

  float tempC = dht.readTemperature();

  float tempF = dht.readTemperature(true);

  lcd.clear();

  if (isnan(humidity) || isnan(tempC)) {

    lcd.setCursor(0,0);
    lcd.print("Sensor Error");

  } else {

    lcd.setCursor(0,0);

    lcd.print("Temp:");
    lcd.print(tempF);
    lcd.print("F");

    lcd.setCursor(0,1);

    lcd.print("Hum:");
    lcd.print(humidity);
    lcd.print("%");

    Serial.print("Temperature: ");
    Serial.print(tempF);
    Serial.print(" F ");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println("%");
  }

  delay(2000);
}
