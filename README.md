# MachineLearning2
Goal:
To create an artificial intelligence in c++ that can solve a Rubik's Cube, without any imports or frameworks.


Note:
Any comment that is in all caps or has a bunch of E's in it are notes to self. I put large strings of capital E's in those comments so that I can easily find them by searching for the E's.


Process:
First, a representation of a Rubik's Cube was made as a class, "Cube". I used a physical Rubik's Cube to label each sticker with a number. This number represented the index of that sticker's location within a one dimensional array. The value at that index indicates the color of the sticker at that location (White=0, Red=1, Green=2, Orange=3, Blue=4, Yellow=5).

Going into this project, I expected mediocre results, so I went ahead an added compatability for a 2x2x2 Rubik's Cube in addition to the regular 3x3x3, since the 2x2x2 would be easier to solve.

Next, I created the Package struct, whose original purpose was to serve as an easy way to return arrays from functions, but over the course of the project became much more complex with features such as the "append" function.
Then, I added the ability to perform moves on the cube. I hardcoded those because I couldn't figure out any easier way to do it with my sticker-numbering system.

Then I began planning out how the AI would work. I decided on a reccurent model, since I hadn't used one before and I believed it would work well for this project, since it would be helpful to know your previous move when solving a Rubik's Cube. (Only after nearly finishing the reccurent brain did I realize that a Rubik's Cube is a form of state machine, so it doesn't matter which moves it took to get there; The current state of the cube is the only variable that matters)

The plan was to feed the brain the current state of the cube, then it would create a copy of the cube. The state of the copied cube would be the values for the input layer nodes, and the output node would determine the move that would be performed. Once a move has been decided, it would be appended to a move-list (which has a predetermined maximum length) and would be applied to the copied cube. Then, the program would check if the cube was solved. If so, it would fill the move-list with a null move (move "12"). If not, it would send the current state of the copied cube back to the input layer nodes to decide on the next move. Once the move-list is full (up to the predetermined max length), the program would score the cube depending on how well it was solved. This would be how I would isolate the good brains from the bad ones.

I did a lot of research on projects similar to this one, and none of them stated how they graded the cubes. This meant I had to come up with my own grading method. So I ended up with a very convoluted and overly complicated grading system (which doesn't work very well).

After finishing the grading function, I began work on the Brain class. I created a few structs to make it easier to follow: Node and Connection. The brain stores all of the nodes within a one dimensional array. The first few nodes are the input nodes, the last node is the output node, and the rest are the hidden nodes. The brain constructor creates all of these nodes, then for each node, it picks a number of other nodes to point towards with an arrow. The nodes they point at are the nodes whose values will be determined by the pointer. These arrows are represented by the Connection struct, and are stored by the nodes who are being pointed at (since those connections are only relevant to that node).

After all of these connections have been generated, it checks if the output node is being pointed at. If it isn't, it generates an additional connection from a random node to point at the output node. This is to ensure that the output node's value actually changes after some number of propagations. (Technically the output node still might not change if the node that is pointing at it never changes value).
