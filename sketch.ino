#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

#define DHTPIN 15
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* apiKey = "YOUR_WRITE_API_KEY_ANAS";
const unsigned long channelID = 3551485;

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password, 6);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");
  Serial.println("University ID: 12218153");
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read DHT22!");
    delay(20000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.println(temperature);

  Serial.print("Humidity: ");
  Serial.println(humidity);

  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    String url = "http://api.thingspeak.com/update?api_key=";
    url += apiKey;
    url += "&field1=" + String(temperature, 2);
    url += "&field2=" + String(humidity, 2);

    http.begin(client, url);

    int httpCode = http.GET();
    String response = http.getString();

    if (httpCode == 200 && response.toInt() > 0) {
      Serial.println("Data sent successfully!");
      Serial.println("Entry ID: " + response);
    } else {
      Serial.print("Send failed. HTTP code: ");
      Serial.println(httpCode);
      Serial.println(response);
    }

    http.end();
  }

  delay(20000);
}
