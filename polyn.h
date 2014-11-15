//tipo Polyn de polinômios de grau inteiro entre 0 e 9
typedef struct{
	float x0;
	float x1;
        float x2;
        float x3;
        float x4;
        float x5;
        float x6;
        float x7;
        float x8;
        float x9;
}polyn;

//tipo Root de raízes reais de um Polyn de 1º ou 2º grau
typedef struct{
	float r1;
	float r2;
	int status;
}root;

//funções de inicialização

/* 
Descricao: inicializa uma struct do tipo Polyn
Entrada: 
Saida: Polyn inicializado
Restrições:
*/
polyn initPolyn();


/* 
Descricao: inicializa uma struct do tipo Root
Entrada: 
Saida: Root inicializada
Restrições:
*/
root initRoot();

//funções de I/O

/* 
Descricao: lê múltiplos termos de um Polyn no formato "a b", onde "a" é o coeficiente e "b" é o expoente de x. "0 0" encerra a leitura.  
Entrada: Polyn para o qual se deseja escanear
Saida: Polyn somado aos termos lidos na entrada
Restrições: coeficiente pode ser ponto flutuante e expoente de x deve ser um inteiro entre 0 e 9
*/
polyn scanTo(polyn p);

/* 
Descricao: imprime o Polyn de forma legível para o usuário
Entrada: Polyn que se deseja imprimir
Saida: Polyn impresso de forma legível para o usuário
Restrições:
*/
void printPolyn(polyn p);

/* 
Descricao: imprime o Root de forma legível para o usuário
Entrada: Root que se deseja imprimir
Saida: Root impresso de forma legível para o usuário
Restrições:
*/
void printRoot(root r);

//getter e setter de Polyn

/* 
Descricao: retorna o coeficiente do Polyn no expoente desejado 
Entrada: Polyn e expoente desejado
Saida: coeficiente do expoente especificado
Restrições: o expoente deve ser um inteiro entre 0 e 9 caso contrário a função retorna 0
*/
float getCoef(polyn p, int exp);

/* 
Descricao: define o coeficiente do Polyn no expoente desejado 
Entrada: Polyn, o expoente desejado e o valor do coeficiente a ser definido
Saida: Polyn redefinido
Restrições: o expoente deve ser um inteiro entre 0 e 9 caso contrário a função retorna o próprio Polyn
*/
polyn setCoef(polyn p, int exp, float value);

//funções matemáticas polinomiais

/* 
Descricao: retorna o grau do Polyn
Entrada: Polyn
Saida: inteiro com o grau do maior expoente cujo coeficiente é diferente de 0
Restrições:
*/
int getBiggerExp(polyn p);

/* 
Descricao: calcula f(x) do Polyn
Entrada: Polyn e valor de x
Saida: f(x)
Restrições:
*/
float calculateValue(polyn p, float x);

/* 
Descricao: deriva Polyn 
Entrada: Polyn
Saida: (d/dx)Polyn
Restrições:
*/
polyn derivatePolyn(polyn p);

/* 
Descricao: soma dois Polyns 
Entrada: Polyns a serem somados
Saida: resultado da soma das entradas
Restrições:
*/
polyn sumPolyn(polyn p, polyn p2);

/* 
Descricao: encontra, se houver, as raízes de um Polyn do 1º ou 2º grau
Entrada: Polyn que se deseja resolver
Saida: Root com as raízes Polyn
Restrições: o grau do Polyn deve ser 1 ou 2
*/
root solvePolyn(polyn p);

