#include < Liquid Crystal l. h >                              // Include the Liquid Crystal library.
#include <DHT .h>                                                 // Include the DHT library.

#define DHTPIN 8                                                // Set the DHT Pin.
#define DHTTYPE DHT11                                  // Set the DHT type.

Liquid Crystal lcd (1, 2, 4, 5, 6, 7) ;                  // Creates a Liquid Crystal object. Parameters: (RS, Enable (E), d4, d5, d6, d7).
DHT dht(DHTPIN, DHTTYPE);                       // Creates a DHT object. Parameters: (DHT Pin, DHT Type).

const int yellow LED = 9;                              // Adds a led light (in that case, it is yellow) to pin 9.
const int blue LED = 10;                               // Adds a led light (in that case, it is blue) to pin 10.
const int white LED = 11;                            // Adds a led light (in that case, it is white) to pin 11.

void setup() {
  lcd. begin(16, 2);                                           // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display.
  lcd. Set Cursor(0, 0);                                     // Set the cursor to column 0, line 0.
  
  Pin Mode (blue LED , OUTPUT);                 // Set blue LED pin as output.
  Pin Mode (yellow LED, OUTPUT);           // Set yellow LED pin as output.
 
  dht. begin();                                            // Initialize the DHT11 sensor.
  
  Digital Write(blue LED , LOW);             // Turn off blue LED.
  Digital Write(yellow LED, LOW);        // Turn off yellow LED.


lcd. print("Temperature:");           // Print "Temperature:" on LCD Screen.
  lcd. Set Cursor(0, 1);                    // Set the cursor to column 0, line 1.
  lcd. print("Humidity   :");          // Print "Humidity:" on LCD Screen.
}

void loop() {
  delay(250);                                                  // Wait 0.5 seconds before updating the values.
  float T = dht. read Temperature ();           // Read temperature in Celsius.
  float H = dht. read Humidity ();                // Read humidity in percentage.

  if (isnan(H) || isnan(T)) {                       // Check if the readings are Nan  (Not A Number).
    lcd. Set Cursor(12, 0);
    lcd .print("ERROR");                             // Print error on the LCD if there's an error.
    return;
  }

  if (T >= 35) {                                          // If the temperature is greater than 22°C.
    digital Write (yellow LED, HIGH);      // Turn on the yellow LED.
    Digital Write (blue LED, LOW);          // Turn off the blue LED.
  } 
  else {                                                    // If the temperature is less than 22°C.
    digital Write (blue LED, HIGH);        // Turn on the blue LED.
    Digital Write (yellow LED, LOW);     // Turn off the yellow LED.
  } 

  lcd. set Cursor (12, 0);                         // Set the cursor to column 12, line 0.
  lcd. print(T);                                       // Print the temperature.
  
  lcd. Set Cursor(12, 1);                       // Set the cursor to column 12, line 1.
  lcd. print(H);                                     // Print the humidity level.
}
