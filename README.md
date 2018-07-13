# ESP32-Long-Range-WiFi

Estos son las primeras pruebas con el protocolo propietario 802.11 LR de espressif de las ESP32.
Los dispositivos utilizados son dos  [Wemos lolin32](https://wiki.wemos.cc/products:lolin32:lolin32), de las antiguas.

El escenario es el siguiente: 

* Una de las lolin32 se configura como master en modo STA y AP. Primero se conecta al router tradicional. Después crea un punto de acceso en modo 802.11 Long Range. Este punto acceso no es visible mediante dispositivos *normales*, ya que no pueden detectar este protocolo
