EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 1250 1350 1550 800 
U 628F83A4
F0 "Supply" 50
F1 "supply.sch" 50
$EndSheet
$Sheet
S 8550 2400 1200 600 
U 628F8524
F0 "Microcontroller" 50
F1 "microcontroller.sch" 50
F2 "SDA" B L 8550 2650 50 
F3 "SCL" O L 8550 2750 50 
$EndSheet
$Sheet
S 3700 4650 1450 850 
U 628F8563
F0 "Codec" 50
F1 "codec.sch" 50
$EndSheet
$Sheet
S 5600 3750 1150 1050
U 628F85AD
F0 "Amplifier" 50
F1 "amplifier.sch" 50
$EndSheet
$Sheet
S 1500 3500 1150 1950
U 628F8AC6
F0 "Input" 50
F1 "input.sch" 50
$EndSheet
$Comp
L Device:R_Small R?
U 1 1 62AF22EA
P 8150 2400
F 0 "R?" H 8209 2446 50  0000 L CNN
F 1 "R_Small" H 8209 2355 50  0000 L CNN
F 2 "" H 8150 2400 50  0001 C CNN
F 3 "~" H 8150 2400 50  0001 C CNN
	1    8150 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 62AF2ABF
P 7750 2400
F 0 "R?" H 7809 2446 50  0000 L CNN
F 1 "R_Small" H 7809 2355 50  0000 L CNN
F 2 "" H 7750 2400 50  0001 C CNN
F 3 "~" H 7750 2400 50  0001 C CNN
	1    7750 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 2750 8150 2750
Wire Wire Line
	7600 2650 7750 2650
Wire Wire Line
	8150 2500 8150 2750
Connection ~ 8150 2750
Wire Wire Line
	7750 2500 7750 2650
Connection ~ 7750 2650
Wire Wire Line
	7750 2650 8550 2650
Wire Wire Line
	8150 2750 8550 2750
$Comp
L power:+3V3 #PWR?
U 1 1 62AF3485
P 7750 2200
F 0 "#PWR?" H 7750 2050 50  0001 C CNN
F 1 "+3V3" H 7765 2373 50  0000 C CNN
F 2 "" H 7750 2200 50  0001 C CNN
F 3 "" H 7750 2200 50  0001 C CNN
	1    7750 2200
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 62AF38AD
P 8150 2200
F 0 "#PWR?" H 8150 2050 50  0001 C CNN
F 1 "+3V3" H 8165 2373 50  0000 C CNN
F 2 "" H 8150 2200 50  0001 C CNN
F 3 "" H 8150 2200 50  0001 C CNN
	1    8150 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 2200 8150 2300
Wire Wire Line
	7750 2200 7750 2300
$EndSCHEMATC
