
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int entradaSensor;
double temp;
String lcdBuffer;
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  entradaSensor = 0;
  temp = 0;
  lcd.print("Temperatura:");
  // Print a message to the LCD.
  
}

void loop(){
  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  
  lcd.print("                ");
  entradaSensor = analogRead(0);
  temp = (double)entradaSensor/1024;
  temp *= 5;
  temp -= 0.5;
  temp *= 100;
  lcd.setCursor(0,1);
  String output = String(temp) + String((char)178) + "C";
  lcd.print(output);
  
  if ( temp >= 20 ) {
    digitalWrite(8, HIGH);
    digitalWrite(10, HIGH);
  }
  else
    digitalWrite(8, LOW);
 	digitalWrite(10, LOW);
  
  if ( temp <= 0 ) {
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
  }
  else
  	digitalWrite(9, LOW);
 	digitalWrite(10, LOW);

}