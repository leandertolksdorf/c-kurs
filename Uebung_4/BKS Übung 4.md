# BKS Übung 3

Leander Tolksdorf, Simon Franke 

## Aufgabe 1

### a) RR

Round Robin bedeutet, dass Prozesse nach einer gewissen Zeit unterbrochen werden und der nächste Prozess wird ausgeführt, sofern einer in der Warteschlange liegt. Erst wenn alle Prozesse ausgeführt wurden, wird der erste wieder gestartet. Deshalb ist das Verfahren präemptiv und da jeder Prozess gleich oft und lange ausgeführt wird wird kein Prozess verhungern.   

### b) HRRN

Das Highest Response Ration Next Verfahren basiert auf der Berechung (time spend waiting + expected service time)/ expected service time. Deshalb werden Prozesse mit erwarteter kürzerer Laufzeit vorgezogen, aber dadurch das auch die bisherige Wartezeit betrachtet wird, wird kein Prozess verhungern, auch wenn es bei langen Prozessen lange dauern kann, bis sie ausgeführt werden. Das Verfahren ist nicht präemtiv.  

### c) SPN

Der Shortest Process Next Algorithmus ist ein nicht präemtiver Algorithmus, bei dem zunächst alle kurzen Prozesse abgearbeitet werden. Dadurch können lange Prozesse verhungern. 		

### d) SRT

Der präemtive Shortest Remaining Time Algorithmus unterbricht laufende Prozesse, wenn ein Prozess mit kürzerer Laufzeit reinkommt als der laufende Prozess noch benötigt. Dadurch können lange Prozesse verhungern, 

### e) FCFS

Die First Come First Served Strategie ist non-preemtive, da Prozesse stur nach der Reihenfolge der Eingänge abgearbeitet werden. Dabei verhungern keine Prozesse, aber auch kurze oder hoch priorisierte Prozesse müssen ggf. lange warten.

  

## Scheduling per Hand

Die Kunden teilen sich wie folgt auf die Kassen auf:

K1: 6,10,13,20,4,21
K2: 15,3,15,19,6
K3: 23,7,40
Die Wartetzeit bis ein Kunde an der Reihe ist beträgt im Durchschnitt 23.1429 Zeiteinheiten, die Wartezeit bis ein Kunde fertig ist beträgt im Durchschnitt 37,57 Zeiteinheiten. 