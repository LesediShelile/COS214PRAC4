# COS214PRAC4 — TaskForge 2026

A C++11 application that manages a nested body of software delivery work.
A project is modelled as a recursive hierarchy of delivery phases and delivery
tasks. Phases may contain other phases as well as individual tasks, so an entire
subsystem and a single work item can be treated uniformly. Individual tasks carry
a lifecycle, and optional responsibilities such as priority handling and auditing
can be attached to objects at runtime without modifying their classes.

---

## Team

| Member | Student number |
|---|---|---|
| Lesedi Shelile | u25110455 |
| Taya Govender | u24697274O |
| Shakir Alexander | u25122208 |

All three members understand the complete submission.

---

## Domain

TaskForge models the delivery of a software project.

- A **delivery task** is a single unit of work — designing a login screen,
  creating an API, running integration tests.
- A **delivery phase** is a named grouping of work. A phase may contain tasks,
  other phases, or both.
- The runtime hierarchy nests at least three levels below the root, and contains
  both individual tasks and nested phases.

The problem the system solves: a project manager needs to report on, traverse
and operate over the whole tree without knowing whether any given node is a
single task or a whole subsystem, and needs to attach cross-cutting concerns
such as auditing or priority to selected items only.

---


## Runtime scenarios

**Setup.** A root phase, `Development phases`, holds seven phases. `Frontend
Phase` and `Backend Phase` hold individual tasks; `Testing Phase` holds a nested
`Login Testing Phase`. This gives at least three levels of nesting below the
client, with both individual work items and nested groups.

**Scenario 1 — traversal.** The same tree is walked twice. `DepthFirstIterator`
visits in pre-order, so a phase appears immediately before its contents;
`BreadthFirstIterator` visits level by level, so all top-level phases appear
before any task. Neither loop touches a phase's internal container — the client
calls only `first()`, `isDone()`, `current()` and `next()`.

**Scenario 2 — lifecycle.** `Login Design` is taken from planning through
in-progress to completed, then refused when asked to return to any earlier
state; each rejection returns `false` and leaves the task unchanged. `Login
Testing` uses the dependency parameter, so it cannot begin while the design it
tests is delayed.

**Scenario 3 — runtime responsibilities.** `PriorityDecorator` adds an attribute
the wrapped class never had. `AuditDecorator` wraps `changeState()`, recording
each attempt with its trigger, prior state and outcome, and returning the result
unchanged. A decorated object stays usable through `DeliveryComponent` — the
decorator forwards `childCount()` and `getChild()`, so it remains traversable
with no special case in the iterators.
---

## Project structure

```
.
├── DeliveryComponent.h/.cpp      Composite — Component
├── DeliveryTask.h/.cpp           Composite — Leaf, State — Context
├── DeliveryPhase.h/.cpp          Composite — Composite
├── State.h/.cpp                  State — State
├── Planning/InProgress/...       State — ConcreteState
├── Iterator.h/.cpp               Iterator — Iterator
├── DepthFirstIterator.h/.cpp     Iterator — ConcreteIterator
├── BreadthFirstIterator.h/.cpp   Iterator — ConcreteIterator
├── DeliveryDecorator.h/.cpp      Decorator — Decorator
├── PriorityDecorator.h/.cpp      Decorator — ConcreteDecorator
├── AuditDecorator.h/.cpp         Decorator — ConcreteDecorator
├── main.cpp                      Client
├── Makefile
├── Dockerfile
├── README.md
└── docs/                         UML class, object, state and activity diagrams
```

---


## Build and run

### Docker

Build the image:

```
docker build -t taskforge .
```

Compile:

```
docker run --rm taskforge make
```

Run:

```
docker run --rm taskforge ./taskforge
```

Run with GDB:

```
docker run --rm -it taskforge gdb ./taskforge
```

Run with Valgrind:

```
docker run --rm taskforge valgrind --leak-check=full --show-leak-kinds=all ./taskforge
```
### Without Docker

```
make            # builds ./taskforge with -std=c++11 -Wall -g
make run        # builds and runs
make clean      # removes objects and the executable
make valgrind   # runs under Valgrind with full leak checking
```

---

