# 8. Übungszettel

## Felix Suhl, Leander Tolksdorf

### Fragen

- Aufgabe 1.4 besprechen
- 

### Aufgabe 1

1. **Warum wird Speicher hierarchisch aufgebaut?**
Verschiedene Speichermedien bieten verschiedene Zugriffsgeschwindigkeiten bei proportionalem Kostenaufwand. So bieten Register die schnellste Geschwidigkeit, sind aber auch am teuersten.
Ziel der Speicherhierarchie ist, es den Datendurchsatz zu erhöhen, indem oft verwendete Daten aus den langsameren Schichten in die schnelleren geladen werden. Das funktioniert aufgrund der zeitlichen und örtlichen Lokalität. 

2. **Wie funktioniert D-RAM und S-RAM und was sind Vor- und Nachteile von beiden?**
In einem **statischen RAM** (SRAM) wird der Speicherinhalt in Flip-Flops gespeichert. Der Zustand ändert sich also nach Speicherzugriff nicht, es sind also keine Refreshs nötig und SRAM ist sehr schnell. Dafür hat er einen hohen Speicherverbrauch und ist vergleichsweise teuer.
**Dynamischer RAM** nutzt als Speicherelemente Kondensatoren, die baubedingt mit der Zeit Spannung abgeben, also Speicherinhalte verlieren. Deshalb muss im DRAM regelmäßig refresht werden, um den Speicherinhalt zu erhalten. DRAM ist relativ langsam, hat dafür aber einen niedrigen Stromverbrauch.
**Für L1/2/3-Cache wird in der Regel SRAM, für Arbeits- oder Hauptspeicher DRAM benutzt.**

3. **Erklären Sie Speichervirtualisierung und warum das sinnvoll ist.**

   Speichervirtualisierung abstrahiert physischen Speicherplatz zu einer logischen Form, damit Speicherverwaltung nicht von physischen Grenzen abhängt. Virtualisierung fügt also eine weitere, logische Schicht hinzu, um Speicherressourcen aufgeteilt oder zusammengefasst werden können.

   Speichervirtualisierung bedeutet für Benutzer mehr Flexibilität, da physischer Speicherplatz effizienter ausgelastet werden kann.

4. **Würden Sie einen Cache mit physikalischen oder virtuellen Adressen organisieren? Warum?**

5. **Erklären Sie, warum i.d.R Cache-Kohärenz und keine Cache-Konsistenz angestrebt wird.**

   Cache-Kohärenz bedeutet, dass den verarbeitenden Einheiten (Prozessoren, ...) immer der aktuellste Wert eines Datums aus dem Cache geliefert wird. Dafür ist es nicht notwendig, dass alle Caches konsistent sind. Verliert ein Datum durch Schreibzugriff an Aktualität, wird dies mit dem Dirty-Bit gekennzeichnet und beim nächsten Lesezugriff erkannt und behoben.

   Die strikte Erhaltung von Cache-Konsistenz benötigt mehr unnötige Lese- und Schreibzugriffe, weshalb Cache-Speicher oft inkonsistent ist.

6. **Warum ist LIFO als Verdrängungsstrategie für Caches i.d.R. ungeeignet?**

   LIFO widerspricht dem zeitlichen Lokalitätsprinzip. Wenn wir davon ausgehen, dass kürzlich verwendete Daten zeitnah wieder benötigt werden, ist es sinnlos, ebendiese aus dem Cache zu verdrängen.

7. **Diskutieren Sie kurz die Vor- und Nachteile von write-through und write-back.**

   In einem write-through werden veraltete Daten stets sowohl im Hauptspeicher als auch im Cache aktualisiert. Dadurch liefern beide Speicher bei Lesezugriffen immer das aktuellste Datum.

   



#### Caches

*1111 1110 1101 | 01 | 10*

**Set:** 1
**Byte:** 2
**Tag:** 0xFED

Das gesuchte Byte ist existent. Das Valid-Bit ist gesetzt.
Es gibt einen Cache-Hit. Der gelesene Wert ist: 0x18.

Nach dem Lesen ändern sich die Counter-Bits wie folgt:

| Tag   | V    | D    | C    |
| ----- | ---- | ---- | ---- |
| 0xFED | 1    | 1    | 3    |
| 0xA0B | 1    | 0    | 0    |
| 0x238 | 1    | 1    | 2    |
| 0xB39 | 0    | 0    | 1    |

*1010 1000 0110 | 11 | 01*

**Set:** 3

**Byte:** 1

**Tag:** 0xA86

Das Tag liegt nicht im Speicher. Also wird nach FIFO die Cacheline mit dem Tag 0xA4E und 0xA86 anstelle geladen. Zustand danach:

| Tag   | V    | D    | C    | Inhalt           |
| ----- | ---- | ---- | ---- | ---------------- |
| 0xA86 | 1    | 0    | 3    | Inhalt von 0xA86 |
| 0xD8E | 0    | 1    | 2    | ...              |
| 0xAB6 | 1    | 1    | 0    | ...              |
| 0xDA9 | 0    | 0    | 1    | ...              |

*0000 0000 1000 | 10 | 00*

**Set:** 2

**Byte:** 0

**Tag:** 0x008

Das Valid-Bit der Cacheline ist nicht gesetzt, also kann es nicht geladen werden. Wir haben also einen Cache-Miss.