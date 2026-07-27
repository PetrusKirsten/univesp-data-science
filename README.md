# univesp-data-science

Repositório acadêmico centralizado para organizar estudos, materiais de aula,
exercícios e pequenos projetos das disciplinas da UNIVESP ligadas a Ciência de
Dados.

## Disciplinas

| Disciplina | Pasta | Status |
| --- | --- | --- |
| Estruturas de Dados | `estruturas-de-dados/` | Em andamento |
| Modelagem e Inferência Estatística | `modelagem-inferencia-estatistica/` | A iniciar |
| Bancos de Dados | `bancos-de-dados/` | A iniciar |

## Organização

Cada disciplina deve manter uma estrutura simples e previsível:

```text
disciplina/
├── README.md
├── semana-01/
│   ├── aula/
│   ├── exercicios/
│   └── dados/
└── semana-02/
```

Convenções gerais:

- `aula/`: materiais originais da disciplina, preservados quando possível.
- `exercicios/`: resoluções próprias, desafios e experimentos.
- `dados/`: datasets pequenos ou arquivos de exemplo.
- `notebooks/`: análises em Python/Jupyter, quando fizer sentido.
- `sql/`: scripts SQL executáveis.
- `diagramas/`: modelos entidade-relacionamento, esquemas e imagens de apoio.

## Fluxo de trabalho

1. Criar ou atualizar uma pasta por semana.
2. Manter materiais originais separados das soluções próprias.
3. Registrar comandos de execução nos READMEs dos exercícios relevantes.
4. Fazer commits pequenos e descritivos.

Exemplos de mensagens:

```text
feat(data-structures): add avl measurement index challenge
docs(stats): add week 01 regression notes
feat(db): create laboratory sample schema
```
