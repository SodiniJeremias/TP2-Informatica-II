# Control automático de barrera para estacionamiento

## Memoria descriptiva:

En un primer momento la barrera permanecerá abajo, evitando el paso de vehículos. Cuando una persona toque el botón  genera una solicitud de apertura que el microcontrolador interpretará y hará accionar al motor. Esto es el estado: **"CERRADO"**

El estado **"ABRIENDO"** se encargara de elevar la barrera hasta que toque un final de carrera y detener el motor cuando esto suceda.

Luego de que ocurra eso pasaremos al estado **"ABIERTO"** en donde un sensor infrarrojo, estara leyendo constantemente si hay un auto en la zona de la barrera, de haberlo, la barrera permanecerá arriba. De no haberlo comenzará a bajar nuevamente. Y pasaremos al estado **"CERRANDO"**

En el estado **"CERRANDO"** la barrera bajará hasta tocar otro final de carrera. Y de esta menera volvera al primer estado.

Si estamos en el estado **"CERRANDO"** y se detecta algún vehículo debajo de la barrera, está frenará su bajada y volverá a subir, volviendo al estado **"ABRIENDO".**

## Maquina de estado:
<img width="1002" height="721" alt="image" src="https://github.com/user-attachments/assets/b11e3c12-39c8-4144-84a0-f12294ae6853" />


## Prueba en Proteus 8:

https://github.com/user-attachments/assets/4df2cf7d-e850-4191-a4a0-a7a0a7fb8ff0

Secuencia del video:
Estado "CERRADO": Empieza con el motor detenido ya que el final_carrera_cerrado detecta que la barrera esta abajo. Se identifica la presencia de un vehículo con el sensor_presencia y se toca el boton. Esto hace que se active el motor.
Estado "ABRIENDO": Como se mueve el motor, la barrera sube y deja de tocar al final_carrera_cerrado. La barrera subira hasta que active el final_carrera_abierto. 
Estado "ABIERTO": Una vez activado el final_carrera_abierto el motor se detendra. 
Estado "CERRANDO": el sensor_presencia deja de detectar al vehiculo lo cual hace que el motor se active y gire en la direccion inversa a como lo hizo cuando se abrio. Gracias a que la barrera ahora baja deja de tocar el final_carrera_abierto. El motor se detiene cuando toca el final_carrera_cerrado

