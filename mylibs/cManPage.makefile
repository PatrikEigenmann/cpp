# ------------------------------------------------------------------------------------
# Makefile for the project cManPage. Compile instruction to compile the c project.
# ------------------------------------------------------------------------------------
# Author: Patrik Eigenmann (p.eigenmann@gmx.net)
# ------------------------------------------------------------------------------------
# Change Log:
# Sat 2024-11-16 File created.                                          Version: 00.01
# Sun 2024-11-17 Changed the configuration to fit the project.          Version: 00.02
# ------------------------------------------------------------------------------------
#The compiler used to compile the project.
comp=gcc
#comp=clang

#If the project needs to be compile with specific compiler flags (optional).
cflags=

#Targed binary of the project, either an executive or an object/library file.
#target=exec
target=obj

#Project name, if there is no src file defined, pmake assumes that the .c file has the same name as the project name.
project=cManPage

#Source file: Use it if the source filename is different than the project name. As example main.c but project is cal.exe.
src=

#Libraries to add, or already compiled .o files. Make sure they are properly included.
libs=