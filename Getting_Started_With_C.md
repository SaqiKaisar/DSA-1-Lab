# Setup C/C++ using MinGW-w64 + VS Code (Recommended)

## Step 1: Install MinGW-w64 (GCC Compiler)

### 🔹 Option A (Easiest – MSYS2 Method – Recommended)

### 1. Download MSYS2

* Go to: [https://www.msys2.org](https://www.msys2.org)
* Download the installer.
* Install it (keep default settings).

---

### 2. Open MSYS2 UCRT64 Terminal

After installation:

* Open **MSYS2 UCRT64** from Start Menu.

---

### 3. Update Package Database

Run:

```bash
pacman -Syu
```

Close terminal when asked and reopen **MSYS2 UCRT64**, then run again:

```bash
pacman -Syu
```

---

### 4. Install GCC Compiler

Run:

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```

Press `Y` when asked.

---

### 5. Add Compiler to Windows PATH

1. Open:

   ```
   C:\msys64\ucrt64\bin
   ```
2. Copy this path.
3. Go to:

   * Search → “Environment Variables”
   * Click **Edit the system environment variables**
   * Click **Environment Variables**
   * Under **System variables**, select `Path`
   * Click **Edit**
   * Click **New**
   * Paste:

     ```
     C:\msys64\ucrt64\bin
     ```
   * Click OK → OK → OK

---

### 6. Verify Installation

Open **Command Prompt (cmd)** and type:

```bash
gcc --version
g++ --version
```

If it shows version info → ✅ Installed correctly.

---

## Step 2: Install Visual Studio Code

1. Download from: [https://code.visualstudio.com](https://code.visualstudio.com)
2. Install it.
3. During installation, check:

   * ✅ Add to PATH
   * ✅ Add "Open with Code"

---

## Step 3: Install C/C++ Extension in VS Code

1. Open VS Code.
2. Go to Extensions (`Ctrl + Shift + X`)
3. Search:

   ```
   C/C++
   ```
4. Install **C/C++ by Microsoft**

Optional:

* Install **Code Runner** (easy run button)

---

## Step 4: Test C Program

### 1. Create a file:

`main.c`

```c
#include <stdio.h>

int main() {
    printf("Hello World!\n");
    return 0;
}
```

---

### 2. Compile Manually in Terminal

Open terminal in VS Code (`Ctrl + ~`) and run:

```bash
gcc main.c -o main
```

Then run:

```bash
main
```

---

## Step 5: Test C++ Program

Create `main.cpp`

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello C++!" << endl;
    return 0;
}
```

Compile:

```bash
g++ main.cpp -o main
```

Run:

```bash
main
```

---

