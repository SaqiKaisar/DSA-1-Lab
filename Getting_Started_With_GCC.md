# GCC Command Guide for C Programming

_(For Windows 10/11, Linux, WSL)_

---

# 1. Introduction

GCC (GNU Compiler Collection) is a compiler used to compile C programs.

This document explains:

- How to compile C programs
- How to run them
- Common compiler options
- Recommended commands for students

---

# 2. Basic Compilation

## 2.1 Compile a C Program

```bash
gcc filename.c
```

Example:

```bash
gcc main.c
```

Output file generated:

- Windows → `a.exe`
- Linux/WSL → `a.out`

---

## 2.2 Run the Program

### Windows:

```bash
a
```

or

```bash
a.exe
```

### Linux / WSL:

```bash
./a.out
```

---

# 3. Compile with Custom Output Name

Instead of the default `a.exe` or `a.out`, use `-o`.

```bash
gcc filename.c -o outputname
```

Example:

```bash
gcc main.c -o main
```

Run:

### Windows:

```bash
main
```

### Linux/WSL:

```bash
./main
```

---

# 4. Recommended Compilation Command

```bash
gcc -std=c11 -Wall -Wextra main.c -o main
```

### Explanation:

- `-std=c11` → Use C11 standard
- `-Wall` → Enable warnings
- `-Wextra` → Enable extra warnings
- `-o main` → Output file name

This ensures clean and modern C code.

---

# 5. Compiling Multiple Files

If your project has multiple source files:

```bash
gcc file1.c file2.c -o program
```

Example:

```bash
gcc main.c functions.c -o app
```

---

# 6. Create Object Files (Large Projects)

## 6.1 Compile Only (No Linking)

```bash
gcc -c filename.c
```

Creates:

```
filename.o
```

## 6.2 Link Object Files

```bash
gcc file1.o file2.o -o program
```

---

# 7. Debug Mode Compilation

To debug using `gdb`:

```bash
gcc -g main.c -o main
```

`-g` adds debugging information.

---

# 8. Optimization Options

```bash
gcc -O2 main.c -o main
```

### Optimization Levels

| Option | Meaning            |
| ------ | ------------------ |
| -O0    | No optimization    |
| -O1    | Basic optimization |
| -O2    | Recommended        |
| -O3    | High optimization  |

For academic work, `-O2` is sufficient.

---

# 9. Using Math Library

If your program uses `math.h` functions like:

- `sqrt()`
- `pow()`
- `sin()`

You must link the math library:

```bash
gcc main.c -o main -lm
```

---

# 10. Show GCC Version

```bash
gcc --version
```

---

# 11. Preprocessing Only

```bash
gcc -E main.c
```

Shows expanded code after preprocessing.

---

# 12. Generate Assembly Code

```bash
gcc -S main.c
```

Creates:

```
main.s
```

---

# 13. One-Line Compile and Run

## Windows:

```bash
gcc main.c -o main && main
```

## Linux/WSL:

```bash
gcc main.c -o main && ./main
```

---

# 14. Common Errors and Solutions

## Error: gcc not recognized

**Cause:**  
Compiler not added to PATH.

**Solution:**

- Add MinGW/MSYS2 `bin` folder to Environment Variables
- Restart terminal

---

## Error: undefined reference to sqrt

**Cause:**  
Math library not linked.

**Solution:**

```bash
gcc main.c -o main -lm
```

---

# 15. Standard Workflow for Students

Step 1 – Write program  
Step 2 – Save as `main.c`

Step 3 – Compile:

```bash
gcc main.c -o main
```

Step 4 – Run:

### Windows:

```bash
main
```

### Linux:

```bash
./main
```

---

**End of Document**
