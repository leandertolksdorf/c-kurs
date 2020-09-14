# 6. Übungsblatt

## Aufgabe 1: Pipelining

### Befehlsfolge

|     | Instruktion        | Konflikt                                 |
| --- | ------------------ | ---------------------------------------- |
| 1   | ADD r0, r1, r2     |                                          |
| 2   | SUB r1, r5, r0     | **RAW:** 2 liest Ergebnis von 1.         |
| 3   | MOV [rsp+8], r5    |                                          |
| 4   | OR r0, r5, r4      |                                          |
| 5   | MOV r3, [rsp+24]   |                                          |
| 6   | AND r1, r0, r3     | **RAW:** 6 liest Ergebnisse von 4 und 5. |
| 7   | ADD r0, r1, r3     | **RAW:** 7 liest Ergebnis von 6.         |
| 8   | ADD r0, r0, 0x341D | 8 liest Ergebnis von 7.                  |
| 9   | ADD r0, r0, 0x52F6 | 9 liest Ergebnis von 8                   |

### 5-stufige Pipeline

| Takt | IF  | ID  | OF  | EX  | WB  |
| ---- | --- | --- | --- | --- | --- |
| 1    | 1   |     |     |     |     |
| 2    | NOP | 1   |     |     |     |
| 3    | NOP | NOP | 1   |     |     |
| 4    | 2   | NOP | NOP | 1   |     |
| 5    | 3   | 2   | NOP | NOP | 1   |
| 6    | 4   | 3   | 2   | NOP | NOP |
| 7    | 5   | 4   | 3   | 2   | NOP |
| 8    | NOP | 5   | 4   | 3   | 2   |
| 9    | NOP | NOP | 5   | 4   | 3   |
| 10   | 6   | NOP | NOP | 5   | 4   |
| 11   | NOP | 6   | NOP | NOP | 5   |
| 12   | NOP | NOP | 6   | NOP | NOP |
| 13   | 7   | NOP | NOP | 6   | NOP |
| 14   | NOP | 7   | NOP | NOP | 6   |
| 15   | NOP | NOP | 7   | NOP | NOP |
| 16   | 8   | NOP | NOP | 7   | NOP |
| 17   | NOP | 8   | NOP | NOP | 7   |
| 18   | NOP | NOP | 8   | NOP | NOP |
| 19   | 9   | NOP | NOP | 8   | NOP |
| 20   |     | 9   | NOP | NOP | 8   |
| 21   |     |     | 9   | NOP | NOP |
| 22   |     |     |     | 9   | NOP |
| 23   |     |     |     |     | 9   |

### Verbesserte Pipeline

In unserer verbesserten Pipeline gehen wir von EXE-zu-EXE-Forwarding aus.

| Takt | IF   | ID   | OF   | EX   | WB   |
| ---- | ---- | ---- | ---- | ---- | ---- |
| 1    | 1    |      |      |      |      |
| 2    | 2    | 1    |      |      |      |
| 3    | 3    | 2    | 1    |      |      |
| 4    | 4    | 3    | 2    | 1    |      |
| 5    | 5    | 4    | 3    | 2    | 1    |
| 6    | 6    | 5    | 4    | 3    | 2    |
| 7    | 7    | 6    | 5    | 4    | 3    |
| 8    | 8    | 7    | 6    | 5    | 4    |
| 9    | 9    | 8    | 7    | 6    | 5    |
| 10   |      | 9    | 8    | 7    | 6    |
| 11   |      |      | 9    | 8    | 7    |
| 12   |      |      |      | 9    | 8    |
| 13   |      |      |      |      | 9    |

