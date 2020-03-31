#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

int funcaoCadastrarCliente();///retorna 1 se deu para cadastrar e zero se não
void imprimiArquivoClientes(char*);
void imprimiArquivoEstadias();
void imprimiArquivoQuartos();
void imprimiArquivoFuncionarios(char*);
int funcaoCadastrarFuncionarios();///retorna 1 se deu para cadastrar e zero se não
int funcaoCadastrarQuarto();///retorna 1 se deu para cadastrar e zero se não
int funcaoCadastrarEstadia(char*,int, char*, char*);///retorna 1 se deu para cadastrar e zero se não
int funcaoValidarData(char*);///retorna 1 se deu para cadastrar e zero se não
int funcaoVerificaExistenciaDoCliente(char*);///retorna 1 se deu para cadastrar e zero se não
int funcaoVerificaExistenciaDeQuarto(int);///retorna 1 se deu para cadastrar e zero se não
int gerarCodigoEstadia();///retorna 1 se deu para cadastrar e zero se não
void funcaoMostrarTodasEstadiasDeUmCliente(char*);
int funcaoBaixaEmUmaEstadia(int, float*);///retorna 1 se deu para cadastrar e zero se não
int funcaoPontosDeFidelidade(char*); ///retorna 0 se não for possível ler o arquivo ou se não tiver o nome procurado cadastrado e retorna a soma dos pontos de fidelidade se o cliente estiver cadastrado e estiver dado baixa em alguma estadia;
#endif // FUNCOES_H_INCLUDED
