#include "optimizer.h"

// Inicializa o otimizador
Optimizer* optimizer_init() {
    Optimizer* opt = malloc(sizeof(Optimizer));
    opt->max_temps = 10;
    opt->temps = malloc(sizeof(TempVar) * opt->max_temps);
    opt->temp_count = 0;
    opt->next_reg = 0;  // Começa com registrador 0
    opt->tmp_offset = 0;
    
    // Inicializa todos os temporários como não usados
    for (int i = 0; i < opt->max_temps; i++) {
        opt->temps[i].name = NULL;
        opt->temps[i].reg = -1;
        opt->temps[i].memory_offset = -1;
        opt->temps[i].in_use = 0;
    }
    
    return opt;
}

// Libera memória do otimizador
void optimizer_free(Optimizer* opt) {
    if (opt) {
        for (int i = 0; i < opt->max_temps; i++) {
            if (opt->temps[i].name) {
                free(opt->temps[i].name);
            }
        }
        free(opt->temps);
        free(opt);
    }
}

// Aloca um novo temporário
int optimizer_allocate_temp(Optimizer* opt, char* name) {
    // Procura por um slot livre
    for (int i = 0; i < opt->max_temps; i++) {
        if (!opt->temps[i].in_use) {
            opt->temps[i].name = strdup(name);
            opt->temps[i].in_use = 1;
            
            // Decide se usa registrador ou memória
            if (opt->next_reg < 5) {
                // Usa registrador (0-4)
                opt->temps[i].reg = opt->next_reg;
                opt->temps[i].memory_offset = -1;
                opt->next_reg++;
            } else {
                // Usa memória
                opt->temps[i].reg = -1;
                opt->temps[i].memory_offset = opt->tmp_offset;
                opt->tmp_offset--;
            }
            
            opt->temp_count++;
            return i;
        }
    }
    
    // Se não encontrou slot livre, usa memória
    for (int i = 0; i < opt->max_temps; i++) {
        if (!opt->temps[i].in_use) {
            opt->temps[i].name = strdup(name);
            opt->temps[i].in_use = 1;
            opt->temps[i].reg = -1;
            opt->temps[i].memory_offset = opt->tmp_offset;
            opt->tmp_offset--;
            opt->temp_count++;
            return i;
        }
    }
    
    return -1; // Erro: não há espaço
}

// Libera um temporário
void optimizer_free_temp(Optimizer* opt, int temp_id) {
    if (temp_id >= 0 && temp_id < opt->max_temps && opt->temps[temp_id].in_use) {
        // Se estava usando registrador, libera para reuso
        if (opt->temps[temp_id].reg >= 0 && opt->temps[temp_id].reg < opt->next_reg) {
            opt->next_reg = opt->temps[temp_id].reg; // Reutiliza o registrador
        }
        
        free(opt->temps[temp_id].name);
        opt->temps[temp_id].name = NULL;
        opt->temps[temp_id].in_use = 0;
        opt->temps[temp_id].reg = -1;
        opt->temps[temp_id].memory_offset = -1;
        opt->temp_count--;
    }
}

// Obtém o registrador usado por um temporário
int optimizer_get_reg(Optimizer* opt, int temp_id) {
    if (temp_id >= 0 && temp_id < opt->max_temps && opt->temps[temp_id].in_use) {
        return opt->temps[temp_id].reg;
    }
    return -1;
}

// Obtém o offset de memória usado por um temporário
int optimizer_get_memory_offset(Optimizer* opt, int temp_id) {
    if (temp_id >= 0 && temp_id < opt->max_temps && opt->temps[temp_id].in_use) {
        return opt->temps[temp_id].memory_offset;
    }
    return -1;
}

// Reseta o otimizador
void optimizer_reset(Optimizer* opt) {
    for (int i = 0; i < opt->max_temps; i++) {
        if (opt->temps[i].name) {
            free(opt->temps[i].name);
        }
        opt->temps[i].name = NULL;
        opt->temps[i].reg = -1;
        opt->temps[i].memory_offset = -1;
        opt->temps[i].in_use = 0;
    }
    opt->temp_count = 0;
    opt->next_reg = 0;
    opt->tmp_offset = 0;
}

// Gera código otimizado para carregar um temporário
char* generate_optimized_load(int temp_id, Optimizer* opt) {
    static char buffer[256];
    int reg = optimizer_get_reg(opt, temp_id);
    int mem_offset = optimizer_get_memory_offset(opt, temp_id);
    
    if (reg >= 0) {
        // Temporário está em registrador
        sprintf(buffer, "LDR %d,%d,%d", 0, reg, 0); // Carrega do registrador para AC
    } else if (mem_offset >= 0) {
        // Temporário está na memória
        sprintf(buffer, "LD %d,%d,%d", 0, mem_offset, 6); // Carrega da memória (mp)
    } else {
        sprintf(buffer, "LDC %d,%d,%d", 0, 0, 0); // Valor padrão
    }
    
    return buffer;
}

// Gera código otimizado para armazenar um temporário
char* generate_optimized_store(int temp_id, Optimizer* opt, char* value) {
    static char buffer[256];
    int reg = optimizer_get_reg(opt, temp_id);
    int mem_offset = optimizer_get_memory_offset(opt, temp_id);
    
    if (reg >= 0) {
        // Armazena em registrador
        sprintf(buffer, "STR %d,%d,%d", 0, reg, 0); // Armazena AC no registrador
    } else if (mem_offset >= 0) {
        // Armazena na memória
        sprintf(buffer, "ST %d,%d,%d", 0, mem_offset, 6); // Armazena na memória (mp)
    } else {
        sprintf(buffer, "NOP"); // Nenhuma operação
    }
    
    return buffer;
} 