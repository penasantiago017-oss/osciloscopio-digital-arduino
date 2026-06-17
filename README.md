Osciloscopio Digital de Bajo Costo: Adquisición, procesamiento y visualización de señales en tiempo real con Arduino

Integrantes

Joel Agudelo

Moises Arrieta

Breinerth Altamar

Said Peña

*Descripción del proyecto*

Este proyecto consiste en el diseño e implementación de un osciloscopio digital accesible que permite adquirir, procesar y visualizar señales eléctricas en tiempo real mediante hardware de bajo costo. El sistema recibe una señal analógica, la acondiciona y protege a través de una etapa de seguridad resistiva con diodo Zener, y la digitaliza utilizando el microcontrolador ATmega328P de un Arduino Nano. Finalmente, las ondas y sus parámetros eléctricos (como voltajes máximos, mínimos y promedios) se renderizan de forma dinámica en una pantalla OLED integrada, ofreciendo una alternativa educativa frente a los costosos equipos de laboratorio comerciales.

*Problema identificado*

Los osciloscopios comerciales suelen tener un costo elevado, lo que limita significativamente su acceso en entornos educativos, laboratorios escolares y proyectos de aprendizaje autónomo. Adicionalmente, herramientas de medición comunes como el multímetro únicamente muestran valores instantáneos y estáticos de voltaje, ocultando por completo el comportamiento real, el ruido, la continuidad y la dinámica temporal de una señal eléctrica. La falta de herramientas accesibles de visualización dificulta la comprensión práctica de conceptos fundamentales de la física eléctrica y la electrónica, como la amplitud, la frecuencia y las variaciones de potencial a lo largo del tiempo.

*Objetivo general*

Diseñar e implementar un prototipo de osciloscopio digital de bajo costo basado en Arduino para la adquisición, procesamiento matemático y representación gráfica de señales eléctricas en tiempo real.

*Objetivos específicos*

1. Implementar una etapa de acondicionamiento de señal con protección contra sobretensiones para resguardar la integridad del microcontrolador.

2. Programar el convertidor analógico-digital (ADC) para realizar un muestreo continuo de la señal de entrada y capturar 128 muestras por barrido.

3. Desarrollar un algoritmo de sincronización por trigger de flanco ascendente para estabilizar la visualización de la onda en la pantalla.

4. Diseñar e integrar una interfaz gráfica en una pantalla OLED para renderizar la curva mediante trazado vectorial e informar parámetros eléctricos calculados en tiempo real.

5. Incorporar un sistema de control de base de tiempo interactivo mediante botones pulsadores con lógica anti-rebote.

*Componentes utilizados*

Arduino Nano (ATmega328P)- Cantidad (1) - Controlador principal encargado del muestreo continuo vía ADC de 10 bits y cálculo matemático de parámetros en tiempo real.


Pantalla OLED (SSD1306)- Cantidad (1) - Matriz de 128×64 píxeles para el renderizado, mapeo espacial de la curva y visualización de telemetría.


Diodo Zener de 5.1 V - Cantidad (1) - Escudo protector que recorta físicamente picos de voltaje que superen los 5.1V, previniendo daños irreversibles en el pin A0.


Resistencia de 1 kΩ (R1) - Cantidad (1) - Componente de la red de entrada diseñado para la limitación crítica de corriente.


Resistencia de 10 kΩ (R2) - Cantidad (1) - Componente complementario de la red resistiva de acondicionamiento.


Resistencia de 100 kΩ (R3) - Cantidad (1) - Configuración Pulldown para garantizar lecturas de 0V cuando no hay señal conectada, evitando el ruido flotante.


Botones pulsadores - Cantidad (Varios) - Interfaces táctiles para el ajuste interactivo de la base de tiempo (escala horizontal).


Protoboard y cables - Cantidad (Varios) - Plataforma de hardware para el montaje y la interconexión de todo el circuito electrónico.


Cable USB - Cantidad (1) - Cable para la alimentación eléctrica del sistema y la programación del microcontrolador.


*Arquitectura del sistema*

El flujo general de procesamiento y conexión del hardware sigue una secuencia lineal estructurada en tres etapas principales:
<img width="952" height="452" alt="image" src="https://github.com/user-attachments/assets/b2c9d27a-f949-4e24-9072-79f4a48942a4" />


*Esquema de Conexión Eléctrica:*

Entrada de Señal: Conectada al pin analógico A0 del Arduino Nano tras pasar por la red de resistencias (R1, R2), la resistencia pulldown (R3) y el Zener en paralelo (D1).


Pantalla OLED: Comunicación mediante bus I²C conectando los pines SDA y SCL a los pines correspondientes del microcontrolador.


Botones de Control: Conectados a pines digitales configurados con lecturas estables para alterar los intervalos de muestreo.


Alimentación: Energizado de forma centralizada mediante el bus USB de 5V del Arduino.


*Funcionamiento*

El comportamiento del osciloscopio digital se ejecuta siguiendo un ciclo de vida de la señal rigurosamente programado:

Acondicionamiento y Filtrado Seguro: La señal física ingresa al circuito. Si presenta sobretensiones peligrosas, el diodo Zener de 5.1V las recorta, protegiendo el pin A0.

Sincronización (Trigger): Para evitar que la onda "salte" en pantalla, el algoritmo evalúa la señal en el pin A0 y espera a que cumpla una condición matemática fija: cruzar un umbral de aproximadamente 2.5V (valor ADC: 512) en flanco ascendente. Incluye un timeout de 80 ms para evitar bloqueos si la señal desaparece.

