#include <LiquidCrystal.h>
#include <Arduino.h>
#include <Wire.h>
                            // Conncectors (for example)
pinMode(A5, INPUT);         //X
pinMode(A4, INPUT);         //Y
pinMode(13, INPUT_PULLUP);  //BUTTON
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print ("Welcome to game");
    lcd.scrollDisplayLeft;
    lcd.setCursor(0,1);
    lcd.print ("by Lobosok");
    lcd.scrollDisplayRight;
}

int previous_x;  

void loop() {
int x = analogRead(A5);
int y = analogRead(A4);
int8_t button = digitalRead(13);
int pos_0 = 0;
int the_end = 1;
bool Changed = false;


for (int i=0;i<7;i++)
 {
    lcd.setCursor(0,0);
    lcd.print("#   ");
 }
 for (int i=0;i<7;i++) 
 {
    lcd.setCursor(0,1);
    lcd.println("  # ");
 }


 int yp = 0;
 int xp = 0;  
 lcd.setCursor(yp,xp++);
 lcd.print(pos_0);

 lcd.setCursor(16,2);
 lcd.print(the_end); 
 
if (y > 850)
{                               //movement Y
    yp +=1;
 lcd.setCursor(yp,xp);
 delay(500);
}
 else if ( y < 1)
 {
   yp -=1;
   lcd.setCursor(yp,xp);
   delay(500);
 }
 
 if ((x > 850) && (previous_x < 500))
 {                        //movement X
     xp+=1;                                              
     lcd.setCursor(yp,xp);
     lcd.print(pos_0);
     delay(500);
 }
  else if ((x<1) && previous_x > 400)
  {
    xp-=1;
    lcd.setCursor(yp,xp);
    lcd.print(pos_0);
    delay(500);
  }


         //the end position
 if ((xp == 16) && (yp == 2))  
      {
      Changed = true;
      }
      if (Changed = true) 
      { 
      lcd.setCursor (0,0);
      lcd.print ("YOU WIN");
      lcd.scrollDisplayRight;
      lcd.setCursor (0,1);
      lcd.print ("NEVER GIVE UP");
      lcd.scrollDisplayLeft;
       }
    
}