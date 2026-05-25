# Bitácora de uso de IA generativa

Aquí contamos cómo usamos la IA durante el desarrollo del proyecto EcoMisión, qué cosas nos sirvieron, qué cosas no, y qué tuvo que entender bien cada integrante para poder defenderlo.

---

## ¿Para qué usamos la IA?

Estos fueron los momentos principales:

- **Para entender el enunciado**. Al principio el documento parecía mucho y queríamos asegurarnos de no estar olvidando algún requisito importante (como las tres clases derivadas, la sobrecarga, el `unordered_map`).
- **Para ideas de diseño**. Cuando no sabíamos si algo debía ser composición o agregación, le explicamos a la IA lo que teníamos en mente y nos ayudó a ver qué implicaba cada opción.
- **Para entender errores del compilador**. Los mensajes de error de C++ a veces son muy confusos. Cuando salía algo como "undefined reference to..." o "is private within this context", le preguntábamos qué significaba y de ahí entendíamos qué teníamos mal.
- **Para repasar conceptos**. Cosas como qué es un destructor virtual, por qué hace falta el `override`, o qué es exactamente la sobrecarga, las repasamos con ayuda de la IA hasta que quedaron claras.
- **Para armar la documentación**. Estos archivos (`diseno.md`, `README.md` y este mismo) los estructuramos con ayuda de IA, pero el contenido lo revisamos y ajustamos a lo que realmente hicimos.

Lo que no hicimos fue pedirle que escribiera el proyecto completo y entregarlo. Cada archivo lo revisamos entendiendo qué hacía. Si había alguna línea que no entendíamos, la cambiábamos por algo que sí entendiéramos o le preguntábamos hasta entenderla.

---

## ¿Qué decisiones de diseño revisamos con IA?

1. **Composición o agregación entre Reserva y Zona**. No teníamos muy claro la diferencia. Lo discutimos y entendimos que como la Reserva es la que crea las zonas y la que las destruye al final, era composición. Si fuera otra clase la que creara las zonas y solo se las pasara a la Reserva, sería agregación.

2. **Cómo iba a funcionar el PortalDeRuta**. Al principio pensamos en darle directamente la zona destino, pero la IA nos hizo ver que era mejor pasarle el código y un puntero a la Reserva, así el portal puede buscar la zona en el momento que se usa. También así el código queda más flexible.

3. **Por qué usar punteros en el vector y no objetos directamente**. La IA nos explicó algo llamado *object slicing* y entendimos que si guardamos objetos en lugar de punteros, se pierde la información de las subclases y el polimorfismo no funciona.

4. **El tema del destructor virtual**. Esta fue una de las cosas que más nos costó entender al principio. Por qué tiene que ser virtual, qué pasa si no lo es. Después de varios ejemplos entendimos que es necesario para que se llamen correctamente los destructores de las subclases.

5. **Si los atributos de la clase abstracta debían ser `private` o `protected`**. Nos decidimos por `protected` porque las subclases los usan directamente en sus métodos, y poner getters para todo era hacer el código más largo sin ganar mucho.

---

## ¿Qué sugerencias de la IA aceptamos y por qué?

- **El destructor virtual en `ElementoInteractivo`**: lo aceptamos porque entendimos por qué era necesario. Sin él, cuando uno destruye un elemento usando un puntero a la clase base, no se llaman los destructores de las subclases y eso causa problemas de memoria. Aunque en nuestro caso ninguna subclase tiene memoria propia que liberar, lo dejamos así porque es la buena práctica.

- **Usar `override` en los métodos sobreescritos**: lo aceptamos porque nos protege de errores. Si por accidente escribimos mal la firma del método (por ejemplo, le ponemos un `const` de más), el compilador nos avisa. Sin `override` el compilador no se da cuenta y simplemente crea un método nuevo, lo cual es peor porque uno no nota el bug.

- **Validar que los punteros no sean nulos antes de usarlos**: lo aceptamos porque es buena práctica. Por ejemplo, en `PortalDeRuta::interactuar` verificamos que el explorador y la reserva no sean nulos antes de hacer cualquier cosa. Si llegan a ser nulos, el programa muestra un mensaje en lugar de crashear.

