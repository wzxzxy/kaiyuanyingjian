void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  int a[4];
  int income,i;
  if (Serial.available()>0)
  {
    income=Serial.read()-'0';
  
  for(i=0;i<4;i++)
  {
    a[i]=income%2;
    income/=2;
    if(a[i]==1)
    {
       digitalWrite(i+2,HIGH);
    }
    else
    {
       digitalWrite(i+2,LOW);
    }
  }
  }
}
