# Projeto de Decodificador de Código Morse - Raspberry Pi Pico W

Este projeto foi desenvolvido para o programa **Embarca Tech** em parceria com o **IFPI Pedro II**, utilizando o **Raspberry Pi Pico W**. O objetivo é implementar um decodificador de código Morse que utiliza dois botões físicos para inserir pontos e traços, e depois traduz a sequência de Morse em letras do alfabeto.

## Descrição

O sistema consiste em dois botões conectados ao Raspberry Pi Pico W. O botão A (pino 5) insere um ponto (`.`) e o botão B (pino 6) insere um traço (`-`) no código Morse. A sequência de Morse é traduzida para o caractere correspondente após um tempo de inatividade (configurado como 1500ms). O caractere traduzido é exibido no terminal.

### Funcionalidades:
- Utiliza dois botões físicos para entrada do código Morse.
- Traduz o código Morse para o alfabeto latino.
- Exibe a tradução dos caracteres no terminal.

## Requisitos

- **Raspberry Pi Pico W**.
- **Cabo micro-USB** para conexão com o computador.
- **Raspberry Pi OS** ou outro sistema operacional compatível para desenvolvimento.
- **Ferramentas de desenvolvimento C para Raspberry Pi Pico** instaladas (ex: [Pico SDK](https://github.com/raspberrypi/pico-sdk)).
- **Visual Studio Code (VSCode)**: Recomendado para edição do código e carregamento no Raspberry Pi Pico W.

## Configuração do Ambiente no VSCode

1. **Instalar o VSCode**:
   - Se ainda não tiver, baixe e instale o [Visual Studio Code](https://code.visualstudio.com/).

2. **Instalar Extensões Necessárias**:
   - Instale a extensão **C/C++** no VSCode (busque por "C++" na loja de extensões do VSCode).
   - Instale a extensão **CMake Tools** para facilitar a configuração e construção do projeto.

3. **Configurar o Ambiente do Raspberry Pi Pico**:
   - Siga o tutorial do [Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk) para configurar o ambiente de desenvolvimento no seu computador.
   - Verifique se o caminho do SDK do Raspberry Pi Pico está corretamente configurado no VSCode.

4. **Compilar e Carregar o Código**:
   - Abra o projeto no VSCode.
   - Compile o código utilizando a extensão **CMake** ou as ferramentas de terminal configuradas.
   - Conecte o Raspberry Pi Pico W ao seu computador via cabo USB.
   - Carregue o código no Raspberry Pi Pico W, seguindo as instruções do SDK ou usando o **VSCode** com a extensão **Pico Debugger**.

5. **Rodar o Projeto**:
   - Após carregar o código, abra o terminal no VSCode e verifique a saída da tradução do código Morse para o alfabeto.

## Conexões

- **Botão A**: Pino 5 do Raspberry Pi Pico W (para o ponto `.`).
- **Botão B**: Pino 6 do Raspberry Pi Pico W (para o traço `-`).

## Estrutura do Código

### Bibliotecas Utilizadas

- `pico/stdlib.h`: Biblioteca padrão para o Raspberry Pi Pico W.
- `hardware/gpio.h`: Biblioteca para manipulação de GPIOs do Raspberry Pi Pico.
- `string.h`: Biblioteca para manipulação de strings em C.

### Definições
- **BOTAO_A (5)**: Pino conectado ao botão A.
- **BOTAO_B (6)**: Pino conectado ao botão B.
- **MAX_SEQ (5)**: Tamanho máximo da sequência de Morse que pode ser inserida.
- **TIMEOUT (1500)**: Tempo de inatividade (em milissegundos) para finalizar a entrada e traduzir a sequência de Morse.

### Funções Principais

- **adicionar_simbolo(char simbolo)**: Adiciona um ponto (`.`) ou traço (`-`) ao código Morse.
- **traduzir_morse()**: Traduz a sequência de Morse armazenada para o alfabeto latino.
- **main()**: Função principal que configura os botões e realiza a leitura e tradução do código Morse.

## Como Usar

1. **Compilação e Carregamento**:
   - Compile o código utilizando o **Pico SDK**.
   - Carregue o código no Raspberry Pi Pico W.

2. **Operação**:
   - Pressione o botão A para inserir um ponto (`.`).
   - Pressione o botão B para inserir um traço (`-`).
   - Após uma pausa de 1500ms (sem pressionar os botões), o código será traduzido e o caractere correspondente será exibido no terminal.

3. **Exemplo de Entrada**:
   - Pressione o botão A, depois o botão B. A sequência gerada será `.-`, que corresponde à letra "A".

## Explicação do Código

- O código está estruturado para identificar as entradas de Morse usando dois botões.
- Quando o botão A é pressionado, um ponto (`.`) é adicionado à sequência.
- Quando o botão B é pressionado, um traço (`-`) é adicionado.
- O código verifica o tempo de inatividade após cada entrada para decidir quando traduzir a sequência e exibi-la no terminal.
- A tradução do código Morse é feita por meio da função `traduzir_morse()`, que compara a sequência de símbolos com os padrões predefinidos para cada letra do alfabeto.

## Considerações Finais

Este projeto é uma demonstração simples de como usar o Raspberry Pi Pico W para realizar tarefas de entrada e processamento de dados em tempo real com botões físicos. O código pode ser expandido para suportar mais funcionalidades, como a adição de um display para mostrar as letras traduzidas ou a implementação de um sistema de feedback sonoro.

## Licença

Este projeto é de código aberto e está disponível para reutilização e modificação sob a licença [MIT](https://opensource.org/licenses/MIT).
