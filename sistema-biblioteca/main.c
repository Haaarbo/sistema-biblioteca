#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define tam 20 //Tamanho do vetor struct
#define tamNome 70 //tamanho da string nome e curso
#define tamNum 30 //tamanho da string cpf e rg

contCad = 0;//quantidade de cadastros realizados, sendo tam a quantidade maxima
codPadrao = 0; //codigo associado a um cadastro, aumenta conforme forem cadastrados mais pessoas

void menu (void);
int novoCadastro(int);
int alterarCadastro();
void excluirCadastro(int);


struct cadastro{
    int cod;
    char nome[tamNome];
    char cpf[tamNum];
    char rg[tamNum];
    char turma;
    int serie;
    char curso [tamNome];
};

struct cadastro cad[tam];

int main()
{
    printf("Bem-vindo(a)!\n Escolha uma das opcoes a seguir:\n\n");
    getchar();
    menu();
    return 0;
}

void menu()
{
    int op;

    system("cls");
    do
    {

        printf("1.Novo cadastro.\n");
        printf("2.Alterar cadastro\n");
        printf("3.Sair.\n");
        fflush(stdin);
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                contCad = novoCadastro(contCad);
                printf("Agora ha %d contas existentes!\n", contCad);
                getchar();
                system("cls");
                break;

            case 2:
                alterarCadastro();
                system("cls");
                break;

            case 3:
                printf("\n\nSaindo...");
                getchar();
                system("cls");
                break;

            default:
                printf("\n\nOpcao invalida! Tente novamente...\n");
                getchar();
                system("cls");
                break;
        }

    }while(op != 3);
}

int novoCadastro(contCad)
{
    system("cls");
    if(contCad >= tam)
    {
        printf("Numero maximo de cadastros. Por favor, exclua algum cadastro para poder registrar um novo...\n\n");
        getchar();
        system("cls");
    }

    else
    {
        printf("Por favor, insira os seguintes dados para efetuar o cadastro:\n\n");
        fflush(stdin);
        printf("Nome completo: ");
        fgets(cad[contCad].nome, tamNome, stdin);
        printf("\nCPF: ");
        fgets(cad[contCad].cpf, tamNum, stdin);
        printf("\nRG: ");
        fgets(cad[contCad].rg, tamNum, stdin);
        printf("\nSerie: ");
        scanf("%d", &cad[contCad].serie);
        fflush(stdin);
        printf("\nTurma: ");
        scanf("%c", &cad[contCad].turma);
        fflush(stdin);
        printf("\nCurso: ");
        fgets(cad[contCad].curso, tamNome, stdin);
        printf("\nCodigo: ");
        scanf("%d", &cad[contCad].cod);
        contCad++;
    }

    return contCad;
}

int alterarCadastro()
{
    int codPesquisa = -1;

    system("cls");
    printf("Insira o codigo do aluno para pesquisa, ou digite 0 para sair...\n\n");
    fflush(stdin);
    scanf("%d", &codPesquisa);
    fflush(stdin);

    if(codPesquisa == 0)
    {
        printf("Saindo\n");
    }

    else
    {
        printf("Resultado da pesquisa:\n\n\n");
        for(int i = 0; i < contCad; i++)
        {
            if(codPesquisa == cad[i].cod)
            {
                puts("------------------------------------");
                puts("Nome: ");//printar os dados do aluno correspondente
                puts(cad[i].nome); //nome
                puts("Codigo: ");//codigo
                printf("%d\n", cad[i].cod);
                puts("Serie: ");//serie
                printf("%d\n", cad[i].serie);
                puts("Turma: ");//turma
                printf("%c\n", cad[i].turma);
                puts("Curso: ");//curso
                puts(cad[i].curso);
                puts("CPF: ");//cpf
                puts(cad[i].cpf);
                puts("RG: ");//rg
                puts(cad[i].rg);
                puts("------------------------------------");
                getchar();

                int opAlterar;
                do{
                    printf("\n\nO que desejas fazer com o cadastro?\n\n");
                    printf("1.Alterar.\n");
                    printf("2.Excluir.\n");
                    printf("3.Sair.\n");
                    fflush(stdin);
                    scanf("%d", &opAlterar);

                    switch(opAlterar)
                    {
                        case 1:
                            getchar();
                            printf("\nopcao 1\n");
                            fflush(stdin);
                            printf("Nome completo: ");
                            fgets(cad[i].nome, tamNome, stdin);
                            fflush(stdin);
                            printf("\nCPF: ");
                            fgets(cad[i].cpf, tamNum, stdin);
                            fflush(stdin);
                            printf("\nRG: ");
                            fgets(cad[i].rg, tamNum, stdin);
                            fflush(stdin);
                            printf("\nSerie: ");
                            scanf("%d", &cad[i].serie);
                            fflush(stdin);
                            printf("\nTurma: ");
                            scanf("%c", &cad[i].turma);
                            fflush(stdin);
                            printf("\nCurso: ");
                            fgets(cad[i].curso, tamNome, stdin);
                            fflush(stdin);
                            printf("\n\nCadastro alterado com sucesso!\n");
                            break;

                        case 2:
                            printf("\nopcao 2\n");
                            getchar();
                            excluirCadastro(i);
                            return 0;
                            break;

                        case 3:
                            menu();
                            printf("\nopcao 3\n");
                            getchar();
                            break;

                        default:
                            printf("\nOpcao invalida.\n");
                            getchar();
                            system("cls");
                            break;
                    }
                }while(opAlterar != 2);
            }

        }
    }

    printf("\nPesquisa finalizada.\n");
    getchar();
    return 0;
}

void excluirCadastro(int numExcluir)
{
    //numExcluir refere-se ao i interior que aponta para a posicao desejada (nao tem nada a ver com ponteiros)
    system("cls");

    puts(cad[numExcluir].nome);
    puts(cad[numExcluir].cpf);
    puts(cad[numExcluir].rg);
    printf("%c\n", cad[numExcluir].turma);
    puts(cad[numExcluir].curso);
    printf("%i\n", cad[numExcluir].serie);
    printf("%i\n", cad[numExcluir].cod);

    getchar();

    cad[numExcluir].cod = -1;
    printf("%d\n", cad[numExcluir].cod);
    contCad--;

    printf("\n\nExclusao do cadastro realizada com exito!\n\n");
    getchar();
}
