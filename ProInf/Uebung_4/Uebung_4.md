# 4. Übungszettel

## Aufgabe 1

### 23 + 81

23 in Binär: 00010111

81 in Binär: 01010001

#### B+V

TODO

#### Einerkomplement

23 im Einerkomplement: 00010111_2

81 im Einerkomplement: 01010001_2

|          |      | 0    | 0    | 0    | 1    | 0    | 1    | 1    | 1    |
| -------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| +        |      | 0    | 1    | 0    | 1    | 0    | 0    | 0    | 1    |
| Übertrag |      |      |      | 1    |      | 1    | 1    | 1    |      |
| Ergebnis |      | 0    | 1    | 1    | 0    | 1    | 0    | 0    | 0    |

01101000_2 = 104_10

#### Zweierkomplement

Im Zweierkomplement werden wie im Einerkomplement positive Zahlen normal dargestellt. Deshalb ist die Addition zweier positiver Zahlen hier die gleiche wie oben.

#### Exzessdarstellung

TODO

### 36 - 14

36 in Binär: 00100100

14 in Binär: 00001110

#### B+V

TODO

#### Einerkomplement

Einerkomplement von +36: 00100100

Einerkomplement von -14:  11110001

|          |      | 0    | 0    | 1    | 0    | 0    | 1    | 0    | 0    |
| -------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| +        |      | 1    | 1    | 1    | 1    | 0    | 0    | 0    | 1    |
| Übertrag | 1    | 1    | 1    |      |      |      |      |      |      |
| Ergebnis | 1    | 0    | 0    | 0    | 1    | 0    | 1    | 0    | 1    |

Da wir einen Übertrag haben, müssen wir diesen noch auf das Zwischenergebnis addieren:

|          |      | 0    | 0    | 0    | 1    | 0    | 1    | 0    | 1    |
| -------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| +        |      | 0    | 0    | 0    | 0    | 0    | 0    | 0    | 1    |
| Übertrag |      |      |      |      |      |      |      | 1    |      |
| Ergebnis |      | 0    | 0    | 0    | 1    | 0    | 1    | 1    | 0    |

Das Ergebnis ist also 00010110_2 = 22_10

#### Zweierkomplement

Zweierkomplement von 36: 00100100

Zweierkomplement von -14: 11110010 (Einerkomplement + 1)

|          |      | 0    | 0    | 1    | 0    | 0    | 1    | 0    | 0    |
| -------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| +        |      | 1    | 1    | 1    | 1    | 0    | 0    | 1    | 0    |
| Übertrag | 1    | 1    | 1    |      |      |      |      |      |      |
| Ergebnis | 1    | 0    | 0    | 0    | 1    | 0    | 1    | 1    | 0    |

Der Übertrag wird im Zweierkomplement verworfen, also ist das Ergebnis:

00010110_2 = 22_10

#### Exzessdarstellung

TODO

### 72 - 87

72 in Binär: 01001000

87 in Binär: 01010111

#### B+V

TODO

### Einerkomplement

72 im Einerkomplement: 01001000

-87 im Einerkomplement: 10101000

|          |      | 0    | 1    | 0    | 0    | 1    | 0    | 0    | 0    |
| -------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| +        |      | 1    | 0    | 1    | 0    | 1    | 0    | 0    | 0    |
| Übertrag |      |      |      |      | 1    |      |      |      |      |
| Ergebnis |      | 1    | 1    | 1    | 1    | 0    | 0    | 0    | 0    |

Das Ergebnis ist 1110000_2, was im Einerkomplement der -15 entspricht.

#### Zweierkomplement

72 im Zweierkomplement: 01001000

-87 im Zweierkomplement: 10101001 (Einerkomplement + 1)

|          |      | 0    | 1    | 0    | 0    | 1    | 0    | 0    | 0    |
| -------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| +        |      | 1    | 0    | 1    | 0    | 1    | 0    | 0    | 1    |
| Übertrag |      |      |      |      | 1    |      |      |      |      |
| Ergebnis |      | 1    | 1    | 1    | 1    | 0    | 0    | 0    | 1    |

Das Ergebis entspricht im Zweierkomplement der -15 und ist damit korrekt.

#### Exzessdarstellung

TODO

### -113 - 37

113 in Binär: 01110001

37 in Binär: 00100101

#### B+V

TODO

#### Einerkomplement

-113 im Einerkomplement: 10001110

-37 im Einerkomplement: 11011010

|          |      | 1    | 0    | 0    | 0    | 1    | 1    | 1    | 0    |
| -------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| +        |      | 1    | 1    | 0    | 1    | 1    | 0    | 1    | 0    |
| Übertrag | 1    |      |      | 1    | 1    | 1    | 1    |      |      |
| Ergebnis | 1    | 0    | 1    | 1    | 0    | 1    | 0    | 0    | 0    |

Der Übertrag muss noch auf das Zwischenergebnis addiert werden, also ist das Ergebnis:

01101001_2. Das entspricht im Einerkomplement jedoch +105 und ist nicht korrekt, da im 8-Bit-Einerkomplement nur Zahlen mit einem Betrag kleiner gleich 127 darstellbar sind.

#### Zweierkomplement

Auch im Zweierkomplement ist durch das Vorzeichenbit der Wertebereich auf -127...127 begrenzt, weshalb diese Berechnung ein falsches Ergebnis hätte.



## Aufgabe 3

1. Gleitkommazahlen haben einen größeren Wertebereich als Festkommazahlen.

2. Eine 32-Bit Fließkommazahl besteht aus drei Teilen:

   1. **Vorzeichen (1 Bit):** gibt an, ob es sich um eine negative Zahl handelt.
   2. **Charakteristik (8 Bit):** Der Exponent der Gleitkommazahl in 128-Bit-Exzessdarstellung
   3. **Mantisse (23 Bit):** Die Nachkommastellen der normalisierten darzustellenden Zahl

3. Ein Overflow liegt dann vor, wenn die Zahl zu groß ist, um den dafür benötigten Exponenten in der Charakteristik darzustellen. Die größte darstellbare 32-bit-Gleitkommazahl im IEEE-754-Format ist.

   Ein Underflow tritt bei betragsmäßig zu kleinen Zahlen auf. Das heißt, dass der benötigte (negative) Exponent nicht in der 8-bit Charakteristik darstellbar ist.

4. Die grundlegende Standardisierung sind die Längen der Charakteristik und der Mantisse in bestimmten Speichergrößen (Single-precision, Double-precision, etc.). Diese Festlegungen sind sinnvoll, da die Beträge von Gleitkommazahlen im Dualsystem reine Interpretationssache sind. 

   Außerdem vereinfacht die Standardisierung der Reihenfolge von Vorzeichen, Charakteristik und Mantisse den Vergleich von zwei Zahlen, da diese einfach lexikalisch sortiert werden können.

5. 