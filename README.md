# tinySH – A Minimal Unix Shell

A simple shell written in C for educational purposes. It demonstrates:
- Process creation (`fork`, `execvp`)
- Built-in commands (`cd`, `exit`)
- Basic command parsing

## Build
```bash
make
```

## Run
```bash
./tinySH
```

## Next Steps
- Add I/O redirection (`<`, `>`, `>>`)
- Implement pipes (`|`)
- Support background processes (`&`)
- Job control with `jobs`, `fg`, `bg`
```

---

## 🚀 Compile and Test

1. In the project root, run:
   ```bash
   make
   ```
2. Start the shell:
   ```bash
   ./tinySH
   ```
3. Try some commands:
   ```
   tinySH> ls -l
   tinySH> pwd
   tinySH> cd /tmp
   tinySH> exit
   ```

---

