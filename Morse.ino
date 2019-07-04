#include <Morse.h>
Morse morse(13);
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
      if(mstr[i]=='.')morse.dot();
      else if(mstr[i] == '-')morse.dash();
      else if(mstr[i] == ' ')morse.c_space();
      else if(mstr[i] == '/')morse.w_space();
      if(mstr[i]=='\0') break;
    }
    Serial.println("发送完毕");
    delay(5);
  }
}
