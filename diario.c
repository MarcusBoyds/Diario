    int endereco_da_entrada = 0;
    
    //buscar entrada
    for(int i=0; numero_de_busca != (ptr+i)->id; i++){ 
        contador++;
        endereco_da_entrada = i;
        if(contador==2){
            printf("Não foi encontrado essa entrada. Digite outra: ");
            scanf("%d", &numero_de_busca);
            contador=0;
            i=0;
        }
    }

    //Pedir senha 
    int senha = 0;
    printf("Entrada encontrada! Digite a senha da entrada %d: ",numero_de_busca);
    scanf("%d",&senha);

    //Verificar senha
    while (senha != (ptr+endereco_da_entrada)->fechadura){
        printf("Senha errada, digite outra: ");
        scanf("%d",&senha);
    }
    
    //Mostrar informações
    printf("Entrada do Diário %d:\n",n_entrada);
    printf("1. Humor: %s\n",(ptr+endereco_da_entrada)->humor);
    printf("2. Dia: %d\n",(ptr+endereco_da_entrada)->dia);
    printf("3. Descricao: %s",(ptr+endereco_da_entrada)->descricao);

}

  
diario setEntradaDoDiario(char *humor, char *descricao, int dia, int id){
    diario dados;
    dados.dia = dia;
    dados.id = id;
    strcpy(dados.humor, humor);
    strcpy(dados.descricao, descricao);
    return dados;
}


//Programa Principal
int main(){
    //Informações do diário.
    diario entradas[2];
    entradas[0] = setEntradaDoDiario("A","Estou bem!",12,1);
    entradas[1] = setEntradaDoDiario("E","Ruim porra!",4,9);

    //Introdução do programa
    printf("Seja bem vindo ao diario, para abrir gere uma chave!\n");

    //Gerar chave e guardar na fechadura 
    int chave = gerarChave();
    entradas[0].fechadura = chave;  //mesma chave pras duas fechaduras!!
    entradas[1].fechadura = chave;

    //Mostrar a informação da entrada pedida
    int n_entrada;
    printf("Deseja abrir o diário em qual entrada?: ");
    scanf("%d",&n_entrada);

    mostrarEntrada(n_entrada, entradas);
    
    return 0;
}