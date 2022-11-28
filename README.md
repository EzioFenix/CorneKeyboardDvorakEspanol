# CorneKeyboardDvorakEspanol
Trato de configurar mi teclado para difrerentes configuraciones del teclado corne keyboard, en especial para programacion.

# Litle

Para compilar el teclado tienes que introducir el siguiente comando:

```
qmk compile -kb litl -km devorak
```

Con ello lo compilamos

## Versiones de teclado que existen:

- Devorak
- Querty (momentanemante es )

# Problemas resueltos

- Como agregar la `ñ`

Incluye la siguiente biblioteca

```
#include "keymap_spanish.h"
```

Más información

- [Crear y flashear tu propio keymap con QMK firmware - DEV Community 👩‍💻👨‍💻](https://dev.to/mandrewcito/crear-y-flashear-tu-propio-keymap-con-qmk-firmware-2nd6)
