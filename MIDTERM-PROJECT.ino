int Vin = 5;
int res1 = 0;
int res2 = 0;
int res3 = 0;
float Vout1 = 0;
float Vout2 = 0;
float Vout3 = 0;
float R0 = 1000,
      R1 = 0,
      R2 = 0,
      R3 = 0;
float out12 = 0,
      out23 = 0,
      out13 = 0,
      ResSum = 0;
float buffer = 0;


void setup() 
{

    Serial.begin(9600);

}

void loop() 
{
  res1=analogRead ( A0 );
  res2=analogRead ( A1 );
  res3=analogRead ( A2 );

Vout1 = (res1 * Vin)/1024.0;
Vout2 = (res2 * Vin)/1024.0;
Vout3 = (res3 * Vin)/1024.0;

R1 = R0*( (Vout2/Vout1) -1);
R2 = R0*( (Vout3/Vout1) -1) - R1;
R3 = R0*( (Vin/Vout1) -1) -R1 -R2;

ResSum = R1 + R2 + R3;
out12 = (R1 * R2)/ResSum;
out23 = (R2 * R3)/ResSum;
out13 = (R1 * R3)/ResSum;

Serial.println();
Serial.println();
Serial.println();
Serial.print("Rab: ");
Serial.println(R1);
Serial.print("Rbc: ");
Serial.println(R2);
Serial.print("Rac: ");
Serial.println(R3);

Serial.println();
Serial.println();
Serial.println();

Serial.print("Ra: ");
Serial.println(out13);

Serial.print("Rb: ");
Serial.println(out12);

Serial.print("Rc: ");
Serial.println(out23);

delay(10000);
}                    
