/*

/*
ADXL335
note:vcc-->5v ,but ADXL335 Vs is 3.3V
The circuit:
      5V: VCC
analog 1: x-axis
analog 2: y-axis
analog 3: z-axis
*/
/*
int xout = A1;

int yout = A2;

int zout = A3;                 // z-axis (only on 3-axis models)

int LDR = A0 ;

int out1 = 0;       
int out2 = 0;     
int out3 = 0;      
int LDRout = 0 ;

void setup()
{
 // initialize the serial communications:
 pinMode(xout, INPUT);
 pinMode(yout, INPUT);
 pinMode(zout, INPUT);
 pinMode(LDR, INPUT);

 Serial.begin(9600);
}

void loop() {

  out1 = analogRead(xout);           
  out2 = analogRead(yout);      
  out3 = analogRead(zout);    
  LDRout = analogRead(LDR) ;       
  Serial.print(" " );                      
  Serial.print(out1);   
  //printf("\n") ;  
  
  Serial.print(" " );                      
  Serial.print(out2);     

  //printf("\n") ;
  
  Serial.print("  ");     
  Serial.println(out3);
  Serial.print(”  angle = “);
  Serial.println(constrain(map(x,349,281,0,90),0,90)); 
  //Serial.print("  ");     
  //Serial.println(LDRout);  

}


                       
//Serial.print(((float)x - 331.5)/65*9.8);  //print x value on serial monitor
//Serial.print("\t");
//Serial.print(((float)y - 329.5)/68.5*9.8);  //print y value on serial monitor
//Serial.print("\t");
//Serial.print(((float)z - 340)/68*9.8);  //print z value on serial monitor
//Serial.print("\n");
//delay(500);

*/


/*
#define ADC_ref 2.56

   

  #define zero_x 1.569

   

  #define zero_y 1.569

   

  #define zero_z 1.569

   

  #define sensitivity_x 0.3

   

  #define sensitivity_y 0.3

   

  #define sensitivity_z 0.3

   

  unsigned int value_x;

  unsigned int value_y;

  unsigned int value_z;

   

  float xv;

  float yv;

  float zv;

   

  float angle_x;

  float angle_y;

  float angle_z;

   

  void setup()   {

   

//  analogReference(INTERNAL2V56);

   

  Serial.begin(9600);

   

  }

   

  void loop() {

   

  value_x = analogRead(1);

  value_y = analogRead(2);

  value_z = analogRead(3);

   

  xv=(value_x/1024.0*ADC_ref-zero_x)/sensitivity_x;

   

 // Serial.print ("x= ");

 // Serial.print (xv);

 // Serial.print(" g ");

   

  yv=(value_y/1024.0*ADC_ref-zero_y)/sensitivity_y;

   

  Serial.print ("y= ");

  Serial.print (yv);

 Serial.print(" g ");

   

//  zv=(value_z/1024.0*ADC_ref-zero_z)/sensitivity_z;

   

 // Serial.print ("z= ");

 // Serial.print (zv);

 // Serial.print(" g ");

   

 // Serial.print("\n");

   

  //Serial.print("Rotation ");

   

 // Serial.print("x= ");

   

  //angle_x =atan2(-yv,-zv)*57.2957795+180;

   

  //Serial.print(angle_x);
  //Serial.print(xv);

  //Serial.print(" deg");

  //Serial.print(" ");

   

  ///Serial.print("y= ");

   

 // angle_y =atan2(-xv,-zv)*57.2957795+180;

   

  //Serial.print(angle_y);
//Serial.print(angle_y);
 // Serial.print(" deg");

  //Serial.print(" ");

   

 /// Serial.print("z= ");

   

 // angle_z =atan2(-yv,-xv)*57.2957795+180;

   

//  Serial.print(angle_z);
 // Serial.print(zv);

  //Serial.print(" deg");

  
   
  Serial.print("\n");
//
  
 

 // delay(1000);

  //delay(500);

  }

  */
  int xout = A0;

int yout = A1;

int zout = A2;                 // z-axis (only on 3-axis models)

int pot= A4 ;

int LDR = A0 ;

int out1 = 0;       
int out2 = 0;     
int out3 = 0;
int inpot = 0;
int finpot = 0;   
float time_t ; 
float result ;
float accel_angle_x ;
float val ; 
float acc ;
float velocity;
float angle;
void setup()
{
 // initialize the serial communications:   
 pinMode(xout, INPUT);
 pinMode(yout, INPUT);
 pinMode(zout, INPUT);
 pinMode(pot, INPUT);

 Serial.begin(9600);
}

void loop() {

  out1 = analogRead(xout);           
   delay(10);
  //out2 = analogRead(yout);      
  //out3 = analogRead(zout); 
  inpot = analogRead(pot)/10 ;
//  time_t = hour();
 delay(250);
 finpot = analogRead(pot)/10 ;

 //angle = (out1-337.92)/61.44*9.81 ;
 
   Serial.print(out1-337.92)/61.44*9.81 ;
   Serial.print(",");              //seperator 
    //Serial.println(inpot) ;
    Serial.print(inpot) ;
    Serial.print(",");              //seperator 
    Serial.println(finpot) ;
  delay(100);
  //Serial.println(out1) ;
    //Serial.println(inpot) ;


 //Serial.println(" ") ;
 //Serial.println(time_t) ;
// Serial.println("\n") ;
//Serial.println(out2) ;
 //https://arduino.stackexchange.com/questions/13887/xl335b-accelerometer-reports-false-readings
  
  //Serial.println(out1);
  /*
  result=sqrt((out2*out2)+(out1*out1));
   val=(out1*3.3/1024)/result;
   accel_angle_x = atan(val);
  Serial.print(" angle.:- ");
  Serial.println(accel_angle_x*57.32);
  delay(150) ;                    
    //limit - 341 - rest, 271- tilted to 90 deg (y axis moved)
  //printf("\n") ;
   */ 
   //Sdelay(100) ;
}
