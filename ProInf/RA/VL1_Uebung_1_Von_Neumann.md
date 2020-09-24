<<<<<<< HEAD
[TOC]

# 1. Vorlesung

## Single Processor Systems

- Wir reden über "echte" Single Processor Systems , also genau 1 Prozessorkern.
- heute: Computer aus Komponenten aufgebaut
- früher: Integrierte Systeme

### Klassische Computerarchitektur

- Komponenten
  - **CPU (Central Processing Unit)**
  - **Speicher**
  - **Bus-System**
  - Video controller
  - Keyboard controller
  - Floppy disk controller
  - Hard disk controller
- Trend: Controller ziehen vom Mainboard in den Prozessor um.
  - Bus-System ist Flaschenhals.

### CPU

- Was braucht eine CPU?
  - Speicher (Register)
  - Arithmetisch-logische Einheit (ALU)
  - Control Unit

### Von-Neumann-Architektur

- Grundlegende Rechnerarchitektur
- Gegenstand dieser Veranstaltung (Prüfungsrelevant)
- Basis vieler Hardware Architekturen in diesem Kurs
- **Charakteristisch:** Nur ein Arbeitsspeicher (für Befehle und Daten)
  - Befehle und Daten werden gleich behandelt (hierarchiefrei) und nicht getrennt
  - *Anders:* Harvard-Architektur - Klare Trennung
  - Probleme
    - Bandbreite: Befehle und Daten können sich auf dem Bus-System gegenseitig blockieren.
    - Sicherheit: "Code injection" - Daten könnten als Code interpretiert werden.
- Hauptkomponenten
  - CPU: Steuert Fluss und Ausführung der Instruktionen
    - ALU: Führt arithmetische Instruktionen aus.
    - Control unit: Interpretiert CPU-Instruktionen und generiert Steuerinstruktionen für andere Komponentem
  - Memory: Speichert Daten und Programme als Bitsequenzen
  - I/O units: Schnittstelle zur Außenwelt, Ein- und Ausgabe von Programmen und Daten.
  - Interconnection (Bus-System)
- Der Neumann-Computer ist eine general purpose machine.

### Principle of Operation of a Computer

- Alle modernen Computerarchitekturen:
  - **SISD:** Single Instruction Single Data
    - Es wird ein Befehl gleichzeitig ausgeführt
    - Ein Befehl manipuliert genau einen Operanden
- Code und Daten liegen im gleichen Speicher.
  - Keine Speicherschutzmechanismen
- Speicher ist unstrukturiert
- 2-Phasen-Prinzip:
  - *1. Phase*
    - Lese Program counter
    - Lade Instruktion aus Stelle Program counter aus dem Speicher (könnte auch irgendwas anderes sein...).
    - Erhöhe Program counter
  - *2. Phase*
    - Lese Befehl
    - Hole Operanden aus Speicherzelle
    - Führe Instruktion aus
    - Schreibe Ergebnis zurück

### Pro and cons of Von-Neumann

- Pro
  - Bottleneck (Bus-System)
  - Low structuring of data (i.e. long sequence of bits)
  - Kein Speicherschutz
  - Programs have to take into account the sequential data flow across the von Neumann bottleneck.

# 1. Übungszettel

## Theorie

### Was ist unter einem "general purpose Computer" zu verstehen?

