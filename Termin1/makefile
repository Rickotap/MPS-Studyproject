# Quellendatei
FILE = Termin1Aufgabe2
# Toolchain
TC = arm-eb63-elf-
# Compiler
GCC = gcc
# Optimierungsstufe
OPTI = 0
			
all:
# Übersetzen und binden der Quelldatei
	$(TC)$(GCC) -g -O$(OPTI) $(FILE).c -o $(FILE).elf
# Erzeugen des Assemblercode aus der C-Datei
	$(TC)$(GCC) -S -O$(OPTI) $(FILE).c 

