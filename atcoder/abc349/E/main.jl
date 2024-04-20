using Combinatorics
using StatsBase
m = zeros(Int, 9); d = collect(1:9)
for i in 0:2
    l = map(x -> parse(Int, x), split(readline()))
    for j in 1:3 m[i * 3 + j] = l[j] end 
end

over = () -> begin
    for i in 1:3:7 
        if length(countmap(m[i:i+2])) == 1 return false end 
    end
    return 
        length(unique([m[1], m[5], m[9]])) > 1 && 
        length(unique([m[3], m[5], m[7]])) > 1
end
