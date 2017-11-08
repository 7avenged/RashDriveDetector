import serial
import matplotlib.pyplot as plt
import numpy as np
import csv

csvfile = open('data_log.csv', 'wb') #open file for operation
writer = csv.writer(csvfile) 

ser = serial.Serial("/dev/ttyACM1", 9600)
#ser = serial.Serial("/dev/rfcomm0", 9600)
a=0 
while a!=120:
    print ser.readline()    
    k = ser.readline()
    angle,vin,vfin = k.split(",")
    angle = float(angle)
    vin = float(vin) 				#assumption for relating velocity and bike's tilt- 
    vfin = float(vfin)
    accel =( vfin - vin )#/4  #this makes acceleration = vfinal - vinitial with t=1/4 sec
    accel =  float(accel)

    thresh = angle/(vin+0.01) #incase the velocity is zero
    if thresh > 2:
       tempthresh = "Excess tilt of bike(A0) "
    else:
       tempthresh = " - "   
    #writer.writerow([angle, vin,vfin, accel])    
    if vin>45 :   
       tempvin = "SPEED LIMIT CROSSED!(A1)"
          
       #writer.writerow([angle, vin,vfin, accel,"SPEED LIMIT CROSSED!(A1)"])   
    else :
       tempvin = "-"           
       #writer.writerow([angle, vin,vfin, accel,"-"])
    if vin <1:  #for initial sudden accelration
       if accel > 1: #some random acceleration threshold
          tempaccel = "sudden acceleration(A2)"
          #tempvin = "-"    
          #writer.writerow([angle, vin,vfin, accel,"LIMIT CROSSED!","sudden acceleration(A2)"]) 
       else :
          tempaccel = "-"
          #tempvin = "-" 
          #tempthresh="-" 
    else :
       #tempvin = "-"
       tempaccel = "-"      
          #writer.writerow([angle, vin,vfin, accel,"LIMIT CROSSED!","-"])	
    if vfin<1:    #for initial sudden deaccelration
         if accel<0.1: #some random deacceleration threshold
            tempdeaccel = " sudden stop(A3) "
            #tempaccel = "-"
            #tempvin = "-" 
         else:
            tempdeaccel = " - "
            #tempaccel = "-"
            #tempvin = "-" 
            #writer.writerow([angle, vin,vfin, accel,"LIMIT CROSSED!"," sudden stop(A3) "])
    else:
       #tempvin = "-"
       #tempaccel = "-"
       tempdeaccel = "-"  
       #tempthresh="-"
        
    writer.writerow([angle, vin,vfin, accel,thresh," ",tempvin,tempaccel,tempdeaccel,tempthresh ])
              
    a = a+1
# Close opend file
csvfile.close()    
#plt.plot(k)
#plt.show()    

