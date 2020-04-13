# C: Cheatsheet

## Variablen

```c
int mehrere, variablen, initialisieren;
int dezimal = 21;
int oktal = 077;
int hexa = 0x7f;
float dezimal4 = 1.32;
double dezimal8 = 1.64;
char zeichen = 'c';
char string[] zeichenkette = "Hallo";

const char string[] konstanten = "sind nicht veränderbar.";
```

## Escape Sequences

- Backspace: \b
- Form feed: \f
- Newline: \n
- Return: \r
- Horizontal tab: \t
- Vertical tab: \v
- Backslash: \\
- Single quotation: \'
- Double quotation: \"
- Question mark: \?
- Null character: \0

## Datentypen

| Datentyp               | Größe (bytes)               | Formatierer |
| ---------------------- | --------------------------- | ----------- |
| Int                    | 2-4                         | %d          |
| Char                   | 1                           | %c          |
| Float                  | 4                           | %f          |
| Double                 | 8                           | %lf         |
| Short Int              | meistens 2                  | %hd         |
| Unsigned Int           | mind. 4, meist 4            | %u          |
| Long Int               | mind. 4, meist 8            | %li         |
| Long Long Int          | mind. 8                     | %lli        |
| Unsigned Long Int      | mind. 4                     | %lu         |
| Unsigned Long Long Int | mind.8                      | %llu        |
| Signed Char            | 1                           | %c          |
| Unsigned Char          | 1                           | %c          |
| Long Double            | mind. 10, meist. 12 oder 16 | %Lf         |

**void:**
Incomplete Datentyp. Bedeutet "kein Typ" oder "nichts". Hat eine Funktion keine Rückgabe, ist ihr Datentyp void.

**short / long**
Spezifizierer, der die Größe von Variablen festlegt.

```c
long a;
long long b;
long double c;

// Größe von a abfragen: (Datentyp Int)
sizeof(a);
```

**signed / unsigned**

```c
unsigned int x;
int y;

// Wertebereich von x: 0 < x < 2^32-1
// Wertebereich von y: -2^31 < x < 2^31-1
``` 

**Weitere Datentypen**

- bool
- Enumerated
- Complex

## Output

```c
#include <stdio.h>

int a = 10;
double b = 1.23;
char c = 'c';
printf("Hallo Welt");
printf("Int: %d \n", a);
printf("Double: %b \n", b);
printf("Char: %c \n", c);
printf("Mehrere Prints: Int %d, Char %c \n", a, c);
```

## Input

```c
#include <stdio.h>

int num1;
int num2;
char ch;

printf("Zahl eingeben:");
scanf("%d", &num1);
// %d -> Lese einen Int, &num1 -> und schreibe ihn in num1.

printf("Mehrere Inputs:");
scanf("%d%c", &num2, &ch);
```

## Verzweigungen

**if/else**

```c
int zahl = 5;

if (zahl == 5) {
    printf("%d ist gleich 5.", zahl)
} else if (zahl > 5) {
    printf("%d ist größer 5.", zahl)
} else {
    printf("%d ist kleiner 5.")
}
```

**Switch-Case**
```c
int a = 2;

switch(a) {
    case 1: printf("a ist eins\n"); break;
    case 2: printf("a ist zwei\n"); break;
    case 3: printf("a ist drei\n"); break;
}
```

**Vergleiche**

Wie gewohnt. Ungleich: !=

**Logische Operatoren**

- Negation: *!a*
- Und: *a && b*
- Oder: *a || b*

**Bedingungs-Operator**

Ist eine Kurzschreibweise der if-else-Anweisung. Zu verwenden z.B., wenn die Zuweisung eines Werts von einem Vergleich abhängt.

```
ZIELVAR = (BEDINGUNG) ? IF-BLOCK : ELSE-BLOCK
```


```c
int a = 3, b = 5, max;
if (a > b) {
    max = a;
} else {
    max = b;
}
printf("Maximum: %d", max);
```
ist äquivalent zu
```c
int a = 3, b = 5, max;

max = (a > b)?a:b;

printf("Maximum: %d", max);
```

## Schleifen

**While-Schleife**
```c
int i = 1;
while (i <= 100) {
    printf("Zahl %d\n", i);
    i++;
}
```
**For-Schleife**
```c
int i;
for (i = 0; i < 5; i++) {
    printf("Zahl %d\n", i);
}
```
**Do-While-Schleife**
```c
int alter;
do {
    printf("Bitte geben Sie Ihr Alter ein");
    scanf("%d", &alter);
} while (alter < 5 || alter > 100);
```
**Break**
break; bricht die Schleife ohne Kontrollpunkt ab.

**Continue**
continue; 