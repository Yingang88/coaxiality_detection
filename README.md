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
* Detektieren des Kalibrierungsmusters und Regulierung des Threshold-Wertes zur Erkennung der vollständigen Konturen des Kalibrierungsmusters
* Anpassung der Kameraposition senkrecht zum Kalibrierungsmuster
* Ausgeben ein Zustandsrückwertes für den Kalibrierungsprozess

### 3. Betriebsprozess
* Ausgeben des detektierten Ergebnisses im eingestellten Erfassungsbereich (ROI)
* Speichern der erkannten Bilder nach der eingestellten Anforderung als Dokumente
## Class-Diagramm


| FolderOfImage |
|---|
| - folderPath: const char* <br> - imageType: const char* <br> - buildFolderFullPath(string folderFullPath): void <br> - buildFileFullPath(string fileFullPath): void|
| + getFolderPath () const: string <br> + getImageType () const: string <br> + setFolderPath (const char* folderPath): void <br> + setImageType (const char* imageType): void <br> + createFolderInSystem (): bool <br> + saveImageInFolder (const char* name, Mat &image, int flag): bool <br> + findeImageFileSystem (): friend vector\<string\> |
  

| InitiCamera |
|---|
| - deviceID: int = 0 <br> - apiID: int = CAP_ANY  <br> - frameWidth: int = 640 <br> - frameHeight: int = 480 <br> - roiX: int = 0 <br> - roiY: int = 0 <br> - roiWidth: int = 0 <br> - roiHeight: int = 0 <br> - highDisplayRate: bool = false <br> - setInitiCameraParameter (): bool|
| + getRoiParameter () const: Rect <br> + setRoiParameter (int deviceID, int apiID, int frameWidth, int frameHeight, bool highDisplayRate): void <br> // TODO |

| ImageDetection |
|---|
| //TODO <br> - <br> -|
| + <br> +|

### - 


