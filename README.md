# Advent-of-Code

My solutions to advent of code in C++.

## Day 1
Overall I enjoyed this challenge, part 1 proved to be relatively simple and my approach utilised going through each character in the string and if it was an integer I added it to a string of possible values. I then took the first and last integer to make up my double digit value.

Part 2 was the hardest day 1 challenge I have seen. 
- My intial approach ended up leading me down a way too complicated solution to the problem. I initially was using str::find() to find the occurences of each value and I would change the value from a string to the integer version manually. After some tinkering I have changed my approach to change the string value into its corresponding integer value, i.e. "three" -> 3. This proved to work much better but I was still getting the wrong answer.
- I checked the reddit and I saw a tip on how to deal with the edge case which I have missed out. There was a case where the numbers could overlap (like this: eighthree)
- I ended up creating a map which had a key value pair of int to string, the key was the int and the string value was the string version of the integer. I used this to calculate the length of each word and replace the whole word but leaving the first and last letter of the word (using the previous example of eighthree, the process would go: eighthree -> e8three -> e8t3e).
- I then fed the new string with converted words to integers into my algorithm from the first part to get the solution.

## Day 2 
This day was simpler but it took me a while as I was busy during this day so I did it in small chunks. This algorithm is not perfect but it works. 
- I used a stringstream to cut the string down into smaller parts. 
- First I erased the "Game 1: " part of the string then I split the string into games divided by the char ';'
- I then split each of the strings into individual colors and numbers of those colors. I analysed each individual one to see if it exceeded the stated rules of no more than 12 red, no more than 13 green and no more than 14 blue.
- I created a bool called isPossible and if any of the rules would be false I would not add the gameID to the total.
- I added all the gameID's of possible games and that was my output of part 1.

- Part 2 was simple. I added a minRed, minGreen and minBlue variable to keep track of which was the minimum number of balls neded to play the game.
- To get the answer for part 2 I multiplied the 3 min variables and stored those values in a powers vector.
- The final step was to sum all the values in the powers vector for each line of input.
