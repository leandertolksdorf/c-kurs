# Rechnerarchitekturen

## Von-Neumann-Modell

### Bestandteile

Die Von-Neumann-Architektur setzt sich zusammen aus:

- **Central Processing Unit (CPU)**
  Steuert den Fluss und die Ausführung von Anweisungen
  - **Control Unit (Befehlsprozessor):** Interpretiert die Anweisungen eines Programms und steuert die Befehlsabfolge.
  - **Arithmetic Logical Unit (Datenprozessor):** Führt Rechenoperationen und logische Verknüpfungen durch.
- **Memory:** Lagerung von Programmen und Daten als Bitsequenzen.
- **I/O-Units:** Schnittstelle zur Außenwelt. Eingabe und Ausgabe von Informationen.
- **Systembus:** Verbindung der Komponenten untereinander. Alle Daten und Instruktionen werden über das Bus-System geführt.
  - **Steuerbus:** Sendet Taktsignale an die Komponenten.
  - **Datenbus:** Überträgt Daten zwischen CPU, Memory und I/O-Units.
  - **Adressbus:** Überträgt Speicheradressen.

### Fragen

#### Warum wird das Bus-System auf Steuer-, Daten- und Adressbus aufgeteilt?

Weil die Anwendungen verschiedene Anforderungen an das Bussystem stellen. Durch Aufteilung sind die Busse jeweils besser auf den Zweck zugeschnitten.

#### Was versteht man unter dem Von-Neumann-Flaschenhals?

Der "Flaschenhals" ist das Bus-System. Beim Bus-System kann immer nur genau ein Signal gleichzeitig übertragen werden. Nachfolgende Signale müssen also warten, bis das Bus-System frei ist. Dadurch entsteht eine Leistungseinschränkung.

#### Was ist SISD/SIMD/MISD/MIMD?

Klassifikationen von Rechnerarchitekturen (nach Michael Flynn).

##### SISD - Single Instruction, Single Data

Aufgaben werden sequentiell abgearbeitet.

Mit einer Instruktion wird genau ein Datum bearbeitet.

Von-Neumann- und Harvard-Architektur sind SISD-Architekturen.

##### SIMD - Single Instruction, Multiple Data

Eine Instruktion kann mehrere Daten gleichzeitig bearbeiten.

Anwendung z.B: bei Bild-, Ton- und Videodaten.

##### MISD - Multiple Instruction, Single Data

