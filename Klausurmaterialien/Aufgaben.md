# Gleitkommazahlen
## Konvertieren in IEEE-754-Format

Aufbau einer 32-bit-Gleitkommazahl:

| Vorzeichen v (1) | Charakteristik c (8) | Mantisse m (23) |
|-|-|-|
|1, wenn negativ. 0, wenn positiv. | Exponent | Normierte Kommazahl

### Vorzeichenbit setzen

Zahl negativ? → **1**

Zahl positiv? → **0**

### Mantisse normalisieren

Charakteristik ist am Anfang = 0.

Komma nach rechts → Charakteristik --

Komma nach links → Charakteristik ++

Format am Ende:

$$ m = (1,... |rsb)_2$$

### Mantisse runden

Round modes nach IEEE-754:

|Eingabe (rsb) | Rundung | Ergebnis |
|-|-|-|
| 000 | keine | m = m |
| 001 | down | m = m |
| 010 | down | m = m |
| 011 | down | m = m |
| 0/100 | down | m = m |
| 1/100 | up | m = m+1 |
| 101 | up | m = m+1 |
| 110 | up | m = m+1 |
| 111 | up | m = m+1 |


### Charakteristik berechnen

Charakteristik c in Exzessdarstellung mit Bias b umrechnen:

$$ Exponent = e $$
$$ Bias = b $$
$$ c = (b + e)_2 $$

