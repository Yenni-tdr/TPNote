#Directory path
Dir_SRC = src
Dir_OBJ = obj
Dir_PROG = bin
Dir_INCL = include

#Compiler
CC = gcc

#Compiler flags
CFLAGS = -g -Wall -fsanitize=address -Wno-unused-variable -Wno-uninitialized

#Library flags
LDLIBS = -lm 

#Shell commands
MKDIR_P = mkdir -p
RM = rm -f
RM_R = rm -rf

#all set up
SRC = $(wildcard $(Dir_SRC)/*.c) 
HEAD = $(wildcard $(Dir_INCL)/*.h)
OBJ = $(SRC:$(Dir_SRC)/%.c=$(Dir_OBJ)/%.o)
PROG = $(Dir_PROG)/AirBnb

#Target
all : $(PROG)

#Compiling target
$(PROG) : $(OBJ) 
	@echo "Generating executable file ..."
	@$(MKDIR_P) $(Dir_PROG)
	@$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)
	@echo "Done !"

$(Dir_OBJ)/%.o : $(Dir_SRC)/%.c 
	@echo "Compiling $^ ..."
	@$(MKDIR_P) $(Dir_OBJ)
	@$(CC) -I $(Dir_INCL) -c $< -o $@ $(LDLIBS)

.PHONY : clean

#Clean files from obj and bin
clean :
	@echo "Cleaning files from $(Dir_OBJ) and $(Dir_PROG) ..."
	@$(RM) $(OBJ) $(PROG)
	@echo "Done !"


#Clean repertories obj and bin
hardClean : 
	@echo "Cleaning repertories $(Dir_OBJ) and $(Dir_PROG)..."
	@$(RM_R) $(Dir_OBJ) $(Dir_PROG)
	@echo "Done !"

#Run your target	
run : 
	@if [ -x $(PROG) ]; then\
		./$(PROG);\
	fi
	@if [ ! -x $(PROG) ]; then\
		echo "$(PROG) found, make before make run";\
	fi


#Help menu
help :
	@echo "Bienvenue dans le Makefile."
	@echo "Voici les options disponibles :"
	@echo "\t make : Compiler le projet,"
	@echo "\t make clean : Nettoyer les dossiers Bin et Obj. Deplacer les fichiers dans la corbeille,"
	@echo "\t make hardClean : Suppression des dossiers Bin et Obj,"
	@echo "\t make run : Executer le programme."