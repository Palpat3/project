To run c programs do:

```
cd c_code
gcc filename.c -o filename -flags
./filename.exe
```

`-fno-stack-protector -Wall`

To run rust do:

```
cargo new project_name
cargo run
```
to run main.rs.

Otherwise do 

```
cargo run --bin filename
```


library in c to use in rust:

```
gcc -c filename.c -o filename.o
ar rcs lib+filename.a filename.o
rustc rustfile.rs -L . -l static=filename -o rustFile

cargo run --bin rustfile

```

(cargo new projectname creates a new folder with src and everything)
(Each rust file )