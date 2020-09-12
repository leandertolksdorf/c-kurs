# 4. Übungszettel

Felix Suhl, Leander Tolksdorf

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

## Aufgabe 2

TODO

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

5. TODO

6. TODO

## Rechnungen

### -592,183940 + 0,91213

```
592,183940 in Binär (27 Bit): 
1001010000,00101111000101|101

Normalisieren: Rechtsshift um 9 und drei Rundungs-Bits behalten.
1,00101000000101111000101|101
guard = 1, round = 0, sticky = 1, also aufrunden (+1)

1,00101000000101111000110
Implizite 1 entfernen.

Mantisse: 00101000000101111000110

Vorzeichen-Bit = 1, weil negativ

Charakteristik = 9, in Exzess-127-Schreibweise: 127+9 = 136
Charakteristik in Binär: 10001000

Endergebnis:
-592,183940 in IEEE-754-Format:
11000100000101000000101111000110
```

```
0,91213 in Binär:
0,111010011000000101011010000...

Normalisieren: Linksshift um 1
1,11010011000000101011010000

Implizite 1 entfernen
11010011000000101011010|000
guard = round = sticky = 0, also abrunden

Mantisse: 11010011000000101011010

Vorzeichen-Bit = 0, weil positiv

Charakteristik = -1, in Exzess-127-Schreibweise: 127-1 = 126
Charakteristik in Binär: 01111110

Endergebnis:
0,91213 in IEEE-754-Format:
00111111011010011000000101011010
```

Addition:

```
Sei a =
1|10001000|00101000000101111000110
Sei b = 
0|01111110|11010011000000101011010

Die Charakteristik von b ist kleiner als die von a, deshalb muss diese angeglichen werden und die Mantisse von b um die Differenz nach rechts geshiftet werden.

Differenz der Charakteristiken: 10 -> Rechtsshift der Mantisse von b um 10
1,11010011000000101011010 wird zu 0,00000000011101001100000010

Addieren (-a + b = b - a):

	0,00000000011101001100000 010
- 1,00101000000101111000110 000 (Zweierkomplement bilden)
-------------------------------
	0,00000000011101001100000 010
+10,11010111111010000111010 000
-------------------------------
 10,11011000010111010011010 010 (Zweierkompklement zurückbilden)
  1,00100111101000101100101 110
  
guard = 1, round = 1, sticky = 0 -> aufrunden (+1)
-> 1,00100111101000101100110

Also ist die Mantisse: 00100111101000101100110
Das Vorzeichen-Bit ist 1, da bei der Addition eine negative Zahl rauskam.
Die Charakteristik ist die von a: 10001000

Ergebnis:
1|10001000|00100111101000101100110

in Dezimal:
- 1,154827833175659 * 2 ^ (136-127) = - 1,154827833175659 * 2 ^ 9
= 591.271850585937408

```





### 3981,1729 * (-2,91762)

```
3981,1729 in Binär (27 Bit):
111110001101,001011000100001

Normalisieren (Rechtsshift um 11):
1,11110001101001011000100|001
guard = 0, round = 0, sticky = 1 -> abrunden

Mantisse (ohne implizite 1):
11110001101001011000100

Charakteristik: 11, in Exzess-127-Schreibweise: 11 + 127 = 138
Charakteristik in Binär: 
10001010

Vorzeichen-Bit: 0, da positiv.

Ergebnis:
0|10001010|11110001101001011000100
```

```
2,91762 in Binär (27 Bit):
10,1110101011101001001001001

Normalisieren (Rechtsshift um 1):
1,01110101011101001001001|001
guard = 0, round = 0, sticky = 1 -> abrunden

Mantisse (ohne implizite 1):
01110101011101001001001

Charakteristik: 1, in Exzess-127-Schreibweise: 1 + 127 = 128
Charakteristik in Binär:
10000000

Vorzeichen-Bit = 1, da negativ.

Ergebnis:
1|10000000|01110101011101001001001
```

Multiplikation:

```
Sei a =
0|10001010|11110001101001011000100

Sei b =
0|10000000|01110101011101001001001

Multiplikation von Zahlen im Gleitkommaformat:

- Vorzeichenbit = (Vorzeichen von a) XOR (Vorzeichen von b)
- Mantisse = (Mantisse von a) * (Mantisse von b) normalisiert.
- Exponent = (Exponent von a) + (Exponent von b) - bias

Vorzeichen-Bit:
0 XOR 1 = 1

Exponent:
128 + 138 - 127= 139
in Binär: 10001011

Mantisse:
  1,11110001101001011000100
* 1,01110101011101001001001
---------------------------
=10,11010101111110001100100|111

Normalisieren (1 nach rechts shiften)
1,01101010111111000110010|011
guard = 0, round = 1, sticky = 1. Also abrunden

Charakteristik angleichen (+1):
10001100


Mantisse (ohne implizite 1):
01101010111111000110010

Ergebnis:
1|10001100|01101010111111000110010

In Dezimal:
- 1,417913675308227 * 2 ^ 13 = 11615,48828124995584
```

