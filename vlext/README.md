# VL Syntax Highlighting

Extensão para o **VS Code** que fornece suporte de coloração de sintaxe (*syntax highlighting*) para a linguagem de programação **VL**.

## 🚀 Funcionalidades

Coloração de sintaxe completa baseada na gramática da linguagem, incluindo:
- **Estruturas de Controle:** `if`, `while`, `return`, `exec`, `import`, `as`
- **Tipos e Modificadores:** `fn`, `void`, `mut`, `const`
- **Comandos e Operadores:** `opn`, `set`, `print`, além de operadores aritméticos, de comparação e setas (`->`, `=>`).
- **Literais e Comentários:** Suporte a literais inteiros, de ponto flutuante, booleanos (`TRUE`, `FALSE`), strings e blocos de comentários (`;< ... >;`).

## ⚙️ Instalação (Local / VSIX)

Se você gerou o arquivo `.vsix` da extensão:
1. Abra o VS Code.
2. Vá até a aba de Extensões (`Ctrl + Shift + X`).
3. Clique nos três pontinhos (`...`) no canto superior direito.
4. Selecione **Install from VSIX...** e escolha o arquivo gerado.

## 📄 Exemplo de Código em VL

```vl
opn fn main() {
    exec {
        mut x => INT = 10;
        print(x);
    }
}