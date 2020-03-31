#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"

///-------------------
struct Estadias{
    int codigo;
    char data_entrada[40];
    char data_saida[40];
    int quant_diarias;
    int codigo_cliente;
    int numero_quarto;
    char estado_da_estadia[80];///estado da estadia (emuso ou desocupada);
};
typedef struct Estadias estadia;
///-------------------
struct Quartos{
    int numero;
    int quant_hospedes;
    float valor_da_diaria;
    char status[80];
};

typedef struct Quartos quarto;
///-------------------
struct Clientes{
    int codigo;
    char nome[80];
    char endereco[80];
    int telefone;
    char estado[80];///presente/ausente
    estadia estadiaEspecifica[80];
    int quant_estadias;
};
typedef struct Clientes cliente;
///-------------------
struct Funcionarios{
    int codigo;
    char nome[80];
    int telefone;
    char cargo[80];
    float salario;
};
typedef struct Funcionarios funcionario;

//função que cadastra clientes
int funcaoCadastrarCliente(){
    FILE *arquivo;
    cliente c;
    cliente aux;
    int arquivoNaoCriado = 0;
    int encontrado = 0;
    arquivo = fopen("cadastroClientes.txt", "r+b");
    if(arquivo == NULL){
        arquivo = fopen("cadastroClientes.txt", "w+b");
        if(arquivo == NULL){
            printf("Não foi possível criar o arquivo\n");
            arquivoNaoCriado = 1;
        }
    }
    if(arquivoNaoCriado){
        ///erro não deu para criar o arquivo
    }
    else{
        printf("Digite um código para este cliente: ");
        scanf("%d", &aux.codigo);
        printf("Digite um nome para este cliente: ");
        fflush(stdin);
        gets(aux.nome);
        printf("Digite um endereco para este cliente: ");
        fflush(stdin);
        gets(aux.endereco);
        printf("Digite um telefone para este Cliente");
        scanf("%d", &aux.telefone);
        aux.quant_estadias = 0;
        strcpy(aux.estado, "ausente");

        ///verificando se tem algum código repetido
        fseek(arquivo,0,SEEK_SET);
        fread(&c, sizeof(c), 1, arquivo);
        while(!feof(arquivo) && !encontrado){
            if(aux.codigo == c.codigo){
                encontrado = 1;
            }
            fread(&c, sizeof(c), 1, arquivo);
        }
        if(encontrado){
            fclose(arquivo);
            return 0;
        }
        else{
            fseek(arquivo,0, SEEK_END);
            fwrite(&aux, sizeof(aux), 1, arquivo);
            fflush(arquivo);
            fclose(arquivo);
            return 1;
        }
    }
}
//função que cadastra funcionários
int funcaoCadastrarFuncionarios(){
    FILE *arquivo;
    funcionario f;
    funcionario aux;
    int arquivoNaoCriado = 0;
    int encontrado = 0;
    arquivo = fopen("cadastroFuncionarios.txt", "r+b");
    if(arquivo == NULL){
        arquivo = fopen("cadastroFuncionarios.txt", "w+b");
        if(arquivo == NULL){
            printf("Não foi possível criar o arquivo\n");
            arquivoNaoCriado = 1;
        }
    }
    if(arquivoNaoCriado){
        ///erro não deu para criar o arquivo
    }
    else{
        printf("Digite um código para este funcionário: ");
        scanf("%d", &aux.codigo);
        printf("Digite um nome para este funcionário: ");
        fflush(stdin);
        gets(aux.nome);
        printf("Digite um telefone para este funcionário: ");
        scanf("%d", &aux.telefone);
        printf("Digite o cargo deste funcionário : ");
        fflush(stdin);
        gets(aux.cargo);
        printf("Digite o salário deste funcionário : ");
        scanf("%f", &aux.salario);

        fseek(arquivo,0,SEEK_SET);
        fread(&f, sizeof(f), 1, arquivo);
        ///validando código para não existirem códigos duplicados
        while(!feof(arquivo) && !encontrado){
            if(aux.codigo == f.codigo){
                encontrado = 1;
            }
            fread(&f, sizeof(f), 1, arquivo);
        }
        if(encontrado){
            fclose(arquivo);
            return 0;
        }
        else{
            fseek(arquivo,0, SEEK_END);
            fwrite(&aux, sizeof(aux), 1, arquivo);
            fflush(arquivo);
            fclose(arquivo);
            return 1;
        }
    }
}


