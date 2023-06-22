# Monty

Monty is a simple scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Compilation & Output

```bash
make build
```

Betty test

```bash
make b
```

## Usage

```bash
./monty file
```

## Example

```bash
$ cat bytecodes/00.m
push 1
push 2
push 3
pall
$ ./monty bytecodes/00.m
3
2
1
```

## Opcodes

| Opcode | Description |
| --- | --- |
| push | Pushes an element to the stack |
| pall | Prints all the values on the stack |
