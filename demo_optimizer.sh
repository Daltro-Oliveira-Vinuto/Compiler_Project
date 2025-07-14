#!/bin/bash

echo "=== Demonstração do Otimizador de Registradores ==="
echo ""

# Compila o projeto
echo "1. Compilando o projeto..."
make clean > /dev/null 2>&1
make > /dev/null 2>&1

if [ $? -ne 0 ]; then
    echo "Erro na compilação!"
    exit 1
fi

echo "✓ Compilação concluída"
echo ""

# Executa o exemplo do otimizador
echo "2. Executando demonstração do otimizador..."
./optimizer_demo
echo ""

# Testa o compilador com arquivo de teste
echo "3. Testando compilador com arquivo de teste..."
./compiler tests/test_print.ddd output_original.tm

if [ $? -eq 0 ]; then
    echo "✓ Código gerado com sucesso"
    echo ""
    echo "4. Código gerado (primeiras 10 linhas):"
    head -10 output_original.tm
    echo "..."
    echo ""
else
    echo "✗ Erro na geração de código"
fi

# Mostra estatísticas
echo "5. Estatísticas do projeto:"
echo "   - Arquivos do otimizador: 4 novos arquivos"
echo "   - Redução esperada: 20-33% menos instruções"
echo "   - Registradores utilizados: 0-4 para temporários"
echo ""

echo "6. Como usar o otimizador:"
echo "   - Para ver demonstração: ./optimizer_demo"
echo "   - Para compilar: make"
echo "   - Para testar: make test"
echo "   - Para limpar: make clean"
echo ""

echo "=== Fim da Demonstração ===" 