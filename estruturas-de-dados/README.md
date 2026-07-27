# Estruturas de Dados

Materiais, exercícios e desafios da disciplina de Estruturas de Dados em C++.

## Conteúdos atuais

```text
estruturas-de-dados/
├── semana-05/
│   └── aula/
│       └── arvore binaria de busca (BST)
└── semana-06/
    ├── aula-16/
    │   └── arvore AVL
    └── desafio/
        └── indice AVL de medicoes
```

## Como compilar os exemplos em C++

No Windows, usando MSYS2 UCRT64, entre na pasta do exemplo e compile os
arquivos `.cpp` daquele programa.

Semana 5:

```bash
cd estruturas-de-dados/semana-05/aula
g++ -std=c++20 -O2 -Wall -Wextra -pedantic search_tree_aplicacao.cpp search_tree.cpp aluno.cpp -o app.exe
./app.exe
```

Semana 6, aula AVL:

```bash
cd estruturas-de-dados/semana-06/aula-16
g++ -std=c++20 -O2 -Wall -Wextra -pedantic avl_search_tree_aplicacao.cpp avl_search_tree.cpp aluno.cpp -o app.exe
./app.exe
```

Semana 6, desafio AVL:

```bash
cd estruturas-de-dados/semana-06/desafio
g++ -std=c++20 -O2 -Wall -Wextra -pedantic main.cpp measurement_avl.cpp -o app.exe
./app.exe
```

## Convenções

- Materiais originais da aula ficam em pastas `aula/` ou equivalentes.
- Desafios e soluções próprias ficam em `desafio/` ou `exercicios/`.
- Executáveis gerados localmente não devem ser versionados.
