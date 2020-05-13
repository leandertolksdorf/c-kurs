# Ue02

## Aufgabe 1

1. Wenn man keine Verzögerungen durch Hardware-Interrupts etc. tollerieren will oder kann könnte der Process ggf. direkt im Ring 0, also dem Kernel, ausgeführt werden. Dadurch würden sich auch Zeitverzögerungen durch Syscalls entfallen. Dann könnte der Prozess aber auf Kernel-Ebene nicht mehr ausreichend überwacht werden und bei Fehlfunktionen nicht durch Timer-Interrupt gestoppt werden. Eine andere Methode wäre die Prozesse durchs Syscalls zu priviligieren, so dass diese kurzzeitig in den Ring 0 wechseln, was schneller ist als ein Prozesswechsel. Der  Prozess könnte dann gernell auf Ring 3 laufen und bei Bedarf priorisiert werden. 

2. Virtuelle Syscalls eignen sich nur für "read-only" Befehle, da Ring 3-Befehle keinen Schreibzugriff auf den Kernel-address-space haben. Sinnvoll ist die Implementierung von vDSOs dann, wenn regelmäßig auf Kernel-Space lesend zugegriffen werden muss. Da verhindert werden kann, dass ein Prozesswechsel von Ring 3 auf 0 stattfindet, bietet sich hier ein Zeitvorteil. 

3. Der größte Vorteil von kooperativem Multitasking ist, dass Prozesse nicht "wiedereintrittsfähig" sein müssen, sie müssen also nicht so implementiert sein, dass sie von der Unterbrechungsroutine zu jedem Zeitpunkt unterbrochen und später wiederhergestellt werden können. 

   (vgl. https://de.wikipedia.org/wiki/Multitasking#Kooperatives_Multitasking)

4.  Im PCB sind Informationen zur Prozessidentifikation, zum Zustand und zur Prozesskontrolle gespeichert. Dazu gehören u.a.: ID, etwaige Elternprozesse, Zugehörigkeit (Nutzer), Programmcounter, Stack-Pointer, bisherige CPU-Zeit, benutzte Daten, ggf. die Priorität und die Zugriffsrechte des Programms.

   Der Dispatcher greift auf den PCB zu, um den Prozess aufzurufen (oder um ihn zu priorisieren). Aktuallisiert wird der PCB bei jedem Prozesswechsel.

   (vgl. https://en.wikipedia.org/wiki/Process_control_block)

5. Threads haben den Vorteil, dass sie sich den selben Adressrau benutzen und insbesondere auf die selben Ressourcen zugreifen können. Processe können das nicht. Deshalb ist es bei "leichtgewichtigen" Teilproblemen sinnvoll, Threads zu starten statt Prozesse. 





