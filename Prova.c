#include <stdio.h>
#include <stdlib.h>

/*O seguinte algoritmo é um cardapio eletrônico com 4 casos. Caso 1, possibilita a leitura do cardapio. Caso 2, Realiza a introdução dos pratos
  que os clientes desejam na lista de pedidos. Caso 3, Finaliza o pedido do cliente. Caso 4, finaliza o sistema do restaurante.*/

int main(){

    // A variavel inteira op2 serve como codigo dos pratos que existem no cardápio do restaurante. (1) Pirão, (2) Pirão com Rabada e assim sucessivamente.
    // A variavel qtd, informa a quantidade de pratos a serem inserida na lista do pedido.
    int op2, qtd;

    // A variavel decimal valor, indica o saldo da conta do cardapio do cliente.
    // valorPago, indica o valor pago pelo cliente.
    // troco, indica o resto que deve ser devolvido ao cliente logo após o pagamento.
    float valor = 0, valorPago =0 , troco = 0;

    printf("Seja bem-vindo ao Restaurante Sabor da Terra!\n");
    
    // O laço while, quando atribuido o valor 1, que significa true = verdadeiro. Funciona como um laço infinito e só é finalizado com o comando exit(0);
    while(1){
        
        // A variavel opc, informa a opção que o usuario deseja selecionar na fução switch case.
        int opc;
        printf("\n\nEscolha as Seguintes opções:\n\n1 - Ver o cardapio; \n2 - Realizar o pedido; \n3 - Finalizar pedido;\n4 - Para sair do nosso sistema.\n\nSelecione: ");
        // o scanf a baixo recebe o valor da opção do switch case.
        scanf("%d", &opc);
        
        switch(opc){

            // case 1, printa o Cardapio do restaurante.
            case 1:
                printf("\t______Cardapio______\n");
                printf("\n\n1 - Pirão com Costela_________R$30,00;\n2 - Pirão com Rabada__________R$30,00.");
                printf("\n3 - Macarrão ao alho e óleo___R$35,50;\n4 - Macarrão Tradicional______R$10,75.");
                break;

            // case 2, insere os pratos que o cliente deseja na lista de pedido.
            case 2:
                printf("\t_____Lista de Pedidos_______\n");
                printf("\nInforme a quantidade de pedidos que você deseja inserir em sua lista.");
                scanf("%d", &qtd);

                // o laço for abaixo, realiza a soma dos valores da conta do pedido do cliente.
                for(int i = 1; i <= qtd; i++){
                    printf("Informe o prato pelo seu determinado codigo: ");
                    scanf("%d",&op2);
                    
                // Como os pratos com os códigos 1 e 2 tem os mesmos valores foi utilizado o operador lógico or (||) condição if abaixo.
                    if(op2 == 1 || op2 == 2){
                        valor += 30.00;
                    }else if(op2 == 3){
                        valor += 35.50;
                    }else if(op2 == 4){
                        valor += 10.75;
                    }
                }

                printf("\nO valor total do pedido é: R$%.2f", valor);       
                break;
            
            case 3:
                // Caso 3, finaliza o pedido do cliente. Informando quanto o cliente deve pagar, e se for o caso, o quanto receber de troco.
                printf("\t_____Finalizar pedido_______\n");
                printf("\nO total do seu pedido é: R$%.2f\n\n",valor);
                printf("Informe o valor pago pelo cliente: ");
                scanf("%f", &valorPago);

                troco = valorPago - valor;
                
                // %.2f é um print formatado que indica que será mostrado somente duas casas decimais logo após a virgula do valor da variavel.
                printf("Você deve devolver ao cliente R$%.2f", troco);
                break;

            case 4:
                printf("Obrigado, volte sempre!");
                // O comando exit(0), força a finalização do comando while() que está setado como laço infinito, graças ao valor 1 dentro de sua condição[while(1)].
                exit(0);
                break;

            default:
                // caso o usuario informe algum valor diferente dos cases especificados a cima, o comando default informa o print a baixo e ignora o valor do informado incorreto pelo o usuario.
                printf("\nOpção invalida. Selecione novamente!");
                break;
        }  
    }
    
    return 0;
}