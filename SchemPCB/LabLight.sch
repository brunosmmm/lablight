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
Sheet 1 4
Title ""
Date "19 apr 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 10100 7300 0    60   ~ 12
Bruno Morais\nbrunosmmm@gmail.com
Wire Wire Line
	4500 3150 2550 3150
Wire Wire Line
	2550 3250 4500 3250
$Sheet
S 4500 2750 1300 950 
U 4EEB4BD4
F0 "Seção de potência" 60
F1 "SecPot.sch" 60
F2 "FCONTROL" I L 4500 3150 60 
F3 "LCONTROL" I L 4500 3250 60 
$EndSheet
$Sheet
S 1250 2750 1300 950 
U 4EEA2D2A
F0 "Controle" 60
F1 "Controle.sch" 60
F2 "FCONTROL" O R 2550 3150 60 
F3 "LCONTROL" O R 2550 3250 60 
$EndSheet
$Sheet
S 1250 1150 1300 1000
U 4EEA2747
F0 "Fonte" 60
F1 "Fonte.sch" 60
$EndSheet
$EndSCHEMATC
