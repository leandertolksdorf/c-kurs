# BKS 2020 Übung 9 

Firas Drass, Leander Tolksdorf, Simon Franke

## Aufgabe 1

1) Switches sind einfacher als Router. Sie verbinden lediglich mehrere Geräte direkt miteinander (in einem Netzwerk). Router hingegen verbinden Netzwerke miteinander. Deshalb müssen Router auch TCP/IP beherrschen.

2) a) OSPF: Wenn ein Router Änderungen an der Routing-Tabelle feststellt, sendet er die Info an alle anderen Hosts im Netzwerk. Die Routing-Entscheidung fällt nicht nur auf Grund der Hops-Anzahl, sondern auch durch Berücksichtigung von anderen Netzwerkinformationen. Jeder Router erstellt in der Routing Tabelle den optimalen Weg zu Zielen im Netzwerk. Das Protokoll wird durch das "Area-Konzept" verbessert. 
Quelle: https://www.computerweekly.com/de/definition/OSPF-Open-Shortest-Path-First

b) BGP: Mit dem BGP lassen sich verschiedene Autonome Systeme des Internet verbinden. Es arbeitet Pfadvektor-basiert, die Router bauen untereinander TCP Verbindungen auf. Im Gegensatz zum EGP werden zwischen den Netzwerken nicht nur die Information zur Erreichbarkeit sondern auch noch weitere Informationen (Origin, AS Path, Next Hop, Unreachable) übermittelt. Außerdem gibt es eine Inter-AS Metric die Verbindungskosten innerhalb des AS angibt, damit der externe Router einen sinnvollen Einstiegspunkt wählen kann. 
Quelle: http://einstein.informatik.uni-oldenburg.de/rechnernetze/bgp.htm

c) Durch IP lassen sich nur direkt erreichbare Teilnehmer ansprechen. Deshalb muss jedem Teilnehmer eine eindeutige IP Adresse (aufgeteilt in Netzwerk- und Teilnehmeradresse) zugeteilt werden, die jedem bekannt sein muss, der ihn erreichen will.  Die Datenübertragung wird in Paketen vorgenommen, wobei größere Datenmengen fragmentiert werden müssen. Alle Datenpakete werden mit einem Header versehen, der u.a. Zielinformationen enthält. 

d) Die ARP ermöglicht es, bei einer bekannten Netzwerkadresse die MAC Adresse (Hardwareadresse) zu ermitteln und so Pakete auf Layer 2 zu verschicken. Eine direkte Adressierung ist allerdings nur möglich, wenn sich beide Teilnehmer in einem Subnetz befinden. 
Quelle: https://www.ip-insider.de/was-ist-arp-address-resolution-protocol-a-664001/

e) Das ICMP ist eingebettet in das IP. Es liefert Informationen zum Zustand und Störungen in Netzwerken. Die Informationen finden sich im Header des IP-Paketes. Deshalb ist ICMP nicht dafür geeignet/ gedacht, eine eigene Payload zu übertragen. 

3) Routing
a) 1.1.1.1 -> 2.1.1.1 (einzige bekannte Verbindung) -> 3.1.1.1 (einzige bekannte Verbindung) -> 5.1.1.1 (über den Gateway 4.1.1.1, da die niedrigste Metrik)

b) bei 3.1.1.1 würde über 2.1.1.1 als Gateway geroutet werden, da das die Verbindung zu 5.1.1.1 mit der geringsten Metrik ist. Das Paket würde also bei 2.1.1.1 "hängen bleiben" und müsste dann wieder über 3.1.1.1 geroutet werden. 