# Data Structures and Algorithms in C

## Setup

### Prerequisites
clang-tidy, cppcheck

```bash
git clone https://github.com/atharva-potdar/DSA_C.git
cd DSA_C
cmake -S . -B build -G Ninja
```

## Build

```bash
cmake --build build
```

## Running

```bash
./build/linked_list_example
./build/doubly_linked_list_example
./build/stack_array_example
./build/stack_list_example
./build/queue_array_example
./build/queue_list_example
```

## Data Structures

| Structure | Header | Implementation | Example |
|---|---|---|---|
| Singly Linked List | [linked_list.h](linked_list/linked_list.h) | [linked_list.c](linked_list/linked_list.c) | [example](linked_list/examples/linked_list_example.c) |
| Doubly Linked List | [doubly_linked_list.h](doubly_linked_list/doubly_linked_list.h) | [doubly_linked_list.c](doubly_linked_list/doubly_linked_list.c) | [example](doubly_linked_list/examples/doubly_linked_list_example.c) |
| Stack (array) | [stack_array.h](stack/stack_array.h) | [stack_array.c](stack/stack_array.c) | [example](stack/examples/stack_array_example.c) |
| Stack (list) | [stack_list.h](stack/stack_list.h) | [stack_list.c](stack/stack_list.c) | [example](stack/examples/stack_list_example.c) |
| Queue (array) | [queue_array.h](queue/queue_array.h) | [queue_array.c](queue/queue_array.c) | [example](queue/examples/queue_array_example.c) |
| Queue (list) | [queue_list.h](queue/queue_list.h) | [queue_list.c](queue/queue_list.c) | [example](queue/examples/queue_list_example.c) |
