This project is about Portable Ground Station
Compile with version  Arduino-1.5.7 
Library used  UTFU  v2.78
Hardware used Arduino DUE , 3.2" TFT LCD 400x240 (16bit parallel bus interface )

*****note******
library need to edit file HW_ARM_defines.h 
by uncomment #define CTE_DUE_SHIELD 1\
arduino due configure is  UTFT myGLCD(CTE32W,25,26,27,28);

file description 
complete_file.ino : merge between interface and  recieve for actual uasge 
interface.ino          : Design and test screen performance 
recieve_merge      : Design custom protocol to communicate with MavLink gateway
performance_tester  : Test performance of arduino DUE , Arduino Mega2560 

##Web blog : http://turkkytothong.blogspot.com/
##GitHub     : https://github.com/TurkkyTothong/portablegroundstation

