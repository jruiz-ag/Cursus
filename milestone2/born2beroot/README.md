*Este proyecto ha sido creado como parte del currículo de 42 por jruiz-ag.*

# Born2beRoot

## 1. Descripción
Born2beRoot es un proyecto de Administración de Sistemas que introduce los fundamentos de la virtualización, la configuración de servidores y la seguridad. El objetivo principal es crear un servidor mínimo y seguro dentro de una máquina virtual (usando VirtualBox o UTM) sin Interfaz Gráfica de Usuario (GUI).

Este proyecto requiere el cumplimiento estricto de protocolos de seguridad, incluyendo la configuración de un cortafuegos (firewall), el establecimiento de una política de contraseñas robusta, la gestión de grupos de usuarios, la restricción del acceso a sudo y la creación de particiones cifradas utilizando LVM. Además, se desarrolla un script en bash (monitoring.sh) para transmitir información del sistema a todos los terminales de los usuarios cada 10 minutos.

---

## 2. Instrucciones

### Ejecución y Conexión SSH
Dado que se trata de una máquina virtual, debe importarse y ejecutarse a través de VirtualBox (o UTM). Para conectarte a la máquina desde tu sistema anfitrión (host) vía SSH utilizando el puerto redirigido, ejecuta en tu terminal local:

```bash
ssh jruiz-ag@localhost -p 4242
```
*(Nota: El inicio de sesión como root a través de SSH está deshabilitado por razones de seguridad).*

### Verificación de la Firma de la VM
Durante la evaluación, la firma del disco de la máquina virtual se comparará con la del archivo signature.txt proporcionado en el repositorio. No inicies la máquina normalmente antes de la evaluación, ya que esto alterará la firma (usa snapshots si necesitas probarla).

Comandos para obtener el hash SHA1 según tu sistema operativo:
* **Linux:** sha1sum [ruta_al_disco].vdi

---

## 3. Decisiones de Diseño y Justificaciones

### Sistema Operativo: Debian
* **Elección:** Debian (última versión estable) en lugar de Rocky Linux.
* **Justificación:** Debian es altamente estable, cuenta con un vasto repositorio de paquetes (gestionado mediante apt o aptitude) y el soporte de su comunidad lo hace ideal para aprender los fundamentos de la administración de sistemas. A diferencia de Rocky Linux, Debian ofrece una curva de aprendizaje más amigable sin la sobrecomplicación de configuraciones predeterminadas restrictivas orientadas a entornos empresariales masivos.

### Hipervisor para la VM
* **Elección:** VirtualBox
* **Justificación:** Es el hipervisor más universal por lo que tiene más soporte y foros donde resolver dudas, además permite la virtualización con mayor facilidad y compatibilidad que el resto de competencias.

### Control de Acceso Obligatorio: AppArmor
* **Elección:** AppArmor (nativo y por defecto en Debian).
* **Justificación:** Se optó por AppArmor en lugar de SELinux por su enfoque basado en rutas de archivos. Esto facilita la creación y mantenimiento de perfiles de seguridad para aislar aplicaciones. SELinux, al basarse en etiquetas, introduce una complejidad innecesaria y propensa a errores para el alcance de este servidor.

### Cortafuegos: UFW (Uncomplicated Firewall)
* **Elección:** UFW.
* **Justificación:** Para un servidor con el propósito específico de exponer únicamente el puerto 4242, UFW es la herramienta ideal. Su filosofía basada en reglas directas permite blindar el tráfico de forma legible y rápida, evitando la sobrecarga abstracta de sistemas basados en zonas de red como firewalld.

### Políticas de Seguridad y Sudo
* **Política de Contraseñas:** Configurada mediante libpam-pwquality y /etc/login.defs. Las contraseñas expiran cada 30 días, requieren un mínimo de 10 caracteres (incluyendo mayúsculas, minúsculas y números), y no pueden contener el nombre del usuario.
* **Configuración de Sudo:** El acceso se registra estrictamente en /var/log/sudo/. Está limitado a 3 intentos de autenticación, requiere modo TTY, restringe las rutas disponibles (secure_path) y muestra un mensaje personalizado al introducir una contraseña incorrecta.

---

## 4. Comparativas Técnicas

### Sistemas Operativos
| Característica | Debian | Rocky Linux |
| :--- | :--- | :--- |
| **Origen** | Distribución Linux independiente impulsada por la comunidad. | Derivado (downstream) de Red Hat Enterprise Linux (RHEL). |
| **Gestor de Paquetes** | apt / dpkg (paquetes .deb). | dnf / rpm (paquetes .rpm). |
| **Ciclo de Lanzamiento** | Más lento, prioriza la estabilidad extrema. | Refleja los lanzamientos de RHEL, centrado en entornos empresariales. |
| **Facilidad de Uso** | Generalmente más amigable para principiantes. | Configuraciones predeterminadas más estrictas; curva de aprendizaje pronunciada. |