//função que cadastra quartos

int funcaoCadastrarQuarto(){
    quarto aux;
    quarto q;
    int arquivoNCriado = 0;
    int encontrado = 0;

    FILE * arquivo;
    arquivo = fopen("cadastroQuartos.txt", "r+b");
    if(arquivo == NULL){
        arquivo = fopen("cadastroQuartos.txt", "w+b");
        if(arquivo == NULL){
            arquivoNCriado = 1;
        }
    }
    if(arquivoNCriado){
        ///ERRO
    }
    else{
        ///inputs do usuário
        aux.numero = rand() % 1000;
        printf("Digite a quantidade de hospedes: ");
        scanf("%d", &aux.quant_hospedes);
        printf("Digite o valor da diária deste quarto : ");
        scanf("%f", &aux.valor_da_diaria);
        strcpy(aux.status, "desocupado");
        fseek(arquivo,0, SEEK_SET);
        fread(&q, sizeof(q), 1, arquivo);
        while(!feof(arquivo) && !encontrado){
            if(q.numero == aux.numero){
                encontrado = 1;
            }
            fread(&q, sizeof(q),1, arquivo);
        }
        if(encontrado){
            fclose(arquivo);
            return 0;
        }
        else{
            fseek(arquivo, 0, SEEK_END);
            fwrite(&aux, sizeof(aux), 1, arquivo);
            fflush(arquivo);
            fclose(arquivo);
            return 1;
        }
    }
}


int gerarCodigoEstadia(){
    estadia e;
    int encontrei = 0;
    FILE * arquivo;
    arquivo = fopen("cadastroEstadias.txt", "r+b");
    while(encontrei == 0){
        codigo = rand() % 2000;
        fseek(arquivo, 0, SEEK_SET);
        fread(&e, sizeof(e), 1, arquivo);
        while(!feof(arquivo) && !encontrei){
            if(e.codigo == codigo){
                encontrei = 1;
            }
            fread(&e, sizeof(e), 1, arquivo);
        }
        if(encontrei){
            encontrei = 0;
        }
        else{
            fclose(arquivo);
            return codigo;
        }
    }
}

