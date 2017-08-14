/*construa um programa que leia os clientes da gremio-tur cada cliente
 devera ter as seguintes informacoes: nome, idade, salario base, valor
 em compras.

 O sistema ira permitir  cadastro e a cxonsulta dos clientes por nome
  e idade ou listar todos.
 */

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<ctype.h>
#include<io.h>
#include<string.h>
#include<string>
#include<dos.h>
#include <math.h>
using namespace std;

struct variavelClientes {
    int  cod_cliente;
    char nome[30];
    char fone[30];
    char endereco[50];
    char cpf[11];
    int cod_notas;

} cliente;
FILE *clientes;
FILE *auxiliarClientes;

struct VariavelNotas {
    int cod_notas;
    char numeroNota[30];
    int cod_cliente;
    int cod_itens_notas;
    float total;

} nota;
FILE *notas;
FILE *auxiliarNotas;

struct varieavelItensNotas {
    int cod_itens_notas;
    int cod_produto;
    int quantidade;
    float preco;

} itens_nota;
FILE *itens_notas;
FILE *auxiliarItensNotas;

struct variavelProdutos {
    int cod_produto;
    char descricao[50];
    float preco;
    int quantidadeEstoque;

} produto;
FILE *produtos;
FILE *auxiliarProdutos;

int tam, opc;
char op;

/*fim declaracao de varieveis */

/* inicio clientes */
void auxiliar_cliente() {

    auxiliarClientes = fopen("auxiliarClientes.dat", "a+");
    if (ferror(auxiliarClientes)) {
        perror("Erro na Criancao");
        fclose(auxiliarClientes);
        exit(1);
    }
    fclose(auxiliarClientes);
}

void arquivo_clientes() {
    if ((clientes = fopen("clientes.dat", "a")) == NULL) {
        printf("Erro de criacao do arquivo");
        return;
    }
    printf("Arquivo Criado");
    //delay(1000);
    fclose(clientes);
}

void cadastrar_clientes() {
    system("cls");

    do {

        clientes = fopen("clientes.dat", "a");
        system("cls");
        cliente.cod_cliente;
        cliente.cod_notas++;
        cout << "Cod. Cliente:" << cliente.cod_cliente << endl;
        cout << "Digite o nome do cliente:" << endl;
        scanf("%s", &cliente.nome);
        cout << "Digite o CPF:" << endl;
        scanf("%s", &cliente.cpf);
        cout << "Digite o telefone:" << endl;
        scanf("%s", &cliente.fone);
        cout << "Digite o Endereço:" << endl;
        scanf("%s", &cliente.endereco);
        cout << "Digite o Cod. notas:" << endl;
        scanf("%s", &cliente.cod_notas);
        fwrite(&cliente, sizeof (struct variavelClientes), 1, clientes);
        fclose(clientes);
        cout << "Continuar cadastrando<s> ou <n>: \n";
        cin>>op;
        op = toupper(op);
    } while (op == 'S');
}

void consulta_clientes() {
    system("cls");
    clientes = fopen("clientes.dat", "r");
    rewind(clientes);

    while (fread(&cliente, sizeof (cliente), 1, clientes) == 1) {
        system("cls");
        cout << "Cod. Cliente: " << cliente.cod_cliente << endl;
        cout << "\n Nome: ";
        cout << cliente.nome;
        cout << "\n Telefone: ";
        cout << cliente.fone;
        cout << "\n CPF: ";
        cout << cliente.cpf;
        cout << "\n Digite enter para continuar \n";
        getch();
    }
    cout << "fim do arquivo";
    fclose(clientes);
    getch();
}

void consulta_nome_cliente() {
    char nom_pro[20];
    int achou,
            cont = 0;
    system("cls");
    clientes = fopen("clientes.dat", "r+");
    rewind(clientes);
    printf("Digite o Nome p/ Procura:");
    cin>> nom_pro;
    while (fread(&cliente, sizeof (cliente), 1, clientes) == 1) {
        achou = strcmp(cliente.nome, nom_pro);
        if (achou == 0) {
            cout << "Nome:" << cliente.nome << endl;
            cout << "Telefone:" << cliente.fone << endl;
            cout << "Endereço:" << cliente.endereco << endl;
            cout << "CPF:" << cliente.cpf << endl;
            printf("_____________________________________________\n");
            getch();
            cont = 1;
        }
    }
    if (cont == 0) {
        printf("Nome nao Cadastrado\n");
        printf("\nCadastrar Cliente<s> ou <n>:");
        cin>>op;
        op = toupper(op);
        if (op == 'S') {
            cadastrar_clientes();
            getch();
        }
    }
}

