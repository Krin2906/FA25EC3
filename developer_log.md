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

 Commit 3 — Implement `addNode` and assignment-correct `printAll`

**What I worked on:**
- Implemented the full `addNode()` function:
    - Looks up the parent using `findNode(parentID)`.
    - Checks if the child already exists in `nodesList`.
    - Creates a new child node if it doesn’t exist yet.
    - Reuses an existing child node if it already exists (so multiple parents can point to the same child).
    - Prevents duplicate links by checking if the parent already has that child.
    - Added a small warning message if the parent doesn’t exist.

- Implemented the `printAll()` function so that it matches the assignment’s required formatting:
    - Prints each node in the format: `Node <id>: <text>`
    - Prints each child in the format: `Child -> <childID>`
    - Prints `Child -> (none)` if the node has no children.
    - Kept the logic simple by iterating over `nodesList`
    - Adjusted the formatting to match the example in the project README.

***Bugs / Issues:***
- originally had a "fancier" print format with Unicode characters, but this didn’t match the assignment.
  I rewrote `printAll()` to match the exact expected structure.
- Unsure whether to overwrite an existing child’s data if `childID` appears again for now tho I left the original text unchanged.

***How I tried to solve them:***
- Re-reviewed the project instructions to ensure correct output format.
- Simplified `addNode()` logic to the essentials: find parent → find/create child → avoid duplicates → link.
- Added a basic warning for missing parent nodes to help catch mistakes.

***Files modified in this commit:***
- `tree.h`

***Commit Reasoning:***
This commit makes the tree functional and verifiable.  
I can now build the parent–child relationships and print the entire structure in the format the assignment expects.  


Commit 4 — Destructor and playGame()

***What I worked on:***
- Implemented the `~Tree()` destructor:
  - Loops through `nodesList` and deletes every node pointer.
  - Clears `nodesList` and sets `rootNode` to `nullptr` so nothing is dangling.
  - This is basically the cleanup phase for all the dynamic memory I’ve been allocating.
- Implemented `playGame()` to turn the tree into an actual playable game:
  - Starts at `rootNode` and prints the current node’s text.
  - If the node has no children, it prints an ending message and stops.
  - If there are children, it prints a numbered list of options and asks the user to pick one.
  - Validates the user’s selection and moves to the chosen child node.
  - Repeats until the story runs out of paths.

***Bugs / Issues:***
- Needed to remember that deleting the same node twice would be bad, so I relied on the fact that every node lives exactly once in `nodesList`.
- Input handling in `playGame()` can get weird if the user types letters or out-of-range numbers, so I had to guard against that.

***How I tried to solve them:***
- Centralized deletion in the destructor by only deleting from `nodesList`, which I’ve been maintaining since the start.
- Used `cin.clear()` and `cin.ignore(std::numeric_limits<streamsize>::max(), '\n')` to reset the input stream when the user enters something invalid.
- Kept the gameplay loop simple: show text, show options, ask for a number, move to the next node.

***Files modified in this commit:***
- `tree.h`

***Commit Reasoning:***
This commit finishes off the main requirements:
- The tree now cleans up all of its dynamic memory correctly when it’s destroyed.
- The user can actually “play” through the story using the `playGame()` function and follow different paths.


