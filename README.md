# Equalizador de Histograma
Este é um projeto de Processamento de Imagens que implementa um equalizador de histograma. O equalizador de histograma é uma técnica utilizada para melhorar o contraste e a distribuição de intensidades em uma imagem, tornando-a mais perceptível aos olhos humanos.

## Mapeamento de Intensidade

O processo de equalização de histograma, também conhecido como Mapeamento de Intensidade, é dado pela fórmula:

![Fórmula de Mapeamento de Intensidade](https://latex.codecogs.com/svg.image?S_k&space;=&space;T(r_k)&space;=&space;\frac{(L&space;-&space;1)}{MN}&space;\sum_{j=0}^{k}n_j)

Onde:
- ![Sk](https://latex.codecogs.com/svg.image?S_k) é o valor do pixel na posição *k* da imagem equalizada.
- ![rk](https://latex.codecogs.com/svg.image?r_k) é o valor original do pixel na posição *k* da imagem de entrada.
- *L* é o número de níveis de intensidade (normalmente 256 em imagens de 8 bits).
- *MN* é o número total de pixels na imagem.
- ![nj](https://latex.codecogs.com/svg.image?n_j) é o número de pixels na imagem de entrada com o nível de intensidade *rj* até o valor *k*.

O equalizador de histograma utiliza essa fórmula para ajustar as intensidades dos pixels na imagem, redistribuindo-as de forma a aumentar o contraste e melhorar a visualização.

## Funcionamento do Programa

O programa irá realizar as seguintes etapas:

1. Leitura da imagem de entrada em formato digital.
2. Cálculo do histograma da imagem original para determinar a distribuição das intensidades.
3. Equalização do histograma usando a fórmula de Mapeamento de Intensidade apresentada acima.
4. Geração da imagem equalizada resultante.
5. Exibição da imagem equalizada e da imagem original para comparação.

## Executando o Programa

Para executar o programa e realizar a equalização de histograma em uma imagem específica, siga os passos abaixo:

1. Utilize o comando `make` para compilar o código e gerar o executável:

   ```
   make
   ```

2. Após a compilação bem-sucedida, abra o terminal ou prompt de comando na pasta do projeto.

3. Execute o programa com o seguinte comando:

   ```
   ./equaliza [imagem.pgm]
   ```

   Substitua `[imagem.pgm]` pelo caminho e nome do arquivo da imagem que deseja equalizar.

   **Exemplo:**

   ```
   ./equaliza mona.pgm
   ```

   Neste exemplo, o programa será executado utilizando a imagem `mona.pgm` como entrada, realizando a equalização de histograma e gerando a imagem equalizada resultante.

## Licença

Este projeto está licenciado sob a [Licença MIT](LICENSE). Sinta-se livre para usar, modificar e distribuir conforme as diretrizes da licença.


