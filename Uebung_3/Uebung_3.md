# TI3: Betriebs- und Kommunikationssysteme

## 1. Übungsblatt

### Simon Franke, Leander Tolksdorf

#### Aufgabe 1.1

*Interne Fragmentierung* tritt auf, wenn die den Prozessen zugewiesenen Speicherblöcke feste Größe haben. 
Ist ein Prozess kleiner als der ihm zugewiesene Speicherblocks, bleibt ein Teil des Speicherblocks frei.

*Externe Fragmentierung* tritt dagegen bei dynamischer Speicherzuweisung auf. Wird ein Prozess aus dem Speicher entfernt, entsteht freier Speicherplatz. Unter der Annahme, dass Prozesse zusammenhängend gespeichert werden, müssen für einen neuen Prozess ggf. andere Prozesse entfernt werden, wenn kein zusammenhängender Speicherbereich von ausreichender Größe vorhanden ist.

*Paging* hilft, die negativen Effekte von interner und externer Fragmentierung zu reduzieren. Dafür wird ein virtueller Adressraum geschaffen, der größer sein kann, als der tatsächlich physisch Vorhandene. Dieser wird in Bereiche (Pages) eingeteilt.
Ist nun nicht genug Speicherplatz für einen Prozess vorhanden, lagert Paging andere Speicherbereiche temporär auf der Festplatte.

Quellen:
- https://gadget-info.com/difference-between-internal
- https://de.wikipedia.org/wiki/Paging

#### Aufgabe 1.2

Das Flag -no-pie (no position independent executabel) bewirkt beim Compiler, dass das Programm immer an der gleichen, statischen Speicheradresse ausgeführt wird. Standardmäßig wird die Speicheradresse zufällig ausgewählt (ASLR). Deshalb hat ein Programm, welches mit -no-pie kompiliert wird immer die gleiche Speicheradresse.

Quelle: https://www.computerweekly.com/de/definition/ASLR-Adress-Space-Layout-Randomization

#### Aufgabe 1.3

Als *Thrashing* bezeichnet man bezogen auf Paging einen Zustand, in dem Pages immer wieder auf die Festplatte ein- und ausgelagert werden. Passiert dies kurz, bevor ein Prozess gebraucht wird, dauert die Wiedereinlagerung des Prozesses länger, als die Ausführung selbst gedauert hätte. Der Prozessor wendet also mehr Rechenleistung für Speicherverwaltung, als für die eigentlichen Befehle auf.

Gründe für Thrashing können sein:
- Speichermangel
- Zu viele Prozesse

Um Thrashing entgegenzuwirken, gibt es Algorithmen, die bestimmen, welche Pages bevorzugt ausgelagert werden.

- Least Recently Used lagert die am längsten ungenutzte Seite aus.
- First-in, First-out ersetzt die Seite, die am längsten im Speicher liegt.
- Clock-Policy setzt für Seiten ein Bit (use bit) auf 1, wenn sie in Benutzung ist und auf 0, wenn nicht. Wird nun Platz gesucht, wird die erste Seite mit einem nicht gesetzten use bit ersetzt.

Weitere Definitionen von Thrashing sind:
- das wiederholte Schlagen eines Menschen oder Tiers mit einem Stock oder einer Peitsche
- Cache thrashing
- TLB thrashing
- Heap thrashing
- Process thrashing

Quelle: 
- https://en.wikipedia.org/wiki/Thrashing_(computer_science)
- http://ais.informatik.uni-freiburg.de/teaching/ws16/systems1/slides/kap08-speicherverwaltung.pdf
- https://www.collinsdictionary.com/de/worterbuch/englisch/thrashing

#### Aufgabe 1.4

#### Aufgabe 1.5

#### Aufgabe 1.6

#### Aufgabe 2

**evil.c**
```c
/*
TI3: 3. Übungsblatt - Aufgabe 2
Bearbeiter: Simon Franke, Leander Tolksdorf
Tutor: Leon Dirmeier
*/

#define _POSIX_C_SOURCE 199309L

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

// Define handlers for SIGINT and SIGTERM

void sigIntHandler(int sigNum) {
    (void) sigNum;
    char* msg = "sigIntHandler: Böse Nachricht\n";
    write(STDOUT_FILENO, msg, strlen(msg));
}

void sigTermHandler(int sigNum) {
    (void) sigNum;
    char* msg = "sigTermHandler: Bösere Nachricht\n";
    write(STDOUT_FILENO, msg, strlen(msg));
}

int main()
{
    // Define structs for SIGINT- and SIGTERM-handling.
    struct sigaction sigInt;
    struct sigaction sigTerm;
    struct timespec sleep;

    // Set sa_handler to corresponding handler-functions.
    sigInt.sa_handler = &sigIntHandler;
    sigTerm.sa_handler = &sigTermHandler;

    // Set sleep time to 2 seconds.
    sleep.tv_sec = 2;
    sleep.tv_nsec = 0;

    // Declare procedure on SIGINT and SIGTERM-signals.
    sigaction(SIGINT, &sigInt, NULL);
    sigaction(SIGTERM, &sigTerm, NULL);

    // Print PID continually.
    while(1){
        printf("PID: %d | Endlosschleife\n", getpid());
        nanosleep(&sleep, (struct timespec *)NULL);
    }

    return 0;
}

```

**kill.c**
```c
/*
TI3: 3. Übungsblatt - Aufgabe 2
Bearbeiter: Simon Franke, Leander Tolksdorf
Tutor: Leon Dirmeier
*/

#define _POSIX_C_SOURCE 199309L

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {
    // Set index of first PID and sigNum to default.
    int first = 1;
    int sigNum = 15;
    pid_t pid;

    // Get first argument as int.
    int firstArg = atoi(argv[1]);

    // If first argument negative (-> sigNum given), increment first-index and convert firstArg for the kill-function.
    if(firstArg < 0) {
        sigNum = firstArg * (-1);
        first = 2;
    }

    // Iterate through PIDs and send desired signal.
    for(int i = first; i < argc; i++) {
        pid = atoi(argv[i]);
        kill(pid, sigNum);
    }


    return 0;
}

```