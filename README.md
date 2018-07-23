# ESP32-Long-Range-WiFi

Estos son las primeras pruebas con el protocolo propietario **802.11 LR (Long Range)** de espressif de las ESP32.
Los dispositivos utilizados son dos  [Wemos lolin32](https://wiki.wemos.cc/products:lolin32:lolin32), de las antiguas.
![](https://wiki.wemos.cc/_media/products:lolin32:lolon32_v1.0.0_1_16x9.jpg)

El escenario es el siguiente: 

* Una de las lolin32 se configura como **master** en modo STA y AP. Primero se conecta al router tradicional y obtiene una IP del mismo. Después crea un punto de acceso en modo 802.11 Long Range, con un ssid llamado "kkkkk". Este punto acceso no es visible mediante dispositivos *normales*, ya que no creo que pueden detectar el protocolo. La IP en modo es la 192.168.4.1.

El master envia ciclicament el *comando* 'b' vía UDP, a la dirección de broadcast 192.168.4.255.

* La otra lolin32 se configura **slave**, en modo STA. Se conecta a la ssid "kkkkk" i obtine su IP, seguramente la 192.168.4.2.
Cada vez que llega el comando 'b' el led conectado en la GPIO5 cambia de estado. Si no hay recepción no hay cambio.

Para conseguir un buen alcance las dos unidades deben de estar en la linea de visión. Las antenas de las lolin32 son del tipo [MIFA](https://en.wikipedia.org/wiki/Inverted-F_antenna) y su máxima radiación se da en esta dirección:

![](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRC79ql3CHAhfLjbrxUMksoLZ9WpQKKgsQRn848KdDWiLN4QdE_5A)

En una primera prueba, seguramente mejorable, he conseguido **294 m** de alcance. Espero superar esta distancia en algunos metros. 

Actualización **346 m**.
![](https://pbs.twimg.com/media/DiDnwA8X4AAGyLf.jpg)
Es de esperar que con antenas externas o direccionales se pudiera alcanzar el 1 kilómetro indicado por espressif. 

Se aceptan consejos y propuestas.
