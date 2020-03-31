#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

int funcaoCadastrarCliente();///retorna 1 se deu para cadastrar e zero se n�o
void imprimiArquivoClientes(char*);
void imprimiArquivoEstadias();
void imprimiArquivoQuartos();
void imprimiArquivoFuncionarios(char*);
int funcaoCadastrarFuncionarios();///retorna 1 se deu para cadastrar e zero se n�o
int funcaoCadastrarQuarto();///retorna 1 se deu para cadastrar e zero se n�o
int funcaoCadastrarEstadia(char*,int, char*, char*);///retorna 1 se deu para cadastrar e zero se n�o
int funcaoValidarData(char*);///retorna 1 se deu para cadastrar e zero se n�o
int funcaoVerificaExistenciaDoCliente(char*);///retorna 1 se deu para cadastrar e zero se n�o
int funcaoVerificaExistenciaDeQuarto(int);///retorna 1 se deu para cadastrar e zero se n�o
int gerarCodigoEstadia();///retorna 1 se deu para cadastrar e zero se n�o
void funcaoMostrarTodasEstadiasDeUmCliente(char*);
int funcaoBaixaEmUmaEstadia(int, float*);///retorna 1 se deu para cadastrar e zero se n�o
int funcaoPontosDeFidelidade(char*); ///retorna 0 se n�o for poss�vel ler o arquivo ou se n�o tiver o nome procurado cadastrado e retorna a soma dos pontos de fidelidade se o cliente estiver cadastrado e estiver dado baixa em alguma estadia;
#endif // FUNCOES_H_INCLUDED
