=begin

random-seating.rb

A port to Ruby of randomSeating.py.

@author Charles Bailey
@version 0.1 9/26/16

=end

def check_neighbors(population, person)
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

	if loc == 0
		return population[ 1..[2, population.length].min ]
	elsif loc == population.length-1
		return population[ ([0,population.length-2].min)..([0, population.length-1].min) ]
	end

	[population[loc-1], population[loc+1]]
end



# main routine: 
unless ARGV.length == 1
	puts "[!] Usage: ./random-seating.rb [seating chart file]"
	exit(1)
end

begin
	students_ordered = File.readlines(ARGV[0]).map{|line| line.strip}
rescue
	puts "[!] Could not open file #{ARGV[0]}"
	exit(2)
end

num_students = students_ordered.length

if num_students <= 1
	puts "[!] Not enough students to shuffle."
	exit(3)
end

students = students_ordered.dup
new_order = []

while new_order.length < num_students

	tmp_student = students[rand(students.length)]
	while new_order.include? tmp_student
		tmp_student = students[rand(students.length)]
	end

	neighbors = check_neighbors(students_ordered, tmp_student)
	unless new_order.empty?
		if neighbors.include? new_order.last
			if students.length != 1
				next		
			else
				for i in 1...new_order.length
					if !( neighbors.include?( new_order[i]) || neighbors.include?( new_order[i-1]) )
						
						new_order.insert(i, tmp_student)
						students.delete(tmp_student)
						
						break

					end
				end
			end
		end
	end

	new_order << tmp_student
	students.delete(tmp_student)
end

for i in 0...new_order.length
	puts "#{format("%2i", i+2)}:\t#{new_order[i]}"
end