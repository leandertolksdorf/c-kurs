# 13. Übungsblatt

## Felix Suhl, Leander Tolksdorf

### Aufgabe 1

**Bis ein Hardware-Interrupt über einen Interrupt-Controller tatsächlich an die CPUgemeldet wurde ist bereits eine (sehr geringe!) Verzögerung eingegangen. In manchenSystemen ist dies nicht tolerierbar (Airbag o. Ä.), wie könnte man das Problem umgehenund warum ist diese Methode schneller?**

Um die Latenz bei zeitkritischen Interrupts zu verringern, ist Präemtives Multitasking nötig. 

**Trotz aller Optimierungen sind auch Systemaufrufe durchaus aufwändig, weshalb vieleverbreitete Betriebssysteme versuchen, bestimmte System-Funktionalität ohne System-aufrufe bereitzustellen. Linux nutzt dazu „vDSO“1. Dies wird dadurch ermöglicht, dassdie Daten – bspw. die (Uhr-)Zeit – direkt als sich stetig verändernde globale Variablenin jedem Nutzerprozess eingeblendet sind.Warum bietet das sich nicht für alle Systemaufrufe an bzw. was unterscheidet die indem verlinkten Artikel genannten Systemaufrufen von anderen?**

Bei einem normalen Systemcall wechselt die CPU immer in den Kernel-Mode. Dafür müssen Register gesichert und wiederhergestellt werden. Für regelmäßige Operationen (wie z.B. das Abrufen der Uhrzeit) reicht es aber, den entsprechenden Teil des Kernelbereichs auszulesen. Dafür gibt es virtuelle Systemcalls, die 

### Aufgabe 2

#### Sequential Interrupt Processing

**Annahme:** Gleichzeitig eintreffende Interrupts werden nach *Highest Priority First* abgearbeitet.

| Zeitslot | Interrupt |
| -------- | --------- |
| 0        | -         |
| 1        | I0 1/4    |
| 2        | I0 2/4    |
| 3        | I0 3/4    |
| 4        | I0 4/4    |
| 5        | I2 1/2    |
| 6        | I2 2/2    |
| 7        | I1 1/1    |
| 8        | I3 1/3    |
| 9        | I3 2/3    |
| 10       | I3 3/3    |
| 11       | I4 1/3    |
| 12       | I4 2/3    |
| 13       | I4 3/3    |
| 14       | I5 1/2    |
| 15       | I5 2/2    |
| 16       | I6 1/1    |
| 17       | -         |

#### Nested Interrupt Processing

**Annahme:** Gleichzeitig eintreffende Interrupts werden nach *Highest Priority First*, bei gleicher Priorität nach *First Come First Serve* abgearbeitet.

| Zeitslot | Interrupt    | Pausierte Interrupts        | Pending Interrupts                         |
| -------- | ------------ | --------------------------- | ------------------------------------------ |
| 0        | -            |                             |                                            |
| 1        | I0 **1** 1/4 |                             |                                            |
| 2        | I2 **2** 1/2 | I0 **1** 1/4                | I1 **1** 0/1                               |
| 3        | I3 **3** 1/3 | I0 **1** 1/4 - I2 **2** 1/2 | I1 **1** 0/1                               |
| 4        | I3 **3** 2/3 | I0 **1** 1/4 - I2 **2** 1/2 | I1 **1** 0/1                               |
| 5        | I3 **3** 3/3 | I0 **1** 1/4 - I2 **2** 1/2 | I1 **1** 0/1 - I4 **2** 0/3                |
| 6        | I5 **3** 1/2 | I0 **1** 1/4 - I2 **2** 1/2 | I1 **1** 0/1 - I4 **2** 0/3                |
| 7        | I5 **3** 2/2 | I0 **1** 1/4 - I2 **2** 1/2 | I1 **1** 0/1 - I4 **2** 0/3 - I6 **1** 0/1 |
| 8        | I2 **2** 2/2 | I0 **1** 1/4                | I1 **1** 0/1 - I6 **1** 0/1                |
| 9        | I4 **2** 1/3 | I0 **1** 1/4                | I1 **1** 0/1 - I6 **1** 0/1                |
| 10       | I4 **2** 2/3 | I0 **1** 1/4                | I1 **1** 0/1 - I6 **1** 0/1                |
| 11       | I4 **2** 3/3 | I0 **1** 1/4                | I1 **1** 0/1 - I6 **1** 0/1                |
| 12       | I0 **1** 2/4 |                             | I1 **1** 0/1 - I6 **1** 0/1                |
| 13       | I0 **1** 3/4 |                             | I1 **1** 0/1 - I6 **1** 0/1                |
| 14       | I0 **1** 4/4 |                             | I1 **1** 0/1 - I6 **1** 0/1                |
| 15       | I1 **1** 1/1 |                             | I6 **1** 0/1                               |
| 16       | I6 **1** 1/1 |                             |                                            |

