# Control automático de barrera para estacionamiento

## Memoria descriptiva:
En este sistema vamos a implementar un control automático para la barrera de un estacionamiento. 

En un primer momento la barrera permanecerá abajo, evitando el paso de vehículos. Cuando una persona toque el botón  genera una solicitud de apertura que el microcontrolador interpretará y hará accionar al motor. Esto es el estado: **"CERRADO"**

El estado **"ABRIENDO"** se encargara de elevar la barrera hasta que toque un final de carrera y detener el motor cuando esto suceda.

Luego de que ocurra eso pasaremos al estado **"ABIERTO"** en donde un sensor infrarrojo, estara leyendo constantemente si hay un auto en la zona de la barrera, de haberlo, la barrera permanecerá arriba. De no haberlo comenzará a bajar nuevamente. Y pasaremos al estado **"CERRANDO"**

En el estado **"CERRANDO"** la barrera bajará hasta tocar otro final de carrera. Y de esta menera volvera al primer estado.

Si estamos en el estado **"CERRANDO"** y se detecta algún vehículo con el sensor, está frenará su bajada y volverá a subir, volviendo al estado **"ABRIENDO".**
