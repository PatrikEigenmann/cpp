# -----------------------------------------------------------------------------------------------
# Samael.ToolBox.makefile - This file is the makefile for the tool pmake for the sub project
# Samael.ToolBox. pmake is a tool that reads instructions you give it about how to use a compiler
# of your choice and then automatically runs the compiler to build your software projects. Imagine
# it as a smart assistant that knows exactly how to compile and prepare all the pieces of your
# software, ensuring everything fits together correctly without you having to manually run each
# step. This automation makes the development process faster and reduces the chance of errors.
# ------------------------------------------------------------------------------------------------
# Author: Patrik Eigenmann 
# eMail:  p.eigenmann@gmx.net
# GitHub: www.github.com/PatrikEigenmann/cpp
# GitHub: www.github.com/PatrikEigenmann/Java
# ------------------------------------------------------------------------------------------------
# Change Log:
# Sat 2025-03-22 File created.                                                      Version: 00.01
# Wed 2025-03-26 Folder changed from Utility to ToolBox                             Version: 00.02
# ------------------------------------------------------------------------------------------------

# The compiler used for compiling the project is essential. Commonly, GCC is employed for Windows
# due to its robustness and prevalence in open-source development. On MacOS, Clang is preferred
# for its speed and advanced diagnostics. These compilers translate source code into executable
# binaries, ensuring compatibility and optimized performance across different operating systems.
# comp=clang
comp=gcc

# If the project requires specific compiler flags for compilation, these flags should be specified
# to ensure the code is compiled correctly and efficiently. Compiler flags can enable or disable
# features, optimize performance, or enforce coding standards. Properly setting and documenting
# these flags can lead to more robust and optimized software, improving performance and catching
# potential errors during compilation. While optional, using the right flags is crucial for
# consistency and reproducibility in the build process.
cflags=

# If the project necessitates specific compiler flags for compilation, these should be meticulously
# specified to ensure precise and efficient code compilation. Compiler flags play a crucial role in
# enabling or disabling features, optimizing performance, and enforcing strict coding standards.
# Properly documenting and utilizing these flags can enhance the robustness and optimization of the
# software, ensuring consistency and reducing potential errors in the build process. Although optional,
# their strategic use is pivotal for achieving high-quality, reliable software development.
# target=obj
target=shared

# Specify the project name, as pmake will use this name to create the executable. If the src directive
# is not specified, pmake assumes the corresponding .c file has the same name as the project directive.
# This automatic association streamlines the build process by aligning the project name with its main 
# source file when no specific source files are defined.
project=bin/libSamael.ToolBox

# The `src` directive specifies the source files that require compilation. If the `src` directive is
# left empty, `pmake` assumes that the corresponding `.c` file shares the same name as the project
# directive. This automatic association streamlines the build process by aligning the project name
# with its main source file when no specific source files are defined. 
src=Samael.ToolBox.c

# Specify the libraries, either as .c source files or already compiled .o object files. Ensure these
# files are properly included in the build process to guarantee successful compilation and linking
# of the project.
# libs=../mylibs/cVersion.c ../mylibs/cManPage.c ../mylibs/cProgress.c
libs=ToolBox/cVersion.c ToolBox/cManPage.c ToolBox/cProgress.c