#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes.h"
#include <string.h>
#include "constantes.h"


int main()
{
    setlocale(LC_ALL, "portuguese");
    int state1, state2, state3, quant_hospedes, state4, state5, numero, retornoFidelidade;
    state4 = 0;
    float valorTotal = 1;
    char nome[80], data_entrada[50], data_saida[50];
    int op;
    do{
        printf("\n------ HOTEL 100SENSACIONAL -------\n");
        printf("Digite 1 para CADASTRAR um cliente!!!\n");
        printf("Digite 2 para CADASTRAR um funcion�rio!!!\n");
        printf("Digite 3 para CADASTRAR um quarto!!!\n");
        printf("Digite 4 para BUSCAR cliente espec�fico!!!\n");
        printf("Digite 5 para BUSCAR funcion�rio espec�fico!!!\n");
        printf("Digite 6 para MOSTRAR todas as estadias\n");
        printf("Digite 7 para MOSTRAR todos os quartos\n");
        printf("Digite 8 para CADASTRAR uma estadia!!!\n");
        printf("Digite 9 para LISTAR estadias de um cliente!!!\n");
        printf("Digite 10 para DAR BAIXA em uma estadia!!!\n");
        printf("Digite 11 para MOSTRAR pontos de Fidelidade de determinado cliente!!!\n");

        printf("Digite uma op��o : ");
        scanf("%d", &op);
        switch(op){
        case 1:
                state1 = funcaoCadastrarCliente();
                if(state1){
                    printf("Cliente Cadastrado com sucesso\n");
                }
                else{
                    printf("ERRO! c�digo j� existente\n");
                }
            break;
        case 2:
                state2 = funcaoCadastrarFuncionarios();
                if(state2){
                    printf("Funcion�rio Cadastrado com sucesso\n");
                }
                else{
                    printf("ERRO! c�digo j� existente\n");
                }
            break;
        case 3:
                state3 = funcaoCadastrarQuarto();
                if(state3){
                    printf("Quarto Cadastrado com sucesso\n");
                }
                else{
                    printf("ERRO! n�mero de quarto j� existente");
                }
            break;
        case 4:
                printf("\n------------------\n");
                printf("Digite um nome de um cliente : ");
                fflush(stdin);
                gets(nome);
                imprimiArquivoClientes(nome);
                printf("\n------------------\n");
            break;
        case 5:
                printf("\n------------------\n");
                printf("Digite um nome de um cliente : ");
                fflush(stdin);
                gets(nome);
                imprimiArquivoFuncionarios(nome);
                printf("\n------------------\n");
            break;
        case 6:
                printf("\n------------------\n");
                imprimiArquivoEstadias();
                printf("\n------------------\n");
            break;
        case 7:
                printf("\n------------------\n");
                imprimiArquivoQuartos();
                printf("\n------------------\n");
            break;
        case 8:
                //entradas da estadia
                printf("Digite o nome do cliente que deseja alocar um quarto: ");
                fflush(stdin);
                gets(nome);
                printf("Digite a quantidade de hospedes :");
                scanf("%d", &quant_hospedes);
                printf("Data de entrada no formato dia/m�s/ano ex = 01/08/2019 : ");
                fflush(stdin);
                gets(data_entrada);
                printf("Data de sa�da no formato dia/m�s/ano ex = 01/08/2019 : ");
                fflush(stdin);
                gets(data_saida);
                fflush(stdin);
                if(funcaoVerificaExistenciaDeQuarto(quant_hospedes) && funcaoVerificaExistenciaDoCliente(nome)){
                    state4 = funcaoCadastrarEstadia(nome, quant_hospedes, data_entrada, data_saida);
                    if(state4){
                        printf("Estadia cadastrada com sucesso!!!\n");
                    }
                    else{
                        printf("Erro estadia n�o cadastrada!!!\n");
                    }
                }
                else{
                    printf("Erro cliente ou quarto n�o encontrado!!!\n");
                }
            break;
        case 9:
            printf("Digite o nome cliente que ser� listado suas estadias: ");
            fflush(stdin);
            gets(nome);
            funcaoMostrarTodasEstadiasDeUmCliente(nome);
            break;
        case 10:
            printf("Digite um n�mero de quarto de uma estadia ocupada para dar baixa na mesma : ");
            scanf("%d", &numero);
            state5 = funcaoBaixaEmUmaEstadia(numero, &valorTotal);
            if(state5){
                printf("Baixa na estadia efetuada com sucesso!!\n");
                printf("\n---------------------------------------\n");
                printf("\n---Valor total a pagar por esta estadia---\n");
                printf("\n------------- R$ %.2f -----------------\n", valorTotal);
                printf("\n---------------------------------------\n");
            }
            else{
                printf("ERRO!!!\n");
            }
            break;
        case 11:
            printf("Digite um nome de cliente para ser calculado os pontos de fidelidade do mesmo !!! : ");
            fflush(stdin);
            gets(nome);
            retornoFidelidade = funcaoPontosDeFidelidade(nome);
            if(retornoFidelidade){
                printf("A quantidade de pontos de fidelidade acumulados pelo cliente %s foi de %d !!!\n", nome, retornoFidelidade);
            }
            else{
                printf("Erro usu�rio n�o encontrado ou arquivo n�o lido ou falta de estadias !!! \n");
            }

        }
    }while(op > 0 && op < 12);

    return 0;
}
