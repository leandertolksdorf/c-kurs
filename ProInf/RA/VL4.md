<<<<<<< HEAD
# 4. Vorlesung

## Gleitkommazahlen

- Je mehr Bits in der Mantisse, desto genauer die Zahl

- Je mehr Bits in der Charakteristik, desto größer der Wertebereich.

- Je größer die Charakteristik, desto 

- **Overflow:** entsteht, wenn eine positive Zahl nicht mehr in der Mantiss

- **smallreal:** Die kleinste Zahl, die man zu 1 addieren kann, um einen von 1 verschiedenen Wert zu erhalten.

  - Warum bei F.P.-Zahlen keine Assoziativität gilt:

  - ```
    (1 + (smallreal / 2)) + (smallreal / 2) = (1) + (smallreal / 2) = 1
    ```

    *(smallreal / 2) < smallreal, deshalb ist 1 + (smallreal / 2) = 1.*

    **aber**

  - ```
    1 + ((smallreal / 2) + (smallreal / 2)) = <u>1 + (smallreal) **!=** 1</u>
    ```

  - **weil 1 + smallreal einen von 1 verschiedenen Wert als Ergebnis hat**

### Floating-Point-Addition

Gegeben seien zwei IEEE-Zahlen:



1. Füge das implizite Bit hinzu. 1,Mantisse
2. Prüfe die Charakteristik:
   1. Gleiche Charakteristik: Keine Anpassung nötig
   2. Ungleiche Charakteristik: Anpassen
      1. Kleinere Charakteristik an Größere angleichen
      2. Mantisse um Differenz nach rechts shiften.
3. Prüfe Vorzeichen-Bit:
   1. gesetzt: Zweierkomplement bilden
   2. nicht gesetzt: Nichts machen
4. Mantissen addieren
5. Normalisieren: Mantissen verschieben, sodass genau eine 1 vor dem Komma steht.
6. Runden: 1, M(...)M g  | r s

**Rundungs-Entscheidungstabelle**

Wir runden nach "Round-to-even"

| guard | round | sticky | Rundung   |
| ----- | ----- | ------ | --------- |
| x     | 0     | x      | Abrunden  |
| x     | 1     | 1      | Aufrunden |
| 0     | x     | 0      | Abrunden  |
| 1     | x     | 0      | Aufrunden |

### Floating-Point-Multiplikation

=======
# 4. Vorlesung

## Gleitkommazahlen

- Je mehr Bits in der Mantisse, desto genauer die Zahl

- Je mehr Bits in der Charakteristik, desto größer der Wertebereich.

- Je größer die Charakteristik, desto 

- **Overflow:** entsteht, wenn eine positive Zahl nicht mehr in der Mantiss

- **smallreal:** Die kleinste Zahl, die man zu 1 addieren kann, um einen von 1 verschiedenen Wert zu erhalten.

  - Warum bei F.P.-Zahlen keine Assoziativität gilt:

  - ```
    (1 + (smallreal / 2)) + (smallreal / 2) = (1) + (smallreal / 2) = 1
    ```

    *(smallreal / 2) < smallreal, deshalb ist 1 + (smallreal / 2) = 1.*

    **aber**

  - ```
    1 + ((smallreal / 2) + (smallreal / 2)) = <u>1 + (smallreal) **!=** 1</u>
    ```

  - **weil 1 + smallreal einen von 1 verschiedenen Wert als Ergebnis hat**

### Floating-Point-Addition

Gegeben seien zwei IEEE-Zahlen:



1. Füge das implizite Bit hinzu. 1,Mantisse
2. Prüfe die Charakteristik:
   1. Gleiche Charakteristik: Keine Anpassung nötig
   2. Ungleiche Charakteristik: Anpassen
      1. Kleinere Charakteristik an Größere angleichen
      2. Mantisse um Differenz nach rechts shiften.
3. Prüfe Vorzeichen-Bit:
   1. gesetzt: Zweierkomplement bilden
   2. nicht gesetzt: Nichts machen
4. Mantissen addieren
5. Normalisieren: Mantissen verschieben, sodass genau eine 1 vor dem Komma steht.
6. Runden: 1, M(...)M g  | r s

**Rundungs-Entscheidungstabelle**

Wir runden nach "Round-to-even"

| guard | round | sticky | Rundung   |
| ----- | ----- | ------ | --------- |
| x     | 0     | x      | Abrunden  |
| x     | 1     | 1      | Aufrunden |
| 0     | x     | 0      | Abrunden  |
| 1     | x     | 0      | Aufrunden |

### Floating-Point-Multiplikation

>>>>>>> 6ef3c254026a694518bd12426917d28d97ac3936
