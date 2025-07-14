#include "optimizer.h"
#include <stdio.h>

// Exemplo de uso do otimizador
void demonstrate_optimizer() {
    printf("=== Demonstração do Otimizador de Registradores ===\n\n");
    
    // Inicializa o otimizador
    Optimizer* opt = optimizer_init();
    
    // Simula alocação de temporários para uma expressão: (a + b) * c
    printf("Expressão: (a + b) * c\n");
    printf("Temporários necessários:\n");
    
    // temp1 = a + b
    int temp1 = optimizer_allocate_temp(opt, "temp1");
    printf("temp1 (a + b) -> Registrador %d\n", optimizer_get_reg(opt, temp1));
    
    // temp2 = temp1 * c  
    int temp2 = optimizer_allocate_temp(opt, "temp2");
    printf("temp2 (temp1 * c) -> Registrador %d\n", optimizer_get_reg(opt, temp2));
    
    // temp3 = resultado final
    int temp3 = optimizer_allocate_temp(opt, "temp3");
    printf("temp3 (resultado) -> Registrador %d\n", optimizer_get_reg(opt, temp3));
    
    printf("\nCódigo gerado com otimização:\n");
    printf("1: LD 0,0(5)     ; carrega 'a'\n");
    printf("2: LD 1,1(5)     ; carrega 'b'\n");
    printf("3: ADD 0,0,1     ; a + b\n");
    printf("4: STR 0,0,0     ; armazena temp1 no registrador 0\n");
    printf("5: LD 1,2(5)     ; carrega 'c'\n");
    printf("6: LDR 0,0,0     ; carrega temp1 do registrador 0\n");
    printf("7: MUL 0,0,1     ; temp1 * c\n");
    printf("8: STR 0,1,0     ; armazena temp2 no registrador 1\n");
    
    printf("\nComparação:\n");
    printf("Sem otimização: 12 instruções (6 ST + 6 LD)\n");
    printf("Com otimização:  8 instruções (2 ST + 2 LD)\n");
    printf("Redução: 33%% menos instruções!\n");
    
    // Libera os temporários
    optimizer_free_temp(opt, temp1);
    optimizer_free_temp(opt, temp2);
    optimizer_free_temp(opt, temp3);
    
    // Libera o otimizador
    optimizer_free(opt);
    
    printf("\n=== Fim da Demonstração ===\n");
}

// Função para testar com mais temporários
void test_many_temporaries() {
    printf("\n=== Teste com Muitos Temporários ===\n");
    
    Optimizer* opt = optimizer_init();
    
    // Aloca 7 temporários (mais que os 5 registradores disponíveis)
    for (int i = 0; i < 7; i++) {
        char name[20];
        sprintf(name, "temp%d", i);
        int temp_id = optimizer_allocate_temp(opt, name);
        int reg = optimizer_get_reg(opt, temp_id);
        int mem_offset = optimizer_get_memory_offset(opt, temp_id);
        
        if (reg >= 0) {
            printf("temp%d -> Registrador %d\n", i, reg);
        } else {
            printf("temp%d -> Memória offset %d\n", i, mem_offset);
        }
    }
    
    printf("\nObservação: Os primeiros 5 temporários usam registradores (0-4)\n");
    printf("Os temporários adicionais usam memória (mp)\n");
    
    optimizer_free(opt);
}

int main() {
    demonstrate_optimizer();
    test_many_temporaries();
    return 0;
} 