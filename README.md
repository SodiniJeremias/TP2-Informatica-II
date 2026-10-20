# Control automático de barrera para estacionamiento

## Memoria descriptiva:
En este sistema vamos a implementar un control automático para la barrera de un estacionamiento. 

En un primer momento la barrera permanecerá abajo, evitando el paso de vehículos. 

Esto quedará así hasta que una persona toque un botón. Esto genera una solicitud de apertura que el microcontrolador interpretará y hará accionar al motor. El motor elevará la barrera hasta que toque un final de carrera. Ahí el motor tiene que detenerse. 

Llegado a este estado, con un sensor infrarrojo, estaremos leyendo constantemente si hay un auto en la zona de la barrera, de haberlo, la barrera permanecerá arriba. De no haberlo comenzará a bajar nuevamente.

Si mientras la barrera está bajando se detecta algún vehículo, está frenará su bajada y volverá a subir. 

La barrera bajará hasta tocar otro final de carrera.  
