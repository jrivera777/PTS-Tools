=begin

random-seating.rb

A port to Ruby of randomSeating.py.

@author Charles Bailey
@version 0.2 9/26/16

=end

=begin
	get_neigbors returns the adjacent people in a linear population
	arrangement.

	@param population an array of strings to search through
	@param person the person for which to search

	@return an array containing a person's neighbors
=end
def get_neighbors(population, person)
	if population.nil? || population.empty?
		puts "[!] Empty population!"
		exit(4)
	elsif population.length == 1
		return []
	end

	loc = population.index(person)
	if loc.nil?
		puts "[!] Could not find such a person in population!"
		exit(5)
	end

	# I've changed this logic because the room is NOT
	# circular.
	if loc == 0
		return [population[1]]
	elsif loc == population.length-1
		return [population[ population.length-2 ]]
	end

	[population[loc-1], population[loc+1]]
end

=begin
	shuffle_and_verify will verify that no two people were
	originally next to each other.

	The function will correct any issues found.

	@param pop the array of people to check
	@param neighbors a hash of strings to arrays of strings
	representing a person's original neigbors

	@return void
=end
def shuffle_and_verify(pop, neighbors)

	changes = true;
	while changes
		changes = false;
		for i in 1...pop.length

			# if the person to the left was an original neighbor...
			if neighbors[pop[i]].include? pop[i-1]

				j = rand(0...pop.length)
				while j == i-1 || j == i
					j = rand(0...pop.length)
				end

				pop[i-1], pop[j] = pop[j], pop[i-1]

				changes = true
			end

		end
	end
	return pop
end



# main routine: 
unless ARGV.length == 1
	puts "[!] Usage: ./random-seating.rb [seating chart file]"
	exit(1)
end

begin
	students_original = File.readlines(ARGV[0]).map{|line| line.strip}
rescue
	puts "[!] Could not open file #{ARGV[0]}"
	exit(2)
end

if students_original.length <= 1
	puts "[!] Not enough students to shuffle."
	exit(3)
end

# I am going to cache the neighbors...
neighbors = {}
students_original.each do |person|
	neighbors[person] = get_neighbors(students_original, person)
end

students_new = shuffle_and_verify( students_original.dup, neighbors )

for i in 0...students_new.length
	puts "#{format("%2i", i+2)}|\t#{students_new[i]}"
end
puts "|X|\tEND"