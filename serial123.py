import serial
import matplotlib.pyplot as plt
import numpy as np
import csv

csvfile = open('data_log.csv', 'wb') #open file for operation
writer = csv.writer(csvfile) 

ser = serial.Serial("/dev/ttyACM0", 9600)
#ser = serial.Serial("/dev/rfcomm0", 9600)
a=0 
while a!=120:
    print ser.readline()    
    k = ser.readline()
    angle,vin,vfin = k.split(",")
    angle = float(angle)
    vin = float(vin) 				#assumption for relating velocity and bike's tilt- 
    vfin = float(vfin)
    accel =( vfin - vin )/4  #this makes acceleration = vfinal - vinitial with t=1/4 sec
    accel =  float(accel)
    writer.writerow([angle, vin,vfin, accel])    
    if vel>45 :        
       writer.writerow([angle, vin,vfin, accel,"LIMIT CROSSED!"])   
    else :      
       writer.writerow([angle, vin,vfin, accel,"speed under control"])
    a = a+1
# Close opend file
csvfile.close()    
#plt.plot(k)
#plt.show()    

