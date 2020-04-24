# TI3: Betriebs- und Kommunikationssysteme

## Fragestunde

### 24.4.2020

#### Klausuren

Noch nichts bekannt, evtl. dann verstreut in der Mensa.

#### Zusammenfassung der 1. Vorlesung

- Folie 1.10: Questions & Tasks
  - Empfehlung: Immer durcharbeiten.
  - Verschiedene Betriebssysteme für verschiedene Anforderungen. In einem Antiblockiersystem brauchen wir keine interaktive Oberfläche.
  - Layering/Schichtenmodell schon in RA kennengelernt. Vorteil: Schnittstellen ermöglichen Unabhängigkeit der Schichten. Nachteil: Funktioniert oft nicht so besonders toll.

#### Fragen

- Folie 1.18: Files - Warum gibt es diese Blöcke zwischen den Dateisystemen?
  - Verschieben von Dateien muss hoch effizient sein. Ist aber eher langsam in der Hardware. Deshalb unterteilt man das Dateisystem in Blöcke, um eine Effizienzsteigerung zu erreichen. Die Blöcke sind effiziente Datentransfereinheit. Folge: Fragmentierung.
- Folie 1.17: Virtual Memory - Was ist externe Fragmentierung?
  - Leonard König
    Externe Fragmentierung:  Nicht verfügbarer Speicher ist *außerhalb* der allokierten Speicherblöcke.
    Interne Fragmentierung:  NIcht verf. Speicher ist *innerhalb* der Speicherblöcke
  - Ressource wird in gewissen Größeneinheiten verwaltet. 
  - Beispiel: ein Container hat 64kbyte. 
  - Interne Fragmentierung: Wir wollen ein Byte irgendwo ablegen. Dann bleiben 63 kbyte im Container frei. 
  - Externe Fragmentierung: Passiert außerhalb der Speicherblöcke. Wir wollen etwas ablegen, was bspw. 4 Container groß sind. Das geht nur, wenn wir es aufteilen, da keine zusammenhängenden 4 Container mehr frei sind. 
- Grundkonzepte anschauen: Virtualisierung, Schichtensystem etc. -> WICHTIG
- Folie 1.21: Protection Rings - Warum nutzen die BS diese Ringe i.d.R nicht?
  - Es gibt einige BS, die diese Protection Rings nutzen, auch Windows. Aber wenn es nicht richtig von der Hardware unterstützt wird, ist es schwierig, dies nachzubilden. Die meisten Betriebssysteme haben nur zwei Ringe. Kernel (Wechseln von Prozessen) ist Ring 0. Dann kommen Treiber etc. in Ring 1. Vorteil: Stürzt bspw. ein Treiber ab, wird der Kern nicht beeinflusst.
  - Microkernel-Betriebssysteme gibt es. Aber wie leistungsfähig sind diese? -> nochmal nachschauen
- Folie 1.16: Processes - Was bedeuten die 3 Prozesszustände?
  - Später in der Vorlesung zum Thema Prozesse
  - 1-Prozessor-System: Nur 1 Prozess kann gleichzeitig laufen. Auf Folie 3-Prozessorsystem: Also 3 Prozesse parallel.
  - Betriebssysteme sucht sich den nächsten Prozess aus. Die wartenden Prozesse sind "ready to execute" und warten in einer Warteschlange. Prozesse, die nicht genutzt werden, sind "blocked". Erst, wenn der Prozess benötigt wird, geht er in den "pending"-Zustand über, bis das Betriebssystem ihn ausführt.
  - I.d.R sind die meisten Prozesse im Pending-Zustand, weil meist auf irgendeine Eingabe gewartet wird.
- Virtualisierung
  - Beispiel: Virtueller Speicher. Ein Prozess sieht nicht den echten Speicher. Dadurch muss bei der Programmierung nicht darauf geachtet werden, da jeder Prozess in seiner virtuellen Umgebung lebt. Also: Trennen und Schützen.
  - Beispiel: Datei. Die Datei ist ein virtuelles Konstrukt. Sie ist nicht real auf der Festplatte (o.ä.) vorhanden. 
- Worin unterscheiden sich Dateisysteme wie NTFS und FAT32?
  - FAT16/32 ist ganz altes Dateisystem. Notation: 8 Zeichen für die Datei und 3 Zeichen für den Typ. Reichte irgendwann nicht mehr aus.
  - NTFS kam auf mit Windows NT (Anfang 90er). Heute noch eingesetzt. Vorteil: Rechteverwaltung. Bei FAT können wir nicht sagen, wem sie gehört. Mit den neuen geht das. Dazu kommt Hardwaresicherheit (Was passiert, wenn der Strom ausfällt?).
- Die nächsten beiden Q&A sind an Feiertagen.
  - Fragen an Public Viewing/Tutorien stellen. Mails senden. Die Fragen werden dann spätestens am 15.5. behandelt.
  - Sprechstunde Jochen Schiller.