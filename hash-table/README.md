# -- SIMPLE HASHING TABLE --

The following program is a chained list with a hashing table. Long story short, if a user enters a 4 characters id, the program will fetch the matching item in the list if it exists, or send back an error. <br />

<hr />

The program comes along with functions to stack items, fetching items and remove them<br/>
For in depth information on recursions, hashing functions or code implementation, see comments.

### Hashing
The hashing is quite simple: this project was more of an excuse to train myself and summarize what I learned over a short C formation. <br /> 

A given input that is four characters long is parsed into a sum of ascii values. This value modulo a given salt, creates an array index for storage within the hashing table.<br />

Recursion functions are there to store values sharing the same indexes to other slots or retreiveing items that share the same index but not the same cell wihtin the chained list.<br />

I did put a lot of emphasis to avoid memory meak issues, and to the extend of my knowledge, none should happen.<br />

There is however the possibility of having a small issue if the user enters a wrong formatted input. The terminal will show "invalid input" upon hitting enter for function selection, and "invalid input" yet again even after giving an input within the authorized switch range

