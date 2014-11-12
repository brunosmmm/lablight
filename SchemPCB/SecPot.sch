EESchema Schematic File Version 2  date Qui 19 Abr 2012 11:39:50 BRT
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:Capacitores
LIBS:CircuitosIntegrados
LIBS:Conectores
LIBS:Cristais
LIBS:Diodos
LIBS:Leds
LIBS:Misc
LIBS:Resistores
LIBS:Transistores
LIBS:LabLight-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 2 4
Title ""
Date "19 apr 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 3100 5700 0    60   ~ 0
Ventoinha de resfriamento sistema\n(sempre ligada)
Text Notes 3100 2600 0    60   ~ 0
Controle LED de potência
Text Notes 7100 2600 0    60   ~ 0
Controle ventoinha de resfriamento do LED
Text Notes 10100 7300 0    60   ~ 12
Bruno Morais\nbrunosmmm@gmail.com
Text Label 9150 4050 1    60   ~ 0
FOUT
Text Label 4700 3800 3    60   ~ 0
LEDOUT
$Comp
L +12V #PWR201
U 1 1 4EEB5A82
P 2800 5650
F 0 "#PWR201" H 2800 5600 20  0001 C CNN
F 1 "+12V" H 2800 5750 30  0000 C CNN
	1    2800 5650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR202
U 1 1 4EEB5A78
P 2800 6350
F 0 "#PWR202" H 2800 6350 30  0001 C CNN
F 1 "GND" H 2800 6280 30  0001 C CNN
	1    2800 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 6350 2800 6100
Wire Wire Line
	2800 6100 3100 6100
Wire Wire Line
	7750 3850 8050 3850
Wire Wire Line
	9150 4700 9150 4500
Wire Wire Line
	9150 4500 9400 4500
Wire Wire Line
	9400 4300 9150 4300
Wire Wire Line
	9150 4300 9150 3300
Wire Wire Line
	9150 3300 8550 3300
Connection ~ 2500 3300
Wire Wire Line
	2500 3300 2500 3850
Wire Wire Line
	2500 3850 2650 3850
Wire Wire Line
	9100 3000 8550 3000
Wire Wire Line
	7400 3150 6900 3150
Wire Wire Line
	5000 4300 4700 4300
Wire Wire Line
	5100 3750 5100 4000
Wire Wire Line
	4900 3000 4200 3000
Wire Wire Line
	2350 3150 3050 3150
Wire Wire Line
	1800 3000 3050 3000
Wire Wire Line
	3050 3300 2350 3300
Wire Wire Line
	4200 3150 5100 3150
Wire Wire Line
	5100 3150 5100 3250
Wire Wire Line
	4200 3300 4700 3300
Wire Wire Line
	4700 3300 4700 4300
Wire Wire Line
	5000 4500 4700 4500
Wire Wire Line
	4700 4500 4700 4700
Wire Wire Line
	6500 3000 7400 3000
Wire Wire Line
	7400 3300 6850 3300
Wire Wire Line
	8550 3150 9500 3150
Wire Wire Line
	9500 3150 9500 3300
Wire Wire Line
	3550 3850 3150 3850
Wire Wire Line
	9500 3800 9500 4000
Wire Wire Line
	7250 3850 7000 3850
Wire Wire Line
	7000 3850 7000 3300
Connection ~ 7000 3300
Wire Wire Line
	3100 5900 2800 5900
Wire Wire Line
	2800 5900 2800 5650
$Comp
L CONN_2 P201
U 1 1 4EEB5A66
P 3450 6000
F 0 "P201" V 3400 6000 40  0000 C CNN
F 1 "CASEFAN" V 3500 6000 40  0000 C CNN
	1    3450 6000
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR206
U 1 1 4EEB55DC
P 8050 3850
F 0 "#PWR206" H 8050 3800 20  0001 C CNN
F 1 "+12V" H 8050 3950 30  0000 C CNN
	1    8050 3850
	0    1    1    0   
