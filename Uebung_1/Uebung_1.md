# TI3: Betriebs- und Kommunikationssysteme

## 1. Übungsblatt

### Simon Franke, Leander Tolksdorf

#### Aufgabe 1.1

a) Prozesse: Gruppieren von Prozessen in process states (running, pending, blocked) macht Multitasking möglich und erhöht die Effizienz.

b) Virtueller Speicher: Verwaltet durch die Memory Management Unit (MMU). Vorteile sind: Höhere Effizienz, Sicherheit und Unabhängigkeit von der Speicherarchitektur

c) Datei: Verwaltet durch ein Dateisystem. 

d) Ports: Ermöglicht mehrere Verbindungen über die selbe IP-Adresse.

#### Aufgabe 1.2

Die Trennung der Protection Rings wird durch Speichervirtualisierung erreicht. Sie verhindert, dass Prozesse unberechtigt auf bestimmte Speicherbereiche oder andere Prozesse zugreift. 
Der Wechsel zwischen Protection Rings heißt *Context switch*. Beispiele, die einen context switch auslösen können, sind:
 - Interrupts 
 - Multitasking

#### Aufgabe 1.3

In der Microkernel-Architektur sind (unterschiedlich) viele Komponenten ausgelagert. Die Schnittstellen zwischen den verschiedenen Komponenten müssen deshalb genau definiert sein. Die Gerätetreiber, das Dateisystem, die Anwendungs-IPC und andere Komponenten, die sich beim Monolithischen Kernel im Kernel befinden (und damit im Kernel-Modus) befinden sich beim Mikrokernel im Benutzer-Modus. Dadurch sind auch die Zugriffsrechte z.B. der Treiber, deutlich variabler. Verschiedene Services (wie Webserver) lassen sich dann auch ohne Kernel-Zugriffsrechte verwalten und verwenden. 

Syscalls, als Zugriff vom User-Mode auf den Kernel-Mode, finden also beim Mikrokernel beispielsweise zwischen den Gerätetreibern und dem eigentlichen Kernel statt, beim Monolitischem System zwischen den Anwendungen (User-Mode) und dem Kernel (z.B. Treibern)

#### Aufgabe 1.4


#### Aufgabe 2
```c
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 16 // Define size of buffer.

int main(int argc, char const *argv[]) {

    // Define vars for file descriptor, for-counter, for-end and new-line.
    int fd, i;
    const int size = argc;
    const char nl = '\n';
    ssize_t readBytes;

    // Allocate memory for buffer.
    char *buf = malloc(BUFFERSIZE);

    // Iterate over Arguments (files).
    for(i=1; i < size; i++) {
        // Save file descriptor of i-th file to fd.
        fd = open(argv[i], O_RDONLY);
        
        do {
            // Read from fd to buffer. Save number of read bytes.
            readBytes = read(fd, buf, BUFFERSIZE);
            // Write read bytes to file-descriptor 1 (stdout).
            write(1, buf, readBytes);
            // Repeat until end of file.
        } while(readBytes != 0);
        // New line after file.
        write(1, &nl, 1);
    }

    return 0;
}
```
