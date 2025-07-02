go: all load 
all: clear rule_bison rule_flex rule_main link_flex_bison_and_main
rule_flex:  flex preprocess_compile_and_assemble_flex
rule_bison: bison preprocess_compile_and_assemble_bison
rule_main: preprocess_compile_and_assemble_main
load: load_elf
run: run_tiny

SRC_MAIN := ../src/main.c
OBJECT_MAIN := main.o
FLEX_FILENAME = scanner.l 
SRC_FLEX := ../src/$(FLEX_FILENAME)
FLEX_OUTPUT := lex.yy.c
OBJECT_FLEX := lex.yy.o
BISON_FILENAME := parser
SRC_BISON := ../src/$(BISON_FILENAME)
BISON_TYPE := .y
BISON_OUTPUT := $(BISON_FILENAME).tab.c
OBJECT_BISON := $(BISON_FILENAME).tab.o
ELF := compiler.elf
INPUT_COMPILER_CODE := ../tests/test_print.ddd
OUTPUT_COMPILER_CODE := ../tiny/output.tm 

# BEGIN Flex section ====================================================
flex:
	flex $(SRC_FLEX)

preprocess_compile_and_assemble_flex:
	gcc $(FLEX_OUTPUT) -c 

link_flex:
	gcc $(OBJECT_FLEX) -o $(ELF)

# END Flex section ========================================================

# BEGIN bison section =======================================================
bison:
	bison $(SRC_BISON)$(BISON_TYPE) -d -t

preprocess_compile_and_assemble_bison:
	gcc $(BISON_OUTPUT) -c 

# END bison section ===========================================================


# BEGIN main section ========================================================

preprocess_compile_and_assemble_main:
	gcc -c $(SRC_MAIN) -o $(OBJECT_MAIN)

# END main section ==========================================================

# BEGIN compile section =====================================================
link_flex_bison_and_main:
	gcc $(OBJECT_FLEX) $(OBJECT_BISON) $(OBJECT_MAIN)  -o $(ELF)

load_elf:
	./${ELF} < $(INPUT_COMPILER_CODE) > $(OUTPUT_COMPILER_CODE)

clear:
	clear

# END compile section ========================================================

run_tiny:
	../tiny/tm.elf  $(OUTPUT_COMPILER_CODE)