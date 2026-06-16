# Osciloscopio Digital con Arduino y Pantalla LCD

## Integrantes
- Said Peña
- Joel Agudelo
- Moises Arrieta
- Breinerth Altamar


## Descripción del proyecto
Este proyecto consiste en el diseño e implementación de un osciloscopio digital portátil utilizando un microcontrolador Arduino. El sistema lee señales analógicas de voltaje variables en el tiempo, procesa la información y despliega la onda de forma gráfica en tiempo real a través de una pantalla LCD, permitiendo medir y visualizar frecuencias y amplitudes de componentes electrónicos.

## Problema identificado
En los laboratorios de electrónica y mecatrónica, los osciloscopios comerciales son equipos costosos y de difícil acceso para estudiantes que trabajan en proyectos domésticos o de bajo presupuesto. Existe la necesidad de contar con una herramienta de diagnóstico de señales que sea económica, portátil y fácil de replicar para realizar pruebas rápidas en circuitos didácticos.

## Objetivo general
Diseñar e implementar un prototipo de osciloscopio digital de bajo costo basado en Arduino para la visualización y análisis de señales eléctricas básicas en tiempo real.

## Objetivos específicos
- Configurar el convertidor analógico-digital (ADC) del Arduino para muestrear señales de voltaje.
- Programar la lógica de control para procesar los datos de la señal y ajustar la escala de tiempo o voltaje.
- Implementar el despliegue visual de la onda mediante una pantalla LCD I2C en la simulación de Tinkercad.
- Diseñar el esquema de conexiones eléctricas garantizando la protección de los pines del microcontrolador.
- Validar el funcionamiento del prototipo mediante pruebas experimentales en el entorno de simulación.

## Componentes utilizados

| Componente | Cantidad | Función |
|---|---:|---|
| Arduino Uno | 1 | Controlador principal y muestreo de la señal (ADC) |
| Pantalla LCD 16x2 I2C | 1 | Visualización de datos de la señal (Frecuencia/Voltaje) |
| Potenciómetro | 1 | Simulación de la variación de la señal de entrada |
| Cables y Protoboard | Varios | Conexión de los componentes en la simulación |

## Arquitectura del sistema
Señal de entrada (Potenciómetro) → Arduino Uno (ADC) → Procesamiento de onda → Pantalla LCD I2C / Monitor Serial

También puedes ver el diagrama detallado aquí:
![Diagrama de bloques](docs/imagenes/diagrama_bloques.png)

## Funcionamiento
1. El Arduino recibe una señal analógica variable a través de uno de sus pines (A0).
2. El ADC interno del microcontrolador transforma la señal de voltaje continuo en valores digitales.
3. El código procesa estos valores calculando la amplitud máxima, mínima y aproximando la frecuencia de la señal.
4. Los datos procesados se envían a la pantalla LCD I2C para mostrar las magnitudes correspondientes.
5. La interfaz se actualiza continuamente para reflejar los cambios de la señal en tiempo real.

## Evidencias del proyecto
### Fotos
![Montaje del circuito en Tinkercad](docs/imagenes/montaje_inicial.png)

### Videos
[Ver video de funcionamiento del osciloscopio](docs/videos/prueba_funcionamiento.mp4)

## Código fuente
El código principal se encuentra en la carpeta `codigo/`:
[Ver código del Osciloscopio](codigo/programa_principal/programa_principal.ino)

Este programa configura los pines de lectura, realiza el muestreo de los datos analógicos y gestiona la comunicación con la pantalla LCD mediante la librería Wire e LiquidCrystal_I2C.

## Esquema de conexiones
![Esquema de conexión Tinkercad](esquemas/diagrama_conexion.png)

## Pruebas realizadas
| Prueba | Descripción | Resultado |
|---|---|---|
| Muestreo Analógico | Se varió el potenciómetro para simular diferentes voltajes de entrada | El Arduino registró correctamente los cambios de 0 a 5V |
| Comunicación I2C | Se conectó la pantalla LCD mediante los pines SDA y SCL | La pantalla encendió y mostró los caracteres de prueba sin retrasos |

## Estado actual del proyecto
El proyecto se encuentra finalizado en su etapa de simulación dentro de la plataforma Tinkercad, logrando medir con éxito las señales simuladas y mostrando los datos en el display.

## Dificultades encontradas
Durante el desarrollo en Tinkercad, la velocidad de refresco de la pantalla LCD limitaba la visualización fluida de señales de alta frecuencia. Se resolvió optimizando el código, reduciendo los retardos (`delay`) y actualizando la pantalla únicamente cuando se detectaban cambios significativos en la señal.

## Mejoras futuras
- Implementar un circuito de acondicionamiento de señal para permitir lecturas de voltajes superiores a 5V.
- Cambiar la pantalla LCD por una pantalla OLED gráfica para dibujar la forma de la onda.
- Añadir botones físicos para pausar la pantalla (función Freeze/Hold).

## Conclusiones
Se logró construir un prototipo funcional de osciloscopio digital básico mediante simulación. El proyecto demostró el potencial de Arduino para el procesamiento de señales analógicas y la utilidad de las herramientas virtuales para validar diseños mecatrónicos antes de su montaje físico.
