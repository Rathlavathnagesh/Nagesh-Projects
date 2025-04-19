#include <Liquid Crystal.h>                              // Include the Liquid Crystal library.
#include <DHT.h>                                                 // Include the DHT library.

#define DHTPIN 8                                                // Set the DHT Pin.
#define DHTTYPE DHT11                                  // Set the DHT type.

LiquidCrystal lcd (1, 2, 4, 5, 6, 7) ;                  // Creates a Liquid Crystal object. Parameters: (RS, Enable (E), d4, d5, d6, d7).
DHT dht(DHTPIN, DHTTYPE);                       // Creates a DHT object. Parameters: (DHT Pin, DHT Type).

const int yellowLED = 9;                              // Adds a led light (in that case, it is yellowLED) to pin 9.
const int blueLED = 10;                               // Adds a led light (in that case, it is blueLED) to pin 10.
const int whiteLED = 11;                            // Adds a led light (in that case, it is white) to pin 11.

void setup() {
  lcd.begin(16, 2);                                           // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display.
  lcd.Set Cursor(0, 0);                                     // Set the cursor to column 0, line 0.
  
  PinMode (blueLED , OUTPUT);                 // Set blueLED pin as output.
  PinMode (yellowLED, OUTPUT);           // Set yellowLED pin as output.
 
  dht.begin();                                            // Initialize the DHT11 sensor.
  
  DigitalWrite(blueLED , LOW);             // Turn off blueLED.
  DigitalWrite(yellowLED, LOW);        // Turn off yellowLED.


  lcd.print("Temperature:");           // Print "Temperature:" on LCD Screen.
  lcd.Set Cursor(0, 1);                    // Set the cursor to column 0, line 1.
  lcd.print("Humidity   :");          // Print "Humidity:" on LCD Screen.
}

void loop() {
  delay(250);                                                  // Wait 0.5 seconds before updating the values.
  float T = dht.readTemperature();           // Read temperature in Celsius.
  float H = dht.readHumidity();                // Read humidity in percentage.

  if (isnan(H) || isnan(T)) {                       // Check if the readings are Nan  (Not A Number).
    lcd.Set Cursor(12, 0);
    lcd.print("ERROR");                             // Print error on the LCD if there's an error.
    return;
  }

  if (T >= 35) {                                          // If the temperature is greater than 22°C.
    digitalWrite (yellowLED, HIGH);      // Turn on the yellowLED.
    DigitalWrite (blueLED, LOW);          // Turn off the blueLED.
  } 
  else {                                                    // If the temperature is less than 22°C.
    digitalWrite (blueLED, HIGH);        // Turn on the blueLED.
    DigitalWrite (yellowLED, LOW);     // Turn off the yellowLED.
  } 

  lcd.setCursor(12, 0);                         // Set the cursor to column 12, line 0.
  lcd.print(T);                                       // Print the temperature.
  
  lcd.Set Cursor(12, 1);                       // Set the cursor to column 12, line 1.
  lcd.print(H);                                     // Print the humidity level.
}