int funcaoCadastrarEstadia(char *nome,int quant_hospedes,char * entrada, char * saida){
    int statusEntrada, statusSaida, quant_diarias, aux_meses_inteiros, aux_anos_inteiros;
    int codigo,problema, dia_entrada, mes_entrada, ano_entrada, dia_saida, mes_saida, ano_saida;
    ///validando data
    statusEntrada = funcaoValidarData(entrada);
    statusSaida = funcaoValidarData(saida);
    quant_diarias = 0;
    problema = 0;
    cliente c;
    quarto q;
    estadia e;
    codigo = 0;
    if(statusEntrada && statusSaida){
        dia_entrada = ( (entrada[0] - '0') * 10) + (entrada[1] - '0');
        dia_saida = ( (saida[0] - '0') * 10) + (saida[1] - '0');
        mes_entrada = ( (entrada[3] - '0') * 10) + (entrada[4] - '0');
        mes_saida = ( (saida[3] - '0') * 10) + (saida[4] - '0');
        ano_entrada = ( (entrada[6] - '0') * 1000) + ( (entrada[7] - '0') * 100) + ( (entrada[8] - '0') * 10) + (entrada[9] - '0');
        ano_saida = ( (saida[6] - '0') * 1000) + ( (saida[7] - '0') * 100) + ( (saida[8] - '0') * 10) + (saida[9] - '0');
        if(ano_entrada > ano_saida){
            printf("ERRO!!! ANO DE ENTRADA MAIOR QUE O DE SAÍDA !!! \n");
        }///final do ano de entrada maior que o de saída
        else{
            if(ano_entrada == ano_saida){
                if(mes_entrada > mes_saida){
                    printf("ERRO !!! MES DE ENTRADA MAIOR QUE O MES DE SAÍDA!!! \n");
                }
                else{
                    if(mes_entrada == mes_saida){
                        if(dia_entrada > dia_saida){
                            printf("ERRO !!! DIA DE ENTRADA MAIOR QUE O DIA DE SAÍDA\n");
                        }
                        else{
                            if(dia_entrada == dia_saida){
                                printf("ERRO !!! USUÁRIO NÃO COMPLETOU UMA DIÁRIA\n");
                            }
                            else{
                                quant_diarias = dia_saida - dia_entrada;
                            }
                        }
                    }
                    else{
                        if(mes_entrada < mes_saida){
                            if(dia_entrada == dia_saida){
                                quant_diarias = (mes_saida - mes_entrada) * 30;
                            }
                            else{
                                aux_meses_inteiros = ( (mes_saida - mes_entrada) - 1) * 30;
                                quant_diarias = ((30 - dia_entrada) + dia_saida ) + aux_meses_inteiros;
                            }
                        }
                    }
                }
            }///final do ano == ano
            if(ano_entrada < ano_saida){
                aux_anos_inteiros = ( (ano_saida - ano_entrada) - 1 ) * 360;

                if(mes_entrada > mes_saida){
                    if(dia_entrada == dia_saida){
                        quant_diarias = ( ((12 - mes_entrada) + (mes_saida)) * 30) + aux_anos_inteiros;

                    }
                    else{
                        aux_meses_inteiros = ( ((12 - mes_entrada) + (mes_saida)) - 1 ) * 30;
                        quant_diarias = ( ((30 - dia_entrada) + (dia_saida)) + aux_meses_inteiros + aux_anos_inteiros);
                    }

                }
                else{
                    if(mes_entrada == mes_saida){
                        if(dia_entrada > dia_saida || dia_entrada < dia_saida){
                            aux_anos_inteiros = ( (ano_saida - ano_entrada) * 360) - 30;
                            quant_diarias = aux_anos_inteiros + ( (30 - dia_entrada) + (dia_saida) );
                        }
                        else{
                            if(dia_entrada == dia_saida){
                                quant_diarias = (ano_saida - ano_entrada) * 360;
                            }
                        }
                    }
                    else{
                        if(mes_entrada < mes_saida){
                            if(dia_entrada == dia_saida){
                                quant_diarias = ( ((12 - mes_entrada) + (mes_saida)) * 30) + aux_anos_inteiros;

                            }
                            else{
                                aux_meses_inteiros = ( ((12 - mes_entrada) + (mes_saida)) - 1 ) * 30;
                                quant_diarias = ( ((30 - dia_entrada) + (dia_saida)) + aux_meses_inteiros + aux_anos_inteiros);
                            }
                        }
                    }
                }
            }///final do ano de entrada menor que o de saída
        }///final do else
        printf("Quantidade de diárias = %d \n", quant_diarias);
        FILE * arquivoEstadia;
        arquivoEstadia = fopen("cadastroEstadias.txt", "r+b");
        if(arquivoEstadia == NULL){
            arquivoEstadia = fopen("cadastroEstadias.txt", "w+b");
            if(arquivoEstadia == NULL){
                problema = 1;
            }
        }
        if(!problema){
            FILE * arquivoClientes;
            FILE * arquivoQuartos;
            codigo = gerarCodigoEstadia();
            ///abrindo arquivos para leitura e escrita
            arquivoClientes = fopen("cadastroClientes.txt", "r+b");
            arquivoQuartos = fopen("cadastroQuartos.txt", "r+b");
            ///posicionando no local desejado dentro do arquivo
            fseek(arquivoClientes, sizeof(c)*posicaoCliente, SEEK_SET);
            fseek(arquivoQuartos, sizeof(q)*posicaoQuarto, SEEK_SET);
            fseek(arquivoEstadia, 0, SEEK_END);
            fread(&q, sizeof(q), 1, arquivoQuartos);
            fread(&c, sizeof(c), 1, arquivoClientes);
            if(c.quant_estadias <= 80 && (strcmp(q.status, "desocupado") == 0 ) ){
                e.codigo = codigo;
                strcpy(e.data_entrada, entrada);
                strcpy(e.data_saida, saida);
                e.numero_quarto = q.numero;
                strcpy(e.estado_da_estadia, "emuso");
                e.codigo_cliente = c.codigo;
                e.quant_diarias = quant_diarias;
                fseek(arquivoClientes, sizeof(c)*posicaoCliente, SEEK_SET);
                c.estadiaEspecifica[c.quant_estadias] = e;
                strcpy(c.estado, "presente");
                c.quant_estadias++;
                fseek(arquivoQuartos, sizeof(q)*posicaoQuarto, SEEK_SET);
                strcpy(q.status, "ocupado");
                fwrite(&q, sizeof(q), 1, arquivoQuartos);
                fwrite(&c, sizeof(c), 1, arquivoClientes);
                fwrite(&e, sizeof(e), 1, arquivoEstadia);
                fflush(arquivoClientes);
                fflush(arquivoEstadia);
                fflush(arquivoQuartos);

                fclose(arquivoClientes);
                fclose(arquivoEstadia);
                fclose(arquivoQuartos);
                return 1;
            }
        }
        else{
            return 0;
        }
    }
    else{
        printf("Erro data inválida");
    }
    return 0;
}

