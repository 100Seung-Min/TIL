void setup()
{

  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop()
{
  int cdsValue = analogRead(A0);
  Serial.print("cds = ");
  Serial.println(cdsValue);
  delay(1000);
}
