#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define LIMITE 10
#define PRECO 10

typedef struct Client{
    char nome[15];
    int idade;
    char cpf[11];
    char numero[15];
    char cep[8];
    int registro;
} Client;

typedef struct Animal{
    char nome[15];
    int idade;
    int registro;
    char cor[15];
    char raca[15];
    bool vacinado;
} Animal;

typedef struct Service{
    double Banho;
    double Tosa;
    double Vacina;
    int registro;
} Service;

typedef struct Stock{
    double Racao;
    double Shampoo;
    double Brinquedo;
    double ;
} Stock;

Client* createClient(int size);

Animal* createAnimal(int size);

Stock* createStock(int size);

void clear_buffer(void);

void accessClient(Client* register, int size);

void accessAnimal(Animal* register, int size);

Animal* search(Animal* register, int lim);

int main(int argc, char* argv[]){
    Client* client;
    Animal* animal;
    Service* service;
    Stock* stock;
    char selection = '0';
    Animal* animalSearch;
    
    client = createClient(LIMITE);
    animal = createAnimal(LIMITE);
    service = createService(PRECO);
    stock = createStock(PRECO);

    do {
        printf("[1] - Cadastrar Cliente\n");
        printf("[2] - Cadastrar Animal\n");
        printf("[3] - Cadastrar Servico\n");
        printf("[4] - Cadastrar Estoque\n");
        printf("[5] - Buscar Animal\n");
        printf("[6] - Imprimir Estoque\n\n\n");
        printf("[7] - Imprimir Servicos\n\n\n");
        printf("[8] - Encerrar Programa\n\n\n");
        
        printf("Sua escolha? ");
        selection = getchar();
        
        switch (selection) {
            case '1':
                accessClient(client, LIMITE);
                break;
            case '2':
                accessAnimal(animal, LIMITE);
                break;
            case '3':
                accessService(service, PRECO);
                break;
            case '4':
                 accessStock(stock, PRECO);
                break;        
            case '5':
                if ((animalSearch = search(animal, LIMITE)) != NULL) {
                    printf("Nome: %s\n", animalSearch->nome);
                    printf("Idade: %d\n", animalSearch->idade);
                    printf("Cor: %s\n", animalSearch->cor);
                    printf("Raca: %s\n", animalSearch->raca);
                    printf("Registro: %d\n", animalSearch->registro);
                    
                    if (animalSearch->vacinado == true) {
                        printf("Vacinado: sim\n");
                    }else{
                        printf("Vacinado: nao\n");
                    }
                }else{
                    printf("Animal nao cadastrado.\n");
                }
                break;
            case '6':
                 printStock(stock);
                break;      
             case '7':
                 printService(service);
                break;          
            case '8':
                printf("Encerrando o programa.");
                break;
            default:
                printf("Opcao Invalida. Tente novamente.\n");
        }
    } while (selection != '8');
    
    return 0;
}

void clear_buffer(void){
    char c;
    
    while((c = getchar()) != '\n' && c != EOF){};
}

Animal* createAnimal(int size){
    Animal* record;
    
    record = (Animal*)malloc(sizeof(Animal) * size);
    
    return record;
}

Client* createClient(int size){
    Client* record;
    
    record = (Client*)malloc(sizeof(Client) * size);
    
    return record;
}

Service* createService(int size){
    Service* record;
    
    record = (Service*)malloc(sizeof(Service) * size);
    
    return record;
}

void accessClient(Client* record, int size){
    int count = 0;
    static int rg;
    char keep;
    
    do {
        system("clear");
        
        printf("Cadastro de Cliente\n\n");
        
        printf("Nome: ");
        fgets(record[count].nome, 15, stdin);
        
        printf("Idade: ");
        scanf("%d", &(record[count].idade));
        
        printf("Cpf: ");
        fgets(record[count].cpf, 15, stdin);

        printf("Numero: ");
        fgets(record[count].numero, 15, stdin);
        
        printf("Cep: ");
        fgets(record[count].cep, 8, stdin);

        clear_buffer();
        
        record[count].registro = rg++;
        
        count++;
    
        printf("\n\n\nCadastrar outro cliente? ");
        
        keep = getchar();
        
    } while (count < size && (keep != 'n' && keep != 'N'));

}

void accessAnimal(Animal* record, int size){
    int count = 0;
    static int rg;
    char keep;
    
    do {
        system("clear");
        
        printf("Cadastro de Animal\n\n");
        
        printf("Nome: ");
        fgets(record[count].nome, 15, stdin);
        
        printf("Idade: ");
        scanf("%d", &(record[count].idade));
        
        clear_buffer();
        
        printf("Cor: ");
        fgets(record[count].cor, 15, stdin);
        
        printf("Raca: ");
        fgets(record[count].raca, 15, stdin);
        
        record[count].registro = rg++;
        
        count++;
    
        printf("\n\n\nCadastrar outro animal? ");
        
        keep = getchar();
        
    } while (count < size && (keep != 'n' && keep != 'N'));

}

void accessService(Service* record, int size){
    int count = 0;
    static int rg;
    char keep;
    
    do {
        system("clear");
        
        printf("Cadastro Pretacao de Servico\n\n");
        
        printf("Banho: ");
        fgets("%ld", &record[count].banho);
        
        printf("Tosa: ");
        scanf("%ld", &(record[count].tosa));
        
        printf("Vacina: ");
        fgets("%ld", &record[count].vacina);

        clear_buffer();
        
        record[count].registro = rg++;
        
        count++;
    
        printf("\n\n\nModificar o preco? ");
        
        keep = getchar();
        
    } while (count < size && (keep != 'n' && keep != 'N'));

}

void accessStock(Stock* record, int size){
    int count = 0;
    static int rg;
    char keep;
    
    do {
        system("clear");
        
        printf("Cadastro Estoque\n\n");
        
        printf("Racao: ");
        fgets("%ld", &record[count].racao);
        
        printf("Shampoo: ");
        fgets("%ld", &(record[count].shampoo));
        
        printf("Brinquedo: ");
        fgets("%ld", &record[count].brinquedo);

        clear_buffer();
        
        record[count].registro = rg++;
        
        count++;
    
        printf("\n\n\nModificar o preco? ");
        
        keep = getchar();
        
    } while (count < size && (keep != 'n' && keep != 'N'));

}

Animal* search(Animal* record, int lim){
    char nameSearch[15];
    int count;
    Animal* response = NULL;
    
    system("clear");
    
    printf("Busca de Animal\n\n");
    
    printf("Nome Animal: ");
    fgets(nameSearch, 15, stdin);
    
    for (count = 0; count < lim; count++) {
        if (strcmp(record[count].nome, nameSearch) == 0) {
            *response = record[count];
        }
    }
    
    return response;
}

int printStock(record){
    int count = 0;
    
    FILE*arq = fopen("stock.txt", "w");
    
    fprint(arq, record);
    
    fclose(arq);
    
    return 0;
}

int printService(record){
    int count = 0;
    
    FILE*arq = fopen("service.txt", "w");
    
    fprint(arq, record);
    
    fclose(arq);
    
    return 0;
}
