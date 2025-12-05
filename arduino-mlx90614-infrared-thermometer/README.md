# 🌡️ Arduino MLX90614 Infrared Thermometer Project

<div align="center">

**Temasız Kızılötesi Termometre Projesi**

[![Arduino](https://img.shields.io/badge/Platform-Arduino-blue?logo=arduino)](https://www.arduino.cc/)
[![Sensor](https://img.shields.io/badge/Sensor-MLX90614-red)](https://www.melexis.com/en/product/MLX90614/Digital-Plug-Play-Infrared-Thermometer-TO-Can)
[![LCD](https://img.shields.io/badge/Display-I2C%20LCD-green)](https://www.arduino.cc/)
[![License](https://img.shields.io/badge/License-MIT-yellow)](LICENSE)

*Developed by Group 4 - Sivas Bilim ve Teknoloji Üniversitesi (SBTU)*

</div>

---

## 🚀 Quick Start / Hızlı Başlangıç

### English
Get your infrared thermometer up and running in 5 minutes!

1. **Connect Hardware** → Wire MLX90614 and I2C LCD to Arduino
2. **Install Libraries** → Add required libraries via Arduino IDE
3. **Upload Code** → Flash `mlx90614_infrared_project.ino` to your board
4. **Power On** → See temperature readings instantly!

### Türkçe
Kızılötesi termometrenizi 5 dakikada çalıştırın!

1. **Donanımı Bağlayın** → MLX90614 ve I2C LCD'yi Arduino'ya bağlayın
2. **Kütüphaneleri Yükleyin** → Arduino IDE üzerinden gerekli kütüphaneleri ekleyin
3. **Kodu Yükleyin** → `mlx90614_infrared_project.ino` dosyasını kartınıza yükleyin
4. **Güç Verin** → Sıcaklık okumalarını anında görün!

---

## 📖 What is This Project? / Bu Proje Nedir?

### English
This is an Arduino-based contactless temperature measurement system. Using infrared technology, it can measure the temperature of objects without any physical contact. Perfect for applications where hygiene, safety, or non-invasive measurement is important.

**Key Applications:**
- Medical temperature screening
- Food temperature monitoring
- Industrial process control
- Educational demonstrations
- DIY projects

### Türkçe
Bu, Arduino tabanlı temasız sıcaklık ölçüm sistemidir. Kızılötesi teknoloji kullanarak, fiziksel temas olmadan nesnelerin sıcaklığını ölçebilir. Hijyen, güvenlik veya invaziv olmayan ölçümün önemli olduğu uygulamalar için idealdir.

**Temel Uygulamalar:**
- Tıbbi sıcaklık taraması
- Gıda sıcaklık izleme
- Endüstriyel proses kontrolü
- Eğitim gösterimleri
- DIY projeleri

---

## 🎯 Project Goals / Proje Hedefleri

| Goal / Hedef | Description / Açıklama |
|--------------|------------------------|
| **Accuracy / Doğruluk** | Measure temperature with ±0.5°C precision |
| **Ease of Use / Kolay Kullanım** | Simple setup and operation |
| **Dual Output / Çift Çıktı** | Display on LCD and Serial Monitor simultaneously |
| **Educational Value / Eğitim Değeri** | Learn about I2C communication and IR sensors |

---

## 📦 What You'll Need / İhtiyacınız Olanlar

### Hardware Components / Donanım Bileşenleri

```
┌─────────────────────────────────────────┐
│  Component List / Bileşen Listesi      │
├─────────────────────────────────────────┤
│  ✓ Arduino Uno (or compatible)         │
│  ✓ MLX90614 Infrared Sensor Module     │
│  ✓ I2C LCD 16x2 Display Module        │
│  ✓ Jumper Wires (Male-to-Male)         │
│  ✓ Breadboard (optional)               │
│  ✓ USB Cable for Arduino               │
└─────────────────────────────────────────┘
```

### Software Requirements / Yazılım Gereksinimleri

- **Arduino IDE** (version 1.8.x or newer)
- **Required Libraries:**
  - `Wire` (built-in)
  - `LiquidCrystal_I2C` by Frank de Brabander
  - `Adafruit MLX90614 Library`
  - `Adafruit Unified Sensor` (dependency)

---

## 🔌 Connection Guide / Bağlantı Kılavuzu

### Step-by-Step Wiring / Adım Adım Bağlantı

#### MLX90614 Sensor Connection / MLX90614 Sensör Bağlantısı

| MLX90614 Pin | Arduino Pin | Color Code / Renk Kodu |
|--------------|-------------|------------------------|
| VIN          | 5V          | 🔴 Red / Kırmızı       |
| GND          | GND         | ⚫ Black / Siyah       |
| SDA          | A4          | 🟢 Green / Yeşil       |
| SCL          | A5          | 🟡 Yellow / Sarı       |

#### I2C LCD Connection / I2C LCD Bağlantısı

| LCD Pin | Arduino Pin | Notes / Notlar |
|---------|-------------|----------------|
| VCC     | 5V          | Power / Güç    |
| GND     | GND         | Ground / Toprak|
| SDA     | A4          | Shared with sensor / Sensörle paylaşılan |
| SCL     | A5          | Shared with sensor / Sensörle paylaşılan |

> 💡 **Tip**: Both devices use I2C, so they share the same SDA and SCL pins. This is normal and expected!
> 
> 💡 **İpucu**: Her iki cihaz da I2C kullandığı için aynı SDA ve SCL pinlerini paylaşır. Bu normal ve beklenen bir durumdur!

### Visual Connection Diagram / Görsel Bağlantı Şeması

```
                    ┌─────────────┐
                    │ Arduino Uno │
                    └──────┬──────┘
                           │
        ┌──────────────────┼──────────────────┐
        │                  │                  │
   ┌────▼────┐        ┌────▼────┐      ┌─────▼─────┐
   │ MLX90614│        │ I2C LCD │      │   USB     │
   │         │        │         │      │  Power    │
   │ VIN → 5V│        │ VCC → 5V│      │           │
   │ GND →GND│        │ GND →GND│      │           │
   │ SDA → A4│◄───────┤ SDA → A4│      │           │
   │ SCL → A5│◄───────┤ SCL → A5│      │           │
   └─────────┘        └─────────┘      └───────────┘
```

---

## 💻 Code Setup / Kod Kurulumu

### Library Installation / Kütüphane Kurulumu

#### Method 1: Arduino Library Manager (Recommended / Önerilen)

1. Open Arduino IDE
2. Navigate to: **Sketch → Include Library → Manage Libraries**
3. Search for each library and click **Install**:
   ```
   📚 LiquidCrystal_I2C
   📚 Adafruit MLX90614 Library
   📚 Adafruit Unified Sensor
   ```

#### Method 2: Manual Installation / Manuel Kurulum

1. Download libraries from GitHub
2. Extract to Arduino libraries folder
3. Restart Arduino IDE

### Uploading the Code / Kodu Yükleme

```bash
# Steps / Adımlar:
1. Connect Arduino via USB
2. Select Board: Tools → Board → Arduino Uno
3. Select Port: Tools → Port → COMx (Windows) or /dev/ttyUSBx (Linux)
4. Click Upload button (→) or press Ctrl+U
```

---

## 🎮 How to Use / Nasıl Kullanılır

### Operation Flow / İşleyiş Akışı

```
┌─────────────┐
│ Power On    │ → Arduino başlatılır
│ / Güç Ver   │
└──────┬──────┘
       │
       ▼
┌─────────────┐
│ Initialize  │ → Sensör ve LCD başlatılır
│ / Başlat    │
└──────┬──────┘
       │
       ▼
┌─────────────┐
│ Display     │ → "HELLO SBTU" ve "GROUP 4" gösterilir
│ Welcome     │
└──────┬──────┘
       │
       ▼
┌─────────────┐
│ Measure     │ → Her saniye sıcaklık ölçülür
│ Temperature │
└──────┬──────┘
       │
       ▼
┌─────────────┐
│ Display     │ → LCD ve Serial Monitor'da gösterilir
│ Results     │
└─────────────┘
```

### Display Outputs / Ekran Çıktıları

#### LCD Screen / LCD Ekran
```
┌──────────────────┐
│ MODULE PROJECT    │ ← Line 1 / Satır 1
│ Temp: 23.45°C    │ ← Line 2 / Satır 2
└──────────────────┘
```

#### Serial Monitor / Serial Monitor
```
MODULE PROJECTTemp: 23.45   °C
MODULE PROJECTTemp: 23.46   °C
MODULE PROJECTTemp: 23.45   °C
...
```

---

## 🔧 Technical Details / Teknik Detaylar

### MLX90614 Specifications / MLX90614 Özellikleri

| Parameter / Parametre | Value / Değer |
|----------------------|---------------|
| **Temperature Range / Sıcaklık Aralığı** | -70°C to +380°C |
| **Accuracy / Doğruluk** | ±0.5°C (at 25°C) |
| **Resolution / Çözünürlük** | 0.02°C |
| **Field of View / Görüş Açısı** | 90° cone |
| **Response Time / Tepki Süresi** | < 1 second |
| **I2C Address / I2C Adresi** | 0x5A (default) |
| **Supply Voltage / Besleme Gerilimi** | 3V - 5V |
| **Current Consumption / Akım Tüketimi** | ~1.5mA |

### I2C LCD Specifications / I2C LCD Özellikleri

| Parameter / Parametre | Value / Değer |
|----------------------|---------------|
| **Display Type / Ekran Tipi** | 16x2 Character LCD |
| **I2C Address / I2C Adresi** | 0x27 (default, can vary) |
| **Backlight / Arka Işık** | LED (adjustable) |
| **Supply Voltage / Besleme Gerilimi** | 5V |
| **Interface / Arayüz** | I2C (2-wire) |

### Arduino Configuration / Arduino Yapılandırması

- **Microcontroller / Mikrodenetleyici**: ATmega328P
- **Operating Voltage / Çalışma Gerilimi**: 5V
- **Clock Speed / Saat Hızı**: 16 MHz
- **Serial Baud Rate / Seri Baud Hızı**: 9600 bps
- **Digital I/O Pins / Dijital G/Ç Pinleri**: 14
- **Analog Input Pins / Analog Giriş Pinleri**: 6

---

## 🐛 Troubleshooting Guide / Sorun Giderme Kılavuzu

### Issue 1: Blank LCD Screen / Boş LCD Ekranı

**Symptoms / Belirtiler:**
- LCD shows nothing
- Backlight may or may not work

**Solutions / Çözümler:**
```cpp
// Check I2C address with scanner:
// I2C adresini scanner ile kontrol edin:
#include <Wire.h>
void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);
  Serial.println("I2C Scanner");
  // ... scanner code
}
```

**Checklist / Kontrol Listesi:**
- [ ] Verify I2C address (try 0x27, 0x3F, 0x20)
- [ ] Check all 4 connections (VCC, GND, SDA, SCL)
- [ ] Ensure 5V power supply
- [ ] Try adjusting contrast potentiometer

### Issue 2: Sensor Returns 0 or Wrong Values / Sensör 0 veya Yanlış Değer Döndürüyor

**Symptoms / Belirtiler:**
- Temperature always shows 0.00°C
- Values don't change
- Negative values when pointing at room temperature

**Solutions / Çözümler:**

1. **Check Wiring / Bağlantıları Kontrol Edin:**
   ```
   MLX90614 SDA → Arduino A4 ✓
   MLX90614 SCL → Arduino A5 ✓
   ```

2. **Verify I2C Communication / I2C İletişimini Doğrulayın:**
   ```cpp
   if (!mlx.begin()) {
     Serial.println("Error connecting to MLX90614");
     while(1);
   }
   ```

3. **Sensor Positioning / Sensör Konumlandırması:**
   - Point sensor directly at object (not empty space)
   - Maintain distance: 1-5 cm for best accuracy
   - Wait 1-2 seconds for stable reading

### Issue 3: Serial Monitor Shows Nothing / Serial Monitor Hiçbir Şey Göstermiyor

**Solutions / Çözümler:**
- [ ] Check baud rate: Must be **9600**
- [ ] Verify USB cable connection
- [ ] Select correct COM port in Arduino IDE
- [ ] Try different USB cable
- [ ] Check if Serial Monitor is open (not just Serial Port)

### Issue 4: Both Devices Not Working / Her İki Cihaz da Çalışmıyor

**Likely Cause / Muhtemel Neden:** I2C bus issue

**Solutions / Çözümler:**
1. Add pull-up resistors (4.7kΩ) to SDA and SCL lines
2. Check for short circuits
3. Verify power supply can handle both devices
4. Try connecting devices one at a time to isolate issue

---

## 📊 Code Explanation / Kod Açıklaması

### Main Components / Ana Bileşenler

```cpp
// Library Includes / Kütüphane Dahilleri
#include <Wire.h>                    // I2C communication
#include <LiquidCrystal_I2C.h>       // LCD control
#include <Adafruit_MLX90614.h>       // Temperature sensor

// Object Initialization / Nesne Başlatma
LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD at address 0x27
Adafruit_MLX90614 mlx;                // Temperature sensor
```

### Setup Function / Setup Fonksiyonu

```cpp
void setup() {
  Serial.begin(9600);    // Start serial communication
  mlx.begin();           // Initialize temperature sensor
  lcd.init();            // Initialize LCD display
  lcd.backlight();       // Turn on LCD backlight
  
  // Display welcome message
  lcd.setCursor(0, 0);
  lcd.print("HELLO SBTU");
  lcd.setCursor(0, 1);
  lcd.print("GROUP 4");
  delay(3000);           // Show for 3 seconds
  lcd.clear();           // Clear screen
}
```

### Loop Function / Loop Fonksiyonu

```cpp
void loop() {
  temp = mlx.readObjectTempC();  // Read temperature in Celsius
  
  // Serial output
  Serial.print("MODULE PROJECT");
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.println("   °C");
  
  // LCD output
  lcd.setCursor(0, 0);
  lcd.print("MODULE PROJECT");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print("°C");
  
  delay(1000);  // Update every second
}
```

---

## 🎓 Learning Resources / Öğrenme Kaynakları

### Concepts Covered / İşlenen Konular

- **I2C Communication Protocol**
  - How multiple devices share same bus
  - Address-based device selection
  - Master-slave communication

- **Infrared Temperature Sensing**
  - Non-contact measurement principles
  - Blackbody radiation theory
  - Sensor calibration and accuracy

- **Arduino Programming**
  - Library usage
  - Serial communication
  - Real-time data display

### Recommended Reading / Önerilen Okumalar

1. **I2C Protocol**: [Arduino I2C Tutorial](https://www.arduino.cc/en/reference/wire)
2. **MLX90614 Datasheet**: Available on Melexis website
3. **LCD Display**: LiquidCrystal_I2C library documentation

---

## 📁 Project Files / Proje Dosyaları

```
arduino-mlx90614-infrared-thermometer/
│
├── 📄 mlx90614_infrared_project.ino    # Main Arduino code
├── 📄 README.md                         # Main documentation
├── 📄 README_ALT.md                     # Alternative documentation (this file)
├── 📊 MODULE PROJECT REPORT.docx        # Detailed project report
├── 📊 MODULE PROJECT.pptx                # Project presentation
└── 🎥 modül.vlog.mp4                     # Project demonstration video
```

---

## 🤝 Contributing / Katkıda Bulunma

This project was developed as part of a module project at Sivas Bilim ve Teknoloji Üniversitesi.

**Group 4 Members:**
- Module Project Team
- SBTU Students

---

## 📝 License / Lisans

This project is licensed under the MIT License - see the LICENSE file for details.

Bu proje MIT Lisansı altında lisanslanmıştır - detaylar için LICENSE dosyasına bakın.

---

## 🙏 Acknowledgments / Teşekkürler

- **Adafruit** for excellent MLX90614 library
- **Frank de Brabander** for LiquidCrystal_I2C library
- **Sivas Bilim ve Teknoloji Üniversitesi (SBTU)** for academic support
- **Arduino Community** for continuous support and resources

---

## 📞 Support / Destek

For questions, issues, or contributions:

**English:** Please open an issue on the repository or contact the development team.

**Türkçe:** Sorularınız için lütfen repository'de bir issue açın veya geliştirme ekibiyle iletişime geçin.

---

<div align="center">

**Made with ❤️ by Group 4 - SBTU**

*Last Updated: 2024 | Version: 1.0*

</div>

