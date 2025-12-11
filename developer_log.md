Commit 1: Initial Tree scaffolding

**What I worked on:**
- Implemented the `Node<U>` constructor to initialize `id` and `data`.
- Implemented the `Tree<T>` constructor to initialize `root` to `nullptr`.
- Added a `vector<Node<T>*> allNodes` member to the `Tree` class
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
