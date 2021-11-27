int cdsValue;
void setup()
{

  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop()
{
  cdsValue = analogRead(A0) / 4;
  Serial.print("cds = ");
  Serial.println(cdsValue);
  if(cdsValue >= 50 && cdsValue != 0){
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
  }
  else{
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  delay(1000);
}
