# Projeto “ Turma do Café”

Uma comunidade é um grupo de pessoas que compartilham interesses
comuns, valores, identidade cultural, ou que estão conectadas de
alguma forma. Essa conexão pode ser baseada em diversos fatores,
como localização geográfica, afinidades culturais, religiosas, étnicas,
profissionais, ou mesmo interesses específicos, como hobbies ou
atividades compartilhadas.
Na Fatec Araras, surgiu uma comunidade com um interesse em
comum: café.
Seu programa deve auxiliar esta comunidade no controle dos
participantes e contribuintes.

# Quem são os participantes da comunidade ?

1) Criar uma estrutura que armazene um número inteiro como ID, o nome (somente primeiro nome),
semestre e ano de ingresso na Fatec Araras e curso (DSM ou SI ou GE). Não há limites, logo, não há número
mínimo ou máximo de participantes. 
Deve existir uma opção no menu principal que chame uma função para inserir novos participantes da
comunidade “ Turma do Café ”.

2) Deve existir uma opção no menu principal que o programa permita editar todos os dados (exceto o ID) a
partir do número ID. 

3) Deve existir uma opção no menu principal que o programa leia os dados de todos os participantes em
arquivo-texto com o nome participantes.txt e alimente a estrutura de dados criado no exercício 1 

4) Deve existir uma opção no menu principal que permita o programa gravar (de forma que sobre escreva )
os dados de todos os participantes em arquivo-texto com o nome participantes.txt 
Após carregar todos os participantes (exercício 3), inserir novos participante (exercício 1), editar algum
participante ( exercício 2 ), o usuário poderá utilizar esta função para sobrescrever o arquivo de participantes.

# Quem contribuiu com o café ?

5) Elabore uma estrutura de dados para controlar os membros pagantes. Esta estrutura deve armazenar em
cada nó (registro), o ID do participante, mês ( número inteiro entre 1 e 12 ), o ano (número inteiro maior ou
igual o número 2024) e valor da contribuição . 
Deve existir uma opção no menu principal chamada “Cadastrar contribuição” que chame uma função para
inserir novas contribuições. Nesta função, o usuário ao digitar o ID do participante, deverá verificar na
estrutura criada no exercício 1 se este ID existe ou não. Caso não exista, nenhuma contribuição deve ser
cadastrada.

6) Deve existir uma opção no menu principal que permita o programa gravar (de forma que sobrescreva ) os
dados de todos os contribuintes em arquivo-texto com o nome contribuintes.txt 
Esta função deve percorrer toda a estrutura de dados criada no exercício 5 e apresentar na saída em texto
todas as contribuições feitas.

7) Deve existir uma opção no menu principal que permita o programa gravar (de forma que sobrescreva )
os dados de todos os contribuintes em arquivo-texto com os seguintes nomes: 

contribuintes_DSM.txt      contribuintes_SI.txt    contribuintes_GE.txt

Esta função deve percorrer a estrutura criada no exercício 5, gerando-se relatório de quem são os
contribuintes por curso.