void menu_clientes() {
    system("cls");
    printf("Menu de opcoes");
    printf("\n");
    printf("1 - Cadastrar\n");
    printf("2 - Consultar\n");
    printf("3 - Consultar Por Nome\n");
    printf("4 - Sair\n");
    printf("Digite uma opcao\n");
    cin>>opc;
    switch (opc) {
        case 1:cadastrar_clientes;
            break;
        case 2:consulta_clientes();
            break;
        case 3:consulta_nome_cliente();
            break;
        case 4:exit(0);
    }
}

/*fim clientes*/

/* inicio notas*/

void auxiliar_notas() {

    auxiliarNotas = fopen("auxiliarNotas.dat", "a+");
    if (ferror(auxiliarNotas)) {
        perror("Erro na Criancao");
        fclose(auxiliarNotas);
        exit(1);
    }
    fclose(auxiliarNotas);
}

void arquivo_notas() {
    if ((notas = fopen("notas.dat", "a")) == NULL) {
        printf("Erro de criacao do arquivo");
        return;
    }
    printf("Arquivo Criado");
    //delay(1000);
    fclose(clientes);
}

void cadastrar_notas() {
    system("cls");

    do {

        clientes = fopen("notas.dat", "a");
        system("cls");
        nota.cod_notas++;
        cout << "Cod. Nota:" << nota.cod_notas << endl;
        cout << "Cod. Cliente:" << endl;
        scanf("%s", &nota.cod_cliente);
        cout << "Digite o Total:" << endl;
        scanf("%s", &nota.total);
        fwrite(&nota, sizeof (struct VariavelNotas), 1, notas);
        fclose(notas);
        cout << "Continuar cadastrando<s> ou <n>: \n";
        cin>>op;
        op = toupper(op);
    } while (op == 'S');
}

void consulta_notas() {
    system("cls");
    clientes = fopen("notas.dat", "r");
    rewind(notas);

    while (fread(&nota, sizeof (nota), 1, notas) == 1) {
        system("cls");
        cout << "Cod. Notas: " << nota.cod_notas << endl;
        cout << "\n Cod. Clientes: ";
        cout << nota.cod_notas;
        cout << "\n Digite enter para continuar \n";
        getch();
    }
    cout << "fim do arquivo";
    fclose(notas);
    getch();
}

void menu_notas() {
    system("cls");
    printf("Menu de opcoes");
    printf("\n");
    printf("1 - Cadastrar\n");
    printf("2 - Consultar\n");
    printf("3 - Sair\n");
    printf("Digite uma opcao\n");
    cin>>opc;
    switch (opc) {
        case 1:cadastrar_notas();
            break;
        case 2:consulta_notas();
            break;
        case 3: exit(0);
    }
}

/*fim notas*/

/*inicio itens notas*/

void auxiliar_itens_notas() {

    auxiliarItensNotas = fopen("auxiliarItensNotas.dat", "a+");
    if (ferror(auxiliarItensNotas)) {
        perror("Erro na Criancao");
        fclose(auxiliarItensNotas);
        exit(1);
    }
    fclose(auxiliarItensNotas);
}

void arquivo_itens_notas() {
    if ((itens_notas = fopen("itens_notas.dat", "a")) == NULL) {
        printf("Erro de criacao do arquivo");
        return;
    }
    printf("Arquivo Criado");
    fclose(itens_notas);
}

void cadastrar_itens_notas() {
    system("cls");

    do {

        clientes = fopen("itens_notas.dat", "a");
        system("cls");
        itens_nota.cod_itens_notas++;
        cout << "Cod. Cliente:" << itens_nota.cod_itens_notas << endl;
        cout << "Digite o Cod. Produto:" << endl;
        scanf("%s", &itens_nota.cod_produto);
        cout << "Digite quantidade:" << endl;
        scanf("%s", &itens_nota.quantidade);
        cout << "Digite o preço:" << endl;
        scanf("%s", &itens_nota.preco);
        fwrite(&itens_nota, sizeof (struct varieavelItensNotas), 1, itens_notas);
        fclose(clientes);
        cout << "Continuar cadastrando<s> ou <n>: \n";
        cin>>op;
        op = toupper(op);
    } while (op == 'S');
}

void consulta_itens_notas() {
    system("cls");
    itens_notas = fopen("itens_notas.dat", "r");
    rewind(itens_notas);

    while (fread(&itens_nota, sizeof (itens_nota), 1, itens_notas) == 1) {
        system("cls");
        cout << "Cod. Itens notas:" << itens_nota.cod_itens_notas << endl;
        cout << "Cod. Produtos:" << itens_nota.cod_produto << endl;
        cout << "\n Digite enter para continuar \n";
        getch();
    }
    cout << "fim do arquivo";
    fclose(itens_notas);
    getch();
}

