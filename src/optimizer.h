#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um temporário
typedef struct TempVar {
    char* name;
    int reg;           // Registrador usado (0-4) ou -1 para memória
    int memory_offset; // Offset na memória se reg == -1
    int in_use;        // Se está sendo usado atualmente
} TempVar;

// Estrutura para o otimizador
typedef struct Optimizer {
    TempVar* temps;
    int temp_count;
    int max_temps;
    int next_reg;      // Próximo registrador disponível (0-4)
    int tmp_offset;    // Offset para temporários em memória
} Optimizer;

// Funções do otimizador
Optimizer* optimizer_init();
void optimizer_free(Optimizer* opt);
int optimizer_allocate_temp(Optimizer* opt, char* name);
void optimizer_free_temp(Optimizer* opt, int temp_id);
int optimizer_get_reg(Optimizer* opt, int temp_id);
int optimizer_get_memory_offset(Optimizer* opt, int temp_id);
void optimizer_reset(Optimizer* opt);

// Funções para otimizar código
void optimize_expression_code(Optimizer* opt, char* code);
char* generate_optimized_load(int temp_id, Optimizer* opt);
char* generate_optimized_store(int temp_id, Optimizer* opt, char* value);

#endif 