> A general-purpose computer is one that, given the appropriate  application and required time, should be able to perform most common  computing tasks. 
>
> Personal computers, including [desktops](https://searchenterprisedesktop.techtarget.com/definition/desktop-computer), [notebooks](https://searchmobilecomputing.techtarget.com/definition/notebook-computer), [smartphones](https://searchmobilecomputing.techtarget.com/definition/smartphone) and [tablets](https://searchmobilecomputing.techtarget.com/definition/tablet-PC), are all examples of general-purpose computers. The term is used to  differentiate general-purpose computers from other types, in particular  the specialized embedded computers used in [intelligent systems](https://whatis.techtarget.com/definition/intelligent-system).
>
> [ENIAC](https://whatis.techtarget.com/definition/ENIAC),  designed and built in the 1940s, was the first general-purpose computer. ENIAC weighed 30 tons and covered an area of about 1,800 square feet.  In contrast, a current smartphone weighs a few ounces and is small  enough to slip into a pocket.
>
> Quelle: https://whatis.techtarget.com/definition/general-purpose-computer

Ein general purpose Computer ist nicht auf ein bestimmtes Problem zugeschnitten, sondern kann für viele verschiedene Anwendungen genutzt werden.

Das heißt: Alle Algorithmen, die berechenbar sind, kann der General Purpose Computer auch berechnen.

### Was ist unter "Programme sind auch nur Daten" zu verstehen?

Diese Sichtweise besagt, dass Programmcode und Daten im Speicher gleich behandelt werden. 

Beide werden als Bitsequenzen gespeichert und müssen dann entsprechend interpretiert werden. 

Das heißt: Alles, was der VN-Rechner macht hängt vom Inhalt des Speichers ab.

### Warum wird der Daten- vom Addressbus getrennt?

Die Einteilung in Daten- und Adressbus hat eine schnellere Bandbreite zur Folge.



### Aus welchen Bestandteilen besteht das Von-Neumann-Rechnermodell?

| Bestandteil             | Aufgabe                                                      |
| ----------------------- | ------------------------------------------------------------ |
| Central processing unit | **Arithmetic logical unit (Rechnenwerk):** Führt arithmetisch-logische Instruktionen aus.  **Control unit:** Steuert den Fluss und die Ausführung der interpretierten Instruktionen. |
| Speicher                | Speichert Programme und Daten                                |
| I/O-Systeme             | Steuert den Fluss von Signalen zwischen Anwender und Computer (Tastatur, Bildschirm etc.) |
| Bus-System              | Verbindet die Komponenten miteinander                        |

### Welche Aufgaben hat der Daten-, welche der Befehlsprozessor?

> Der  **Datenprozessor**  enthält  für  arithmetische  und  logische  Operationen  ein  Rechenwerk,  oft  als "Arithmetic Logical  Unit  (ALU)  bezeichnet.  Darüber  hinaus  werden  mindestens  3  Register  für  die Zwischenspeicherung der Operanden benötigt.
>
> Bei den Registern handelt es sich um den Akkumulator (A), das Multiplikator-Register (MR) und ein Link-Register  (L).    Letzteres  kann  im  einfachsten  Fall  einstellig  sein,  etwa  um  einen  Übertrag aufzunehmen. Über  ein  weiteres  Register,  das  Puffer-Register  (Memory  Buffer  Register  MBR),  wird  der  Verkehr mit dem Speicher abgewickelt.
>
> Der  **Befehlsprozessor**  hat  die  Aufgabe,  Befehle  zu  entschlüsseln  und  ihre  Ausführung  zu  steuern. Dazu werden folgende Register benötigt: Ein aktuell abzuarbeitender Befehl steht im Befehlsregister (instruction register, IR). Die Adresse desnächsten   anzusprechenden   Speicherplatzes   steht   im Speicheradreßregister   (Memory   AddressRegister, MAR). Die Adresse des nächsten auszuführenden Befehls wird im Befehlszähler (Program Counter, PC) gespeichert. Damit ein Befehl die Verarbeitung von Daten steuern kann, muss er durcheinen Befehlsdekodierer entschlüsselt werden. Dann erfolgt die Steuerung der Ausführung durch ein Steuerwerk.
>
> Quelle: http://www.antriebstechnik.fh-stralsund.de/1024x768/Dokumentenframe/Kompendium/Fachvorlesungen/Elektronik_fuer_Informatiker/16._von_Neumann-Rechner.pdf

### Welches Prinzip verbirgt sich hinter der Abkürzung SISD?

https://de.wikipedia.org/wiki/Flynnsche_Klassifikation

**SISD:** Single Instruction Single Data

- Es wird immer nur eine Instruktion gleichzeitig ausgeführt
- Eine Instruktion manipuliert immer genau einen Operanden

**Andere Kategorien nach Flynn:**

- SIMD
- MISD
- MIMD

### Universelle Programmierbarkeit

**Maschinencode:** 

> Eine **Maschinensprache**, wie sie bei **Maschinencode** bzw. **nativem Code** verwendet wird, ist eine [Programmiersprache](https://de.wikipedia.org/wiki/Programmiersprache), bei der die [Instruktionen](https://de.wikipedia.org/wiki/Instruktion#Programmierbefehl), die vom [Prozessor](https://de.wikipedia.org/wiki/Prozessor) ausgeführt werden sollen, als formale Sprachelemente festgelegt sind. Aufgrund ihrer Nähe zur [Hardware](https://de.wikipedia.org/wiki/Hardware) wird sie auch verallgemeinernd als *die* „Programmiersprache eines Computers“ bezeichnet.[[1\]](https://de.wikipedia.org/wiki/Maschinensprache#cite_note-1) Umfang und [Syntax](https://de.wikipedia.org/wiki/Syntax) der Maschinenbefehle sind im [Befehlssatz](https://de.wikipedia.org/wiki/Befehlssatz) definiert und abhängig vom Prozessortyp. Maschinensprache wird meistens als [Binärcode](https://de.wikipedia.org/wiki/Binärcode) oder vereinfacht mithilfe von [Hexadezimalzahlen](https://de.wikipedia.org/wiki/Hexadezimalzahlen) dargestellt.
>
> Quelle: https://de.wikipedia.org/wiki/Maschinensprache

**Assembler:**

Ist eine menschenlesbare Programmiersprache, die an die das vorgegebene Instruction Set eines Prozessors angelehnt ist. Das heißt:

- Eine Zeile entspricht genau einem Befehl
- Binärcodes der Maschinensprache werden in Befehlscodes (mov, add, sub, ...) dargestellt
- Der Assembler übersetzt Assemblersprache in Maschinencode

### Zwei-Phasen-Konzept

Das Zwei-Phasen-Konzept trennt die Interpretationsphase von der Ausführungsphase in zwei Phasen. Diese Phasen werden sequentiell ausgeführt.

- **Interpretationsphase:** Maschinenbefehl aus dem Speicher holen
- **Ausführungsphase:** 



## Programmieren

```assembly
global gauss

section .text

gauss:

  mov rax, rdi  ; rax = n
  inc rdi       ; rdi = n + 1
  mul rdi       ; rax = n * (n+1)
  shr rax, 1    ; nach rechts shiften <-> /2
  ret
```

=======
[TOC]

# 1. Vorlesung

## Single Processor Systems

- Wir reden über "echte" Single Processor Systems , also genau 1 Prozessorkern.
- heute: Computer aus Komponenten aufgebaut
- früher: Integrierte Systeme

### Klassische Computerarchitektur

- Komponenten
  - **CPU (Central Processing Unit)**
  - **Speicher**
  - **Bus-System**
  - Video controller
  - Keyboard controller
  - Floppy disk controller
  - Hard disk controller
- Trend: Controller ziehen vom Mainboard in den Prozessor um.
  - Bus-System ist Flaschenhals.

### CPU

- Was braucht eine CPU?
  - Speicher (Register)
  - Arithmetisch-logische Einheit (ALU)
  - Control Unit

### Von-Neumann-Architektur

- Grundlegende Rechnerarchitektur
- Gegenstand dieser Veranstaltung (Prüfungsrelevant)
- Basis vieler Hardware Architekturen in diesem Kurs
- **Charakteristisch:** Nur ein Arbeitsspeicher (für Befehle und Daten)
  - Befehle und Daten werden gleich behandelt (hierarchiefrei) und nicht getrennt
  - *Anders:* Harvard-Architektur - Klare Trennung
  - Probleme
    - Bandbreite: Befehle und Daten können sich auf dem Bus-System gegenseitig blockieren.
    - Sicherheit: "Code injection" - Daten könnten als Code interpretiert werden.
- Hauptkomponenten
  - CPU: Steuert Fluss und Ausführung der Instruktionen
    - ALU: Führt arithmetische Instruktionen aus.
    - Control unit: Interpretiert CPU-Instruktionen und generiert Steuerinstruktionen für andere Komponentem
  - Memory: Speichert Daten und Programme als Bitsequenzen
  - I/O units: Schnittstelle zur Außenwelt, Ein- und Ausgabe von Programmen und Daten.
  - Interconnection (Bus-System)
- Der Neumann-Computer ist eine general purpose machine.

### Principle of Operation of a Computer

- Alle modernen Computerarchitekturen:
  - **SISD:** Single Instruction Single Data
    - Es wird ein Befehl gleichzeitig ausgeführt
    - Ein Befehl manipuliert genau einen Operanden
- Code und Daten liegen im gleichen Speicher.
  - Keine Speicherschutzmechanismen
- Speicher ist unstrukturiert
- 2-Phasen-Prinzip:
  - *1. Phase*
    - Lese Program counter
    - Lade Instruktion aus Stelle Program counter aus dem Speicher (könnte auch irgendwas anderes sein...).
    - Erhöhe Program counter
  - *2. Phase*
    - Lese Befehl
    - Hole Operanden aus Speicherzelle
    - Führe Instruktion aus
    - Schreibe Ergebnis zurück

### Pro and cons of Von-Neumann

- Pro
  - Bottleneck (Bus-System)
  - Low structuring of data (i.e. long sequence of bits)
  - Kein Speicherschutz
  - Programs have to take into account the sequential data flow across the von Neumann bottleneck.

# 1. Übungszettel

## Theorie

### Was ist unter einem "general purpose Computer" zu verstehen?

> A general-purpose computer is one that, given the appropriate  application and required time, should be able to perform most common  computing tasks. 
>
> Personal computers, including [desktops](https://searchenterprisedesktop.techtarget.com/definition/desktop-computer), [notebooks](https://searchmobilecomputing.techtarget.com/definition/notebook-computer), [smartphones](https://searchmobilecomputing.techtarget.com/definition/smartphone) and [tablets](https://searchmobilecomputing.techtarget.com/definition/tablet-PC), are all examples of general-purpose computers. The term is used to  differentiate general-purpose computers from other types, in particular  the specialized embedded computers used in [intelligent systems](https://whatis.techtarget.com/definition/intelligent-system).
>
> [ENIAC](https://whatis.techtarget.com/definition/ENIAC),  designed and built in the 1940s, was the first general-purpose computer. ENIAC weighed 30 tons and covered an area of about 1,800 square feet.  In contrast, a current smartphone weighs a few ounces and is small  enough to slip into a pocket.
>
> Quelle: https://whatis.techtarget.com/definition/general-purpose-computer

Ein general purpose Computer ist nicht auf ein bestimmtes Problem zugeschnitten, sondern kann für viele verschiedene Anwendungen genutzt werden.

Das heißt: Alle Algorithmen, die berechenbar sind, kann der General Purpose Computer auch berechnen.

### Was ist unter "Programme sind auch nur Daten" zu verstehen?

Diese Sichtweise besagt, dass Programmcode und Daten im Speicher gleich behandelt werden. 

Beide werden als Bitsequenzen gespeichert und müssen dann entsprechend interpretiert werden. 

Das heißt: Alles, was der VN-Rechner macht hängt vom Inhalt des Speichers ab.

### Warum wird der Daten- vom Addressbus getrennt?

Die Einteilung in Daten- und Adressbus hat eine schnellere Bandbreite zur Folge.



### Aus welchen Bestandteilen besteht das Von-Neumann-Rechnermodell?

| Bestandteil             | Aufgabe                                                      |
| ----------------------- | ------------------------------------------------------------ |
| Central processing unit | **Arithmetic logical unit (Rechnenwerk):** Führt arithmetisch-logische Instruktionen aus.  **Control unit:** Steuert den Fluss und die Ausführung der interpretierten Instruktionen. |
| Speicher                | Speichert Programme und Daten                                |
| I/O-Systeme             | Steuert den Fluss von Signalen zwischen Anwender und Computer (Tastatur, Bildschirm etc.) |
| Bus-System              | Verbindet die Komponenten miteinander                        |

### Welche Aufgaben hat der Daten-, welche der Befehlsprozessor?

> Der  **Datenprozessor**  enthält  für  arithmetische  und  logische  Operationen  ein  Rechenwerk,  oft  als "Arithmetic Logical  Unit  (ALU)  bezeichnet.  Darüber  hinaus  werden  mindestens  3  Register  für  die Zwischenspeicherung der Operanden benötigt.
>
> Bei den Registern handelt es sich um den Akkumulator (A), das Multiplikator-Register (MR) und ein Link-Register  (L).    Letzteres  kann  im  einfachsten  Fall  einstellig  sein,  etwa  um  einen  Übertrag aufzunehmen. Über  ein  weiteres  Register,  das  Puffer-Register  (Memory  Buffer  Register  MBR),  wird  der  Verkehr mit dem Speicher abgewickelt.
>
> Der  **Befehlsprozessor**  hat  die  Aufgabe,  Befehle  zu  entschlüsseln  und  ihre  Ausführung  zu  steuern. Dazu werden folgende Register benötigt: Ein aktuell abzuarbeitender Befehl steht im Befehlsregister (instruction register, IR). Die Adresse desnächsten   anzusprechenden   Speicherplatzes   steht   im Speicheradreßregister   (Memory   AddressRegister, MAR). Die Adresse des nächsten auszuführenden Befehls wird im Befehlszähler (Program Counter, PC) gespeichert. Damit ein Befehl die Verarbeitung von Daten steuern kann, muss er durcheinen Befehlsdekodierer entschlüsselt werden. Dann erfolgt die Steuerung der Ausführung durch ein Steuerwerk.
>
> Quelle: http://www.antriebstechnik.fh-stralsund.de/1024x768/Dokumentenframe/Kompendium/Fachvorlesungen/Elektronik_fuer_Informatiker/16._von_Neumann-Rechner.pdf

### Welches Prinzip verbirgt sich hinter der Abkürzung SISD?

https://de.wikipedia.org/wiki/Flynnsche_Klassifikation

**SISD:** Single Instruction Single Data

- Es wird immer nur eine Instruktion gleichzeitig ausgeführt
- Eine Instruktion manipuliert immer genau einen Operanden

**Andere Kategorien nach Flynn:**

- SIMD
- MISD
- MIMD

### Universelle Programmierbarkeit

**Maschinencode:** 

> Eine **Maschinensprache**, wie sie bei **Maschinencode** bzw. **nativem Code** verwendet wird, ist eine [Programmiersprache](https://de.wikipedia.org/wiki/Programmiersprache), bei der die [Instruktionen](https://de.wikipedia.org/wiki/Instruktion#Programmierbefehl), die vom [Prozessor](https://de.wikipedia.org/wiki/Prozessor) ausgeführt werden sollen, als formale Sprachelemente festgelegt sind. Aufgrund ihrer Nähe zur [Hardware](https://de.wikipedia.org/wiki/Hardware) wird sie auch verallgemeinernd als *die* „Programmiersprache eines Computers“ bezeichnet.[[1\]](https://de.wikipedia.org/wiki/Maschinensprache#cite_note-1) Umfang und [Syntax](https://de.wikipedia.org/wiki/Syntax) der Maschinenbefehle sind im [Befehlssatz](https://de.wikipedia.org/wiki/Befehlssatz) definiert und abhängig vom Prozessortyp. Maschinensprache wird meistens als [Binärcode](https://de.wikipedia.org/wiki/Binärcode) oder vereinfacht mithilfe von [Hexadezimalzahlen](https://de.wikipedia.org/wiki/Hexadezimalzahlen) dargestellt.
>
> Quelle: https://de.wikipedia.org/wiki/Maschinensprache

**Assembler:**

Ist eine menschenlesbare Programmiersprache, die an die das vorgegebene Instruction Set eines Prozessors angelehnt ist. Das heißt:

- Eine Zeile entspricht genau einem Befehl
- Binärcodes der Maschinensprache werden in Befehlscodes (mov, add, sub, ...) dargestellt
- Der Assembler übersetzt Assemblersprache in Maschinencode

### Zwei-Phasen-Konzept

Das Zwei-Phasen-Konzept trennt die Interpretationsphase von der Ausführungsphase in zwei Phasen. Diese Phasen werden sequentiell ausgeführt.

- **Interpretationsphase:** Maschinenbefehl aus dem Speicher holen
- **Ausführungsphase:** 



## Programmieren

```assembly
global gauss

section .text

gauss:

  mov rax, rdi  ; rax = n
  inc rdi       ; rdi = n + 1
  mul rdi       ; rax = n * (n+1)
  shr rax, 1    ; nach rechts shiften <-> /2
  ret
```

>>>>>>> 6ef3c254026a694518bd12426917d28d97ac3936
