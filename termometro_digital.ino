
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
  // set uo initial values of variables;
  entradaSensor = 0;
  temp = 0;
  // Print a message to the LCD:
  lcd.print("Temperatura:");
  
}

void loop(){
  
  pinMode(8, OUTPUT);  //Red LED
  pinMode(9, OUTPUT);  //Blue LED
  pinMode(10, OUTPUT); //Buzzer
  
  lcd.print("                ");
  
  // Reading analog input and coverting to Celsius
  entradaSensor = analogRead(0);
  temp = (double)entradaSensor/1024;
  temp *= 5;
  temp -= 0.5;
  temp *= 100;
  
  lcd.setCursor(0,1);
  String output = String(temp) + String((char)178) + "C";
  lcd.print(output);
  
  // High temperature, turn on red LED and beep
  if ( temp >= 7 ) {
    digitalWrite(8, HIGH);
    digitalWrite(10, HIGH);
  }
  else
    digitalWrite(8, LOW);
 	  digitalWrite(10, LOW);
  
  // Low temperatura, turn on blue LED and beep
  if ( temp <= 4 ) {
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
  }
  else
  	digitalWrite(9, LOW);
 	  digitalWrite(10, LOW);

}
