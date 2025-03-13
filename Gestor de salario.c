// Bibliotecas requeridas ---
#include <stdio.h>                // Para funciones de entrada y salida (printf)
#include <stdlib.h>              // Para activar la función system("pause")
#include <string.h>             // Para manipulación de cadenas (strlen)
#include <locale.h>            // Para configuración regional (setlocale)
#ifdef _WIN32                 // Si el sistema es Windows:
#include <windows.h>         // Incluye funciones de la API de Windows (SetConsoleOutputCP)
#endif

#define WIDTH 80           // Ancho de la consola para el centrado de texto (80 Caracteres)

// --- Configuración de codificación ---
void configure_encoding() {
    #ifdef _WIN32
  // Configura la consola en Windows para usar UTF-8 al abrir el programa (evita caracteres corruptos).
        SetConsoleOutputCP(CP_UTF8);
    #endif
// Configuración regional para configurar UTF-8 en todos los sistemas operativos
    setlocale(LC_ALL, "en_US.UTF-8");  // "en_US.UTF-8" es compatible con la mayoria de sistemas operativos.
}

// --- Función para imprimir texto centrado ---
void print_centered(const char *text) {
    int len = strlen(text);  // Longitud original del texto.

  // Ajuste de longitud si el texto termina en salto de línea:
    if (len > 0 && text[len - 1] == '\n') len--;  // Ignora '\n' para cálculos de centrado.

  // Cálculo de espacios a la izquierda:
    int padding = (WIDTH - len) / 2;  // Espacios = (Ancho total - Longitud de texto) / 2.
    if (padding < 0) padding = 0;    // Evita valores negativos (textos más largos que WIDTH)

  // Impresión eficiente:
    // - "%*s": Crea una cadena de 'padding' espacios en blanco.
   // - "%s": Imprime el texto original (incluyendo su '\n' si lo tiene).
    printf("%*s%s", padding, "", text);
}
// --- Función principal ---
int main() {
    configure_encoding();   // Primero asegura que la consola maneje UTF-8
    // Impresión de lineas centradas:
    print_centered("***Fundamentos de programación U2 Act2***\n");
    print_centered("***Gestor de salario***\n");
    print_centered("Estudiante: Orlando Antonio Maturano Pizaña - Matrícula: ES251107915 - Grupo: DS-DFPR-2501-B1-013\n");
    print_centered("================================================================================\n");

  // --- Entrada de datos ---
    char nombre[100];
    float salario;

  printf("---Ingrese su nombre: ");
  fgets(nombre, sizeof(nombre), stdin);            // Lee nombre con espacios.
  nombre[strcspn(nombre, "\n")] = '\0';            // Elimina el salto de línea.

  printf("Ingrese su salario mensual: ");
  scanf_s("%f", &salario);                           // Lee el salario.
  
  // --- Cálculos ---
  const float RENTA = salario * 0.25f;
  const float ALIMENTOS = salario * 0.30f;
  const float BANCO = salario * 0.07f;
  const float EDUCACION = salario * 0.20f;
  const float OTROS = salario * 0.10f;
  const float DIVERSION = salario - (RENTA + ALIMENTOS + BANCO + EDUCACION + OTROS);

  // --- Salida formateada ---
  printf("\n---Nombre del trabajador: %s\n", nombre);
  printf("Distribución del salario\n");
  printf("Renta: $%.2f (25%%)\n", RENTA);
  printf("Comida: $%.2f (30%%)\n", ALIMENTOS);
  printf("Pagos bancarios: $%.2f (7%%)\n", BANCO);
  printf("Educación: $%.2f (20%%)\n", EDUCACION);
  printf("Otros gastos: $%.2f (10%%)\n", OTROS);
  printf("Diversión: $%.2f (%.0f%%)\n", DIVERSION, (DIVERSION/salario)*100);

  // --- Pausa para evitar que el programa se cierre ---
    #ifdef _WIN32
        system("pause");    // Solo en Windows.
    #else
        system("read -p 'Presiona Enter para continuar...'");  // Linux y macOS
    #endif

    return 0;  // Fin exitoso.
}

