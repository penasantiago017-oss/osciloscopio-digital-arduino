#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa la pantalla LCD en la direccion 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

int pinSeñal = A0; // Pin donde se lee la señal analógica
int valorAnalogico = 0;
float voltaje = 0.0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
  // Mensaje de bienvenida
  lcd.setCursor(0, 0);
  lcd.print("  Osciloscopio  ");
  lcd.setCursor(0, 1);
  lcd.print("   Digital   ");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Lee el valor del pin analógico
  valorAnalogico = analogRead(pinSeñal);
  
  // Convierte el valor a voltaje (0 a 5V)
  voltaje = (valorAnalogico * 5.0) / 1023.0;
  
  // Muestra los datos en el Monitor Serial
  Serial.print("Valor: ");
  Serial.print(valorAnalogico);
  Serial.print(" | Voltaje: ");
  Serial.println(voltaje);
  
  // Muestra los datos en la pantalla LCD
  lcd.setCursor(0, 0);
  lcd.print("Signal: ");
  lcd.print(valorAnalogico);
  lcd.print("     "); // Limpia espacios vacíos
  
  lcd.setCursor(0, 1);
  lcd.print("Volt: ");
  lcd.print(voltaje);
  lcd.print(" V   ");
  
  delay(200); // Pequeño retraso para estabilidad visual
}
