# Calculadora HP 12C em C 💻

Projeto de uma calculadora financeira inspirada na HP 12C, desenvolvida em linguagem C.  
O programa é executado no **terminal** e utiliza três arquivos: `expressao.c`, `expressao.h` e `main.c`.

## ✨ Funcionalidades
- Avaliação de expressões numéricas básicas.  
- Operações financeiras típicas da HP 12C (como juros compostos, descontos, etc. – dependendo da implementação).  
- Separação de responsabilidades em múltiplos arquivos (`.c` e `.h`) para melhor organização do código.  

## 🛠️ Tecnologias Utilizadas
- Linguagem C.  
- Estruturas de dados simples (pilhas) para processamento de expressões.  
- Terminal como interface de entrada e saída.

## ▶️ Como compilar e executar
1. Abra o terminal e navegue até a pasta do projeto.  
2. Compile os arquivos com o GCC (ou outro compilador C):
```bash
gcc main.c expressao.c -o calculadora
