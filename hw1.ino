#include<LiquidCrystal.h>
#include<MsTimer2.h>


LiquidCrystal lcd(12, 11,  5, 4, 3, 2); 
int h,m,s;
int test,t;
int wordn = 0;
#define MAXword 40
#define ROW(x) (x / 2)
#define COL(x) (x % 20)
int i ;
char ti[8];


void setup() 
{
Serial.begin(9600);
Serial.println("04050343  04050794");
lcd.begin(20, 2); 
lcd.cursor(); // 游標
lcd.blink(); // 游標閃爍
lcd.home();
pinMode(13,OUTPUT);
MsTimer2::set(1000,ccutt);
MsTimer2::start();

}
void ccutt()
{
  ti[2]=':';
  ti[5]=':';
  
  int i=0,k;
  lcd.home();
  lcd.write(ti);
  for(i=0;i<8;i++)
  {
    if(i==2 || i==5)
    {
      Serial.print(ti[i]);
   //   lcd.write(ti[i]);
    }
    else
      {
      Serial.print(ti[i]);
//      lcd.write(ti[i]);
      }
   
   }
  Serial.println();

  if(ti[7]=='0')
   {
     ti[7]='9';
     if(ti[6]=='0')
      {
        ti[6] = '5';
        ///////
            if(ti[4]=='0')
               {
                 ti[4]='9';
                 if(ti[3]=='0')
                  {
                    ti[3] = '5';
/////////////////////////////
                              if(ti[1]=='0')
                                 {
                                 ti[1]='3';
                                 if(ti[0]=='0')
                                  {
                                   // ti[0] = '2';
                                     MsTimer2::stop();
                                     digitalWrite(13,HIGH);
                                  }
                                  else
                                  {
                                    ti[0]=ti[0]-1;
                                    }
                                    
                               }
                               else
                               {
                                ti[1]=ti[1]-1;
                                }
////////////////////////////////                    
                  }
                  else
                  {
                    ti[3]=ti[3]-1;
                    }
                    
               }
               else
               {
                ti[4]=ti[4]-1;
                }



        ///////
      }//秒結束
      else
      {
        ti[6]=ti[6]-1;
        }
        
   }//秒
   else
   {
    ti[7]=ti[7]-1;
    }

    

}

void loop()
{
  int k;

   while(Serial.available())
  {   
    ti[i]=Serial.read();
    i=i+1;
   }

}
