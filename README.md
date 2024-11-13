# Buscaminas v1.0.0-terminal

Este proyecto es una implementación del clásico juego **Buscaminas** para la terminal, desarrollado como práctica para la asignatura de **Introducción a la Programación** en la Universidad Rey Juan Carlos.

## Características

- **Interfaz de línea de comandos**: Juega al Buscaminas directamente desde la terminal.
- **Personalización del tablero**: Ajusta el tamaño del tablero y la cantidad de minas según tus preferencias.
- **Guardado y carga de partidas**: Guarda tu progreso y retoma la partida en cualquier momento.

## Requisitos

- **Compilador de C**: Se requiere un compilador compatible con el estándar C para compilar el código fuente.
- **CMake**: También puedes usar CMake para compilar el proyecto.
- **Sistema operativo**: Compatible con sistemas basados en Unix y Windows.

## Instalación

### Clonar el repositorio

```bash
git clone https://github.com/AlvaroTena/Buscaminas_IP.git
```

### Navegar al directorio del proyecto

```bash
cd Buscaminas_IP
```

### Compilar usando GCC (opción 1)

```bash
gcc -o buscaminas main.c ajustes.c jugadas.c salida.c saves.c tablero.c
```

Asegúrate de tener `gcc` instalado. Si utilizas otro compilador, ajusta el comando según corresponda.

### Compilar usando CMake (opción 2)

El proyecto también incluye un archivo `CMakeLists.txt` para una compilación más simplificada:

1. Crear un directorio para la compilación:
   ```bash
   mkdir build
   cd build
   ```
2. Ejecutar CMake y compilar:
   ```bash
   cmake ..
   make
   ```
3. Ejecutar el programa:
   ```bash
   ./buscaminas
   ```

## Uso

Ejecuta el programa desde la terminal:

```bash
./buscaminas
```

Sigue las instrucciones en pantalla para configurar el tamaño del tablero, la cantidad de minas y comenzar a jugar.

## Estructura del Código

El proyecto está organizado en los siguientes módulos:

- **`main.c`**: Función principal que inicia el juego.
- **`ajustes.c` y `ajustes.h`**: Manejo de la configuración del juego.
- **`jugadas.c` y `jugadas.h`**: Lógica relacionada con las jugadas del jugador.
- **`salida.c` y `salida.h`**: Funciones para la visualización y salida de información.
- **`saves.c` y `saves.h`**: Funcionalidad para guardar y cargar partidas.
- **`tablero.c` y `tablero.h`**: Gestión del tablero de juego y las minas.

## Contribuciones

Este proyecto fue desarrollado con fines educativos y no se aceptan contribuciones externas en este momento.

## Licencia

Este proyecto está licenciado bajo la **Licencia MIT**. Consulta el archivo [LICENSE](LICENSE) para obtener más detalles.

```text
MIT License

Copyright (c) [2017] [Alvaro Tena]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## Contacto

Para más información, visita el repositorio oficial:

[https://github.com/AlvaroTena/Buscaminas_IP](https://github.com/AlvaroTena/Buscaminas_IP)
