#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Adafruit_MLX90614.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
float temp; 
void setup() {
  Serial.begin(9600);
  mlx.begin();
  // initialization of LCD
  lcd.init();
  
  
  lcd.backlight();

  lcd.setCursor(0, 0); 
  lcd.print("HELLO SBTU");
 
  lcd.setCursor(0, 1); 
  lcd.print("GROUP 4");
  delay(3000);
  lcd.clear();
}
void loop() {
  

  temp = mlx.readObjectTempC(); //comment this line if you want to test
  Serial.print("MODULE PROJECT");
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.println("   °C");
  lcd.setCursor(0,0);
  lcd.print("MODULE PROJECT");
  lcd.setCursor(0, 1); 
  lcd.print("Temp: ");
  lcd.setCursor(6, 1); 
  lcd.print(temp);
  lcd.print((char)223);
  lcd.setCursor(12, 1); 
  lcd.print("C");
  delay(1000);

}
