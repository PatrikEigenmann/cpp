# cpp Projects

This repository contains C-based projects, utilities, and libraries, organized for easy navigation and use. The custom tool pmake is included to compile all projects and programs with its specific makefiles.
It is up to the developer completely to use my pmake, make or cmake. Whatever you prefer, but once you look into pmake and the ease of use, I promise you'll love it. :-)

## 📂 Directory Structure

### 1. **dosutils**
Windows specific utility programs (who doesn't like the old schoold UNIX commands), including:
- `cp.c` and `ls.c` with their respective `makefiles`.

### 2. **enigma**
An implementation of the Enigma machine:
- Code and makefile for `cEnigma`.

### 3. **hangman**
Classic Hangman game:
- Code and makefile for `cHangman`.

### 4. **mylibs**
This folder contains shared libraries, umbrella headers, and utility files. Umbrella headers are an invention of mine, as a collective component to combine similar modules into one shared/dynamic library.
Umbrella headers simplify the process of building shared libraries. Shared libraries are stored in the bin folder. Further explanations and usage instructions are provided in the mylibs folder's dedicated README.md.

A collection of libraries and utilities:
- **bin**: Precompiled shared libraries (`*.so`).
- **md4c**: Markdown processing library.
- **utility**: Helper utilities like `cManPage` and `cProgress`.
- Other libraries and makefiles.

### 5. **network**
Network utilities:
- `chkip`: A tool for IP-related tasks with source and makefile.

### 6. **tests**
Assorted test programs:
- Examples include `cAppend`, `cQuickSort`, `exmplNCurses`, and many more.
- Organized with individual source files and makefiles.

### 7. **tools**
Build and process management tools:
- Tools like `jmake` and `pmake` with corresponding source and makefiles.

---

## 🛠 Setting Up pmake:

- Clone the repository.
- Change to the tools directory.
- Compile pmake using GCC. Instructions are in the pmake.c
- Copy the binary pmake to the bin directory in your home folder.
- Add bin directory to your system PATH:
    - Open your shell configuration file (.zshrc for MacOS, .bashrc for Linux).
    - Add the line: export PATH="/path/to/your/bin:$PATH".
    - Save and close the file.
- Source the shell configuration file to apply changes.

You are now ready to use pmake!

# License
This project is distributed under the GNU open source License, more in the LICENSE file.
Review the terms before use.

# Note from the Developer
"C Hackers... Come out and play!"