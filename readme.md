
# Programação de Competição - Análise Estatística com Vetores Dinâmicos

Este projeto apresenta uma aplicação completa para análise de dados em uma competição de programação, utilizando **vetores dinâmicos** e registros para armazenamento e processamento das informações. O sistema coleta dados de participantes, tempo de resolução de questões e grau de dificuldade, e exibe estatísticas detalhadas de desempenho, tanto por participante quanto por questão.

## Descrição Técnica

A aplicação utiliza estruturas avançadas de dados em **C++**, incluindo vetores dinâmicos e operadores sobrecarregados para facilitar a manipulação de horários e cálculos de tempo. Todo o programa é modularizado, com separação clara entre as funções de cálculo, resumo e exibição de dados.  

### Estrutura de Dados

- **Registro de Horário:** Representa a hora e minuto de início e término de cada questão.  
- **Registro de Questão:** Contém o grau de dificuldade e o horário de início e fim.  
- **Registro de Participante:** Armazena o nome e um ponteiro para as suas questões no vetor dinâmico.  
- **Registro de Média:** Utilizado para calcular as médias de dificuldade e tempo de resolução.  

### Arquitetura do Programa

O projeto é dividido em três arquivos principais:
- **`estatisticas.cpp`**: Contém a função principal (`main`), responsável pela coleta de dados, chamadas às funções de cálculo e exibição dos resultados.  
- **`concurso.h`**: Define os registros e protótipos das funções do programa.  
- **`concurso.cpp`**: Implementa as funções de cálculo, resumo e manipulação de dados.  

## Funcionamento

1. **Entrada de Dados:**  
   O programa solicita o número de participantes e questões. Para cada questão, o usuário deve informar:  
   - Grau de dificuldade (de 1 a 5)  
   - Horário de início e término (no formato horas e minutos)  

2. **Cálculo das Estatísticas:**  
   O programa calcula:  
   - Tempo total gasto em cada questão (em minutos)  
   - Resumo por participante e por questão  
   - Média de dificuldade e tempo para cada questão e para o concurso completo  

3. **Saída Formatada:**  
   Exibição das estatísticas detalhadas, com cálculos precisos e organização clara das informações.  

### Exemplo de Saída  

```
-----------------------
Resumo por Participante
-----------------------
João:
    A (1) 09:30 às 09:45 (15 min)
    B (4) 09:50 às 10:20 (30 min)
Pedro:
    A (2) 10:00 às 10:12 (12 min)
    B (5) 10:30 às 11:05 (35 min)
------------------
Resumo por Questão
------------------
Questão A:
    João (1) 09:30 às 09:45 (15 min)
    Pedro (2) 10:00 às 10:12 (12 min)
Questão B:
    João (4) 09:50 às 10:20 (30 min)
    Pedro (5) 10:30 às 11:05 (35 min)
------------------
Estatísticas
------------
Questão A: Dificuldade (1.50) – Tempo (13.50 minutos)
Questão B: Dificuldade (4.50) – Tempo (32.50 minutos)
Concurso:  Dificuldade (3.00) – Tempo (23.00 minutos)
```

## Tecnologias e Conceitos Aplicados

- **C++**: Linguagem utilizada para implementação.  
- **Vetores Dinâmicos**: Utilizados para armazenar participantes e questões.  
- **Registros e Ponteiros**: Manipulação eficiente de dados estruturados.  
- **Sobrecarga de Operadores (`operator-`)**: Para cálculo de diferença entre horários.  
- **Programação Modular**: Separação clara de responsabilidades para maior manutenção e escalabilidade do código.  

## Como Executar

1. Compile os arquivos (`estatisticas.cpp`, `concurso.cpp`) utilizando um compilador C++:
   ```g++ estatisticas.cpp concurso.cpp -o programacao-competicao```
2. Execute o programa:
   ```./programacao-competicao```
3. Insira o número de participantes e questões, seguido das informações solicitadas para cada questão.
