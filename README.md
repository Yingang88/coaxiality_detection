# Verwendung von Bilderkennung (OpenCV) zur Koaxilitätsdetektion des Bauteils

## Einführung
Aufgrund des aufwendigen Aufbaus und Abbaus des mechanischen Koaxialitätsmessgerätes und der Anforderungen an die Messgeschwindigkeit ist die Verwendung einer Bilderkennungsmethode eine nützliche Lösung für die Koaxialitätsdetektion der Bauteile.

Folgend wird der Hauptprozess eines mit der OpenCV-Bibliothek erstellten Programmes zur Erfassung der Koaxialität der zylinderförmigen Bauteile beschrieben. 
### 1. Systeminitialisierungsprozess
* Erstellung des Dokumentationsspeicherordners
* Überprüfung des Kamerazustands

### 2. Initialisierung der Kamera
* Automatische Erfassung der Kameraauflösung
* Angepasste Auflösung auswählen
* Einstellung der erforderlichen Helligkeit und des Kontrastverhältnisse des Bildes
* Erstellung eines Erfassungsbereiches (ROI)
* Detektieren des Kalibrierungsmusters und Einstellung des Threshold-Wertes zur Erkennung der vollständigen Konturen des Kalibrierungsmusters
* Einstellung der Kameraposition senkrecht zum Kalibrierungsmuster
* Ausgeben ein Zustandsrückwertes für den Kalibrierungsprozess

### 3. Betriebsprozess
* Ausgeben des detektierten Ergebnisses im eingestellten Erfassungsbereich (ROI)
* Speichern der erkannten Bilder nach der eingestellten Anforderung als Dokumente
### - 
### - 
