# Projetos de Arduino: Sequência de LEDs e Calculadora Binária

Este repositório contém arquivos de código e documentação para dois projetos práticos de eletrônica digital e programação Arduino:

1.  **Sequência Circular de LEDs**: Um circuito que acende LEDs em um ciclo contínuo.
2.  **Calculadora Binária com LEDs**: Uma calculadora simples que realiza adição e subtração e exibe o resultado em binário usando LEDs.

---

## 📂 Estrutura de Arquivos

| Arquivo | Descrição |
| :--- | :--- |
| `Atividade - Sequência Circular de Leds.pdf` | Documentação do projeto Sequência Circular de LEDs. |
| `sequenciaCircular.ino` | Código Arduino para o projeto Sequência Circular de LEDs. |
| `sequenciaCircular_imagem.pdf` | Imagem do protótipo físico (com 3 LEDs) do projeto de Sequência Circular. |
| `Atividade - Calculadora Binária com Leds.pdf` | Documentação do projeto Calculadora Binária com LEDs. |
| `CalculadoraBinaria.ino` | Código Arduino para o projeto Calculadora Binária. |
| `CalculadoraBinaria_imagem.pdf` | Imagem do protótipo físico do projeto Calculadora Binária (com 3 LEDs). |

---

## 1️⃣ Sequência Circular de LEDs

### 📝 Descrição do Projeto

Este projeto consiste em desenvolver um protótipo no **Circuits** (usando Arduino Uno) para ligar e desligar indefinidamente uma **sequência circular de seis LEDs** de cores distintas. Cada LED deve ficar ligado por exatamente um segundo a cada ciclo.

A posição relativa de cada LED na sequência, indicada pela variável **$x$**, corresponde à respectiva porta digital do Arduino.


### 💻 Código (`sequenciaCircular.ino`)

O código implementa um *loop* que liga e desliga cada LED na sequência:

* **Variável de Controle:** `int x = 0`.
* **Mapeamento de Portas:** O código utiliza as portas digitais do Arduino (provavelmente portas 2, 3 e 4, conforme a inicialização no `setup`). O cálculo da porta é feito com `x + 2`.
* **Lógica do Loop (`loop()`):**
    * Liga o LED na porta `x + 2` (`digitalWrite(x + 2, HIGH)`).
    * Aguarda 1000 milissegundos (1 segundo) (`delay(1000)`).
    * Desliga o LED na porta `x + 2` (`digitalWrite(x + 2, LOW)`).
    * **Avança $x$** usando a operação módulo: `x = (x + 1) % 3`.

> **Nota:** A lógica no código (`x = (x + 1) % 3`) configura uma sequência de **3 LEDs** (índices 0, 1, 2). O documento original pede 6 LEDs ($x$ variando de 0 a 5). Para 6 LEDs, a linha de avanço deveria ser `x = (x + 1) % 6`.

### ➗ Cálculo do Resistor

O valor do resistor para cada LED deve ser calculado usando a **Lei de Ohm** e considerando a tensão de saída do Arduino ($5V$) e a corrente desejada ($20mA$).

A fórmula usada é:
$$R = \frac{V_{fonte} - V_{LED}}{I}$$
Onde:
* $V_{fonte} = 5V$
* $I = 20mA = 0.020A$
* $V_{LED}$ varia conforme a cor.

| Cor do LED | $V_{LED}$ (Tensão Nominal) [cite: 8, 9, 10, 11, 12] | Cálculo ($R$) |
| :--- | :--- | :--- |
| Vermelho | $\sim 2.0V$  | $R = (5V - 2.0V) / 0.020A = 150 \Omega$ |
| Amarelo | $\sim 2.2V$  | $R = (5V - 2.2V) / 0.020A = 140 \Omega$ |
| Laranja | $\sim 2.2V$  | $R = (5V - 2.2V) / 0.020A = 140 \Omega$ |
| Verde | $\sim 2.2V$  | $R = (5V - 2.2V) / 0.020A = 140 \Omega$ |
| Azul | $\sim 2.6V$  | $R = (5V - 2.6V) / 0.020A = 120 \Omega$ |
| Branco (Composto)| $\sim 3.0V$  | $R = (5V - 3.0V) / 0.020A = 100 \Omega$ |

---

## 2️⃣ Calculadora Binária com LEDs

### 📝 Descrição do Projeto

O objetivo é construir uma calculadora que execute **adição** e **subtração** de dois números (A e B).

* **Entrada de Dados:** Os números A e B são inseridos pelo usuário no **Monitor Serial** (console) na notação **decimal**, juntamente com o operador (+ ou -).
* **Saída (Resultado X):** O resultado **X** é um número de 5 bits e é representado por **5 LEDs**.
    * Cada LED representa um bit.
    * A identificação dos bits é feita em ordem crescente, da direita (bit menos significativo, bit 0) para a esquerda (bit mais significativo, bit 4).


### 💻 Código (`CalculadoraBinaria.ino`)

O código utiliza a abordagem de fazer o cálculo em decimal e depois converter o resultado para binário (opção 1 no documento).

* **Definição de Portas (3 LEDs):** O código usa 3 LEDs (Verde, Vermelho, Amarelo) nas portas 4, 3 e 2, respectivamente, o que limita a exibição a resultados de 3 bits (0 a 7).
* **Leitura de Dados:** O programa usa `Serial.parseInt()` e `Serial.read()` para receber o primeiro número (`A`), o operador e o segundo número (`B`).
* **Lógica de Validação e Cálculo:**
    * **Subtração:** Válida se $A \ge B$ e $A - B \le 7$.
    * **Adição:** Válida se $A + B \le 7$.
    * Se a condição for válida, calcula `resultado`. Caso contrário, exibe "Dados inválidos!!!".
* **Exibição Binária:** O resultado é exibido nos 3 LEDs (Verde, Vermelho, Amarelo) usando a função **`bitRead()`**:
    * LED Amarelo (Porta 2): Exibe o **Bit 0** do resultado (`bitRead(resultado, 0)`).
    * LED Vermelho (Porta 3): Exibe o **Bit 1** do resultado (`bitRead(resultado, 1)`).
    * LED Verde (Porta 4): Exibe o **Bit 2** do resultado (`bitRead(resultado, 2)`).

> **Nota:** O documento original pede um resultado **X de 5 bits**. O código fornecido só utiliza 3 LEDs, limitando o resultado máximo a $2^3 - 1 = 7$. Para atender ao requisito de 5 bits, seriam necessários mais dois LEDs conectados às portas do Arduino, exibindo os bits 3 e 4.
