# Arduino MLX90614 Infrared Thermometer Project

*Arduino MLX90614 Kızılötesi Termometre Projesi*

Arduino tabanlı temasız sıcaklık ölçüm sistemi. MLX90614 sensörü ile I2C LCD ekran ve Serial Monitor üzerinden sıcaklık gösterimi.

*Institution / Kurum:* Sivas Bilim ve Teknoloji Üniversitesi (SBTU)  
*Development Team / Geliştirme Ekibi:* Group 4

---

## Contents / İçindekiler

- [System Overview / Sistem Genel Bakış](#system-overview--sistem-genel-bakış)
- [Components / Bileşenler](#components--bileşenler)
- [Installation / Kurulum](#installation--kurulum)
- [Usage / Kullanım](#usage--kullanım)
- [Code Documentation / Kod Dokümantasyonu](#code-documentation--kod-dokümantasyonu)
- [Troubleshooting / Sorun Giderme](#troubleshooting--sorun-giderme)
- [Technical Specifications / Teknik Özellikler](#technical-specifications--teknik-özellikler)

---

## System Overview / Sistem Genel Bakış

*Components / Bileşenler:*
1. Arduino Uno Microcontroller
2. MLX90614 Infrared Sensor
3. I2C LCD 16x2 Display

*Communication / İletişim:*
- Protocol: I2C
- Master: Arduino Uno
- Slaves: MLX90614 (0x5A), LCD (0x27)
- Pins: SDA (A4), SCL (A5)

---

## Components / Bileşenler

### MLX90614 Sensor
- *Voltage:* 3.0V - 5.0V
- *I2C Address:* 0x5A
- *Temperature Range:* -70°C to +382°C
- *Accuracy:* ±0.5°C
- *Distance:* 1-5 cm optimal

### I2C LCD 16x2
- *Voltage:* 5V
- *I2C Address:* 0x27 (may vary: 0x3F, 0x20)
- *Display:* 16 columns × 2 rows
- *Current:* ~20mA

### Arduino Uno
- *Microcontroller:* ATmega328P
- *I2C Pins:* A4 (SDA), A5 (SCL)
- *Operating Voltage:* 5V

---

## System Requirements / Sistem Gereksinimleri

### Hardware / Donanım
- Arduino Uno (or compatible)
- MLX90614 sensor module
- I2C LCD 16x2 display
- Jumper wires (10-12 pieces)
- USB cable or 5V power supply

### Software / Yazılım
- Arduino IDE 1.8.x or newer
- *Libraries:*
  - Wire (built-in)
  - LiquidCrystal_I2C (Frank de Brabander)
  - Adafruit MLX90614 Library
  - Adafruit Unified Sensor (dependency)

---

## Installation / Kurulum

### Hardware Connections / Donanım Bağlantıları

*MLX90614 to Arduino:*
- VIN → 5V
- GND → GND
- SDA → A4
- SCL → A5

*I2C LCD to Arduino:*
- VCC → 5V
- GND → GND
- SDA → A4 (shared)
- SCL → A5 (shared)

*Note:* Both devices share I2C bus with unique addresses (MLX90614: 0x5A, LCD: 0x27)

### Software Setup / Yazılım Kurulumu

1. Install Arduino IDE (1.8.x or newer)
2. Install libraries via Library Manager:
   - LiquidCrystal_I2C
   - Adafruit MLX90614 Library
   - Adafruit Unified Sensor (auto-installed)
3. Open mlx90614_infrared_project.ino
4. Select board: Tools → Board → Arduino Uno
5. Select port: Tools → Port → [Your Port]
6. Upload code

### I2C Address Verification / I2C Adres Doğrulama

If devices don't work, use I2C scanner:

cpp
#include <Wire.h>
void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("I2C Scanner");
}
void loop() {
  for(byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("Device at 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  delay(5000);
}


*LCD Address:* If different from 0x27, change in code: LiquidCrystal_I2C lcd(0x27, 16, 2);

*Serial Baud Rate:* 9600 (must match Serial Monitor setting)

---

## Usage / Kullanım

### Startup / Başlatma

1. Power on Arduino (USB or external supply)
2. LCD shows "HELLO SBTU" and "GROUP 4" for 3 seconds
3. System enters continuous measurement mode (updates every 1 second)

### Measurement / Ölçüm

*Best Practices:*
- Point sensor directly at object
- Maintain 1-5 cm distance
- Wait 1-2 seconds for stabilization
- Avoid reflective surfaces

*Display Format:*
- LCD Line 1: "MODULE PROJECT"
- LCD Line 2: "Temp: XX.XX°C"
- Serial Monitor: "MODULE PROJECTTemp: XX.XX   °C"

---

## Code Documentation / Kod Dokümantasyonu

### Libraries / Kütüphaneler

cpp
#include <Wire.h>              // I2C communication
#include <LiquidCrystal_I2C.h> // LCD control
#include <Adafruit_MLX90614.h> // Temperature sensor


### Variables / Değişkenler

cpp
LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD: address 0x27, 16x2
Adafruit_MLX90614 mlx;                // MLX90614 sensor
float temp;                            // Temperature value


### Setup Function / Setup Fonksiyonu

cpp
void setup() {
  Serial.begin(9600);    // Serial communication
  mlx.begin();           // Initialize sensor
  lcd.init();            // Initialize LCD
  lcd.backlight();       // Enable backlight
  
  lcd.setCursor(0, 0);
  lcd.print("HELLO SBTU");
  lcd.setCursor(0, 1);
  lcd.print("GROUP 4");
  delay(3000);
  lcd.clear();
}


### Loop Function / Loop Fonksiyonu

cpp
void loop() {
  temp = mlx.readObjectTempC();  // Read temperature
  
  // Serial output
  Serial.print("MODULE PROJECTTemp: ");
  Serial.print(temp);
  Serial.println("   °C");
  
  // LCD output
  lcd.setCursor(0, 0);
  lcd.print("MODULE PROJECT");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print((char)223);  // Degree symbol
  lcd.print("C");
  
  delay(1000);  // Update every second
}


---

## Troubleshooting / Sorun Giderme

### LCD Not Working / LCD Çalışmıyor

*Check:*
- Power connections (VCC→5V, GND→GND)
- I2C address (try 0x27, 0x3F, 0x20)
- SDA/SCL connections
- Use I2C scanner to verify address

*Solutions:*
- Adjust contrast potentiometer (if available)
- Verify correct I2C address in code
- Check for loose connections

### Sensor Not Reading / Sensör Okumuyor

*Check:*
- SDA/SCL connections
- I2C address (should be 0x5A)
- Power to sensor (VIN→5V)

*Solutions:*
- Add error check: if (!mlx.begin()) { Serial.println("Error"); while(1); }
- Point sensor at object (not empty space)
- Wait 1-2 seconds for stabilization
- Maintain 1-5 cm distance

### Serial Monitor Issues / Serial Monitor Sorunları

*Check:*
- Baud rate: 9600 (must match code)
- Correct COM port selected
- USB cable is data-capable (not charge-only)

*Solutions:*
- Verify Serial Monitor is open
- Check baud rate setting
- Try different USB port/cable

### Only One Device Works / Sadece Bir Cihaz Çalışıyor

*Solutions:*
- Verify both devices share SDA/SCL lines (this is correct)
- Use I2C scanner to detect both devices
- Check power supply can handle both devices (~30mA total)
- Add external 4.7kΩ pull-up resistors if needed

---

## Technical Specifications / Teknik Özellikler

### I2C Protocol / I2C Protokolü

- *Type:* Master-Slave
- *Speed:* 100kHz (standard mode)
- *Addresses:* MLX90614 (0x5A), LCD (0x27)
- *Lines:* SDA (data), SCL (clock)

### Power Consumption / Güç Tüketimi

| Component | Current | Voltage |
|-----------|---------|---------|
| Arduino Uno | ~50mA | 5V |
| MLX90614 | 1.5mA | 5V |
| LCD | 20mA | 5V |
| *Total* | *~72mA* | *5V* |

### Measurement Theory / Ölçüm Teorisi

MLX90614 detects infrared radiation emitted by objects. All objects above absolute zero emit IR radiation proportional to temperature.

*Accuracy Factors:*
- Distance: 1-5 cm optimal
- Surface type: Matte surfaces more accurate
- Emissivity: Default 1.0 (blackbody)
- Response time: < 1 second

---

## Project Information / Proje Bilgileri

*Project:* Arduino MLX90614 Infrared Thermometer  
*Institution:* Sivas Bilim ve Teknoloji Üniversitesi (SBTU)  
*Team:* Group 4  
*Version:* 1.0  
*License:* MIT (Educational use)

### Acknowledgments / Teşekkürler

- Adafruit Industries - MLX90614 library
- Frank de Brabander - LiquidCrystal_I2C library
- Arduino Community
- SBTU - Academic support

---

*Last Updated:* 2024