- **La lista de inicialización en los constructores**: aceptamos usar `: nombre(nombre), energia(...)` en vez de hacer las asignaciones dentro del cuerpo del constructor. Es más limpio y en algunos casos es la única forma de inicializar.

- **Hacer la sobrecarga con `int` y `string`**: nos pareció una buena forma de demostrar claramente la sobrecarga, porque las dos firmas son obviamente distintas y se entiende cuál se llama según lo que uno le pase.

---

## ¿Qué sugerencias de IA corregimos o rechazamos y por qué?

- **Smart pointers (`unique_ptr`, `shared_ptr`)**: la IA nos sugirió varias veces usar smart pointers para que la memoria se libere automáticamente. No los usamos por dos razones simples: no los hemos visto en clase y no sabríamos defenderlos bien en la sustentación. Preferimos hacer `new` y `delete` explícitos, así se ve claramente quién libera qué.

- **Templates y cosas más avanzadas**: en algún momento nos sugirió usar templates para hacer cosas más genéricas, pero rechazamos porque el proyecto no lo pedía y era complicarlo sin necesidad.

- **Acentos y símbolos especiales en los mensajes**: al principio los `cout` tenían acentos como "energía" y "demostración", pero en la consola de Windows salían como caracteres raros. Los quitamos y dejamos todo sin acentos.

- **Que el portal se desactivara después de usarse**: la IA nos sugirió que el portal se gastara después de cruzarlo una vez, pero decidimos que no. Nos pareció más realista que el portal sea como un camino: uno puede ir y volver tantas veces como tenga energía.

---

## Responsabilidades individuales

Cada uno tiene que poder defender ciertas partes del proyecto. Esto es lo que cada integrante manejó más a fondo:

### []

Se encargó principalmente de:

- La parte de herencia: `ElementoInteractivo` y sus tres hijas (`EstacionEnergia`, `ResiduoContaminante`, `PortalDeRuta`).
- Entender el polimorfismo y cómo se aplica en el vector de elementos.
- El tema del destructor virtual y por qué hace falta.

Tiene que poder explicar:

- Por qué `ElementoInteractivo` es una clase abstracta y qué la hace abstracta.
- Cómo decide C++ qué método llamar cuando uno hace `elemento->interactuar(exp)`.
- Por qué los atributos de la clase abstracta están en `protected` y no en `private`.
- La diferencia entre sobreescritura y sobrecarga.

### []

Se encargó principalmente de:

- La clase `Reserva` con el `unordered_map`.
- La clase `Zona` con la sobrecarga del método `interactuar`.
- La clase `EcoMision` que coordina todo.

Tiene que poder explicar:

- Por qué se usa `unordered_map` y no `map` o `vector`.
- Qué es composición y dónde está en el código.
- Cómo funciona la sobrecarga (las dos versiones de `interactuar` en Zona).
- Cómo se destruye todo cuando termina el programa (la cadena de destructores).

### Lo que tiene que saber cualquiera del equipo

Sin importar quién hizo qué, los dos integrantes tienen que poder:

- Abrir el proyecto, compilarlo y ejecutarlo en su computador.
- Modificar el código en vivo si la profesora lo pide (por ejemplo, agregar una nueva zona o un nuevo tipo de elemento).
- Recorrer mentalmente lo que pasa cuando uno hace `mision.ejecutar()`, paso por paso.
- Mostrar en el código dónde está cada uno de los cuatro pilares: abstracción, encapsulamiento, herencia, polimorfismo.

---

## Reflexión final

Fue tentador dejar que la IA nos diera el código y ya. Pero nos dimos cuenta rápido de que si íbamos a sustentar individualmente y sin asistencia, esa estrategia nos iba a costar caro. Entonces lo que hicimos fue usar la IA más para aprender que para producir.

Esto nos hizo el proyecto más largo de lo que hubiera sido si dejábamos que la IA lo escribiera todo, pero también nos dejó la confianza de poder hablar del código en la sustentación.