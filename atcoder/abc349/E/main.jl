using Combinatorics
m = zeros(Int, 9)
for i in 0:2
    l = map(x -> parse(Int, x), split(readline()))
    for j in 1:3 m[i * 3 + j] = l[j] end 
end

over = () -> begin
    
end

x = 0
for perm in permutations(collect(1:9))
    global x += 1
end
println(x)