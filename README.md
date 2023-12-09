# Mr-Wolf

Based on the children's game Mr. Wolf. In the physical game, one child, the 'wolf', stands at a fixed location with his eyes closed and back turned. The rest of the children are dispersed around the wolf. The children are instructed to ask the wolf the time, and the wolf must reply back with, "it's n o'clock', where n is a natural number that exists on the clock. The children must then take n steps towards the wolf, with the goal of reaching the wolf without getting caught during 'lunch time'.

In this C++ implementation, the wolf is fixed at the origin (0,0), and the children's scattered locations are stored as nodes in a linked list. The game asks the user for the input (the time), and the children's position will change according to: 
<br/>
Δ𝑥 = 𝑡 cos(𝑎𝑡𝑎𝑛2(𝑦, 𝑥)) 
<br/>
Δ𝑦 = 𝑡 sin (𝑎𝑡𝑎𝑛2(𝑦, 𝑥))
