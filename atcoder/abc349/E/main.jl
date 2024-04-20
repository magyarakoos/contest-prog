using Combinatorics
using StatsBase
m = zeros(Int, 9)
for i in 0:2
    l = map(x -> parse(Int, x), split(readline()))
    for j in 1:3 m[i * 3 + j] = l[j] end 
end

over = () -> begin
    for i in 1:3:7 
        if length(countmap(m[i:i+2])) == 1 return false end 
    end
    
end
