# 2. Vorlesung

## Benchmarks

- Eine Performancemessung ist nur für ein bestimmtes Problem gültig.
  - Andere Probleme könnten immer auf einem anderen System besser funktionieren.

### Benchmark programs

- Sieb de Erathostenes, Ackermann Funktion
- Primzahlen berechnen
  - Vorteil: Keine Peripherie, nicht speicherintensiv.

## Wichtig

- Für welches Problem wird die Performance verglichen?
- Grad der Parallelisierung mitbeachten (Ist ein Problem parallelisierbar?)



# Six-level Computer

- **Level 5:** Problem-oriented language level
  - Translation (Compiler)
- **Level 4:** Assembly language level
  - Translation (Assembler)
- **Level 3:** Operating system machine level
  - Partial interpretation (operating system)
- **Level 2:** ISA (Instruction Set Architecture) level
  - Interpretation (microprogram) or direct execution
- **Level 1:** Microarchitecture level
  - Hardware
- **Level 0:** Digital logic level.

## Wiederholen für Prüfung

- Abgrenzung der Von Neumann von der Harvard Architektur.
- Unterschied: Universellen und special Purpose Computern
- Mikrocomputer und Mikrocontroller (Embedded Chips)
- Meilensteine der Computergeschichte (Geschichte ohne Beispiele, dafür Technologien)
- Definition von Computer Architektur (keine klare, Unterschiedliche)
- Klassifizierung von Computern (Parallelisierung, ...)
- Performancemessung
- Layered computer model (nicht jeden einzelnen Layer, sondern Unterschiede, Zusammenhänge etc)

# 2. Übungszettel

## Interpreter, Compiler, Assembler, Linker

| Interpreter                                                  | Compiler                                                     | Assembler                                                    | Linker                                                       |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Ein *Interpreter* ist ein Programm, das einen Quellcode zur **Laufzeit** ausführt. Dabei wird sequenziell Zeile für Zeile eingelesen und direkt ausgeführt. Nachdem eine Zeile ausgeführt wurde, geht es mit der Nächsten auf gleiche Weise weiter, bis entweder das Ende des Quellcodes erreicht ist oder ein Fehler auftritt. Der Code wird vor Ausführung nicht auf semantische Korrektheit geprüft. Ein Interpreter ist in der Regel langsamer als ein Compiler. | Ein *Compiler* liest den kompletten Quellcode ein und übersetzt diesen in Maschinencode. Anders als der Interpreter kann der Compiler vor Ausführung des Programms Optimierungen vornehmen und den Code auf Korrektheit überprüfen. Moderne Compiler kompilieren oft nicht in Maschinencode, sondern in Bytecode. | Ein *Assembler* konvertiert Assemblercode (also menschenlesbare Mnemonics für direkte Maschinenbefehle) in nativen Maschinencode umwandelt. Dabei entspricht eine Assembler-Zeile auch genau einem Maschinenbefehl. | Ein *Linker* ist ein Programm, das mehrere Programmodule zu einem ausführbaren Programm zusammenstellt (*to link* oder *to bind*). Ein C-Programm könnte bspw. die Netzwerkbibliothek oder stdio zur Ausführung benötigen. Der Linker fügt nun also benötigte Funktionen  (z.B. aus Bibliotheken oder einem Assembler-Programm) zum Hauptprogramm hinzu. |

## Sprachen

| Programmiersprache                                           | Hochsprache                                                  | Assemblersprache                                             |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Eine *formal definierte Sprache*, mit der Programme geschrieben werden können. Sie ist durch ihre Syntax und Semantik definiert und dient dazu, reale Probleme oder Prozesse (Algorithmen) in eine maschinenlesbare Form zu bringen und auszuführen. Es gibt verschiedene Programmiersprachen mit unterschiedlicher Funktionsweise und bestimmten Spezialisierungen. | Eine Hochsprache ist eine Programmiersprache, die auf Menschenlesbarkeit ausgelegt ist. Ihre Befehle können nicht direkt vom Prozessor verstanden, sondern müssen erst von einem **Interpreter** oder **Compiler** zu Maschinencode konvertiert werden. Eine Hochsprache ist meistens prozessorunabhängig und bietet, anders als die Assemblersprache Datenstrukturen wie Listen oder Kontrollstrukturen wie Schleifen und if-else-Anweisungen. Vorteilig an der Hochsprache ist, dass sie in beliebige Assemblersprachen übersetzt werden kann. Beispiele für Hochsprachen sind *Python, Java und C*. | Eine Assemblersprache ist auch menschenlesbar, orientiert sich aber am Befehlssatz einer bestimmten Prozessorarchitektur. Eine Assembler-Zeile entspricht auch genau einem Maschinenbefehl. Eine Assemblersprache kennt nur einfache Datentypen (Bytes) und Sprungbefehle. Eine Assemblersprache basiert auf einer CPU-Architektur und ist somit nicht auf anderen lauffähig. |

## ISA, CISC, RISC

https://de.wikipedia.org/wiki/Befehlssatzarchitektur  

https://www.bernd-leitenberger.de/cisc-risc.shtml

### Instruction Set Architecture

Die *Befehlssatzachitektur* ist das Bindeglied zwischen Software und Hardware. In der Befehssatzarchitektur ist ein Befehlssatz (eine Menge von Befehlen, die der Prozessor ausführen kann) und deren binäre Kodierung definiert. 

**Abgrenzung:** Der Befehlssatz allein beinhaltet nur die Befehle, nicht die binäre Kodierung. In der ISA ist bspw. definiert, wie die CPU mit einem Interrupt umgeht oder mit welchen Inhalten Register initialisiert werden. 

Eine Befehlssatzarchitektur muss nicht zwingend auf einem Mikroprozessor implementiert werden, sondern kann auch auf einer Virtuellen Maschine emuliert werden. 

ISA werden klassifiziert nach bestimmten Eigenschaften: Typ des Befehlssatzes, Bitbreite, Registeranzahl, Adressierungsarten, Unterbrechungsanforderungen und Ausnahmebehandlung

### CISC

*CISC (Complex Instruction Set Computer)* ist ein Konzept im Computerbau. 

Anders als bei RISC gibt es einen umfangreichen Befehlssatz, in dem die Befehle eine hohe Mächtigkeit (also Komplexität) haben. So können komplexe Operationen in wenigen Befehlszeilen (dafür aber mit mehr Takten Dauer) ausgeführt werden. 

Mit der Zeit zeigte sich, dass trotz der großen Auswahl in der Praxis nur ein kleiner Teil dieser Befehle benutzt werden. Daduch blieb ein großer Teil des Prozessors unbenutzt, was ineffizient ist.  

### RISC

*RISC (Reduced Instruction Set Computer)* enthält dagegen nur einen reduzierten Befehlssatz, der aus einigen wenigen elementaren Befehlen besteht. 

Diese Befehle dauern wenige Takte. Die geringere Komplexität dieser Befehle hat einen simpleren Aufbau des Prozessors zur Folge. Außerdem müssen sie nicht in Mikrocodes dekodiert werden und sind dadurch schneller.

Die meisten heutigen Prozessoren sind RISC-Prozessoren, da sie schneller, einfacher zu bauen und damit günstiger sind.



 **Fragen:**

- https://www.bernd-leitenberger.de/cisc-risc.shtml: Ein prinzipieller Nachteil von CISC ist, das es in der Regel nicht möglich ist  viele Register zu verwenden. 
  - Warum können bei CISC weniger Register verwendet werden?
- 