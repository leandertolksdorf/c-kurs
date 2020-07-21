## BKS 2020 Übung 10

#### Firas Drass, Leander Tolksdorf, Simon Franke

### A 1

1) UDP ist eine unzuverlässige Übertragung, die zwar wie TCP Multiplexing beherrscht, aber deutlich "primitiver" ist als TCP. UDP beherrscht keine umfassende flow control wie TCP und ist nicht TCP friendly. TCP ist eine zuverlässige Verbindung, der Verbindungsaufbau wird über ein 3-Wege-Handshake durchgeführt, gesendete Bytes werden bestätigt und der Verbindungsabbau durch einen Timer unterstützt.  

2) Bei UDP bekommen wir keine Fehlinformationen, wenn das Paket nicht ankommt (unzuverlässige Verbindung), bei TCP meldet der Empfänger die nächsten erwarteten Bytes, also bemerken wir so, wenn Bytes (z.B. durch Ablauf der TTL) verloren gegangen sind. 

Ein Vorteil bei einer TTL ist, dass die Pakete nicht endlos durchs Netz schwirren, wenn sie nicht beim Empfänger ankommen. Dadurch kann Netzverkehr reduziert werden. Die RTT versucht das Protokoll zu ermitteln, um die Größe des Advertisement Window festlegen zu können. 

3) Verbindungsaufbau: 
Sender ----  SYN -----> Receiver
S <------- SYNACK ---------- R
S --------ACK packet + Data ---> R

Das SYN ist das Syncronize Package

Verbindungsabbau:
S1---- FIN (+Timer) ----> S2
S1 <------ACK----- S2
S1 <------FIN (+Timer)-------S2
S1 -------ACK---------> S2

FIN: Das FIN zeigt an, dass von dieser Seite aus keine Daten mehr gesendet werden. Der Timer wird mitgeschickt, falls die Bestätigung (von denen man theoretisch unendlich viele bräuchte -> two army problem), nicht ankommt. Wenn der Timer abläuft, dann wird die Verbindung unterbrochen. 

4) Beide Abfragen müssen sich die selbe Leitung teilen. Wenn alle verwendeten Protokoll TCP friendly sind, teilen sie sich die Leitung gerecht. Wenn ein Protokoll nicht TCP friendly ist, (z.B. UDP) kann es vorkommen, dass dieser die Leitung komplett für sich beansprucht. Wenn also der Livestream über UDP laufen sollte, dann kann dieser die (TCP-)Verbindung zum KVV unterbrechen. 

5) UDP: multimediale Datenübertragung (z.B. digitales Fernsehen, Videokonferenzen). Hierbei ist insbesondere die Echtzeitübertragung entscheidend, nicht unbedingt dass jedes einzelne Byte beim Empfänger ankommen, Übertragungsfehler führen also nur zu kurzen Unterbrechungen und nicht zur Verzögerung der nachfolgenden Daten. 
Client-Server-Bereich (z.B. RPC) hier besticht UDP durch seine Einfachheit. Wenn Anfragen im Netz verloren gehen, schickt der Sender nach Ablauf eines Timers die selbe Anfrage nochmal. 

TCP wird überall dort verwendet, wo es auf eine gesicherte Übertragung aller Bytes ankommt, zum Beispiel beim Aufruf von Webseiten und dem Versenden von Emails. 

