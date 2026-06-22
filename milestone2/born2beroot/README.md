*Este proyecto ha sido creado como parte del currículo de jruiz-ag.*

# Born2beRoot

## 1. Descripción
Born2beRoot es un proyecto de Administración de Sistemas que introduce los fundamentos de la virtualización, la configuración de servidores y la seguridad. El objetivo principal es crear un servidor mínimo y seguro dentro de una máquina virtual (usando VirtualBox o UTM) sin Interfaz Gráfica de Usuario (GUI).

Este proyecto requiere el cumplimiento estricto de protocolos de seguridad, incluyendo la configuración de un cortafuegos (firewall), el establecimiento de una política de contraseñas robusta, la gestión de grupos de usuarios, la restricción del acceso a sudo y la creación de particiones cifradas utilizando LVM. Además, se desarrolla un script en bash (monitoring.sh) para transmitir información del sistema a todos los terminales de los usuarios cada 10 minutos.

---

## 2. Instrucciones

### Ejecución y Conexión SSH
Dado que se trata de una máquina virtual, debe importarse y ejecutarse a través de VirtualBox (o UTM). 
Para conectarte a la máquina desde tu sistema anfitrión (host) vía SSH:

```bash
ssh [tu_login]@localhost -p 4242
```
(Nota: El inicio de sesión como root a través de SSH está deshabilitado por razones de seguridad).

### Verificación de la Firma de la VM
Durante la evaluación, la firma del disco de la máquina virtual se comparará con la del archivo signature.txt proporcionado en el repositorio. No inicies la máquina normalmente antes de la evaluación, ya que esto alterará la firma (usa snapshots si necesitas probarla). 
Para comprobar la firma:
* Linux/Windows: sha1sum [ruta_al_disco].vdi
* Mac/macOS: shasum [ruta_al_disco].vdi

### Script de Monitorización
El script monitoring.sh se ejecuta automáticamente cada 10 minutos usando cron. Para comprobar la configuración de cron:
```bash
sudo crontab -l
```
Para detener el script temporalmente sin modificarlo, puedes detener el servicio cron:
```bash
sudo systemctl stop cron
```

---

## 3. Decisiones de Diseño del Proyecto

### Sistema Operativo
Elegí Debian (última versión estable) en lugar de Rocky Linux. Debian es altamente estable, cuenta con un vasto repositorio de paquetes (gestionado mediante apt o aptitude) y el soporte de su comunidad lo hace ideal para aprender los fundamentos de la administración de sistemas.

### Particionado y LVM
El disco está particionado utilizando LVM (Logical Volume Manager) con cifrado (LUKS). 
* ¿Por qué LVM? Proporciona flexibilidad. Abstrae el almacenamiento físico, permitiéndonos redimensionar particiones sobre la marcha sin tener que formatear o migrar datos a un nuevo disco.
* Configuración: El sistema contiene al menos dos particiones cifradas para separar la lógica de arranque (boot) del sistema de archivos raíz y los datos de los usuarios.

### Políticas de Seguridad
* Política de Contraseñas: Configurada mediante libpam-pwquality y /etc/login.defs. Las contraseñas expiran cada 30 días, requieren un mínimo de 10 caracteres (incluyendo mayúsculas, minúsculas y números), y no pueden contener el nombre del usuario.
* Configuración de Sudo: El acceso a Sudo se registra estrictamente en /var/log/sudo/. Está limitado a 3 intentos de autenticación, requiere modo TTY, restringe las rutas disponibles (secure_path) y muestra un mensaje personalizado al introducir una contraseña incorrecta.

---

## 4. Comparativas Técnicas

Las siguientes comparaciones cubren las preguntas teóricas principales que se hacen durante la defensa:

### Sistemas Operativos
| Característica | Debian | Rocky Linux |
| :--- | :--- | :--- |
| **Origen** | Distribución Linux independiente impulsada por la comunidad. | Derivado (downstream) de Red Hat Enterprise Linux (RHEL). |
| **Gestor de Paquetes** | apt / dpkg (paquetes .deb). | dnf / rpm (paquetes .rpm). |
| **Ciclo de Lanzamiento** | Más lento, prioriza la estabilidad extrema. | Refleja los lanzamientos de RHEL, centrado en entornos empresariales. |
| **Facilidad de Uso** | Generalmente más amigable para principiantes. | Configuraciones predeterminadas más estrictas; curva de aprendizaje más pronunciada. |

### Control de Acceso Obligatorio (MAC)
| Característica | AppArmor (Por defecto en Debian) | SELinux (Por defecto en Rocky) |
| :--- | :--- | :--- |
| **Concepto** | Asegura las aplicaciones vinculando atributos de control de acceso a programas (Basado en rutas). | Asegura el sistema etiquetando archivos, procesos y puertos (Basado en etiquetas). |
| **Complejidad** | Más fácil de aprender, configurar y mantener. | Altamente granular, pero notoriamente complejo de configurar. |
| **Aplicación** | Los perfiles dictan a qué archivos/capacidades puede acceder un programa. | Las políticas dictan las interacciones entre los objetos etiquetados. |

### Cortafuegos (Firewalls)
| Característica | UFW (Uncomplicated Firewall) | firewalld |
| :--- | :--- | :--- |
| **Sistema Base** | Interfaz (Front-end) para iptables / nftables. | Interfaz (Front-end) para nftables / iptables. |
| **Enfoque** | Basado en reglas (permitir/denegar puertos/IPs específicos). Sintaxis muy sencilla. | Basado en zonas (asigna interfaces de red a zonas de confianza). |
| **Mejor Para** | Configuraciones de servidores simples y máquinas de propósito único. | Entornos de red complejos con niveles de confianza cambiantes. |

### Hipervisores
| Característica | VirtualBox | UTM |
| :--- | :--- | :--- |
| **Arquitectura** | Emulación y Virtualización (x86/x64). | Basado en QEMU; soporta Apple Silicon (ARM) mediante virtualización. |
| **Plataforma** | Ideal para máquinas basadas en Intel/AMD. | Necesario para usuarios de Mac modernos con chips M1/M2/M3. |

---

## 5. Recursos y Uso de IA

### Referencias
* Documentación Oficial de Debian (https://www.debian.org/doc/)
* Guía de Administración de LVM (https://tldp.org/HOWTO/LVM-HOWTO/)
* Hoja de Trucos de Scripting en Bash (https://devhints.io/bash)
* Conceptos Básicos de UFW (https://www.digitalocean.com/community/tutorials/ufw-essentials-common-firewall-rules-and-commands)

### Declaración de Uso de IA
De acuerdo con las directrices de IA de 42, las herramientas de IA se utilizaron de manera consciente durante este proyecto.
* ¿Para qué se utilizó la IA? La IA se utilizó principalmente como tutor para explicar conceptos complejos (ej. "Explica cómo funciona LVM como si tuviera 5 años") y para aclarar las diferencias entre apt y aptitude.
* ¿Para qué NO se utilizó la IA? La IA no se utilizó para generar el script de bash (monitoring.sh), escribir archivos de configuración, ni para omitir el proceso de instalación manual. Todos los comandos y configuraciones se escribieron y probaron manualmente para construir una base de conocimiento genuina.