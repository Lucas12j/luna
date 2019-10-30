#include <Ultrasonic.h>

#define trigger 9
#define echo 8

float dist;
long randon;
int select;
int randon2;


Ultrasonic ultrasonic(trigger, echo); 

int var;

void setup() 
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);  
  pinMode(12, OUTPUT); 
  pinMode(11, OUTPUT); 
  pinMode(10, OUTPUT); 
  randomSeed(analogRead(A0));

  
}

void loop() 
{
  
if (Serial.available() > 0)
{
var = Serial.read();

if ( var=='A')
{
  select = 1;
}
if (var =='B')
{
  select = 2;
  }


while (select == 1)
{            
  
             var = Serial.read();
             long microsec = ultrasonic.timing();
             dist = ultrasonic.convert(microsec, Ultrasonic::CM);

           
           if( dist > 22 && select == 1)
         {
             
             var = Serial.read();
             if (var =='B'){select = 2;}
             Serial.println("maior 15");
            
             digitalWrite(12,0);
             digitalWrite(13,1);
             digitalWrite(11,0);
             digitalWrite(10,1);

             long microsec = ultrasonic.timing();
             dist = ultrasonic.convert(microsec, Ultrasonic::CM);
              
        
         }
          
            if ( dist <= 22 && select == 1)
         {    
              randon = random(2);
              randon2 = random(5,15);
              var = Serial.read();
              if (var =='B'){select = 2;}
   
              Serial.println("menor 15");
              digitalWrite(12,0);
              digitalWrite(13,0);
              digitalWrite(11,0);
              digitalWrite(10,0);
              delay(400);


            

            if (randon == 0 && select == 1)
           {  Serial.println("randon 0");
             
             var = Serial.read();
             if (var =='B'){select = 2;}

             
              digitalWrite(12,1);
              digitalWrite(13,0);
              digitalWrite(11,1);
              digitalWrite(10,0);
              delay(700);
              digitalWrite(12,1);
              digitalWrite(13,0);
              digitalWrite(11,0);
              digitalWrite(10,1);
              delay(randon2*100);
           

            }
            if (randon == 1 && select == 1)
            {
              Serial.println("randon 1");
               long microsec = ultrasonic.timing();
                dist = ultrasonic.convert(microsec, Ultrasonic::CM);
                var = Serial.read();
                if (var =='B'){select = 2;}
           
              digitalWrite(12,1);
              digitalWrite(13,0);
              digitalWrite(11,1);
              digitalWrite(10,0);
              delay(700);
               digitalWrite(12,0);
               digitalWrite(13,1);
               digitalWrite(11,1);
               digitalWrite(10,0);
               delay(randon2*100);    
               
            }


             long microsec = ultrasonic.timing();
             dist = ultrasonic.convert(microsec, Ultrasonic::CM);
            
         }   
      
var = Serial.read();
if (var =='B'){select = 2;}
      
      
   
}

if (select == 2)
{
   Serial.println("B");    

  switch (var)
{
   case 'E':
 
   digitalWrite(12,1);
   digitalWrite(13,0);
   digitalWrite(11,0);
   digitalWrite(10,1);
   break;

   case 'D':

   digitalWrite(12,0);
   digitalWrite(13,1);
   digitalWrite(11,1);
   digitalWrite(10,0);
   break;

   case 'R':
    
   digitalWrite(12,1);
   digitalWrite(13,0);
   digitalWrite(11,1);
   digitalWrite(10,0);
   break;

   case 'F':
   
   digitalWrite(12,0);
   digitalWrite(13,1);
   digitalWrite(11,0);
   digitalWrite(10,1);
   break;

   case '*':
  
   digitalWrite(12,0);
   digitalWrite(13,0);
   digitalWrite(11,0);
   digitalWrite(10,0);
   break;

}
}
}
  }   
