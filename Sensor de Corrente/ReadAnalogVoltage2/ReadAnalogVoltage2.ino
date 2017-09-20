#include "EmonLib.h" // Include Emon Library
EnergyMonitor emon1; // Create an instance

void setup()
{
Serial.begin(9600);

emon1.current(A4, 97.5); // Current: input pin, calibration.
}

void loop()
{
double Irms = emon1.calcIrms(3000); // Calculate Irms only

Serial.print("Potencia: ");
Serial.print(Irms*220.0); // Apparent power
Serial.print("\t Corrente: ");
Serial.println(Irms); // Irms
}