int funcaoValidarData(char * saida){
    int tamanho = strlen(saida);
    int entradaEquivocada = 0;
    int quantBarras = 0;
    int dataErrada = 0;
    int dataCorreta = 0;
    if(tamanho != 10){
        printf("deu errado %d \n", tamanho);
        return 0;
    }
    else{
        char simbolo = '`';
        int i = 0;

        while(simbolo != '\0'){
            simbolo = saida[i];
            if( (simbolo >= '0' && simbolo <= '9') || simbolo == '/' ){
            }
            else{
                if(simbolo == NULL){

                }
                else{
                    entradaEquivocada = 1;
                }
            }
            if(simbolo == '/'){
                quantBarras++;
            }
            i++;
        }
        if(!entradaEquivocada  && quantBarras == 2 && saida[2] == '/' && saida[5] == '/'){
            if( (saida[0] >= '0' && saida[0] <= '3') && (saida[3] >= '0' && saida[3] <= '1') ){
                if(saida[0] == '0'){
                    if(saida[1] == '0'){
                        dataErrada++;
                    }
                    else{
                        dataCorreta++;
                    }
                }
                if(saida[0] == '3'){
                    if(saida[1] != '0'){
                        dataErrada++;
                    }
                    else{
                        dataCorreta++;
                    }
                }

                if(saida[3] == '0'){
                    if(saida[4] == '0'){
                        dataErrada++;
                    }
                    else{
                        dataCorreta++;
                    }
                }
                if(saida[3] == '1'){
                    if(saida[4] >= '3'){
                        dataErrada++;
                    }
                    else{
                        dataCorreta++;
                    }
                }
                if( (dataCorreta == 2 && dataErrada == 0) || (dataCorreta == 1 && dataErrada == 0) ){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }

        }
        else{
            return 0;
        }
    }
}

int funcaoVerificaExistenciaDoCliente(char* nome){
    cliente c;
    posicaoCliente = 0;
    int encontrado = 0;
    FILE * arquivo;
    arquivo = fopen("cadastroClientes.txt", "r+b");
    if(arquivo == NULL){
        printf("ERRO NENHUM CLIENTE CADASTRADO !!! ");
    }
    else{
        fseek(arquivo, 0, SEEK_SET);
        fread(&c, sizeof(c), 1, arquivo);
        while(!feof(arquivo) && !encontrado){
            if(strcmp(c.nome, nome) == 0){
                encontrado = 1;
            }
            else{
                posicaoCliente++;
            }
            fread(&c, sizeof(c), 1, arquivo);
        }
        fclose(arquivo);
        return encontrado;
    }
}

int funcaoVerificaExistenciaDeQuarto(int quant_hospedes){
    quarto q;
    posicaoQuarto = 0;
    int encontrado = 0;
    FILE * arquivo;
    arquivo = fopen("cadastroQuartos.txt", "r+b");
    if(arquivo == NULL){
        printf("ERRO NENHUM QUARTO CADASTRADO !!! ");
    }
    else{
        fseek(arquivo, 0, SEEK_SET);
        fread(&q, sizeof(q), 1, arquivo);
        while(!feof(arquivo) && !encontrado){
            if( (q.quant_hospedes == quant_hospedes) && (strcmp(q.status, "desocupado")  == 0 ) ) {
                encontrado = 1;
            }
            else{
                posicaoQuarto++;
            }

            fread(&q, sizeof(q), 1, arquivo);
        }
        fclose(arquivo);
        return encontrado;
    }
}



///-------------------------funções que imprimem documentos texto ---------------------------

void imprimiArquivoClientes(char* nome){
    FILE *arquivo;
    cliente c;
    int encontrado = 0;
    arquivo = fopen("cadastroClientes.txt", "r+b");
    if(arquivo == NULL){
        printf("Erro na leitura do arquivo!!! \n");
    }
    else{
        fseek(arquivo,0, SEEK_SET);
        fread(&c, sizeof(c), 1, arquivo);
        while(!feof(arquivo) && !encontrado){
            if(strcmp(c.nome, nome) == 0){
                encontrado = 1;
                printf("código : %d\n", c.codigo);
                printf("nome : %s\n", c.nome);
                printf("endereço : %s\n", c.endereco);
                printf("telefone : %d\n", c.telefone);
            }
            else{
                fread(&c, sizeof(c), 1, arquivo);
            }
        }
    }
    fclose(arquivo);
}

//==========/=////=/=/=/=/=/=/=/=/=/=/=/=/=//=/=/=/=/=/=/

void imprimiArquivoEstadias(){
    FILE *arquivo;
    estadia e;
    arquivo = fopen("cadastroEstadias.txt", "r+b");
    if(arquivo == NULL){
        printf("Erro na leitura do arquivo!!! \n");
    }
    else{
        fseek(arquivo,0, SEEK_SET);
        fread(&e, sizeof(e), 1, arquivo);
        while(!feof(arquivo)){
            if(strcmp(e.estado_da_estadia, "emuso") == 0){
                printf("código : %d\n", e.codigo);
                printf("data entrada : %s\n", e.data_entrada);
                printf("data saída : %s\n", e.data_saida);
                printf("quantidade de dias que pode ser reservado : %d\n", e.quant_diarias);
                printf("código do cliente que reservou o imóvel : %d\n", e.codigo_cliente);
                printf("número do quarto reservado : %d\n", e.numero_quarto);
            }

            fread(&e, sizeof(e), 1, arquivo);
        }
    }
    fclose(arquivo);
}


//==========/=////=/=/=/=/=/=/=/=/=/=/=/=/=//=/=/=/=/=/=/

void imprimiArquivoQuartos(){
    FILE *arquivo;
    quarto q;
    arquivo = fopen("cadastroQuartos.txt", "r+b");
    if(arquivo == NULL){
        printf("Erro na leitura do arquivo!!! \n");
    }
    else{
        fseek(arquivo,0, SEEK_SET);
        fread(&q, sizeof(q), 1, arquivo);
        while(!feof(arquivo)){
            printf("número : %d\n", q.numero);
            printf("quantidade de hospedes suportada : %d\n", q.quant_hospedes);
            printf("valor da diária : %f\n", q.valor_da_diaria);
            printf("status do quarto (ocupado / desocupado) : %s\n", q.status);
            fread(&q, sizeof(q), 1, arquivo);
        }
    }
    fclose(arquivo);
}

void imprimiArquivoFuncionarios(char* nome){
    FILE *arquivo;
    funcionario f;
    int encontrado = 0;
    arquivo = fopen("cadastroFuncionarios.txt", "r+b");
    if(arquivo == NULL){
        printf("Erro na leitura do arquivo!!! \n");
    }
    else{
        fseek(arquivo,0, SEEK_SET);
        fread(&f, sizeof(f), 1, arquivo);
        while(!feof(arquivo) && !encontrado){
            if(strcmp(f.nome, nome) == 0){
                encontrado = 1;
                printf("código : %d\n", f.codigo);
                printf("nome : %s\n", f.nome);
                printf("telefone : %d\n", f.telefone);
                printf("cargo : %s\n", f.cargo);
                printf("salário : %f\n", f.salario);
            }
            else{
                fread(&f, sizeof(f), 1, arquivo);
            }
        }
    }
    fclose(arquivo);
}

void funcaoMostrarTodasEstadiasDeUmCliente(char * nome){
    cliente c;
    int encontrei = 0;
    int i;
    int posicao = 0;
    FILE * arquivo;
    arquivo = fopen("cadastroClientes.txt", "r+b");
    fseek(arquivo, 0, SEEK_SET);
    fread(&c, sizeof(c), 1, arquivo);
    while(!feof(arquivo) && !encontrei){
        if(strcmp(nome, c.nome) == 0){
            encontrei = 1;
        }
        else{
            posicao++;
        }
        fread(&c, sizeof(c), 1, arquivo);
    }
    if(!encontrei){
        printf("Nome do cliente não encontrado!!!\n");
    }
    else{
        fseek(arquivo, sizeof(c) * posicao, SEEK_SET);
        fread(&c, sizeof(c), 1, arquivo);
        for(i = 0; i < c.quant_estadias;i++){
            if(strcmp(c.estadiaEspecifica[i].estado_da_estadia, "emuso") == 0){
                printf("\n------- %d º estadia -------\n", i+1);
                printf("Código da estadia %d\n", c.estadiaEspecifica[i].codigo);
                printf("Código do cliente %d\n", c.estadiaEspecifica[i].codigo_cliente);
                printf("Data de entrada %s\n", c.estadiaEspecifica[i].data_entrada);
                printf("Data de saída %s\n", c.estadiaEspecifica[i].data_saida);
                printf("Número do quarto %d\n", c.estadiaEspecifica[i].numero_quarto);
                printf("Quantidade de diárias %d\n", c.estadiaEspecifica[i].quant_diarias);
            }

        }
    }
    fclose(arquivo);
}

///função que da baixa em uma estadia

int funcaoBaixaEmUmaEstadia(int numeroEstadia, float*total){

    *total = 1;
    FILE * arquivoClientes;
    arquivoClientes = fopen("cadastroClientes.txt", "r+b");
    FILE * arquivoQuartos;
    arquivoQuartos = fopen("cadastroQuartos.txt", "r+b");
    FILE * arquivoEstadias;
    arquivoEstadias = fopen("cadastroEstadias.txt", "r+b");
    int encontrei = 0;
    int i = 0;
    int posicao = 0;
    cliente c;
    quarto q;
    estadia e;
    fseek(arquivoQuartos, 0, SEEK_SET);
    ///atualizando status do quarto
    fread(&q, sizeof(q), 1, arquivoQuartos);
    while(!feof(arquivoQuartos) && !encontrei){
        if(q.numero == numeroEstadia){
            encontrei = 1;
            strcpy(q.status, "desocupado");
            *total = (*total) * q.valor_da_diaria;
        }
        else{
            posicao++;
            fread(&q, sizeof(q), 1, arquivoQuartos);
        }

    }
    if(encontrei){
        fseek(arquivoQuartos, sizeof(q)* posicao, SEEK_SET);
        fwrite(&q, sizeof(q), 1, arquivoQuartos);
        fflush(arquivoQuartos);
    }


    encontrei = 0;
    posicao = 0;
    fseek(arquivoClientes, 0, SEEK_SET);
    ///atualizando o status da estadia do cliente
    fread(&c, sizeof(c), 1, arquivoClientes);

    while(!feof(arquivoClientes) && !encontrei){
        i = 0;
        for(i = 0; i < c.quant_estadias;i++){
            if(c.estadiaEspecifica[i].numero_quarto == numeroEstadia && !encontrei){
                encontrei = 1;
                c.estadiaEspecifica[i].numero_quarto = -1;
                strcpy(c.estadiaEspecifica[i].estado_da_estadia, "desocupada");
                *total = (*total) * c.estadiaEspecifica[i].quant_diarias;
                printf("quant %d\n", c.estadiaEspecifica[i].quant_diarias);
            }
        }
        if(!encontrei){
            posicao++;
            fread(&c, sizeof(c), 1, arquivoClientes);
        }


    }
    if(encontrei){
        fseek(arquivoClientes, sizeof(c)* posicao, SEEK_SET);
        fwrite(&c, sizeof(c), 1, arquivoClientes);
        fflush(arquivoClientes);
    }


    encontrei = 0;
    posicao = 0;
    fseek(arquivoEstadias, 0, SEEK_SET);
    ///atualizando o status da estadia no cadastroestadias.txt
    fread(&e, sizeof(e), 1, arquivoEstadias);

    while(!feof(arquivoEstadias) && !encontrei){
        if(e.numero_quarto == numeroEstadia){
            encontrei = 1;
            strcpy(e.estado_da_estadia, "desocupada");
        }
        else{
            posicao++;
            fread(&e, sizeof(e), 1, arquivoEstadias);
        }

    }
    if(encontrei){
        fseek(arquivoEstadias, sizeof(e)* posicao, SEEK_SET);
        fwrite(&e, sizeof(e), 1, arquivoEstadias);
        fflush(arquivoEstadias);
    }


    ///fechando os arquivos
    fclose(arquivoEstadias);
    fclose(arquivoClientes);
    fclose(arquivoQuartos);
    return encontrei;
}


///função calcula a quantidade de pontos de fidelidade de determinado cliente

int funcaoPontosDeFidelidade(char* nome){
    cliente c;
    int encontrado = 0;
    int i;
    int soma = 0;
    FILE * arquivo;
    arquivo = fopen("cadastroClientes.txt", "r+b");
    if(arquivo == NULL){
        return 0;
    }
    else{
        fseek(arquivo, 0, SEEK_SET);
        fread(&c, sizeof(c), 1, arquivo);
        while(!feof(arquivo), !encontrado){
            if(strcmp(c.nome, nome) == 0){
                encontrado = 1;
            }
            else{
                fread(&c, sizeof(c), 1, arquivo);
            }
        }
        if(encontrado){
            for(i = 0;i < c.quant_estadias;i++){
                if(strcmp(c.estadiaEspecifica[i].estado_da_estadia, "desocupada") == 0){
                    soma += (c.estadiaEspecifica[i].quant_diarias * 10);
                }
            }
            if(soma == 0){
                printf("Usuário provavelmente não deu baixa em nenhma estadia !!! \n");
            }
            return soma;
        }
        else{
            return 0;
        }
    }
}
