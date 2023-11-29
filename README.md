# Projeto-Guiart
![nascimento-de-venus-scaled](https://github.com/FelipeNMorgado/Projeto-Guiart/assets/128396955/de092eab-f2f7-45f6-822d-98c908e8ebe9)

# Guiart 


# Como Funciona

### 1- Sensor Ultrasômico🔊
+ Esse código se resume a identificar obstáculos
    
+ Da linha 1 até  a 12 linhas do código foram usadas para programar os pinos de entrada:
     - sensor ultrassônico🔉
     - vibracall🔉
+ O restante do código serve para criar uma distância mínima que o sensor possa identificar e enviar esse sinal para  o vibracall o fazendo vibrar 
### 2- Bluetooth Arduino ⚙️      
+ Este código se refere ao sensor de cor e o Bluetooth:
    - a-Arduíno
    - Mega
+ Da linha 1 até a  linha 23 são cadastros dos pinos dos sensores e da led rgb no arduino
+ O restante do código se refere a uma leitura de cor feita pelo sensor que manda um sinal pelo bluetooth através da serial e envia para o computador com o código de python
+ ⚠️Necessaria a Instalação do pygame (pip install pygame)⚠️
### 3- Bluetooth Python 📲
+ Esse código é o tocador do áudio
+ Feito através da biblioteca pygame
+ O computador recebe um comando da serial pelo arduino printado após a identficação da cor , EX:
    - RED: 1 , GREEN : 2 , BLUE : 3
+ Irá tocar o  áudio referente ao número

## Pontos importantes para a utilização do código:

### 4-Visualizar /Caso o usuario deseja visualizar as informações e livros inseridos até o momento📖/
+ Dentro dessa opção o usuario terá como filtar a sua busca para achar o livro que busca enquanto o código mostra as indormações:
    - Caategoria, Livro e Informações mais detalhadas sobre o livro
### 5-Dineiro /Caso o usuario queira saber o total de deinhero gasto na compra de todos os livros/
+ Ao seleciona essa opção será exibido para o usuario o total de denheiro gasto pelo usuario
+ ⚠️!!!IMPORTANTE!!!⚠️
    - Ao modificar a informação de preço na biblioteca pela opção de atualizar a soma total será automaticamente atualizada
### 6-Carrinho /Armazenamento de livros que deseja obter/💡!!NOVIDADE!!💡
+ O carrinho é uma plataforma onde você pode inserir e remover livros que deseja futuramente sabendo o quanto será gasto nessas aquisições.
+ O adereço "Carrinho" possue funções muito similares as funções apresentadas no código anterirormente.
    -Adicionar
    -Remover
    -Visualizar 
+ Assim mantendo sua organização financeira muito mais prática
