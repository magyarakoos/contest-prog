using Combinatorics
using StatsBase

m = zeros(Int, 9); d = collect(1:9)
for i in 0:2
    l = map(x -> parse(Int, x), split(readline()))
    for j in 1:3 m[i * 3 + j] = l[j] end 
end

over = () -> begin
    for i in 1:3:7 
        if length(countmap(d[i:i+2])) == 1 return false end 
    end
    return 
        length(unique([d[1], d[5], d[9]])) > 1 && 
        length(unique([d[3], d[5], d[7]])) > 1
end

for perm in permutations(collect(1:9))
    scores = [0, 0]
    for i in 1:9
        
    end
end