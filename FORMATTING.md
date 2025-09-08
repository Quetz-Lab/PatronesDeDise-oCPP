# Guía de Formateo de Código

Este proyecto utiliza **clang-format** para mantener un estilo de código consistente en todos los archivos C++.

## 🔧 Instalación de clang-format

### Opción 1: Visual Studio (Recomendado)
1. Abrir **Visual Studio Installer**
2. Modificar tu instalación de Visual Studio
3. En "Componentes individuales", buscar y seleccionar:
   - **LLVM (clang-cl)**
   - **CMake tools for Visual Studio**
4. Aplicar cambios

### Opción 2: LLVM Standalone
1. Descargar LLVM desde: https://llvm.org/builds/
2. Instalar y agregar al PATH del sistema
3. Reiniciar la terminal/IDE

### Opción 3: Chocolatey (Windows)
```powershell
# Instalar chocolatey si no lo tienes
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))

# Instalar LLVM
choco install llvm
```

### Opción 4: Scoop (Windows)
```powershell
# Instalar scoop si no lo tienes
Set-ExecutionPolicy RemoteSigned -Scope CurrentUser
irm get.scoop.sh | iex

# Instalar LLVM
scoop install llvm
```

## 🚀 Uso del Formateo

### Formateo Automático (Script)
```powershell
# Ejecutar el script de formateo
.\format_code.ps1
```

### Formateo Manual
```bash
# Formatear un archivo específico
clang-format -i src/PatronesDeDisenoCPP.cpp

# Formatear todos los archivos .cpp y .h
clang-format -i src/**/*.cpp Include/**/*.h
```

### Verificar Formateo sin Aplicar Cambios
```bash
# Ver diferencias sin aplicar cambios
clang-format src/PatronesDeDisenoCPP.cpp

# Verificar si un archivo necesita formateo
clang-format --dry-run --Werror src/PatronesDeDisenoCPP.cpp
```

## 📋 Configuración del Estilo

El archivo `.clang-format` en la raíz del proyecto define el estilo de código:

### Características Principales:
- **Estilo base**: Google con modificaciones
- **Indentación**: 4 espacios (sin tabs)
- **Límite de línea**: 100 caracteres
- **Llaves**: Estilo Allman (nueva línea)
- **Punteros**: Alineados a la izquierda (`int* ptr`)
- **Espacios**: Configuración consistente
- **Includes**: Ordenamiento automático

### Ejemplo de Formateo:

**Antes:**
```cpp
class Character{
private:float _health;int _damage;
public:Character(float health,int damage):_health(health),_damage(damage){}
void Jump(){std::cout<<"Saltando"<<std::endl;}
};
```

**Después:**
```cpp
class Character
{
private:
    float _health;
    int _damage;

public:
    Character(float health, int damage) : _health(health), _damage(damage)
    {
    }
    
    void Jump()
    {
        std::cout << "Saltando" << std::endl;
    }
};
```

## 🔄 Integración con IDEs

### Visual Studio
1. **Herramientas** → **Opciones**
2. **Editor de texto** → **C/C++** → **Formato**
3. Habilitar **"Habilitar ClangFormat"**
4. Configurar para usar archivo `.clang-format`

### Visual Studio Code
1. Instalar extensión **"C/C++"** de Microsoft
2. Instalar extensión **"Clang-Format"**
3. Configurar en `settings.json`:
```json
{
    "C_Cpp.clang_format_style": "file",
    "editor.formatOnSave": true,
    "[cpp]": {
        "editor.defaultFormatter": "ms-vscode.cpptools"
    }
}
```

## 📝 Comandos Útiles

```bash
# Formatear y mostrar diferencias
clang-format -i src/PatronesDeDisenoCPP.cpp && git diff

# Formatear solo archivos modificados (Git)
git diff --name-only --diff-filter=M | grep -E '\.(cpp|h)$' | xargs clang-format -i

# Verificar formateo en CI/CD
find . -name "*.cpp" -o -name "*.h" | xargs clang-format --dry-run --Werror
```

## 🎯 Beneficios del Formateo Consistente

1. **Legibilidad**: Código más fácil de leer y entender
2. **Mantenimiento**: Menos tiempo perdido en discusiones de estilo
3. **Colaboración**: Diffs más limpios en control de versiones
4. **Profesionalismo**: Código que se ve pulido y bien mantenido
5. **Automatización**: Menos errores manuales de formato

## 🚨 Notas Importantes

- **Siempre revisa** los cambios antes de hacer commit
- **Ejecuta el formateo** antes de cada pull request
- **No modifiques** `.clang-format` sin consenso del equipo
- **Usa el script** `format_code.ps1` para formatear todo el proyecto de una vez

## 🔍 Solución de Problemas

### Error: "clang-format no se reconoce"
- Verificar que LLVM esté instalado
- Agregar LLVM al PATH del sistema
- Reiniciar terminal/IDE

### Formateo inconsistente
- Verificar que `.clang-format` esté en la raíz del proyecto
- Usar `clang-format --version` para verificar la versión
- Diferentes versiones pueden producir resultados ligeramente diferentes

### Conflictos con IDE
- Deshabilitar otros formateadores automáticos
- Configurar IDE para usar clang-format exclusivamente
- Verificar configuración de tabs vs espacios