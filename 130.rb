#130
#dailyprogrammer
#rs

=begin
rescue In many board games, you have to roll multiple multi-faces dies.jpg) to generate random 
numbers as part of the game mechanics. A classic die used is the d20 (die of 20 faces) in the 
game Dungeons & Dragons. This notation, often called the Dice Notation, is where you write NdM, 
where N is a positive integer representing the number of dies to roll, while M is a positive 
integer equal to or grater than two (2), representing the number of faces on the die. Thus, 
the string "2d20" simply means to roll the 20-faced die twice. On the other hand "20d2" means 
to roll a two-sided die 20 times.
Your goal is to write a program that takes in one of these Dice Notation commands and correctly 
generates the appropriate random numbers. Note that it does not matter how you seed your random 
number generation, but you should try to as good programming practice.
=end

NdM = ARGV[0].split("d")
1.upto(NdM[0].to_i) {print "#{Random.rand(1..NdM[1].to_i)} "}

