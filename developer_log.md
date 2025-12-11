Commit 1: Initial Tree scaffolding

**What I worked on:**
- Implemented the `Node<U>` constructor to initialize `id` and `data`.
- Implemented the `Tree<T>` constructor to initialize `rootNode` to `nullptr`.
- Added a `vector<Node<T>*> nodesList` member to the `Tree` class
- Declared all required public methods in `Tree`, including `playGame()`.

**Bugs / Issues:**
- No  issues really but  making sure template syntax in the header was correct.

**How I tried to solve them:**
- I double checked header guards and template class placement.
- I made sure everything is defined in the header so templates will link correctly.

**Files modified in this commit:**
- `tree.h`

**Commit Reasoning (why this commit exists):**
- This commit establishes the foundation of the data structure (Node and Tree) before implementing any logic like adding nodes or searching.


Commit 2: createRoot + findNode using node list

**What I worked on:**
- Implemented `createRoot` so it dynamically allocates a root node (`rootNode`) and stores it in `nodesList` for tracking.
- Implemented `findNode` to scan through `nodesList` and return the first node whose `id` matches the search string.
- Added a small helper `nodeExists` that just wraps `findNode` 

**Bugs / Issues:**
- Debated whether `createRoot` should overwrite an existing root or throw, but for now it just returns if a root already exists.
- Thought about using `std::find_if` for `findNode` but decided a simple loop is easier to read.

**How I tried to solve them:**
- Kept the logic very straightforward: one vector (`nodesList`) stores all nodes, and all search operations go through it.


**Files modified in this commit:**
- `tree.h`

**Commit reasoning (why this commit exists):**
- This commit gets the basic "create a root" and "look up a node by ID" functionality working.