### Control de Acceso Obligatorio (MAC)
| Característica | AppArmor (Por defecto en Debian) | SELinux (Por defecto en Rocky) |
| :--- | :--- | :--- |
| **Concepto** | Asegura las aplicaciones vinculando atributos a programas (Basado en rutas). | Asegura el sistema etiquetando archivos, procesos y puertos (Basado en etiquetas). |
| **Complejidad** | Más fácil de aprender, configurar y mantener. | Altamente granular, pero notoriamente complejo de configurar. |
| **Aplicación** | Los perfiles dictan a qué archivos/capacidades puede acceder un programa. | Las políticas dictan las interacciones entre los objetos etiquetados. |

### Cortafuegos (Firewalls)
| Característica | UFW (Uncomplicated Firewall) | firewalld |
| :--- | :--- | :--- |
| **Sistema Base** | Interfaz (Front-end) para iptables / nftables. | Interfaz (Front-end) para nftables / iptables. |
| **Enfoque** | Basado en reglas (permitir/denegar puertos/IPs específicos). | Basado en zonas (asigna interfaces de red a zonas de confianza). |
| **Mejor Para** | Configuraciones de servidores simples y máquinas de propósito único. | Entornos de red complejos con niveles de confianza cambiantes. |

### Hipervisores
| Característica | VirtualBox | UTM |
| :--- | :--- | :--- |
| **Arquitectura** | Emulación y Virtualización (x86/x64). | Basado en QEMU; soporta Apple Silicon (ARM) mediante virtualización. |
| **Plataforma** | Ideal para máquinas basadas en Intel/AMD. | Necesario para usuarios de Mac modernos con chips M1/M2/M3. |

---

## 5. Comandos Interesantes

### Verificación del Sistema y SSH
* **Comprobar la versión del Kernel y arquitectura:** `uname -a`
* **Comprobar el estado del servicio SSH:** `sudo systemctl status ssh`
* **Verificar que el puerto de escucha de SSH es el 4242:** `sudo ss -tunlp | grep ssh`
* **Cambiar nombre de la terminal con su hostname:** `sudo hostnamectl set-hostname "nuevo_nombre"`

### Verificación del Cortafuegos y AppArmor
* **Comprobar el estado del firewall y sus reglas activas:** `sudo ufw status numbered`
* **Comprobar que AppArmor está cargado y activo:** `sudo aa-status`

### Gestión de Usuarios y Grupos
* **Mostrar todos los usuarios locales creados en el sistema:** `cut -d: -f1 /etc/passwd`
* **Comprobar a qué grupos pertenece tu usuario:** `groups jruiz-ag`
* **Crear un nuevo usuario (requerido en la evaluación):** `sudo adduser nuevo_usuario`
* **Crear un grupo y añadir al usuario (requerido en la evaluación):** `sudo groupadd nuevo_grupo` y luego `sudo adduser nuevo_usuario nuevo_grupo`

### Políticas de Contraseñas y Sudo
* **Comprobar las políticas de caducidad de contraseña de tu usuario:** `sudo chage -l jruiz-ag`
* **Ver el registro (logs) de acciones realizadas con sudo:** `sudo ls -l /var/log/sudo/` y `sudo cat /var/log/sudo/sudo.log`

---

## 6. Recursos y Uso de IA

### Referencias
* Documentación Oficial de Debian ([https://www.debian.org/doc/](https://www.debian.org/doc/))
* Guía de Administración de LVM ([https://tldp.org/HOWTO/LVM-HOWTO/](https://tldp.org/HOWTO/LVM-HOWTO/))
* Hoja de Trucos de Scripting en Bash ([https://devhints.io/bash](https://devhints.io/bash))
* Conceptos Básicos de UFW ([https://www.digitalocean.com/community/tutorials/ufw-essentials-common-firewall-rules-and-commands](https://www.digitalocean.com/community/tutorials/ufw-essentials-common-firewall-rules-and-commands))

### Declaración de Uso de IA
De acuerdo con las directrices de IA de 42, las herramientas de IA se utilizaron de manera consciente durante este proyecto. Principalmente para la aclaración de conceptos y fundamentos de administración de sistemas, así como la comprensión de la estructura de comandos para el script de monitorización.