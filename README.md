## Compiler Project

Members:
	- Daltro Oliveira Vinuto
 	- JOAO VITOR DICKMANN
 	- Maria Clara Mendes Goncalves
  	- Raylan da Silva Sales
   	- HENRIQUE CARVALHO WOLSKI

## How to Run?

- clone the Project  
- download MSYS2 at https://www.msys2.org  
- open the terminal [MSYS2 MSYS]  
- navigate to your cloned Project  

```bash
cd /c/your_directory/Compiler_Project
make
./analisador < ./testes/multiple_comands.txt
```

Exemplo
```bash
{ a = 3; b = 2 + 3; print a; print b; }
```

Resultado
```bash
Número
Identificador
Atribuição
Número
Número
Soma
Identificador
Atribuição
Identificador
Comando de impressão com expressão
Identificador
Comando de impressão com expressão
```
