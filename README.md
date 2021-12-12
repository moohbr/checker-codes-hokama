# verificador-codigos-hokama

Podemos utilizar uma pilha para verificar se a parentização está balanceada. Utilizando a
seguinte ideia:

● Sempre que abrimos um símbolo ‘(‘, ‘[‘ ou ‘{‘, colocamos ele em uma pilha.
● Sempre que fechamos um símbolo ‘)’, ‘]’ ou ‘}’, retiramos o elemento do topo da pilha
e verificamos se é o símbolo de abertura correspondente. Se não for, significa que
detectamos um desbalanceamento.
● Ao final do código/expressão verificamos se a pilha está vazia. Se não estiver
significa que abrimos um símbolo que nunca fechamos.
● Todos os outros tipos de caracteres são ignorados.

Nesse trabalho você deverá implementar um verificador de parentização simples. Que
simplesmente lê o texto da entrada padrão do sistema e verifica se nesse texto, parentes,
colchetes e chaves são abertos e fechados de maneira balanceada. Um código será
fornecido e você pode usá-lo à vontade.

O verificador não vai verificar todos os casos. Por exemplo, se um símbolo aparece dentro
de uma string, ele vai ser considerado um símbolo e acusará um erro.

Obviamente o nosso verificador também não garante que um código/expressão está
corretamente escrito, mas pode sim ser usado como uma das etapas da verificação
completa.
O seu programa deverá indicar qual o símbolo que originou o problema. Se o símbolo é de
fechamento, ele deve dizer a linha que houve esse fechamento. E se for um símbolo de
abertura que não foi fechado, o programa deve indicar o símbolo, mas não precisa indicar
em qual linha ele foi aberto. 
