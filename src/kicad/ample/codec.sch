EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title "CS42528"
Date "2022-06-02"
Rev "00.01"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 5800 1900 0    200  Italic 0
Codec
Text Notes 5850 2150 0    100  ~ 0
I²C Address: 0b10011nn(r/w)
$Comp
L power:GND #PWR?
U 1 1 629B73A3
P 4500 4600
F 0 "#PWR?" H 4500 4350 50  0001 C CNN
F 1 "GND" H 4505 4427 50  0000 C CNN
F 2 "" H 4500 4600 50  0001 C CNN
F 3 "" H 4500 4600 50  0001 C CNN
	1    4500 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 4500 4500 4600
Wire Wire Line
	4500 4200 4500 4300
Connection ~ 4500 4200
Wire Wire Line
	4500 4150 4500 4200
Wire Wire Line
	3750 4200 4500 4200
$Comp
L Device:C_Small C?
U 1 1 629B6CBD
P 4500 4400
F 0 "C?" H 4592 4446 50  0000 L CNN
F 1 "C_Small" H 4592 4355 50  0000 L CNN
F 2 "" H 4500 4400 50  0001 C CNN
F 3 "~" H 4500 4400 50  0001 C CNN
	1    4500 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 629B595B
P 4500 4050
F 0 "R?" H 4559 4096 50  0000 L CNN
F 1 "R_Small" H 4559 4005 50  0000 L CNN
F 2 "" H 4500 4050 50  0001 C CNN
F 3 "~" H 4500 4050 50  0001 C CNN
	1    4500 4050
	1    0    0    -1  
$EndComp
NoConn ~ 5750 3300
NoConn ~ 5750 3200
NoConn ~ 5750 3100
NoConn ~ 6600 5100
NoConn ~ 6700 5100
NoConn ~ 6800 5100
NoConn ~ 6900 5100
NoConn ~ 7200 5100
NoConn ~ 7300 5100
NoConn ~ 7400 5100
NoConn ~ 7500 5100
NoConn ~ 7600 5100
NoConn ~ 7700 5100
NoConn ~ 7800 5100
NoConn ~ 8400 4550
$Comp
L cs42528:CS42528 U?
U 1 1 629ACE8A
P 5850 2650
F 0 "U?" H 8444 1521 50  0000 L CNN
F 1 "CS42528" H 8444 1430 50  0000 L CNN
F 2 "Package_QFP:LQFP-64_10x10mm_P0.5mm" H 8800 150 50  0001 C CNN
F 3 "" H 5900 2700 50  0001 C CNN
	1    5850 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 4200 5750 4200
$Comp
L eec2:TORX1350AF U?
U 1 1 629BADCD
P 700 1000
F 0 "U?" H 1500 1265 50  0000 C CNN
F 1 "TORX1350AF" H 1500 1174 50  0000 C CNN
F 2 "Toshiba-TORX1350AF-*" H 700 1400 50  0001 L CNN
F 3 "https://toshiba.semicon-storage.com/info/docget.jsp?did=35629&prodName=TORX1350A(F)" H 700 1500 50  0001 L CNN
F 4 "No" H 700 1600 50  0001 L CNN "automotive"
F 5 "IC" H 700 1700 50  0001 L CNN "category"
F 6 "Optoelectronics" H 700 1800 50  0001 L CNN "device class L1"
F 7 "Fiber Optics" H 700 1900 50  0001 L CNN "device class L2"
F 8 "unset" H 700 2000 50  0001 L CNN "device class L3"
F 9 "OPTICAL LINK RECEIVING MODULE 10" H 700 2100 50  0001 L CNN "digikey description"
F 10 "TORX1350A(F)-ND" H 700 2200 50  0001 L CNN "digikey part number"
F 11 "8.8mm" H 700 2300 50  0001 L CNN "height"
F 12 "Yes" H 700 2400 50  0001 L CNN "lead free"
F 13 "228871f278280f59" H 700 2500 50  0001 L CNN "library id"
F 14 "Toshiba" H 700 2600 50  0001 L CNN "manufacturer"
F 15 "5.25V" H 700 2700 50  0001 L CNN "max supply voltage"
F 16 "4.75V" H 700 2800 50  0001 L CNN "min supply voltage"
F 17 "757-TORX1350AF" H 700 2900 50  0001 L CNN "mouser part number"
F 18 "2mA" H 700 3000 50  0001 L CNN "output current"
F 19 "OPTIC_RECIEVER_13MM0_13MM5" H 700 3100 50  0001 L CNN "package"
F 20 "Yes" H 700 3200 50  0001 L CNN "rohs"
F 21 "0.2-100m" H 700 3300 50  0001 L CNN "sensing distance"
F 22 "0.1mm" H 700 3400 50  0001 L CNN "standoff height"
F 23 "+85°C" H 700 3500 50  0001 L CNN "temperature range high"
F 24 "-40°C" H 700 3600 50  0001 L CNN "temperature range low"
	1    700  1000
	1    0    0    -1  
$EndComp
$EndSCHEMATC