Digitalización: Una vez disparado el trigger, el ADC de 10 bits traduce el voltaje continuo (0-5V) en valores enteros discretos (0-1023), capturando exactamente 128 muestras consecutivas. La velocidad entre muestras varía según la base de tiempo seleccionada por el usuario con los botones.

Análisis Matemático: Con las 128 muestras almacenadas en memoria, se extraen los parámetros eléctricos de forma inmediata: Voltaje Máximo, Voltaje Mínimo, Voltaje Promedio y Voltaje Pico a Pico (Vpp).

Inversión Espacial Crítica: Dado que las pantallas digitales posicionan el origen (0,0) en la esquina superior izquierda, el código invierte matemáticamente el eje Y utilizando una función de mapeo para que 0V se dibuje abajo y 5V arriba.

Renderizado OLED Vectorial: El sistema une los 128 puntos consecutivos mediante líneas vectoriales continuas. El dibujo se restringe a un área útil para no alterar la barra de telemetría superior de la pantalla.

El dispositivo cuenta con dos modalidades operativas seleccionables:

Modo de Prueba (Loop Interno): El Arduino genera autónomamente una señal cuadrada de referencia a 25 Hz en el pin D9. Al puentear físicamente D9 con A0, sirve para autocalibración y diagnóstico del sistema.

Modo Externo (Medición Activa): Realiza la lectura directa de señales analógicas externas provenientes de circuitos ajenos o sensores en el pin A0, respetando el límite estricto de 5V.

*Evidencias del proyecto*


### Evidencias del proyecto

### Evidencias del proyecto

### Fotos

#### Montaje inicial del circuito en Protoboard
![Montaje inicial](docs/imagenes/montaje_inicial.jpg.jpeg)

#### Prueba de señal en pantalla OLED
![Prueba de señal](docs/imagenes/prueba_senal_cuadrada.jpg.jpeg)

#### Prototipo Final Conectado
![Prototipo Final](docs/imagenes/prototipo_final.jpg.jpeg)

### Videos

[▶️ Haz clic aquí para ver el video de funcionamiento del osciloscopio](docs/videos/prueba_funcionamiento.mp4)


*Esquema de conexiones*


1. El diagrama de conexiones detalla de forma explícita la distribución de los componentes y la red de acondicionamiento de señal para asegurar la replicabilidad exacta del proyecto.

2. El esquema permite identificar:

3. El conexionado de los buses de datos de la pantalla OLED (SDA/SCL) a los pines correspondientes del Arduino Nano.

4. La topología de la etapa de protección: entrada principal seguida por R1 (1 kΩ), R2 (10 kΩ), la derivación a tierra con el diodo Zener (5.1V) y la resistencia pulldown R3 (100 kΩ) antes de ingresar a A0.

5. Los pulsadores para modificar la escala temporal enganchados a pines digitales.

*Pruebas realizadas*

<img width="732" height="642" alt="image" src="https://github.com/user-attachments/assets/615d3f36-df67-42fb-a8d1-d46749305e5e" />


*Estado actual del proyecto*


El proyecto se encuentra en fase de pruebas finales y validación. El hardware ha sido integrado en su totalidad y el software es capaz de adquirir señales y renderizar líneas vectoriales estables. Se están realizando pequeños ajustes para mitigar el ruido electromagnético proveniente de la alimentación USB no aislada.

*Dificultades encontradas*


Frontera del Ancho de Banda: Inicialmente las señales superiores a ciertas frecuencias se distorsionaban severamente debido a la tasa de conversión estándar del ADC de Arduino. Se optimizaron los intervalos de muestreo en el código, delimitando el uso del dispositivo para bajas frecuencias (audio o sensores analógicos lentos).

Eje Y Invertido en Pantalla: Al trazar las primeras ondas, las señales se renderizaban de forma invertida debido a que el origen (0,0) de las pantallas está en la esquina superior izquierda. Esto se resolvió aplicando una inversión de la matriz del eje Y para adaptar los voltajes correctamente.

Ruido Flotante en la Entrada: Cuando no había ninguna fuente conectada al pin A0, la pantalla dibujaba ondas de ruido caóticas por inducción ambiental. Se solucionó integrando una resistencia pulldown de 100 kΩ en la etapa de entrada, forzando un estado estable de 0V ante la ausencia de señal.

*Mejoras futuras*


Nivel de Trigger Configurable: Reemplazar el trigger estático por un umbral dinámico ajustable por el usuario para estabilizar señales que poseen amplitudes muy bajas o un offset diferente.

Ampliación de Ancho de Banda: Modificar el divisor de frecuencia (prescaler) del ADC para acelerar significativamente la frecuencia de muestreo.

Telemetría Avanzada: Incorporar la medición automática de frecuencia (Hz) y período utilizando software de detección de cruces por cero.

Aislamiento Eléctrico Avanzado: Diseñar una etapa de entrada con mayor rango de voltaje y mejor aislamiento eléctrico para proteger el ordenador ante picos accidentales.

*Conclusiones*


Este proyecto demuestra que mediante la aplicación de componentes electrónicos comunes y una lógica algorítmica optimizada es viable replicar las operaciones esenciales de instrumentos científicos complejos y de alto costo. Se validó de manera práctica la integración de técnicas de digitalización analógica, procesamiento estadístico y mapeo espacial sobre pantallas OLED. La construcción del prototipo cumple con los requerimientos técnicos fijados y consolida una plataforma democratizada de hardware abierto, ideal para la experimentación académica.

