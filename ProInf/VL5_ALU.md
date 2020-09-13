# 5. Vorlesung

## Wiederholung: Einfache ALU

- arithmetisch-logisches Schaltnetz
  - bspw. Carry-Lookahead-Addierer
  - enthält Flags
  - Schickt Ergebnis an Schiebeschaltnetz
- Schiebeschaltnetz
  - für Bitshifts und Speichern
  - Verbunden mit Zielregistern

## Interner Aufbau eines einfachen Mikroprozessors

3.5

Schema so auch heute noch benutzt, aber viel komplexer.

### Steuerwerk

- Steuert die Systemkomponenten
- Bestandteile
  - Befehlsregister: enthält gerade ausgeführten Befehl
  - Dekodierer: Dekodiert Befehle (mit eigenem Schaltwerk) und erzeugt Mikroprogramme von Steuersignalen.
    - Vor allem bei CISC
  - Taktgenerator: Externer Quartz (oder rein elektronisch) erzeugt Systemtakt - 1-0-1-0-1-0-...
    - Bei jedem 1-0 Übergang wird ein Ergebnis geschrieben
    - Nicht nur für das Steuerwerk, erzeugt Takt für ganzen Prozessor
    - Aufgaben:
      - Taktfrequenz herstellen
      - Erzeugung eines mit dem Prozessortakt synchronisierten Rücksetzsignals
      - Rücksetzen:
        - Steuerwerk durchläuft eine Initialisierungsroutine, die genauen zeitlichen Spezifikationen genügen muss.
- Mindesttaktfrequenz erforderlich
  - Taktsignale gehen bei zu niedrigem Takt durch Leckströme verloren.

#### Mikroprogramm

- Folge von Befehlen
- Liegen im Festwertspeicher

### Phasen der Befehlsausführung

- Holphase
  - nächsten Befehl ins Befehlsregister laden
- Dekodierphase
  - Startadresse des Mikroprogramms zum Befehl ermitteln
- Ausführungsphase
  - Mikroprogramm steuert Signalfolgen, übermittelt die an andere Prozessorkomponenten
  - Mikroprogramm wertet Signale aus

## Steuerwerk

### Befehlsregister

- Register nur für Befehle
- Befehle sind unterschiedlich lang (1-Wort, 2-Wort, ...)
- Vorabladen von Befehlen (Opcode-Prefetching)
  - Performancesteigerung durch Vorabladen von Befehlen während anderer noch ausgeführt wird.
  - Opcode Prefetch Queue, Warteschlange, Pipelining
  - **Opcode-Prefetching** ist z.B. dann sinnvoll, wenn der Speicherbus eine größere Breite hat als die Maschinenworte. (Ein 256-Bit Speicherbus kann gleich mehrere kurze Befehle holen, um optimale Auslastung zu erreichen)
- Steuerwerk eines Standard-MP ist mikroprogrammiert
  - Bei RISC-Prozessoren kann das Steuerwerk auch festverdrahtet sein.

### Steuerregister

- Bedeutung der Bits hängt vom Prozessor ab.
- Wichtige Bits:
  - Interrupt Enable Bit
    - Bestimmt, ob auf eine Interrupt-Anforderung reagiert wird
  - User/

[... Pause ...]

### Statusregister

- Speichert einzelne Bits, die das Ergebnis einer arithmetischen Operation widerspiegeln
- Nullbit: Grundlage für <u>alle</u> Vergleiche.
- Flags
  - ZERO: Fest verdrahtet
  - CARRY: Übertrag
  - SIGN: Vorzeichen
  - ...

## Operationsvorrat einer ALU

- Arithmetische Operationen
  - Addieren 
  - Subtrahieren
  - Inkrement/Dekrement
  - Multiplizieren
  - Dividieren
  - Komplementieren
- Logische Bitweise Verknüpfungen
  - Negation
  - UND
  - ODER
  - Antivalenz / XOR

## Registersatz

- Speicherzellen mit kleiner Zugriffszeit (wenige ns, ps)
- Auswahl einzelner Register durch individuelle Steuerleitungen
- kleine Register-Anzahl
  - Vorteil: kein Adressdecoder erforderlich => schneller
- Register sind direkt auf dem Prozessorchip
  - Vorteil: Kein Umschalten auf externe Daten- und Adresswege

### Funktion von Basis- und Indexregister

- Basisregister: 
  - Enthält Anfangsadresse eines Speicherbereichs
  - Bleibt während Bearbeitung des Bereichs unverändert
- Indexregister:
  - Enthält Distanz zu einer Basisadresse
  - Dient zur Auswahl eines bestimmten Datums des Speicherbereichs

### Stack

- Bereich im Arbeitsspeicher
- LIFO-System
- Funktion:
  - Ablegen des Prozessorstatus und Program Counter beim Aufruf von Unterprogrammen und Aufruf von Unterbrechungsroutinen
  - Parameterübergabe
  - Kurzzeitige Lagerung von Daten bei der Ausführung
- Oft getrennte Stackspeicher:
  - System Stack
  - User Stack
  - Data Stack
- Stackregister
  - enthält Adresse des letzten eingetragenen Datums
- Befehle für den Stack
  - PUSH
  - POP

## Adresswerk

- Berechnet nach Vorschriften des Steuerwerks die Adresse eines Befehls oder eines Operanden
- Heute sehr komplex, deshalb eigenständig

## Systembus-Schnittstelle

- Stellt Verbindung des Mikroprozessors zur Umwelt dar
- Aufgaben
  - Kurzfristiges Zwischenspeichern von Adressen und Daten
  - [...]

## Bussystem





## Fragen

- Wann wird das Carrybit gesetzt? Evtl. für FP-Rechner benutzen?
- 

