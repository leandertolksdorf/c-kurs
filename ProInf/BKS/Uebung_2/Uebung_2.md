# 4. Übungszettel

Felix Suhl, Leander Tolksdorf

## Aufgabe 2

### 1)
Echt-

### 3)
- mehr Fokus: Bei kooperativem Multitasking kann der CPU seine Kapazitäten auf einzelne Prozesse fokussieren, wohingegen präemptives Multitasking fortlaufend Prozesse unterbricht und andere rechenbereite Prozesse weiterführt. 
- früher weniger Eintrittsvarianzprobleme: Da Programme selber entscheiden, wann sie unterbrochen werden, und da es früher keine Mehrkernprozessoren gab, waren Programme eher eintrittsvariant/wiedereintrittsfähig. Beispielsweise indem sie vor der Unterbrechung globale Variabeln wiederherstellen.
- weniger Overhead: Bei präemptivem Multitasking ist der Overhead des Prozess-Wechselns größer, weil kooperatives Multitasking den Prozesswechsel Programmen überlässt. Diese wechseln an bestimmten Stellen und so weniger häufig als ein Hardware-Timer.

### 4)
Im Process Control Block eines Prozesses müssen stehen:
    - Identifikation (PID), ggfs. PIDs der Kindprozesse
    - Inhalte der 'general purpose'-CPU-Register
    - Stack-Pointer
    - Program Counter
    - Infos über belegten Primär- und Sekundärspeicher
    - Status ('ready', 'running'...)
    - Prioriät
    - Zustände von geöffneten Dateien, Ein-/Ausgabegeräten und anderen relevanten Einheiten

### 5)
Zum Beispiel, wenn innerhalb eines Programmes verschiedene Aufgaben übernommen werden müssen, diese aber von denselben Daten abhängen. Prozesse zu erstellen ist einerseits teuer. Außerdem teilen Threads eines Prozesses denselben Adressraum, sie können untereinander auf dieselben Daten innerhalb ihres Speicheraddressraums manipulieren ohne dafür kostspielige IPC-Methoden zu nutzen.
Ein weiterer Nachteil bei Prozesses ist die Synchronisierung. Prozesse müssen hierfür meist teure System Calls aufrufen, während Threads Kontrollvariabeln innerhalb des gemeinsamen Heaps beobachten und sich so synchronisieren können. 