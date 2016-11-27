=begin

random-seating.rb

A port to Ruby of randomSeating.py.

@author Charles Bailey
@version 0.2 9/26/16

=end

def get_good_shuf(len)
	arr = []
	len.times{|i| arr << i}
	arr.shuffle!

	return arr if len <= 3

	changes = true
	while changes
		changes = false

		for i in 1...arr.length
			if (arr[i-1] - arr[i]).abs <= 1
				j = rand(0...arr.length)
				while (j == i-1 || j == i)
					j = rand(0...arr.length)
				end

				arr[i-1],arr[j] = arr[j],arr[i-1]
				changes = true
			end
		end

	end
	return arr
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

arr = get_good_shuf(students_original.length)
arr.each_with_index do |v,i|
	puts "#{format("%2i", i+2)}|\t#{students_original[v]}"
end
