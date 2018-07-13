# ESP32-Long-Range-WiFi

Estos son las primeras pruebas con el protocolo propietario 802.11 LR de espressif de las ESP32.
Los dispositivos utilizados son dos  [Wemos lolin32](https://wiki.wemos.cc/products:lolin32:lolin32), de las antiguas.

El escenario es el siguiente: 

* Una de las lolin32 se configura como master en modo STA y AP. Primero se conecta al router tradicional y obtiene una IP de este. Después crea un punto de acceso en modo 802.11 Long Range, con un ssid llamado "kkkkk". Este punto acceso no es visible mediante dispositivos *normales*, ya que no pueden detectar este protocolo. La IP de este modo es 192.168.4.1.

El master envia ciclicament el *comando* 'b' via UDP, a la dirección de broadcast 192.168.4.255.

* La otra lolin32 se configura como slave, en modo STA. Se conecta a la ssid "kkkkk" i obtine su IP, seguramente 192.168.4.2.
Cada vez que llega el comando 'b' el led connectado en la GPIO5 cambia de estado. Si no hay recepción no hay cambio.

Para conseguir un buen alcance las dos unidades deben de estar en la linea de visión. Las antenas de las lolin32 son del tipo [MIFA](https://en.wikipedia.org/wiki/Inverted-F_antenna) y su máxima radiación se da en esta dirección:

![](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRC79ql3CHAhfLjbrxUMksoLZ9WpQKKgsQRn848KdDWiLN4QdE_5A)
