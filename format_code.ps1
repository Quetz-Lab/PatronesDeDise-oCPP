# Script de PowerShell para formatear todo el código fuente
# Requiere tener clang-format instalado

Write-Host "Formateando código fuente con clang-format..." -ForegroundColor Green

# Verificar si clang-format está disponible
try {
    $clangFormatVersion = clang-format --version
    Write-Host "Usando: $clangFormatVersion" -ForegroundColor Cyan
} catch {
    Write-Host "Error: clang-format no está instalado o no está en el PATH" -ForegroundColor Red
    Write-Host "Para instalar clang-format:" -ForegroundColor Yellow
    Write-Host "1. Instalar LLVM desde https://llvm.org/builds/" -ForegroundColor Yellow
    Write-Host "2. O usar Visual Studio Installer para agregar 'LLVM (clang-cl)'" -ForegroundColor Yellow
    Write-Host "3. O usar chocolatey: choco install llvm" -ForegroundColor Yellow
    exit 1
}

# Archivos a formatear
$sourceFiles = @(
    "src\PatronesDeDisenoCPP.cpp",
    "src\Core\Character.cpp",
    "src\Patterns\Command.cpp",
    "src\Patterns\EventQueue.cpp",
    "src\Patterns\InputHandler.cpp",
    "src\Patterns\Observer.cpp",
    "src\Patterns\State.cpp",
    "src\System\Achievements.cpp",
    "src\System\AudioSystem.cpp"
)

$headerFiles = @(
    "Include\Core\Character.h",
    "Include\Patterns\Command.h",
    "Include\Patterns\EventQueue.h",
    "Include\Patterns\InputHandler.h",
    "Include\Patterns\Observer.h",
    "Include\Patterns\State.h",
    "Include\Systems\Achievements.h",
    "Include\Systems\AudioSystem.h"
)

# Formatear archivos fuente
Write-Host "`nFormateando archivos .cpp..." -ForegroundColor Blue
foreach ($file in $sourceFiles) {
    if (Test-Path $file) {
        Write-Host "  Formateando: $file"
        clang-format -i $file
    } else {
        Write-Host "  Archivo no encontrado: $file" -ForegroundColor Yellow
    }
}

# Formatear archivos header
Write-Host "`nFormateando archivos .h..." -ForegroundColor Blue
foreach ($file in $headerFiles) {
    if (Test-Path $file) {
        Write-Host "  Formateando: $file"
        clang-format -i $file
    } else {
        Write-Host "  Archivo no encontrado: $file" -ForegroundColor Yellow
    }
}

Write-Host "`n✅ Formateo completado!" -ForegroundColor Green
Write-Host "Revisa los cambios con git diff antes de hacer commit." -ForegroundColor Cyan