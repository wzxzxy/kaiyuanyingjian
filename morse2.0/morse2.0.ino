int _pin=13;
int _dottime=250;
char MORSE[][4] = 
{
  {'.', '-', '*', '*'}, //a
  {'-', '.', '.', '.'}, //b
  {'-', '.', '-', '.'}, //c
  {'-', '.', '.', '*'}, //d
  {'.', '*', '*', '*'}, //e
  {'.', '.', '-', '.'}, //f
  {'-', '-', '.', '*'}, //g
  {'.', '.', '.', '.'}, //h
  {'.', '.', '*', '*'}, //i
  {'.', '-', '-', '-'}, //j
  {'-', '.', '-', '*'}, //k
  {'.', '-', '.', '.'}, //l
  {'-', '-', '*', '*'}, //m
  {'-', '.', '*', '*'}, //n
  {'-', '-', '-', '*'}, //o
  {'.', '-', '-', '.'}, //p
  {'-', '-', '.', '-'}, //q
  {'.', '-', '.', '*'}, //r
  {'.', '.', '.', '*'}, //s
  {'-', '*', '*', '*'}, //t
  {'.', '.', '-', '*'}, //u
  {'.', '.', '.', '-'}, //v
  {'.', '-', '-', '*'}, //w
  {'-', '.', '.', '-'}, //x
  {'-', '.', '-', '-'}, //y
  {'-', '-', '.', '.'}  //z
};

void setup()
{
   pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  String str="\0";  
  String mstr="\0"; 
  int i,t,flag=0;
  while (Serial.available())
  {
    flag=1; 
    str+=char(Serial.read()); 
    delay(5);
  }

  if(flag)
  {
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='a'&&str[i]<='z')
        {
          for(t=0;t<4;t++)
         {
            mstr+=char(MORSE[int(str[i]-97)][t]);
         }
         if((str[i+1]!='\0')&&(str[i+1]!=' '))
          mstr+=' ';
        }
         if(str[i]==' ')
         mstr+='/';
    }
    flag=0;
    Serial.println(mstr); 
    for(i=0;;i++)
    {
      if(mstr[i]=='.')
      {
  digitalWrite(_pin,HIGH);
  delay(_dottime);
  digitalWrite(_pin,LOW);
  delay(_dottime);
      }
      else if(mstr[i] == '-')
      {
  digitalWrite(_pin,HIGH);
  delay(_dottime*4);
  digitalWrite(_pin,LOW);
  delay(_dottime);
      }
      else if(mstr[i] == ' ')
      {
  digitalWrite(_pin,LOW);
  delay(_dottime*3);
      }
      else if(mstr[i] == '/')
      {
  digitalWrite(_pin,LOW);
  delay(_dottime*7);
      }
      if(mstr[i]=='\0') break;
    }
    Serial.println("ok");
    delay(5);
  }

}