void menu_itens_notas() {
    system("cls");
    printf("Menu de opcoes");
    printf("\n");
    printf("1 - Cadastrar\n");
    printf("2 - Consultar\n");
    printf("3 - Sair\n");
    printf("Digite uma opcao\n");
    cin>>opc;
    switch (opc) {
        case 1:cadastrar_itens_notas();
            break;
        case 2:consulta_itens_notas();
            break;
        case 3: exit(0);
    }
}

/*fim itens notas*/

/*inicio produtos*/

void auxiliar_produtos() {

    auxiliarProdutos = fopen("auxiliarProdutos.dat", "a+");
    if (ferror(auxiliarProdutos)) {
        perror("Erro na Criancao");
        fclose(auxiliarProdutos);
        exit(1);
    }
    fclose(auxiliarProdutos);
}

void arquivo_produtos() {
    if ((produtos = fopen("produtos.dat", "a")) == NULL) {
        printf("Erro de criacao do arquivo");
        return;
    }
    printf("Arquivo Criado");
    //delay(1000);
    fclose(produtos);
}

void cadastrar_produtos() {
    system("cls");

    do {

        clientes = fopen("produtos.dat", "a");
        system("cls");
        produto.cod_produto++;
        cout << "Cod. Produto:" << produto.cod_produto << endl;
        cout << "Digite a descricao do produto:" << endl;
        scanf("%s", & produto.descricao);
        cout << "Digite o preco:" << endl;
        scanf("%s", &produto.preco);
        cout << "Digite a quantidade em estoque:" << endl;
        scanf("%s", &produto.quantidadeEstoque);
        fwrite(&produto, sizeof (struct variavelProdutos), 1, produtos);
        fclose(clientes);
        cout << "Continuar cadastrando<s> ou <n>: \n";
        cin>>op;
        op = toupper(op);
    } while (op == 'S');
}

void consulta_produtos() {
    system("cls");
    clientes = fopen("produtos.dat", "r");
    rewind(produtos);

    while (fread(&produto, sizeof (produto), 1, produtos) == 1) {
        system("cls");
        cout << "Cod. Produto: " << produto.cod_produto << endl;
        cout << "\n Digite enter para continuar \n";
        getch();
    }
    cout << "fim do arquivo";
    fclose(produtos);
    getch();
}

void consulta_descricao_produto() {
    char nom_pro[20];
    int achou,
            cont = 0;
    system("cls");
    clientes = fopen("produtos.dat", "r+");
    rewind(produtos);
    printf("Digite a descricao:");
    cin>> nom_pro;
    while (fread(&produto, sizeof (produto), 1, produtos) == 1) {
        achou = strcmp(produto.descricao, nom_pro);
        if (achou == 0) {
            cout << "Descricao:" << produto.descricao << endl;
            cout << "Cod. produto:" << produto.cod_produto << endl;
            cout << "Preço do produto" << produto.preco << endl;
            cout << "QUantidade do produto em estoque" << produto.quantidadeEstoque << endl;
            printf("_____________________________________________\n");
            getch();
            cont = 1;
        }
    }
    if (cont == 0) {
        printf("Produto nao Cadastrado\n");
        printf("\nCadastrar Produto<s> ou <n>:");
        cin>>op;
        op = toupper(op);
        if (op == 'S') {
            cadastrar_produtos();
            getch();
        }
    }
}

void menu_produtos() {
    system("cls");
    printf("Menu de opcoes");
    printf("\n");
    printf("1 - Cadastrar\n");
    printf("2 - Consultar\n");
    printf("3 - Consultar Descricao do produto\n");
    printf("4 - Sair\n");
    printf("Digite uma opcao\n");
    cin>>opc;
    switch (opc) {
        case 1:cadastrar_produtos();
            break;
        case 2:consulta_produtos();
            break;
        case 3:consulta_descricao_produto();
            break;
        case 4:exit(0);
    }
}

/*fim produtos*/

main() {
    system("cls");
    do {
        printf("::: Menu geral opcoes :::");
        printf("\n");
        printf("1 - Menu Clientes\n");
        printf("2 - Menu Notas\n");
        printf("3 - Menu Itens Notas \n");
        printf("4 - Menu Produtos \n");
        printf("5 - Sair\n");
        printf("Digite uma opcao\n");

        cin>>opc;

        switch (opc) {
            case 1:menu_clientes();
                break;
            case 2:menu_notas();
                break;
            case 3:menu_itens_notas();
                break;
            case 4:menu_produtos();
                break;
            case 5:exit(0);
        }
    } while (op != 5);
}