$EndComp
$Comp
L R R203
U 1 1 4EEB55C4
P 7500 3850
F 0 "R203" V 7580 3850 50  0000 C CNN
F 1 "10k" V 7500 3850 50  0000 C CNN
	1    7500 3850
	0    1    1    0   
$EndComp
$Comp
L GND #PWR207
U 1 1 4EEB55BD
P 9150 4700
F 0 "#PWR207" H 9150 4700 30  0001 C CNN
F 1 "GND" H 9150 4630 30  0001 C CNN
	1    9150 4700
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P203
U 1 1 4EEB55B5
P 9750 4400
F 0 "P203" V 9700 4400 40  0000 C CNN
F 1 "LEDFAN" V 9800 4400 40  0000 C CNN
	1    9750 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR208
U 1 1 4EEB55B2
P 9500 4000
F 0 "#PWR208" H 9500 4000 30  0001 C CNN
F 1 "GND" H 9500 3930 30  0001 C CNN
	1    9500 4000
	1    0    0    -1  
$EndComp
Text GLabel 3550 3850 2    60   Input ~ 0
LEDVCC
$Comp
L R R201
U 1 1 4EEB5595
P 2900 3850
F 0 "R201" V 2980 3850 50  0000 C CNN
F 1 "10k" V 2900 3850 50  0000 C CNN
	1    2900 3850
	0    1    1    0   
$EndComp
$Comp
L R R204
U 1 1 4EEB5591
P 9500 3550
F 0 "R204" V 9580 3550 50  0000 C CNN
F 1 "1k" V 9500 3550 50  0000 C CNN
	1    9500 3550
	1    0    0    -1  
$EndComp
Text Label 9100 3000 2    60   ~ 0
Q2GQ1DF
Text Label 6850 3300 0    60   ~ 0
Q2GQ1DF
Text HLabel 6500 3000 0    60   Input ~ 0
FCONTROL
$Comp
L FDC6420C U202
U 1 1 4EEB5550
P 8000 3150
F 0 "U202" H 7750 3450 60  0000 C CNN
F 1 "FDC6420C" H 7900 2850 60  0000 C CNN
	1    8000 3150
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR205
U 1 1 4EEB51D4
P 6900 3150
F 0 "#PWR205" H 6900 3100 20  0001 C CNN
F 1 "+12V" H 6900 3250 30  0000 C CNN
	1    6900 3150
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR203
U 1 1 4EEB4D89
P 4700 4700
F 0 "#PWR203" H 4700 4700 30  0001 C CNN
F 1 "GND" H 4700 4630 30  0001 C CNN
	1    4700 4700
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P202
U 1 1 4EEB4D7C
P 5350 4400
F 0 "P202" V 5300 4400 40  0000 C CNN
F 1 "LED" V 5400 4400 40  0000 C CNN
	1    5350 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR204
U 1 1 4EEB4C63
P 5100 4000
F 0 "#PWR204" H 5100 4000 30  0001 C CNN
F 1 "GND" H 5100 3930 30  0001 C CNN
	1    5100 4000
	1    0    0    -1  
$EndComp
$Comp
L R R202
U 1 1 4EEB4C53
P 5100 3500
F 0 "R202" V 5180 3500 50  0000 C CNN
F 1 "1k" V 5100 3500 50  0000 C CNN
	1    5100 3500
	1    0    0    -1  
$EndComp
Text Label 4900 3000 2    60   ~ 0
Q2GQ1D
Text Label 2350 3300 0    60   ~ 0
Q2GQ1D
Text GLabel 2350 3150 0    60   Input ~ 0
LEDVCC
Text HLabel 1800 3000 0    60   Input ~ 0
LCONTROL
$Comp
L FDC6420C U201
U 1 1 4EEB4C01
P 3650 3150
F 0 "U201" H 3400 3450 60  0000 C CNN
F 1 "FDC6420C" H 3550 2850 60  0000 C CNN
	1    3650 3150
	1    0    0    -1  
$EndComp
$EndSCHEMATC
